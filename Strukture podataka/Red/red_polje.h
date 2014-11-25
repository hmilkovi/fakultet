#include <iostream>

using namespace std;

struct pacijent
{
    string ime, prezime;
    char spol;
    int dan, mjesec, godina;
    int ai, bi, ci, di, ei;
};

struct red
{
    pacijent podaci[1000];
    int celo, zacelje;
};

typedef red tred;

int AddOne(int n)
{
    return((n+1)%1000);
} // AddOne(n)

pacijent FrontQ(tred *Q)
{
    int indeks = (*Q).celo;
    return (*Q).podaci[indeks];
} // FrontQ(Q)

void EnQueueQ(pacijent x, tred *Q)
{
    (*Q).zacelje++;
    int indeks = (*Q).zacelje;
    (*Q).podaci[indeks] = x;
} // EnQueueQ((pacijent,Q)

void DeQueueQ(tred *Q)
{
    (*Q).celo++;
} // DeQueueQ(Q)

void InitQ(tred *Q)
{
    (*Q).celo = 500;
    (*Q).zacelje = 499;
} // InitQ(Q)

bool IsEmptyQ(tred *Q)
{
 if(AddOne((*Q).zacelje) == (*Q).celo)
    return true;
 else
    return false;
} // IsEmptyQ(Q)
