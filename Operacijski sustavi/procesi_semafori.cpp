#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>

using namespace std;

int Sems,Shm;
long long UkupnaSuma = 0;
int M;
int N;

struct Struktura
{
  int ulaz, izlaz;
  int M[5];
  int STOP;
}* K;

void Provjera_semafora(int n)
{
  Sems = semget( IPC_PRIVATE, n, 0600 );

  if(Sems==-1)
  {
    cout<<"Semafora nema\n";
    exit(0);
  }
}

int Operacija_kontrole(int SemNum, int Val)
{
  return semctl(Sems,SemNum,SETVAL,Val);
}

int SemOp(int SemNum, int Op)
{
  struct sembuf buf;

  buf.sem_num = SemNum;
  buf.sem_op = Op;
  buf.sem_flg = 0;

  return semop(Sems, &buf, 1);
}

void Potrosac()
{
  do
  {
    SemOp(0, -1);

    UkupnaSuma += K->M[K->izlaz];

    cout<<"Potrosac prima "<<K->M[K->izlaz]<<"\n";

    K->izlaz = (K->izlaz + 1) % 5;

    SemOp(2, 1);

  } while(--K->STOP > 0);

  cout<<"Potrosac je izracunao ukupnu sumu "<<UkupnaSuma<<"\n";
}

void Proizvodac(int x)
{
  srand(x+x);

  int i = 0;

  do
  {
    SemOp(2, -1);
    SemOp(1, -1);

    K->M[K->ulaz] = 1+rand()%1000;

    cout<<"Proizvodjac "<<x<<" salje "<<K->M[K->ulaz]<<"\n";

    K->ulaz = (K->ulaz + 1) % 5;

    SemOp(1, 1);
    SemOp(0, 1);

  } while(++i < N);
}

void Pocisti(int x)
{
  semctl(Sems, 0, IPC_RMID, 0);
  shmdt( (char*)K );
  shmctl(Shm, IPC_RMID, NULL);

  exit(0);
}

int main(int argc, char* argv[])
{
  Provjera_semafora( 3 );
  Shm=shmget(IPC_PRIVATE, 30*sizeof(int), 0600);

  if(Shm == -1)
	exit(1);

  K = (Struktura*)shmat(Shm, NULL, 0);

  M = atoi(argv[1]);
  N = atoi(argv[2]);

  K->izlaz = 0;
  K->ulaz = 0;
  K->STOP = M * N;

  Operacija_kontrole(2, 4);
  Operacija_kontrole(1, 1);
  Operacija_kontrole(0, 0);

  sigset(SIGINT, Pocisti);

  if(fork() == 0)
  {
	Potrosac();

	exit(0);
  }

  for(int i=0; i<M; i++)
  {
	  if(fork() == 0)
	  {
		Proizvodac(i+1);

		exit(0);
	  }
  }

  for(int i=0; i<=M; i++)
	wait(NULL);

  Pocisti(0);

  return 0;
}

