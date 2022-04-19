#include <iostream>
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int tab[], int p, int k)
{
    int x = tab[p];
    int i = p, j = k, w; 
    while (true)
    {
        while (tab[j] > x) 
            j--;
        while (tab[i] < x) 
            i++;
        if (i < j) 
        {
            w = tab[i];
            tab[i] = tab[j];
            tab[j] = w;
            i++;
            j--;
        }
        else 
            return j;
    }
}
void quicksort(int tab[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(tab, p, r); 
        quicksort(tab, p, q); 
        quicksort(tab, q + 1, r); 
    }
}
void babyl(int tab[], int p,int k)
{
    int i, j;
    for (i = p; i < k - 1; i++)
    {
        for (j = p; j < k - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                swap(&tab[j], &tab[j + 1]);
            }
        }  
    }    
}
/*
void wypisz(int tab[], int rozmiar)
{
    int i;
    for (i = 0; i < rozmiar; i++)
        cout << tab[i] << " ";
    cout << endl;
}
*/

void hybrydka(int tab[], int p,int k)//bubble i quick
{
    if (p - k <= 10)
    {
        babyl(tab, p, k);
    }
    else
    {
        quicksort(tab, p, k);
    }

}


int main()
{
    srand(time(NULL));

    const int ile=10;
    int* tab = new int [ile];
    for (int i = 0; i < ile; i++)
    {
        tab[i] = rand() % 50;
        cout << tab[i] << endl;
    }
    babyl(tab[], p, k);
}




