#include <iostream>
#include <string>
#include "OpStablo.h"
#include "bStablo_polje.h"
#include "bStablo_pokazivac.h"

using namespace std;

spolje*stablo;
string ispis;
bool alocirano3=false,alocirano4=false;
char naziv[50],naziv4[50];
int izbor1=0,opcija=0,n;

bool funkcija1()
{
    if(!alocirano3)
    {
        stablo=new spolje;
        alocirano3=true;
        cout<<"Unesite naziv najstarijeg potomka: ";
        cin.ignore();
        cin.getline(naziv,50);
        InitT(naziv,stablo);
    }

    while(opcija!=10)
    {
        cout<<"Izbornik\n";
        cout<<"1. InitT \n";
        cout<<"2. ParentT\n";
        cout<<"3. FirstChildT\n";
        cout<<"4. NextSiblingT\n";
        cout<<"5. RootT\n";
        cout<<"6. LabelT\n";
        cout<<"7. CreateT\n";
        cout<<"8. ChangeLabelT\n";
        cout<<"9. DeleteT\n";
        cout<<"10. Izlaz\n";
        cout<<"Vas odabir =  ";
        cin>>opcija;

        switch(opcija)
        {
            case 1:
                alocirano3=true;
                cout<<"Unesite naziv najstarijeg potomka: ";
                cin.ignore();
                cin.getline(naziv,50);
                InitT(naziv,stablo);
                break;

            case 2:
                if(!alocirano3)
                {
                    cout<<"Ne postoji clan u stablu\n";
                    return 0;
                }
                cout<<"Indeks cvora kojemu zelite pronaci roditelja: ";
                cin>>n;
                n=ParentT(n,stablo);
                if(n==1000)cout<<"Ovaj cvor u stablu ne postoji\n";
                break;

            case 3:
                cout<<"Unesite indeks elementa kojemu zelite pronaci prvo lijevo dijete: ";
                cin>>n;
                n=FirstChildT(n,stablo);
                if(n==1000)cout<<"NE POSTOJI LIJEVO DIJETE ILI NE POSTOJI OVAJ CVOR\n";
                else cout<<"Lijevo dijete je: "<<stablo->dijelovi[n].label<<endl;
                break;

            case 4:
                cout<<"Unesite indeks cvora kojemu zelite pronaci sljedeceg brata: ";
                cin>>n;
                n=NextSiblingT(n,stablo);
                if(n==1000)cout<<"NE POSTOJI OVAJ CVOR U STABLU\n";
                else cout<<"Sljedeci brat ovog cvora je: "<<stablo->dijelovi[n].label<<endl;
                break;

            case 5:
                n=RootT(stablo);
                cout<<"Naziv korijena binarnog stabla je: "<<stablo->dijelovi[n].label<<endl;
                break;

            case 6:
                cout<<"Unesite indeks elementa kojeg zelite pronaci naziv: ";
                cin>>n;
                LabelT(n,stablo);
                break;

            case 7:
                cout<<"Unesite indeks elementa kojemu zelite dodati novog potomka: ";
                cin>>n;
                cout<<"Unesite indeks novog potomka: ";
                int indeks;
                cin>>indeks;
                CreateT(indeks,n,stablo);
                break;

            case 8:
                cout<<"Unesite indeks cvora kojem zelite promijeniti oznaku: ";
                cin>>n;
                promijeninaziv(n,stablo);
                break;

            case 9:
                cout<<"Unesite indeks cvora kojem zelite obrisati potomke: ";
                cin>>n;
                deleteT(n,stablo);
                if(n==999)cout<<"Stablo vise nije alocirano!\n";
                break;
        }
    }

    system("cls");
    izbor1=0;
    opcija=0;
    return 1;
}

sp*polje=new sp;

