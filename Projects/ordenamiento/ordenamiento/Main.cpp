#include "quick.h"
//#include "heap.h"
#include "merge.h"
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <ctime>

using namespace std;

vector<int> grande;
vector<int> seleccionados;
int numero_nucleos;


int tam = 100000;
int arreglo[100000];
//para el heap
int vector_final[100000];


void burbuja(vector<int>&arreglo, int ini, int fin)
{
	for (int i = ini; i<fin; i++)
	{
		int temp = 0;
		for (int j = 0; j<fin - (i); j++)
		{
			if (arreglo[temp]<arreglo[j])
				temp = j;
		}
		swap(arreglo[temp], arreglo[fin - (i + 1)]);
	}
}

void BubbleSort(vector<int>& arreglo)
{
	burbuja(arreglo, 0, arreglo.size());
}

void seleccionar_elemento(int i, int j) // la metodologia es buscar un elemento lo mas grande posible
{
	int temporal = i;
	while (i<j)
	{
		if (grande[temporal]<grande[i])
			temporal = i;
		i++;
	}
	seleccionados.push_back(temporal);
}

void burbuja_paralalelo(int i)
{
	vector<thread> hebras;
	int razon = i / numero_nucleos;

	for (int p = 0; p<numero_nucleos - 1; p++)
	{
		//lo mas factible es que cada nucleo busque elementos grandes
		hebras.push_back(thread(seleccionar_elemento, p*razon, (p + 1)*razon));
	}
	hebras.push_back(thread(seleccionar_elemento, (numero_nucleos - 1)*razon, i));

	for (unsigned int p = 0; p<hebras.size(); p++)
		hebras[p].join();
}

void ordenamiento_burbuja_paralelo(vector<int>& arreglo, int cores)
{
	numero_nucleos = thread::hardware_concurrency();
	numero_nucleos = cores;
	grande = arreglo;
	for (int i = grande.size(); i>numero_nucleos; i--)
	{
		burbuja_paralalelo(i);
		int temporal = 0;

		for (int po = 0; po<numero_nucleos; po++)
		{
			// compara entre mis elementos seleccionados, temp=mayor de todos
			if (grande[seleccionados[temporal]]<grande[seleccionados[po]])
				temporal = po;
		}
		swap(grande[seleccionados[temporal]], grande[i - 1]);
		seleccionados.clear();
	}
	burbuja(grande, 0, numero_nucleos);
	arreglo = grande;
}


int main() {

	vector<int> contenedor(10000);

	srand(double(time(NULL)));
	for (int i = contenedor.size(), j = 0; i >= 1; j++, i--)
		contenedor[j] = rand() % (contenedor.size()*contenedor.size());
	//for(int i=0;i<contenedor.size();i++) cout<<contenedor[i]<<" ";
	//cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


	ordenamiento_burbuja_paralelo(contenedor, 1000);


	//quick_sort_paralelo(contenedor,10);


	//ordenamiento_monticulos(contenedor,4);




	//for(int i=0;i<contenedor.size();i++) cout<<contenedor[i]<<" ";


	//for(int i=0;i<contenedor.size();i++) cout<<contenedor[i]<<" ";
	cout << endl;



	//para el merge sort y modificar los arreglos globales
	/*
	srand(double(time(NULL)));
	for(int i =tam,j=0; i>=1;j++, i--){
	arreglo[j]=rand()%(tam*tam);
	vector_final[i]=0;
	}
	//for(int i=0;i<contenedor.size();i++) cout<<arreglo[i]<<" ";
	mergesort_paralelo(arreglo, 0, tam,4);
	//
	//for(int i=0;i<contenedor.size();i++) cout<<arreglo[i]<<" ";
	*/


	cout << endl;

	cout << "TIEMPO " << GetTime() << endl;

}

