#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include "stog_polje.h"
//#include "stog_pokazivac.h"

using namespace std;

class teretnivlak{
private:
    roba artikl;
    int kolicina;
    string stanica1, stanica2;
    time_t now, later;
    int brojac;
    
public:
    Stack stog;
    
    void sleep(int delay)
    {
         now=time(NULL);
         later=now+delay;
         while(now<=later)now=time(NULL);
    }
    
    int rdtsc()
    {    
        __asm__ __volatile__("rdtsc");
    } 
    
    bool vlak(int vlak)
    {
         
         cout << "\nStigao je vlak u stanicu za utovar " << endl;
         
         stog.InitS();  
         
         return vlak = 1;
    }
    
    void utovar()
    {
         
         cout << "\nU skladistu zastupljeni artikli " << endl;
         cout << "___________________________________" << endl;
         cout << "|Televizor LG 29'' SMART HD LN460R |" << endl;
         cout << "|Mobitel Sony Xperia E             |" << endl;
         cout << "|Tablet FORCEBOOK UltraTab 9       |" <<endl;
         cout << "|Kucno kino LG DH3120              |" << endl;
         cout << "|Laptop TOSHIBA Satellite C850D-10J|" << endl;
         cout << "|LCD TV monitor SAMSUNG            |" << endl;
         cout << "|__________________________________|" << endl;
         
    
         srand(rdtsc());
         
         cout << "\nKoliko robe zelite utovariti? ", cin >> kolicina;
         
         for(int i = 0; i < kolicina; i++)
         {
                 string boja[10] = {"Crvena", "Plava", "Zelena", "Zuta", "Ljubicasta", "Narandasta", "Ruzicasta", "Grimizna", "Bijela", "Crna"};
                 
                 cout << "\nArtikl broj " << i+1 << "." <<endl;
                 cout << "____________________________" <<endl;
                 
                 int generator = (rand()%6)+1;
                 
                 switch(generator)
                 {
                               case 1:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta: Televizor" << endl;
                                    artikl.vrsta = "Televizor";
                                    cout << "Model: LG 29'' SMART HD LN460R" << endl;
                                    artikl.model = "LG 29'' SMART HD LN460R";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               case 2:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta: Mobitel" << endl;
                                    artikl.vrsta = "Mobitel";
                                    cout << "Model: Sony Xperia E" << endl;
                                    artikl.model = "Sony Xperia E";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               case 3:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta: Tablet" << endl;
                                    artikl.vrsta = "Tablet";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Model: FORCEBOOK UltraTab 9" << endl;
                                    artikl.model = "FORCEBOOK UltraTab 9";
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               case 4:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta: Kucno kino" << endl;
                                    artikl.vrsta = "Kucno kino";
                                    cout << "Model: LG DH3120" << endl;
                                    artikl.model = "LG DH3120";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               case 5:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta robe: Laptop" <<endl;
                                    artikl.vrsta = "Laptop";
                                    cout << "Model: TOSHIBA Satellite C850D-10J" << endl;
                                    artikl.model = "TOSHIBA Satellite C850D-10J";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               case 6:
                                    cout << "Sifra (12 znakova): ";
                                    cin.ignore();
                                    cin.getline(artikl.sifra,12);
                                    cout << "Vrsta: Monitor" << endl;
                                    artikl.vrsta = "Monitor";
                                    cout << "Model: LCD TV monitor SAMSUNG" << endl;
                                    artikl.model = "LCD TV monitor SAMSUNG";
                                    artikl.boja = boja[rand()%9];
                                    cout << "Boja: "<< artikl.boja << endl;
                                    cout << "Datum proizvodnje (dd.mm.gggg.): ";
                                    cin >> artikl.datum;
                                    cout << "Cijena (kn): ";
                                    cin >> artikl.cijena;
                                    break;
                               default: 
                                        cout << "Krivo generirani broj: " << generator << endl;
                                        return;
                 }
                 stog.PushS(artikl);
         }
         cout << "\nUnesite prvu lokaciju transporta: ", cin >> stanica1;
         cout << "Unesite drugu lokaciju transporta: ", cin >> stanica2;
    }
    
