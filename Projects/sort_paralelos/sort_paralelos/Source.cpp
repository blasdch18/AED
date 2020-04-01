#include <iostream>
#include <vector>
#include <string.h>
#include <thread>
#include <mutex>
#include <time.h>
#include <stdlib.h>
using namespace std;
mutex io_mote;
int * vector1,*grandote, tam ,nThreads=thread::hardware_concurrency();
/*
	*vector dinamico -> int..int..int..int..int......
*/
void crear_datos(int num_datos)
{
	vector1 = new int[num_datos];
	for (int i = 0; i < num_datos; i++) {
		vector1[i] = 1 + rand() % 100;
		cout << vector1[i] << "   ";
	}
}
void imprimir(int * num,int tam)
{
	for (int i = 0; i < tam; i++) {
		cout << num[i] << "  ";
	}
}
void hilera1(int *numeros , int tam)
{
	int tmp;
	io_mote.lock();
		for (int j = 0; j < tam - 1; j++) {
			if (numeros[j + 1] < numeros[j]) {
				 tmp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = tmp;
			}
			//cout << numeros[i] << " ";
	}io_mote.unlock();
}
void bubble(int * numeros, int tam)
{
	int nThreads = thread::hardware_concurrency();
	vector <thread> t(nThreads);
	for (int i = 0; i < nThreads; i++) {
		//cout << "tam=" << tam << "  ";
		for (int j = 0; j < tam / nThreads; j++) {
			t[j] = thread(hilera1, numeros, tam);
			
			t[j].join();
		}
		//cout << numeros[i] << " ";
	}
	cout << endl;
}


int main()
{
	srand(time(0));
	int tam;
	cout << "\t\tSorts Paralelos\n\nNumero de Datos=";
	cin >> tam;
	crear_datos(tam);
	cout << endl;
	cout << "\n\t\tBubble sort\n\n";
	bubble(vector1, tam);
	imprimir(vector1, tam);
	cout << endl<<endl<<"Nuevos datos... \n";
	crear_datos(tam);
	cout << endl << endl;
	cout << "\n\t\tSelection Sort sort\n\n";
	
	system("pause");
}