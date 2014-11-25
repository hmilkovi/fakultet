#include <iostream>
#include <cstring>
using namespace std;

// Struktura za zaposlenika
struct zaposlenik
{
    char oib[12], prezime[30], ime[20], dat_rod[12], rad_mj[30]; // Opæi podaci
};

// Struktura za vezanu listu
struct lista
{
    zaposlenik podaci[100]; // 100 zaposlenika
    int cursor;             // kursor na element u listi
}; // struct

typedef lista tlista;
typedef int tel;

tel endL(tlista *L)
{
    return (*L).cursor;
}


tel firstL(tlista *L)
{
    return 0; // 0 je indeks prvog elementa polja
}


tel nextL(tel p, tlista *L)
{
    if(p == endL(L))
        cout << "Funkcija nije definirana." << endl;
    else
        return p+1;
}


tel previousL(tel p, tlista *L)
{
    if (p == 0)
        cout << "Funkcija je nedefinirana." << endl;
    else
        return p-1;
}


tel locateL(zaposlenik x, tlista *L)
{
    int indeks = 0;
    do
    {
        if (strcmp(x.oib,(*L).podaci[indeks].oib))
            return indeks;
            indeks++;
    } while (indeks != (*L).cursor);
}


tel insertL(zaposlenik x, tel p, tlista *L)
{
    for(int i = endL(L); i > p; i--)
        (*L).podaci[i] = (*L).podaci[i-1];
    (*L).podaci[p] = x;
    (*L).cursor = (*L).cursor+1;
}


tel deleteL(tel p, tlista *L)
{
    if((p < (*L).cursor) && (p >= 0))
    {
        for(int i = p; i < (*L).cursor; i++)
        {
            (*L).podaci[i]=(*L).podaci[i+1];
            (*L).cursor--;
        }
    }
    else
        return 0;

}


zaposlenik retrieveL(tel p,tlista *L)
{
    return (*L).podaci[p];
}


void deleteAll(tlista *L)
{
    (*L).cursor = 0;
}


tlista *initL(tlista *L)
{
    L = new tlista;
    (*L).cursor = 0;
    return L;
}
