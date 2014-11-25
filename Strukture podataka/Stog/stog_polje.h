using namespace std;

struct roba
{
       char sifra[12];
       float cijena;
       string vrsta, model, boja, datum;
};

class Stack
{

private:
   int MAX;
   int top;
   roba* items;

public:
       
	void InitS()
    {
		MAX = 100;
		top = -1;
		items = new roba[MAX];
	}
	
	roba TopS()
	{
         return items[top];
    }

	void PushS(roba c)
    {
		if(IsFullS())
        {
			cout << "\nVlak je pun! Zadnji artikl nije utovaren!" << endl;
			return;
		}
        items[++top] = c;
	}

	void PopS()
    {
		if(IsEmptyS())
        {
			cout << "\nVlak je prazan! Zadnji istovar neuspjesan!" << endl;
			return;
		}
        items[top--];
	}

	int IsEmptyS(){ return top == -1; }

	int IsFullS(){ return top+1 == MAX; }
};
