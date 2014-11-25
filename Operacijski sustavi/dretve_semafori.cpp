#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

sem_t Semafor[2];
int ima_zadatka;
int M, N;
long long Generirani_broj;

void* Dretva_generiraj(void* x)
{
  cout<<"Dretva koja generira zadatke je pocela s radom - broj zadataka = "<<N<<"/n";

  for(int i=0; i<N; i++)
  {
    Generirani_broj = 1+rand()%1000000000;

    cout<<"> generiran je zadatak "<<Generirani_broj<<"\n";

    sem_post(&Semafor[1]);
    sem_wait(&Semafor[0]);
  }

  ima_zadatka=1;
  sem_post(&Semafor[1]);
}

void* Dretva_sumiraj(void* x)
{
  long long procitan_broj;

  int drID = *((int*)x);

  cout<<"Dretva broj "<<drID<<" je pocela s radom\n";

  do
  {
	long long suma;

    sem_wait(&Semafor[1]);

    if(!ima_zadatka)
    {
      suma = 0;

      procitan_broj = Generirani_broj;

      cout<<"<-- dretva "<<drID<<" je preuzela zadatak "<<procitan_broj<<"\n";

      sem_post(&Semafor[0]);

      for(unsigned int i=0; i<procitan_broj; i++)
        suma+=i;

      cout<<"---> dretva "<<drID<<" je obradila zadatak "<<procitan_broj<<" te izracunala sumu brojeva "<<suma<<endl;
    }
  } while(!ima_zadatka);

  sem_post(&Semafor[1]);
}

int main(int argc, char* argv[])
{
  if(argc<3 || argc>3)
    return -1;

  M = atoi(argv[1]);
  N = atoi(argv[2]);

  pthread_t Generirajuca;
  pthread_t Sumirajuca[M];

  int Thread_arguments[M];

  ima_zadatka=0;

  if(sem_init(&Semafor[0],0,0)==-1 || sem_init(&Semafor[1],0,0)==-1)
  {
    cout<<"Semafor nije uspjesno inicijaliziran!"<<endl;
	exit(1);
  }

  if(pthread_create(&Generirajuca, NULL, Dretva_generiraj, NULL) != 0)
  {
    cout<<"Dretva koja racuna neuspjesno je kreirana!"<<endl;
	exit(1);
  }

  for(int i=0; i<M; i++)
  {
    Thread_arguments[i] = i+1;

    if(pthread_create(&Sumirajuca[i], NULL, Dretva_sumiraj, &Thread_arguments[i]) != 0)
    {
        cout<<"Nije moguce kreirati dretvu "<<i<<" koja racuna sumu!"<<endl;
		exit(1);
    }
  }

  pthread_join(Generirajuca, NULL);

  for(int i=0; i<M; i++)
	pthread_join(Sumirajuca[i], NULL);

  for(int i=0; i<2; i++)
	sem_destroy(&Semafor[i]);

  return 0;
}

