/* Operacijski sustavi 1
 * Autor: Hrvoje Milković
 * Broj indeksa: 41182/12R
 */
using System;
using System.Threading;

namespace OS2
{
    class Program
    {
        static private int[] polje = new int[10000];
        static int i = 0, j = 0;

        public static void Suma(int koeficijent)
        {
            int suma = 0;

            int granica = j * koeficijent + j;

            if (granica > i) granica = i;

            for (int z = j * koeficijent; z < granica; z++)
            {
                suma += polje[z];
            }

            Console.WriteLine("Suma({0} - {1}) = {2}", j * koeficijent, granica, suma);
        }


        static void Main(string[] args)
        {
            do
            {
                Console.WriteLine("Unesite broj elemenata polja: ");
                string ulaz1 = Console.ReadLine();
                i = Convert.ToInt16(ulaz1);

            }while(i > 10000 || i <= 0);

            do
            {
                Console.WriteLine("Unesite velicinu dijela polja: ");
                string ulaz2 = Console.ReadLine();
                j = Convert.ToInt16(ulaz2);

            } while (j > i || j <= 0);

            var br_dijelova = (int)(i/j);

            if(i - (j*br_dijelova) != 0)
            {
                br_dijelova += 1;
            }

            Random random = new Random();

            Console.WriteLine();

            Console.WriteLine("Generirano je {0} slucajnih brojeva:",i);

            for (int h = 0; h < i; h++)
            {
                polje[h] = random.Next(0,100);
                Console.WriteLine("{0}. {1}", h, polje[h]);
            }

            Console.WriteLine();
            Console.WriteLine("Broj potrebnih dretva: {0}",br_dijelova);



            Thread[] dretve = new Thread[br_dijelova];
            for (int k = 0; k < br_dijelova; k++)
            {
                int indeks = k;
                dretve[k] = new Thread(() => Suma(indeks));
                dretve[k].Start();
                dretve[k].Join();
            }

            Console.WriteLine();
            Console.WriteLine("Stisnite Enter za izlaz...");
            Console.ReadLine();
        }
    }
}
