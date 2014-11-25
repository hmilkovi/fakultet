#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "red_polje.h"

using namespace std;

struct petorka
{
    int ai, bi, ci, di, ei;
};

int broj_pacijenata;

int nasumicni_broj(int poc, int kraj)
{
    kraj = kraj + 1;
    rand();
    int broj = (rand()%(kraj-poc))+poc;
    return broj;
}

void generiranje_pacijenata(int n, petorka polje[], tred *Q)
{
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        rand();
        polje[i].ai = nasumicni_broj(50, 300);
        rand();
        polje[i].bi = nasumicni_broj(50, 300);
        rand();
        polje[i].ci = nasumicni_broj(1, 5);
        if (polje[i].ci == 1)
        {
            rand();
            polje[i].di = nasumicni_broj(1, 2);
            polje[i].ei = nasumicni_broj(2, 5);
        }
        else if (polje[i].ci == 2)
        {
            rand();
            polje[i].di = nasumicni_broj(1, 4);
            polje[i].ei = nasumicni_broj(1, 5);
        }
        else if (polje[i].ci == 3)
        {
            rand();
            polje[i].di = nasumicni_broj(1, 4);
            do
            {
                polje[i].ei = nasumicni_broj(1, 5);
            } while (polje[i].ei == 4);
        }
        else if (polje[i].ci == 4)
        {
            rand();
            polje[i].di = nasumicni_broj(1, 4);
            do
            {
                polje[i].ei = nasumicni_broj(1, 5);
            } while (polje[i].ei == 4);
        }
        else
        {
            rand();
            polje[i].di = nasumicni_broj(1, 4);
            polje[i].ei = nasumicni_broj(1, 5);
        }
        rand();
    }
    cout << "Generirano je " << n << " petorki." << endl << endl;
}

void ispis_kategorija(petorka polje)
{
    switch(polje.ci){
        case 1: cout << "Prioritet pacijenta: Hitni slucaj" << endl; break;
        case 2: cout << "Prioritet pacijenta: Invalidi" << endl; break;
        case 3: cout << "Prioritet pacijenta: Trudnice" << endl; break;
        case 4: cout << "Prioritet pacijenta: Djeca mlada od 6 godina" << endl; break;
        case 5: cout << "Prioritet pacijenta: Ostali pacijenti" << endl; break;
        default: cout << "Pogreska." << endl;
    }

    switch(polje.di){
        case 1: cout << "Vrsta usluge: Pregled" << endl; break;
        case 2: cout << "Vrsta usluge: Previjanje" << endl; break;
        case 3: cout << "Vrsta usluge: Recept" << endl; break;
        case 4: cout << "Vrsta usluge: Uputnica" << endl; break;
        default: cout << "Pogreska." << endl;
    }

    switch(polje.ei){
        case 1: cout << "Vrsta ordinacije: Obiteljska medicina" << endl; break;
        case 2: cout << "Vrsta ordinacije: Oftalmologija" << endl; break;
        case 3: cout << "Vrsta ordinacije: Dermatovenerologija" << endl; break;
        case 4: cout << "Vrsta ordinacije: Ginekologija" << endl; break;
        case 5: cout << "Vrsta ordinacije: Urologija" << endl; break;
        default: cout << "Pogreska." << endl;
    }
}


void ispis_reda(int uneseno_pacijenata, tred *Q)
{
    tred *pomocni_red = new tred;
    pacijent pomocna_osoba;
    cout << "Svi pacijenti u redu" << endl;
    cout << "--------------------" << endl;
    cout << "Ime\t\tPrezime\tSpol\tPrioritet" << endl;
    cout << "---\t\t-------\t----\t---------" << endl;
    for(int i = 0; i < uneseno_pacijenata; i++)
    {
        pomocna_osoba = FrontQ(Q);
        DeQueueQ(Q);
        EnQueueQ(pomocna_osoba,pomocni_red);
        cout << pomocna_osoba.ime << "\t";
        cout << pomocna_osoba.prezime << "\t";
        cout << pomocna_osoba.spol << "\t";
        cout << pomocna_osoba.ci << "\t";
    }

    do
    {
        pomocna_osoba = FrontQ(pomocni_red);
        DeQueueQ(pomocni_red);
        EnQueueQ(pomocna_osoba,Q);
    } while (IsEmptyQ(pomocni_red) == true);

    cout << endl;
    delete pomocni_red;
}


