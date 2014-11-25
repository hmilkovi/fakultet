// Hrvoje Milkovic;
// 0016096241

#include <iostream>
#include <csignal>
#include <ctime>

#define  N 8

using namespace std;

int Oznaka_cekanja [N];
int Prioritet [N];
int Tekuci_prioritet;

void obrada_prekida (int prekid)
{
	cout << "Zapocela je obrada prekida razine " << prekid << " !" << endl;

	for (int i = 1; i <= 5; i ++)
	{
		cout << " " <<  prekid <<" Obrada prekida razine " << i << " /5" << endl;
		sleep (1);
	}

	cout << " Obrada prekida razine " << prekid << " je zavrsena!" << endl;

	return;
}

void prekidna_rutina (int s)
{
	time_t time_h = time (NULL);

	cout << " Prekidna rutina pozvana u: " << ctime (&time_h);

	int i;

	do
	{
		cout << " Razina prekida: ";
		cin >> i;
	} while (i < 0 || i > N);

	Oznaka_cekanja [i] = 1;

	int prekid;

	do
	{
		prekid = 0;

		for (int j = Tekuci_prioritet + 1; j <= N; j ++)
		{
			if (Oznaka_cekanja [j] != 0) prekid = j;
		}

		if (prekid > 0)
		{
			Oznaka_cekanja [prekid] = 0;
			Prioritet [prekid] = Tekuci_prioritet;
			Tekuci_prioritet = prekid;
			sigrelse (SIGINT);
			obrada_prekida (prekid);
			sighold (SIGINT);
			Tekuci_prioritet = Prioritet [prekid];
		}

	} while (prekid > 0);

	return;
}

int main (void)
{
	sigset (SIGINT, prekidna_rutina);

	cout << " Glavni program zapoceo je s izvodjenjem!" << endl;

	for (int i = 1; i <= 30; i ++)
	{
		cout << " Izvodi se glavni program: " << i << " /30" << endl;
		sleep (1);
	}

	cout << " Glavni program je zavrsio s izvodjenjem! " << endl;

	return 0;
}
