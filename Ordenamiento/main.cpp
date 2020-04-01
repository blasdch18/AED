#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

void imprimirArreglo(const int *m, const int t)
{
    for(int i=0;i<t;i++)
    cout << *(m+i) << " ";
    cout << endl << endl;
}
int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
        imprimirArreglo(a,n);
    }
}
void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}

void generate_random_array(int * &p,int t,int value)
{
    srand(time(0));
    p=new int[t];
    for(int i=0;i<t;i++)
    {
        p[i] = rand() % value;
    }
}
int main()
{
    int *p;
    int t=5;
    generate_random_array(p,t,100);
    heapsort(p,t);
    imprimirArreglo(p,t);

    return 0;
}
