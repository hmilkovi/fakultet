#include <iostream>
#include "Windows.h"
using namespace std;
char oznaka[50];

bool alocirano=false;
struct el
{
    char naziv[50];
    bool koristeno;
};

struct sp
{
    el elementi[1000];
};

bool parent(int n,sp*stablo)
{
    if(n==1)
    {
        cout<<"NULL cvor\n";
        return 0;
    }
    strcpy(oznaka,stablo->elementi[n/2].naziv);
    return 1;
}
bool createleft(char naziv[50],int n,sp*stablo)
{
    if(stablo->elementi[n].koristeno=0)
    {
        cout<<"Ne postojeci cvor!\n";
        return 0;
    }
    if(stablo->elementi[n*2].koristeno==1)
    {
        cout<<"Error\n";
        return 0;
    }
    stablo->elementi[n*2].koristeno=1;
    strcpy(stablo->elementi[n*2].naziv,naziv);
    return 1;
}
bool createright(char naziv[50],int n,sp*stablo)
{
    if(stablo->elementi[n].koristeno=0)
    {
        cout<<"Ne postojeci cvor!\n";
        return 0;
    }
    if(stablo->elementi[n*2+1].koristeno==1)
    {
        cout<<"Error\n";
        return 0;
    }
    stablo->elementi[n*2+1].koristeno=1;
    strcpy(stablo->elementi[n*2+1].naziv,naziv);
    return 1;
}
bool deleteT(int n,sp*stablo)
{
    stablo->elementi[n].koristeno=0;
    stablo->elementi[n].naziv[0]='\0';
    int j=n*2,k=n*2+1;
    if(j<1000)
        deleteT(j,stablo);

    if(k<1000)
        deleteT(k,stablo);

    return 0;
}
void labelT(int n,sp*stablo)
{
    strcpy(oznaka,stablo->elementi[n].naziv);
}
void ChangeLabelT(char naziv[50],int n,sp*stablo)
{
    strcpy(stablo->elementi[n].naziv,naziv);
}
bool RootT(sp*stablo)
{
    if(!alocirano)
    {
        cout<<"Stablo je prazno\n";
        return 0;
    }
    strcpy(oznaka,stablo->elementi[1].naziv);
    return 1;
}
bool rightchild(int n,sp*stablo)
{
    if(stablo->elementi[n*2+1].koristeno==0)
    {
        cout<<"Nema desnog djeteta!\n";
        return 0;
    }
    strcpy(oznaka,stablo->elementi[n*2+1].naziv);
    return 0;
}
bool leftchild(int n,sp*stablo)
{
    if(stablo->elementi[n*2].koristeno==0)
    {
        cout<<"Nema lijevog djeteta!\n";
        return 0;
    }
    strcpy(oznaka,stablo->elementi[n*2].naziv);
    return 1;
}

void InitT(char naziv[50],sp*stablo)
{
    for(int i=0; i<999; i++)stablo->elementi[i].koristeno=0;
    stablo->elementi[1].koristeno=1;
    strcpy(stablo->elementi[1].naziv,naziv);
    alocirano=true;
}
