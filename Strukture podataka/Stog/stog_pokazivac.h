using namespace std;

struct roba{
    char sifra[12];
    float cijena;
    string vrsta, model, boja, datum;
};

class Stack
{
   roba items;
   Stack *vrh;
   Stack *sljedeci;

public:

   void InitS()
   {
     vrh = NULL;
     sljedeci = NULL;
   }
   
   void PushS(const roba& x)
   {
       Stack *novi;
       novi = new Stack;
       novi->sljedeci = vrh;
       novi->items = x;
       vrh=novi;
   }
   
   void PopS()
   {
      if(IsEmptyS())
      {
          cout << "\nVlak je prazan! Zadnji istovar neuspjesan!" << endl;
          return;
      }
      Stack *sljedeci = vrh->sljedeci;
      delete vrh;
      vrh=sljedeci;
   }
   
   roba TopS()
   {
        return vrh->items;
   }
   
   int IsEmptyS(){ if(vrh == NULL) return true; else return false; }
};
