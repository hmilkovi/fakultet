#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sstream>
//#include "pokazivac.h"
#include "polje.h"
using namespace std;

// Indikator dali je lista sortirana
bool sort = false;


// Broj ciklusa CPU od resetiranja
int rdtsc()
{    
    __asm__ __volatile__("rdtsc");
} 

// Unos zaposlenika
int unos_zaposlenika(tlista *L)
{
    zaposlenik novi, zadnji, tekuci;

    
    // Random generiran OIB-a i unos OIB-a
    for(int i = 0; i < 11; i++)
    {
        srand(rdtsc());
        novi.oib[i] = (rand()%10+48);
    }
    novi.oib[12] = '\0';
    
    // Ispis OIB-a
    cout << "OIB: " << novi.oib << endl;
    // Unos podataka
    cout << "Ime: ";
    cin.ignore();
    cin.getline(novi.ime,20);
    cout << "Prezime: ";
    cin.getline(novi.prezime,30);
    cout << "Datum rodenja (DD.MM.GGGG.): ";
    cin.getline(novi.dat_rod,12);
    cout << "Radno mjesto: ";
    cin.getline(novi.rad_mj,30);
    cout << endl;

    bool postoji = false;
    tel mjesto = firstL(L);
    while(mjesto != endL(L))
    {
        tekuci = retrieveL(mjesto,L);
        if(strcmp(tekuci.oib,novi.oib) == 0)    // Provjera dali postoji isti OIB
        {
            postoji = true;
            break;
        }
        mjesto = nextL(mjesto,L);
    }

    if(postoji == false)
    {
        insertL(novi,endL(L),L);
        return 1;
    }
    else
        return 0;
}

tel pozicija(int indeks, tlista *L)
{
    tel pozicija_elementa;
    bool nadjen = false;
    int brojac = 0;
    do
    {
        tel mjesto = firstL(L);
        while(mjesto != endL(L))
        {
            if (brojac == indeks)
            {
                pozicija_elementa = mjesto;
                nadjen = true;
            }
            brojac++;
            mjesto = nextL(mjesto,L);
        }
    } while (nadjen == false);
    return pozicija_elementa;
}

// Usporedba OIB-ova
int usporedba(char oib1[], char oib2[])
{
    for (int i = 0; i < 12; i++)
    {
        if (oib1[i] > oib2[i])
            return 1;
        if (oib1[i] < oib2[i])
            return 2;
    }
}

// Sortiranje liste
void QuickSort(tlista *L, int pocetak, int kraj)
{
    if(pocetak < kraj)
    {
        int p = pocetak;
        tel pivot = pozicija(p,L), lokacija;

        for(lokacija = pivot; lokacija != endL(L); lokacija = nextL(lokacija,L))
        {
            if(usporedba(retrieveL(pivot,L).oib,retrieveL(lokacija,L).oib) == 2)
            {
                insertL(retrieveL(lokacija,L),pivot,L);
                deleteL(nextL(lokacija,L),L);

                p++;
                pivot = pozicija(p,L);
            }
        }

        QuickSort(L, pocetak, p-1);
        QuickSort(L, p+1, kraj);
    }
}


// Poziv funkcije QuickSort i ispis liste
void sortiranje_ispis(tlista *L)
{
    tel mjesto = firstL(L);
    int duljina = 0;

    while(mjesto != endL(L))
    {
        duljina++;
        mjesto = nextL(mjesto, L);
    }

    QuickSort(L, 0, duljina);
    
    // Ispis zaposlenika
    cout << "    OIB    \t" << "   Ime    \t" << "  Prezime  \t" << " Dat. rod. \t" << "Radno mjesto" << endl;
    
    // Prolazak kroz listu
    mjesto = firstL(L);
    zaposlenik osoba;
    while (mjesto != endL(L))
    {
         zaposlenik osoba = retrieveL(mjesto,L);
         cout << osoba.oib << "\t" << osoba.ime << "\t\t" << osoba.prezime << "\t" << osoba.dat_rod << "\t" << osoba.rad_mj << endl;
         mjesto = nextL(mjesto,L);
    }
    cout << endl;
} 

// Zaposlenici horoskopskog znaka rak
void horoskop(tlista *L)
{
    int broj_zaposlenika = 0;
    cout << "Zaposlenici (Raka)" << endl;
    cout << "__________________" << endl;
    
    // Prolazak cijele liste
    tel mjesto = firstL(L);
    while(mjesto != endL(L))
    {

        zaposlenik osoba = retrieveL(mjesto,L);
        char buffer[3];
        
        buffer[0] = osoba.dat_rod[0];
        buffer[1] = osoba.dat_rod[1];
        
        stringstream string1;
        string1 << buffer;
        int dan;
        string1 >> dan;
        
        buffer[0] = osoba.dat_rod[3];
        buffer[1] = osoba.dat_rod[4];
        
        stringstream string2;
        string2 << buffer;
        int mjesec;
        string2 >> mjesec;

        if (mjesec==6 && dan >= 22)
        {
           cout << osoba.ime << " " << osoba.prezime << "\t" << osoba.dat_rod << endl;
           broj_zaposlenika++;
        }
        
        if(mjesec==7 && dan <= 23)
        {
           cout << osoba.ime << " " << osoba.prezime << "\t" << osoba.dat_rod << endl;
           broj_zaposlenika++;
        }
        
        mjesto = nextL(mjesto,L);
    }
    cout << "\nBroj zaposlenika: " << broj_zaposlenika << endl << endl;;
}

