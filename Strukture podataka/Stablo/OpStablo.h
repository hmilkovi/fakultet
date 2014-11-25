#include <iostream>
#include "Windows.h"
using namespace std;

bool pronadj;
struct element

{
    char label[50];
    int prvodijete, sljedecibrat;
};

struct spolje
{
    struct element dijelovi[1000];
    int korijen;
};
struct spolje2
{
    struct element dijelovi[11];
    int korijen;
};

void InitT(char naziv[50], spolje*stablo)
{
    stablo->korijen=999;
    strcpy(stablo->dijelovi[999].label,naziv);
    for(int i=0; i<1000; i++)
    {
        stablo->dijelovi[i].prvodijete=-1;
        stablo->dijelovi[i].sljedecibrat=-1;
    }
}

int ParentT(int n,spolje*stablo)
{
    if(n==stablo->korijen)
    {
        cout<<"NULL cvor\n";
        pronadj=true;
        return 999;
    }
    for (int i=0; i<1000; i++)
    {
        if(stablo->dijelovi[i].prvodijete==n)
        {
            cout<<"Roditelj ovog cvora je: "<<stablo->dijelovi[i].label<<endl;
            pronadj=true;
            return i;
        }
        if(stablo->dijelovi[i].sljedecibrat==n)
        {
            cout<<"Roditelj ovog cvora je: "<<stablo->dijelovi[i].label<<endl;
            pronadj=true;
            return i;
        }
    }
    return 1000;
}

int FirstChildT(int n, spolje*stablo)
{
    if(stablo->dijelovi[n].prvodijete!=-1) return stablo->dijelovi[n].prvodijete;
    else return 1000;
}

int NextSiblingT(int n, spolje*stablo)
{
    if(stablo->dijelovi[n].sljedecibrat!=-1) return stablo->dijelovi[n].sljedecibrat;
    else return 1000;
}

void LabelT(int n, spolje*stablo)
{
    cout<<"Naziv "<<n<<"-tog cvora binarnog stabla je: "<<stablo->dijelovi[n].label<<endl;
}

int RootT(spolje*stablo)
{
    return stablo->korijen;
}

bool CreateT(int indeks,int n,spolje*stablo)
{
    if(stablo->dijelovi[n].prvodijete!=-1)
    {
        cout<<"Unesite naziv novog djeteta stabla: ";
        cin>>stablo->dijelovi[indeks].label;
        cout<<"Premjestam sadasnje prvo dijete sa indeksa : "<<stablo->dijelovi[n].prvodijete<<" na : "<<indeks<<endl;
        cout<<", a sljedecibrat novog djeteta je: "<<stablo->dijelovi[n].prvodijete<<endl;

        stablo->dijelovi[indeks].sljedecibrat=stablo->dijelovi[n].prvodijete;
        stablo->dijelovi[n].prvodijete=indeks;
        return 1;
    }
    if(stablo->dijelovi[n].prvodijete==-1)
    {
        cout<<"Unesite naziv novog djeteta stabla: ";
        cin>>stablo->dijelovi[indeks].label;
        stablo->dijelovi[n].prvodijete=indeks;
        return 1;
    }
}

void promijeninaziv(int n, spolje*stablo)
{
    cout<<"Unesite novi naziv: ";
    cin>>stablo->dijelovi[n].label;
}

bool deleteT(int n,spolje*stablo)
{
    if(n==999)return 1;
    for(int i=0; i<1000; i++)
    {
        if(stablo->dijelovi[i].sljedecibrat==n)
        {
            stablo->dijelovi[i].sljedecibrat=-1;
            cout<<"Dealociran je potomak : "<<stablo->dijelovi[n].label<<endl;
        }
        if(stablo->dijelovi[i].prvodijete==n)
        {
            stablo->dijelovi[i].prvodijete=-1;
            cout<<"Dealociran je potomak : "<<stablo->dijelovi[n].label<<endl;
        }
    }
    if(stablo->dijelovi[n].sljedecibrat!=-1)deleteT(stablo->dijelovi[n].sljedecibrat,stablo);
    if(stablo->dijelovi[n].prvodijete!=-1)deleteT(stablo->dijelovi[n].prvodijete,stablo);
    return 1;
}
