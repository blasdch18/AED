#ifndef SORTS_algorithm_merge_h
#define SORTS_algorithm_merge_h

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

void Intercalar(int *A, int izq, int der, int p)
{
	int i, j, k;
	int n1 = p - izq + 1;
	int n2 = der - p;

	int L[n1], R[n2]; // creando arreglos temporales

					  //copiar datos a los arrays temporales
	for (i = 0; i < n1; i++)     L[i] = A[izq + i];
	for (j = 0; j < n2; j++)     R[j] = A[p + 1 + j];


	//mezclando los arreglos temporales de nuevo
	i = 0;  j = 0;  k = izq;
	while (i < n1 && j < n2) { // compara los elementos de un arreglo con el otro
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	//copiar los elementos restantes de L
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	//copiar los elementos restantes de R
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}


int *Mezcla(int *A, int izq, int der) {
	int p;
	if (izq < der) {
		p = (izq + der) / 2;
		Mezcla(A, izq, p);
		Mezcla(A, p + 1, der);
		Intercalar(A, izq, der, p);
	}
	return A;
}



void mergesort_paralelo(int *arreglo, int inicio, int final, int cores) {
	int numero_cores = thread::hardware_concurrency();
	numero_cores = cores;
	vector<thread> thr(numero_cores);
	//vector<int> copia(20);
	while (numero_cores) {
		int razon = final / numero_cores;
		for (int p = 0; p < numero_cores - 1; p++) {
			thr[p] = thread(Mezcla, arreglo, inicio, final);
			inicio += razon;
		}
		thr[numero_cores - 1] = thread(Mezcla, arreglo, inicio, final);

		for (int p = 0; p < numero_cores; p++)
			thr[p].join();
		numero_cores = numero_cores / 2;
	}
	Mezcla(arreglo, inicio, final);
}
#endif
