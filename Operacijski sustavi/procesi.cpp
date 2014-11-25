#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

struct varijable
{
  int p;

  int z[2];
} * mem;

int mem_id;

void ulazKO( int i, int j )
{
  mem->z[i] = 1;
  while( mem->z[j] == 1 )
  {
    if( mem->p == j )
    {
      mem->z[i] = 0;
      while( mem->p == j )
      { }
      mem->z[i] = 1;
    }
  }
}

void izlazKO( int i, int j )
{
  mem->p = j;
  mem->z[i] = 0;
}

void FunkcijaKO( int i )
{
  int j;
  j = ! i;

  for( int k=1; k<=5; k++ )
  {
    ulazKO( i, j );

    for( int m=0; m<5; m++ )
    {
      usleep( 1000000 );
      printf( "Proces %d je u k.o. br. %d --> %d/5\n", i+1, k, m+1 );
    }

    izlazKO( i, j );
  }
}

void memorija()
{
  mem_id = shmget( IPC_PRIVATE, sizeof(int)*60, 0600 );

  if( mem_id == -1 )
  {
    exit( 1 );
  }

  mem = ( varijable* ) shmat( mem_id, NULL, 0 );
  mem->p = 1;

  for( int i=0; i<2; i++ )
  {
    mem->z[i] = 0;
  }
}

void OslobadanjeRisursa( int sig )
{
  shmdt( ( char* ) mem );
  shmctl( mem_id, IPC_RMID, NULL );

  exit( 0 );
}

int main( int arg, char **argumenti )
{
  memorija();

  sigset( SIGINT, OslobadanjeRisursa );

  int i = 0;
  for(i=0; i<2; i++ )
  {
    int id = fork();

    if( id == 0 )
    {
      FunkcijaKO( i );
      exit( 0 );
    }
  }

  while(i--) wait( NULL );

  OslobadanjeRisursa( 0 );
}