bool funkcija2()
{
    int opcija;

    if(!alocirano)
    {
        cout<<"Unesite naziv korijena binarnog stabla\n";
        cin.ignore();
        cin.getline(naziv,50);
        InitT(naziv,polje);
        alocirano=true;
    }

    while(opcija!=11)
    {
        cout<<"\nIzbornik\n";
        cout<<"1. InitT\n";
        cout<<"2. CreateLeft\n";
        cout<<"3. CreateRight\n";
        cout<<"4. ParentT\n";
        cout<<"5. LeftChildT\n";
        cout<<"6. RightChildT\n";
        cout<<"7. LabelT\n";
        cout<<"8. DeleteT\n";
        cout<<"9. RootT\n";
        cout<<"10. ChangeLabelT\n";
        cout<<"11. Izlaz\n";
        cout<<"Odaberite jednu od opcija: ";
        cout<<"Vas odabir =  ";
        cin>>opcija;

        switch(opcija)
        {
            case 1:
                cout<<"Unesite naziv korijena binarnog stabla\n";
                cin.ignore();
                cin.getline(naziv,50);
                InitT(naziv,polje);
                alocirano=true;
                break;
            case 2:
                cout<<"Na koji cvor zelite dodati lijevo dijete?\n";
                cin>>opcija;
                cout<<"Unesite naziv lijevog djeteta: ";
                cin.ignore();
                cin.getline(naziv,50);
                createleft(naziv,opcija,polje);
                break;
            case 3:
                cout<<"Na koji cvor zelite dodati desno dijete?\n";
                cin>>opcija;
                cout<<"Unesite naziv desnog djeteta: ";
                cin.ignore();
                cin.getline(naziv,50);
                createright(naziv,opcija,polje);
                break;
            case 4:
                cout<<"Kojeg cvora zelite pronaci roditelja? \n";
                cin>>opcija;
                parent(opcija,polje);
                cout<<"Roditelj cvora "<<opcija<<" je : "<<oznaka<<endl;
                break;
            case 5:
                cout<<"Unesite cvor od kojega zelite pronaci lijevo dijete: ";
                cin>>opcija;
                if(!leftchild(opcija,polje)) {}
                else
                {
                    cout<<"Lijevo dijete cvora "<<opcija<<" je : "<<oznaka<<endl;
                }
                break;
            case 6:
                cout<<"Unesite cvor od kojega zelite pronaci desno dijete: ";
                cin>>opcija;
                if(!rightchild(opcija,polje)) {}
                else
                {
                    cout<<"Desno dijete cvora "<<opcija<<" je: "<<oznaka<<endl;
                }
                break;
            case 7:
                cout<<"Unesite naziv cvora kojeg zelite da nadjete naziv: ";
                cin>>opcija;
                labelT(opcija,polje);
                cout<<"Naziv "<<opcija<<"-tog cvora je: "<<oznaka<<endl;
                break;
            case 8:
                cout<<"Unesite od kojeg cvora zelite obrisati potomke: ";
                cin>>opcija;
                deleteT(opcija,polje);
                if(opcija==1)
                {
                    alocirano=false;
                    cout<<"Unesite naziv korijena binarnog stabla\n";
                    cin.ignore();
                    cin.getline(naziv,50);
                    InitT(naziv,polje);
                    alocirano=true;
                }
                break;
            case 9:
                RootT(polje);
                cout<<"Naziv korijena binarnog stabla je: "<<oznaka<<endl;
                break;
            case 10:
                cout<<"Unesite redni broj cvora od kojeg zelite promijeniti naziv: ";
                cin>>opcija;
                cout<<"Unesite naziv kojim zelite zamijeniti postojeci: ";
                cin.ignore();
                cin.getline(naziv,50);
                ChangeLabelT(naziv,opcija,polje);
                break;
        }
    }

    system("cls");
    opcija=0,izbor1=0;
    return 1;
}

ele*polje2=new ele;

