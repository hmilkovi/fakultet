#include <iostream>
#include <cstring>

using namespace std;

// Struktura zaposlenika
struct zaposlenik
{
    char oib[12], prezime[30], ime[20], dat_rod[12], rad_mj[30]; // Opæi podaci
};

// Struktura vezane liste
struct lista
{
    zaposlenik podaci;
    lista *sljedeci;
};

typedef lista *tel;
typedef lista tlista;

tlista *initL (lista *L)
{
    L = new tlista;
    tlista *novi = new tlista;
    L->sljedeci = NULL;
    novi->sljedeci = NULL;
    return L;
}

tel endL(tlista *L)
{
    tel zadnji = L;
    while(zadnji->sljedeci != NULL)
        zadnji = zadnji->sljedeci;
    return zadnji;
 }


tel firstL(tlista *L)
{
    if ((*L).sljedeci == NULL)
        return endL(L);
    else
        return L;
}


tel nextL(tel x, tlista *L)
{
    if (x->sljedeci == NULL)
        endL(L);
    else
        return x->sljedeci;
}


tel previousL(tel x, tlista *L)
{
    tel tekuci = L->sljedeci;
    while(x != tekuci->sljedeci && tekuci->sljedeci != 0)
        tekuci = tekuci->sljedeci;
    return tekuci;
}

int insertL(zaposlenik x, tlista *p, tlista *L)
{
    tlista *tekuci = p;
    tlista *novi = new tlista;

    if(p == endL(L))
    {
        novi->sljedeci = NULL;
        tekuci->sljedeci = novi;
        tekuci->podaci = x;
    }
    else
    {
        tlista *prethodni = previousL(p,L);
        novi->sljedeci = tekuci;
        prethodni->sljedeci = novi;
        novi->podaci = x;
    }

    return 1;
}

tel locateL(zaposlenik x, tlista *L)
{
    tel el = L;
    for(el = firstL(L); el != endL(L); el = el->sljedeci ) {
		if(strcmp(x.oib,el->podaci.oib) == 0)
			return el;
	}
}

zaposlenik retrieveL(tel x, tlista *L)
{
    return x->podaci;
}

int deleteL ( tlista *x, lista *L)
{
    tlista *prethodni, *tekuci;
    tekuci = x;
    if (x == firstL(L))
    {
        L->sljedeci = tekuci->sljedeci;
        delete tekuci;
        return 1;
    }
    else
    {
        prethodni = previousL(tekuci,L);
        prethodni->sljedeci = tekuci->sljedeci;
        delete tekuci;
        return 1;
    }
}

void deleteallL(lista *L)
{
    tlista *element_brisanje = L->sljedeci;
    if(element_brisanje == NULL)
        return;
    tlista *element = element_brisanje->sljedeci;
    while(element)
    {
        delete element_brisanje;
        element_brisanje = element;
        element = element_brisanje->sljedeci;
    }
    delete element_brisanje;
}
