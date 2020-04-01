#include <iostream>
#include <vector>
#include <thread>
#include <stdlib.h>
using namespace std;

int Partition(int *num, int izq, int der)
{
	int p = izq;
	for (int i = p + 1; i <= der; ++i)
	{
		if (num[i] < num[p])
		{
			swap(num[i], num[p]);
			if (i != p + 1)
			{
				swap(num[i], num[p + 1]);
			}
			p = p + 1;
		}
	}

	return p;
}
void QuickSort(int *num, int izq, int der)
{
	if (izq >= der) return;
	thread th1;
	thread th2;
	int p = Partition(num, izq, der);
	th1 = thread(QuickSort, num, izq, p - 1);
	th2 = thread(QuickSort, num, p + 1, der);
	th1.join();
	th2.join();
}

int main()
{
    int tam_vector;
    cout << "ALGORITMOS DE ORDENACION" << endl;
	cout << "Ingresar cantidad de datos:";
	cin >> tam_vector;
	int *a=new int[tam_vector];
	for (int j = 0; j<tam_vector; j++){
		a[j] = rand() % 1000;
		cout << a[j] << " ";
	}
	thread th;
	th = thread(QuickSort, a, 0, tam_vector);
	th.join();
	cout << endl << endl;
	for (int i = 0; i < tam_vector; i++){
		cout << a[i] << " ";
	}
	return 0;

}
