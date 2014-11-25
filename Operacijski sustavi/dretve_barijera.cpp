#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

pthread_mutex_t monitor;
pthread_cond_t red;

int N;
int brojac;

void Barijere(int i)
{
        int Brojevi;

        pthread_mutex_lock(&monitor);

        brojac++;

        if(brojac < N)
        {
                cout << "Dretva " << i ". unesite Brojevi\n";
                scanf("%d", &Brojevi);
                pthread_cond_wait(&red, &monitor);
        }
        else
        {
                cout << "Dretva " << i ". unesite Brojevi\n";
                scanf("%d", &Brojevi);
                brojac = 0;
                pthread_cond_broadcast(&red);
        }

        pthread_mutex_unlock(&monitor);


        pthread_mutex_lock(&monitor);

        brojac++;

        if(brojac < N)
        {
                cout << "Dretva " << i << ". uneseni je broj: " << Brojevi << "\n";
                pthread_cond_wait(&red, &monitor);
        }
        else
        {
                cout << "Dretva " << i << ". uneseni je broj: " << Brojevi << "\n";
                brojac = 0;
                pthread_cond_broadcast(&red);
        }

        pthread_mutex_unlock(&monitor);
}

void Ocisti(int x)
{
        pthread_mutex_destroy(&monitor);

        pthread_cond_destroy(&red);

        exit(0);
}


void* Dretva(void* i)
{
        Barijere(*(int*)i);
}



int main(int argc, char** argv)
{
        if(argc!=2)
        {
                cout << "Netocan broj argumenata! Potreba samo jedan argumenta\n";
                return 0;
        }

        N = atoi(argv[1]);
        brojac = 0;

        pthread_mutex_init(&monitor, NULL);
        pthread_cond_init(&red, NULL);


        sigset(SIGINT, Ocisti);


        pthread_t dretva_id[N];

        int argumenti_dretve[N];

        for(int i=0; i<N; i++)
                argumenti_dretve[i]=i;

        for(int i=0; i<N; i++)
                pthread_create(&dretva_id[i], NULL, Dretva, (void*)&argumenti_dretve[i]);

        for(int i=0; i<N; i++)
                pthread_join(dretva_id[i], NULL);

        pthread_mutex_destroy(&monitor);
        pthread_cond_destroy(&red);

        return 0;
}