bool funkcija3(){
   ispis=("                  \nDRUGI ZADATAK\n                       \n\n");
    for(int i=0; i<110; i++) {
        cout<<ispis[i];
    }

    int izbor2;

    if(!alocirano2) {
        alocirano2=true;
        cout<<"Unesite naziv korijena stabla: ";
        cin.ignore();
        cin.getline(naziv,50);
        init(naziv,polje2);
        system("cls");
        ispis=("Uspjesno je inicijalizirano novo stablo\n");
        for(int i=0; i<40; i++) {
            cout<<ispis[i];
        }
    }

    while(izbor2!=10) {
        cout<<"\nIzbornik\n";
        cout<<"1. InitT\n";
        cout<<"2. CreateLeftT\n";
        cout<<"3. CreateRightT\n";
        cout<<"4. ParentT\n";
        cout<<"5. LeftChildT\n";
        cout<<"6. RightChild\n";
        cout<<"7. DeleteSiblingsT\n";
        cout<<"8. RootT\n";
        cout<<"9. ChangeNameT\n";
        cout<<"10. Izlaz\n";
        cout<<"Odaberite jednu od opcija: ";
        cin>>izbor2;

        system("cls");

        switch(izbor2) {
            case 1:
                alocirano2=true;
                cout<<"Unesite naziv korijena stabla: ";
                cin.ignore();
                cin.getline(naziv,50);
                init(naziv,polje2);
                system("cls");
                ispis=("Uspjesno je inicijalizirano novo stablo\n");
                for(int i=0; i<40; i++) {
                    cout<<ispis[i];
                }
                break;

            case 2:
                pronadjen=false;
                cout<<"Unesite naziv cvora kojem zelite dodati lijevo dijete: ";
                cin.ignore();
                cin.getline(naziv,50);
                cout<<"Unesite naziv novog lijevog djeteta: ";
                cin.getline(naziv4,50);
                novolijevo(naziv,naziv4,polje2);
                if(!pronadjen)cout<<"NE POSTOJI TAJ CVOR\n";
                break;

            case 3:
                pronadjen=false;
                cout<<"Unesite naziv cvora kojem zelite dodati desno dijete: ";
                cin.ignore();
                cin.getline(naziv,50);
                cout<<"Unesite naziv desnog djeteta: ";
                cin.getline(naziv4,50);
                novodesno(naziv,naziv4,polje2);
                if(!pronadjen)cout<<"NE POSTOJI TAJ CVOR\n";
                break;

            case 4:
                cout<<"Unesite naziv cvora kojem zelite pronaci roditelja: ";
                cin.ignore();
                cin.getline(naziv,50);
                pronadjen=false;
                roditelj(naziv,polje2);
                if(!pronadjen)cout<<"NE POSTOJI RODITELJ TOG CVORA!\n";
                break;

            case 5:
                cout<<"Unesite naziv cvora kojem zelite pronaci lijevo dijete: ";
                cin.ignore();
                cin.getline(naziv,50);
                lijevodijete(naziv,polje2);
                if(!pronadjen)cout<<"NIJE PRONADJEN TAJ CVOR\n";
                else cout<<"Naziv lijevog djeteta je: "<<oznaka2<<endl;
                break;

            case 6:
                cout<<"Unesite naziv cvora kojem zelite pronaci desno dijete: ";
                cin.ignore();
                cin.getline(naziv,50);
                desnodijete(naziv,polje2);
                if(!pronadjen)cout<<"NIJE PRONADJEN TAJ CVOR\n";
                else cout<<"Naziv desnog djeteta je: "<<oznaka2<<endl;
                break;

            case 7:
                cout<<"Unesite naziv cvora kojem zelite obrisati potomke: ";
                cin.ignore();
                cin.getline(naziv,50);
                pronadjen=false;
                brisanje(naziv,polje2);
                if(!pronadjen)cout<<"NIJE PRONADJEN TAJ CVOR\n";
                break;

            case 8:
                root(polje2);
                cout<<"Naziv korijena binarnog stabla je: "<<oznaka2<<endl;
                break;

            case 9:
                cout<<"Unesite naziv cvora kojem zelite promijeniti naziv: ";
                cin.ignore();
                cin.getline(naziv,50);
                pronadjen=false;
                cout<<"Unesite novi naziv tog cvora: ";
                cin.getline(naziv4,50);
                mijenjanje(naziv,naziv4,polje2);
                if(!pronadjen)cout<<"NIJE PRONADJEN TAJ CVOR\n";
                break;
        }
    }
    izbor2=0,izbor1=0;

    return 1;
}



int main()
{
    while(izbor1!=9)
    {
        cout<<"____________________IZBORNIK_____________________"<<endl;
        cout<<"1. Opcenito stablo 'prvo dijete - sljedeci brat\n";
        cout<<"2. Binarno stablo pomocu polja\n";
        cout<<"3. Binarno stablo pomocu pokazivaca\n";
        cout<<"9. Izlaz iz programa\n";
        cout<<"Vas izbor =  ";
        cin>>izbor1;

        system("cls");

        switch(izbor1)
        {
            case 1: funkcija1(); break;
            case 2: funkcija2(); break;
            case 3: funkcija3(); break;
        }
    }

    cout<<"Kraj programa\n";

    cin>>opcija;

    return 0;
}