// Brisanje zaposlenika s unesenim OIB-om
int brisanje_oib(tlista *L)
{
    char oib[12];
    zaposlenik osoba;
    tel brojac = 0, mjesto;
    bool pronadjen = false;

    cout << "Unesite OIB: ";
    cin >> oib;

    mjesto = firstL(L);
    while (mjesto != endL(L))
    {
        zaposlenik osoba = retrieveL(mjesto,L);

        if (strcmp(osoba.oib, oib) == 0)
        {
            brojac++;
            cout << "\nOsoba s unesenim OIB-om je pronadjena i obrisana.\n";
            pronadjen = true;
            deleteL(mjesto, L);
            break;
        }
        mjesto = nextL(mjesto,L);
    }

    if(pronadjen == false)
    {
        cout << "\nOsoba s "<<oib<<" OIB-om nije pronadjena." << endl;
        return 0;
    }
    else
    {
        cout << "\nUkupno obrisanih zaposlenika: " << brojac << "." << endl;
        return 1;
    }
}


int brisanje_radmjest(tlista *L)
{
    char radno_mjesto[30];
    zaposlenik osoba;
    tel brojac = 0, pozicija;
    bool pronadjen = false;

    cout << "Unesite naziv radnog mjesta: ";
    cin >> radno_mjesto;

    pozicija = firstL(L);
    while (pozicija != endL(L))
    {
        zaposlenik osoba = retrieveL(pozicija,L);

        if (strcmp(osoba.rad_mj, radno_mjesto) == 0)
        {
            brojac++;
            cout << "\nOsoba s unesenim radnim mjestom je pronadjena i obrisana." << endl;
            pronadjen = true;
            deleteL(pozicija, L);
        }
        pozicija = nextL(pozicija,L);
    }

    if(pronadjen == false)
    {
        cout << "\nOsoba s radnim mjestom "<<radno_mjesto<<" nije pronadjena." << endl;
        return 0;
    }
    else
    {
        cout << "\nBroj obrisanih zaposlenika: " << brojac << "." << endl;
        return 1;
    }
}


int velicina_liste(tlista *L)
{
    tel mjesto = firstL(L);
    int broj = 0;
    while (mjesto != endL(L))
    {
        broj++;
        mjesto = nextL(mjesto,L);
    }
    if(broj == 0)
        cout << "Lista je prazna." << endl << endl;
    return broj;
}

int main()
{
    tlista *L = initL(L);
    int izbor, stat;

    do
    {
        cout << "Izbornik" << endl;
        cout << "________________________________________________" << endl;
        cout << "| 1. Unos podataka o zaposleniku               |" << endl;
        cout << "| 2. Sortiranje i ispis zaposlenika            |" << endl;
        cout << "| 3. Ispis zaposlenika istog horoskopskog znaka|" << endl;
        cout << "| 4. Brisanje zaposlenika                      |" << endl;
        cout << "| 9. Izlaz iz programa                         |" << endl;
        cout << "|______________________________________________|\n" << endl;

        cout << "Izbor: ";
        cin >> izbor;
        cout << endl;

        switch(izbor)
        {
            case 1:
                stat = unos_zaposlenika(L);
                if (stat == 1)
                    cout << "Uspjesan unos.\n" << endl;
                else
                    cout << "Neuspjesan unos, OIB vec postoji.\n" << endl;
                break;

            case 2:
                if(velicina_liste(L) == 0)
                    break;
                sortiranje_ispis(L);
                break;

            case 3:
                if(velicina_liste(L) == 0)
                    break;
                horoskop(L);
                break;

            case 4:
                if(velicina_liste(L) == 0)
                    break;
                char odabir;
                cout << "A. Brisanje prema OIB-u. \nB. Brisanjeprema radnom mjestu.\n"<<"Odabir: ";
                cin >> odabir;
                cout << endl;
                switch(odabir)
                  case 'A':
                    stat = brisanje_oib(L);
                  case 'B':
                    stat = brisanje_radmjest(L);
                  default:
                    cout << "Krivi unos." << endl << endl;
                    break;
                    
                if (stat == 1)
                    cout << "\nUspjesno brisanje." << endl;
                else
                    cout << "\nNeuspjesno brisanje.\n" << endl;
                break;

            case 9:
                cout << "Kraj programa." << "\nIzradio: Hrvoje Milkovic"<<endl;

        }
    } while(izbor != 9);
    return 0;
}
