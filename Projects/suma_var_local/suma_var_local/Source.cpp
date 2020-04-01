#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <mutex>
#include <time.h>
/*

**puntero_matriz  ->	* puntero_fila -> [int]	[int]
						* puntero_fila -> [int]	[int]
						* puntero_fila -> [int]	[int] ...


*/
using namespace std;
vector <long > sumas_totales;
mutex io_mote;

void create(int **&matriz1,int &filas ,int &columnas) {
	//cout << "Matriz en memoria ....\n\nDimensiones de la Matriz\nFilas=";
	//cin >> filas;
	//cout << "columnas=";
	//cin >> columnas;
	matriz1 = new int*[filas];
	for (int i = 0; i<filas; i++)
	{
		matriz1[i] = new int[columnas];
	}
	for (int i = 0; i<filas; i++) {
		for (int j = 0; j<columnas; j++) {
			int tmp = 1;//rand() % 100;   // elementos aleatorios
			*(*(matriz1 + i) + j) = tmp;
			//cout << tmp<<" ";
		}
		//cout << endl;
	}
}
long sumatoria(int **matriz1, int filas, int columnas,long suma_total)
{
	//suma_total=0;
	for (int i = 0; i < columnas; i++) {
		io_mote.lock();
		suma_total += *(*(matriz1 + filas) + i);
		io_mote.unlock();
	}
	int tmp = filas;
	//cout << "Hilo" << tmp + 1 << endl;
	//cout << suma_total<<"\n";
	sumas_totales.push_back(suma_total);
	return suma_total;
}
int main()
{
	int nThreads = 1;// thread::hardware_concurrency();
	vector<thread> ths(nThreads);
	
	cout << "\t\tMatrices Dinamicas\n\nnThreads=" << nThreads << endl;
	srand(time(NULL));
	clock_t t_ini, t_fin;
	double secs;
	int **matriz, fila, columna;
	cout << "Matriz en memoria ....\n\nDimensiones de la Matriz\nFilas=";
	cin >> fila;
	cout << "columnas=";
	cin >> columna;
	create(matriz, fila, columna);
	vector <long> suma_total;
	long sumas = 0;
	int tmp_filas = 0;

	t_ini = clock();

	for (int i = 0; i < nThreads; i++) {
		if (fila != nThreads) {
			for (int j = 0; j < (fila / nThreads); j++) {
				ths[i] =  thread(sumatoria, matriz, tmp_filas++, columna ,sumas);
				//sumas += sumas;
				ths[i].join();
			}
		}
		else
		{
			ths[i] = thread(sumatoria, matriz, tmp_filas++, columna,sumas);
			//sumas += sumas;
			ths[i].join();
		}
	} 
	for (int i = 0; i < fila; i++) {
		sumas += sumas_totales[i];
	}

	t_fin = clock();

	cout << "Sumatoria de Elementos=" << sumas<< endl;
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	printf("%.16g milisegundos\n", secs * 1000.0);

	system("pause");
}