    int trenutanmjesec()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return (now->tm_mon + 1);
    }
    
    int trenutnagodina()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return (now->tm_year + 1900);
    }
    
    void rekurzija(roba polje[],int n)
    {
         roba istovar;
         char boja = 'e';
         
         if(stog.IsEmptyS())
         {
          cout << "Stanje artikala unutar vagona" << endl;
          cout << "____________________________________________________" << endl;
          for(int i = n; i >= 0; i--)
          {
                  stog.PushS(polje[i]);
                  if(stog.IsEmptyS()) break;
                  cout << "Sifra: " << polje[i].sifra << endl;
                  cout << "Vrsta: " << polje[i].vrsta << endl;
                  cout << "Model: " << polje[i].model << endl;
                  cout << "Boja: " << polje[i].boja << endl;
                  cout << "Datum proizvodnje: " << polje[i].datum << endl;
                  cout << "Cijena: " << polje[i].cijena << endl<<endl;
          }
          return;
         }
         else
         {
             istovar = stog.TopS();
             int mjesec = ((istovar.datum[3]-48)*10)+(istovar.datum[4]-48);
             int godina = ((istovar.datum[7]-48)*1000) + ((istovar.datum[8]-48)*100) + ((istovar.datum[9]-48)*10) + ((istovar.datum[10]-48));
             
             if(stog.TopS().boja[1] == boja && stog.TopS().cijena > 5000 && mjesec >= (trenutanmjesec()-3) && mjesec <= trenutanmjesec() && trenutnagodina() == godina)
             {
              cout << "Sifra: " << istovar.sifra << endl;
              cout << "Vrsta: " << istovar.vrsta << endl;
              cout << "Model: " << istovar.model << endl;
              cout << "Boja: " << istovar.boja << endl;
              cout << "Datum proizvodnje: " << istovar.datum << endl;
              cout << "Cijena: " << istovar.cijena << endl<<endl;
              stog.PopS();
              n++;
             }
             else
             {
                 polje[n] = stog.TopS();
                 stog.PopS();
             }
             return rekurzija(polje,n);
         }
    }
    
    void transport(int da_ne)
    {
         if(da_ne == 1)
         {
                  if(stog.IsEmptyS())
                  {
                       cout << "\nVlak je prazan, niste utovarili robu!" << endl;
                       return;
                  }
         }
         else
         {
             cout << "\nVLak jos nije stigao u stanicu za utovar!" << endl;
             return;
         }
         
         cout << "\nVlak je krenuo prema "<< stanica1 << "u." << endl;
         sleep(1);
         cout << " -> ";
         sleep(1);
         cout << " -> ";
         sleep(1);
         cout << " -> " << endl;
         cout << "Vlak je stigao u stanicu " << stanica1 << " te zapocinje se istovar!\n" << endl; 
         
         Stack pomocniStog;
         pomocniStog.InitS();
         roba istovar, vagoni, rek[kolicina];
         
         cout << "Istovareni su artikli kojima je cijena manja ili jednaka 1000kn (Najjeftiniji)" << endl;
         cout << "___________________________________________________________________________" << endl;
         
         while(!stog.IsEmptyS())
         {
               if(stog.TopS().cijena <= 1000)
               {
                istovar = stog.TopS();
                cout << "Sifra: " << istovar.sifra << endl;
                cout << "Vrsta: " << istovar.vrsta << endl;
                cout << "Model: " << istovar.model << endl;
                cout << "Boja: " << istovar.boja << endl;
                cout << "Datum proizvodnje: " << istovar.datum << endl;
                cout << "Cijena: " << istovar.cijena << endl<<endl;
                stog.PopS();
               }
               else
               {
                   pomocniStog.PushS(stog.TopS());
                   stog.PopS();
               }
         }
         
         cout << "Stanje artikala unutar vagona" << endl;
         cout << "____________________________________________________" << endl;
         
         while(!pomocniStog.IsEmptyS())
         {
          vagoni = pomocniStog.TopS();
          cout << "Sifra: " << vagoni.sifra << endl;
          cout << "Vrsta; " << vagoni.vrsta << endl;
          cout << "Model: " << vagoni.model << endl;
          cout << "Boja: " << vagoni.boja << endl;
          cout << "Datum proizvodnje: " << vagoni.datum << endl;
          cout << "Cijena: " << vagoni.cijena << endl<<endl;
          stog.PushS(vagoni);
          pomocniStog.PopS();
         }
         
        if(stog.IsEmptyS())
        {
              cout << "\nVlak je prazan, istovarila se sva roba!" << endl;
              return;
        }
        
        cout << "\nVlak je krenuo prema "<< stanica2 << "u." << endl;
        sleep(1);
        cout << " -> ";
        sleep(1);
        cout << " -> ";
        sleep(1);
        cout << " -> " << endl;
        cout << "Vlak je stigao u stanicu " << stanica2 << " te zapocinje se istovar!\n" << endl;
        
        cout << "Istovareni artikala koji su\nzelene boje, skuplji od 5000kn i proizvedeni unutar zadnja 3 mjesec" << endl;
        cout << "___________________________________________________________________________" << endl;
        
        rekurzija(rek,0);
    }
} funkcije;

int main()
{
    teretnivlak funkcije;
    int izbor = 0;
    int v = 0;
    
    cout << "Kolegij: Strukture podataka. Zadatak 2" << endl;
    cout << "Simulacija utovara, prijevoza i istovara tehnicke robe\npomocu teretnog vlaka." << endl;
    
    do
    {
        cout << "\n       Izbornik" << endl;
        cout << "_______________________" << endl;
        cout << "| 1. Dolazak vlaka     |" << endl;
        cout << "| 2. Utovar robe       |" << endl;
        cout << "| 3. Zapocni transport |" << endl;
        cout << "| 0. Izlaz iz programa |" << endl;
        cout << "|______________________|" << endl;
        cout << "Izbor: ", cin >> izbor;
        
        switch(izbor)
        {
                     case 1: v = funkcije.vlak(0); break;
                     case 2: funkcije.utovar(); break;
                     case 3: funkcije.transport(v); break;
                     case 0: cout << "Kraj simulacije. Izradio Hrvoje Milkovic" << endl; break;
                     default: cout << "Krivi izbor" << endl;
        }
        
    }while(izbor != 0);
    
    system("PAUSE");
    return 0;
}
