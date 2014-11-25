#include <iostream>

using namespace std;

struct pacijent
{
    string ime, prezime;
    char spol;
    int dan, mjesec, godina;
    int ai, bi, ci, di, ei;
};

struct element
{
    pacijent podaci;
    element *sljedeci;
};

struct red
{
    element *celo, *zacelje;
};

typedef red tred;
typedef element *telement;


pacijent FrontQ(tred *Q)
{
    return Q->celo->sljedeci->podaci;
} // FrontQ(Q)

void EnQueueQ(pacijent x, tred *Q)
{
    element *novi = new element;
    telement posljednji;
    novi->podaci = x;
    novi->sljedeci = NULL;
    posljednji = Q->zacelje;
    posljednji->sljedeci = novi;
    Q->zacelje = novi;
} // EnQueueQ((pacijent,Q)

void DeQueueQ(tred *Q)
{
    telement prvi;
    prvi = Q->celo;
    Q->celo = prvi->sljedeci;
    delete prvi;
} // DeQueueQ(Q)

void InitQ(tred *Q)
{
    telement glava = new element;
    glava->sljedeci = NULL;
    Q->celo = glava;
    Q->zacelje = glava;
} // InitQ(Q)

bool IsEmptyQ(tred *Q)
{
    if(Q->celo == Q->zacelje)
        return true;
    else
        return false;
} // IsEmptyQ(Q)
