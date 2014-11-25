#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>
#include <signal.h>

using namespace std;

int N;
int M;

pthread_mutex_t monitor;

pthread_cond_t red_programeri[2];


int br_mjesta_restoran;
int br_sitih;

int br_programeri[2];
int vrsta_u_restoranu = -1;


void ispis(int ni, string st)
{

        cout << "Red Linux:";

        for(int i=0; i<M; i++)
                if(i<br_programeri[0]) cout << "L";
                else cout << "-";


        cout << " Red Microsoft:";

        for(int i=0; i<M; i++)
                if(i<br_programeri[1]) cout << "M";
                else cout << "-";


        cout << " Restoran:";

        if(vrsta_u_restoranu==0) for(int i=0; i<br_mjesta_restoran; i++) cout << "L";
        else for(int i=0; i<br_mjesta_restoran; i++) cout << "M";


        cout << " ---> ";

        if(ni==0) cout << "L " << st;
        else cout << "M " << st;

        cout << endl;
}


void udji(int vrsta)
{
        pthread_mutex_lock(&monitor);

        br_programeri[vrsta]++;

        while(vrsta_u_restoranu == 1-vrsta || br_sitih >= N)
        {
                ispis(vrsta, "u red cekanja");
                pthread_cond_wait(&red_programeri[vrsta], &monitor);
        }


        br_programeri[vrsta]--;

        vrsta_u_restoranu = vrsta;
        br_mjesta_restoran++;


        if(br_programeri[1-vrsta] > 0)
                br_sitih++;


        ispis(vrsta, "u restoran");

        pthread_mutex_unlock(&monitor);
}

void izadji(int vrsta)
{
        pthread_mutex_lock(&monitor);


        br_mjesta_restoran--;

        if(br_mjesta_restoran==0)
        {
                if(br_programeri[1-vrsta] > 0)
                {

                        vrsta_u_restoranu = 1-vrsta;

                        pthread_cond_broadcast(&red_programeri[1-vrsta]);
                }
                else
                {

                        vrsta_u_restoranu = -1;
                }

                br_sitih = 0;
        }

        ispis(vrsta, "iz restorana");
        pthread_mutex_unlock(&monitor);
}

void* Programer(void* vrsta)
{
        usleep(rand()%100000);

        udji(*((int*)vrsta) );
        usleep(rand()%100000);

        izadji(*((int*)vrsta) );
}

void Ocisti(int x)
{
        pthread_mutex_destroy(&monitor);


        for(int i=0; i<2; i++)
                pthread_cond_destroy(&red_programeri[i]);

        exit(0);
}

int main(int argc, char** argv)
{

        if(argc!=3)
        {
                cout << "Netocan broj argumenata!" << endl;
                return 0;
        }


        N = atoi(argv[1]);
        M = atoi(argv[2]);

        pthread_mutex_init(&monitor, NULL);

        for(int i=0; i<2; i++)
                pthread_cond_init(&red_programeri[0], NULL);

        sigset(SIGINT, Ocisti);

        pthread_t dretva_id[M*2];
        int argument_dretve[M*2];

        for(int i=0; i<M*2; i++)
                argument_dretve[i] = i%2;

        for(int i=0; i<M*2; i++)
                pthread_create(&dretva_id[i], NULL, Programer, (void*)&argument_dretve[i]);


        for(int i=0; i<M*2; i++)
                pthread_join(dretva_id[i], NULL);

        pthread_mutex_destroy(&monitor);

        for(int i=0; i<2; i++)
                pthread_cond_destroy(&red_programeri[i]);

        return 0;
}