void unos_u_glavni_red(int uneseno_pacijenata, int danas_god, pacijent osoba, tred *Q)
{
    tred *pomocni_red = new tred;
    pacijent pomocna_osoba;

    if(IsEmptyQ(Q) ==  true)
    {
        EnQueueQ(osoba, Q);
        return;
    }

    bool prvi_prolaz = true;
    bool unesen_pacijent = false;
    do
    {
        pomocna_osoba = FrontQ(Q);
        DeQueueQ(Q);
        if(prvi_prolaz = true)
        {
            EnQueueQ(pomocna_osoba, pomocni_red);
            prvi_prolaz = false;
        }
        else if(osoba.ci < pomocna_osoba.ci && unesen_pacijent == false)
        {
            EnQueueQ(osoba, pomocni_red);
            unesen_pacijent = true;
            EnQueueQ(pomocna_osoba, pomocni_red);
        }
        else
            EnQueueQ(pomocna_osoba, pomocni_red);
    } while(IsEmptyQ(Q) == true);

    bool prvi_ispis_oftalmolog = true;
    do
    {
        pomocna_osoba = FrontQ(pomocni_red);
        DeQueueQ(pomocni_red);
        EnQueueQ(pomocna_osoba,Q);
        if(pomocna_osoba.ei == 2 && (danas_god - pomocna_osoba.godina > 25))
        {
            if(prvi_ispis_oftalmolog == true)
            {
                cout << "Pregled kod oftalmologa (Z 25+)" << endl;
                cout << "-------------------------------" << endl;
                cout << "Ime\tPrezime\tGodine" << endl;
                prvi_ispis_oftalmolog = false;
            } // if
            cout << pomocna_osoba.ime << "\t";
            cout << pomocna_osoba.prezime << "\t";
            cout << 2013 - pomocna_osoba.godina << endl;
        }
    }   while(IsEmptyQ(pomocni_red) == true);
    cout << endl;
    delete pomocni_red;
}

void unos_pacijenata(petorka polje[], tred *Q)
{
    if(broj_pacijenata < 1)
    {
        cout << "Svi pacijenti su vec uneseni." << endl << endl;
        return;
    }

    int danas_dan, danas_mj, danas_god;
    int uneseno_pacijenata = 0;
    cout << "Unesite datum unosa (DD MM GGGG): ";
    cin >> danas_dan >> danas_mj >> danas_god;
    cout << endl;

    int n = broj_pacijenata;
    for(int i = 0; i < n; i++)
    {
        if(polje[i].ci > 5 || polje[i].di > 4 || polje[i].ei > 5)
        {
            cout << "Niste generirali petorke (preskocili ste opciju 1!)" << endl << endl;
            break;
        }

        cout << "Unos pacijenta" << endl;
        cout << "--------------" << endl;
        ispis_kategorija(polje[i]);

        pacijent osoba;
        osoba.ai = polje[i].ai;
        osoba.bi = polje[i].bi;
        osoba.ci = polje[i].ci;
        osoba.di = polje[i].di;
        osoba.ei = polje[i].ei;
        if (polje[i].ci == 3 || polje[i].ei == 4)
        {
            osoba.spol = 'Z';
            cout << "Spol: " << osoba.spol << endl;
        }
        else if (polje[i].ei == 5)
        {
            osoba.spol = 'M';
            cout << "Spol: " << osoba.spol << endl;
        }
        else
        {
            cout << "Spol (M/Z): ";
            cin >> osoba.spol;
        }
        cout << "Ime: ";
        cin >> osoba.ime;
        cout << "Prezime: ";
        cin >> osoba.prezime;
        bool upis_datuma = false;
        do
        {
            if (upis_datuma == true)
                cout << "Krivi unos datuma. Ponovite unos." << endl;
            cout << "Datum rodenja (DD MM GGGG): ";
            upis_datuma = true;
            cin >> osoba.dan >> osoba.mjesec >> osoba.godina;
        } while ((danas_god-osoba.godina >= 6 && osoba.ci == 4) || osoba.dan > 31 || osoba.mjesec > 12 || osoba.godina > danas_god);
        cout << endl;
    uneseno_pacijenata++;
    unos_u_glavni_red(uneseno_pacijenata,danas_god,osoba,Q);
    broj_pacijenata--;
    }
    cout << endl;
    ispis_reda(uneseno_pacijenata,Q);
    cout << endl;
}

void vrijeme123()
{
    int polje[]={1,2,3,0,2,1,2,3,3,1,1,2,3,0,1,1,0,3,2,1};
    int trenutno = polje[0],i = 0;
    do{
            if(trenutno == clock()/1000){
                trenutno = trenutno + polje[i];
                cout << "vrijednost: " << polje[i] << endl;
                i++;
            }

    }while (i < 20);
}

int main()
{
    tred *Q = new tred;
    InitQ(Q);

    cout << "Unesite broj N za generiranje pacijenata: ";
    cin >> broj_pacijenata;
    petorka polje[broj_pacijenata];
    cout << endl;
    rand();
    int izbor;
    do
    {
        cout << "Izbornik" << endl;
        cout << "_____________________________________________________" << endl;
        cout << "1. Generiranje pacijenata" << endl;
        cout << "2. Unos podataka o pacijentima, dolazak u red i ispis" << endl;
        cout << "5. Testiranje vremena" << endl << endl;
        cout << "_____________________________________________________" << endl;
        cout << "Izbor opcije: ";
        cin >> izbor;
        cout << endl;

        switch(izbor)
        {
            case 1:
                cout << IsEmptyQ(Q) << endl;
                generiranje_pacijenata(broj_pacijenata, polje, Q);
                break;

            case 2:
                unos_pacijenata(polje, Q);
                break;

            case 5:
                vrijeme123();
                break;

            default:
                break;
        }
    } while (izbor != 9);
    cout << "Kraj programa." << endl;
    return 0;
}
