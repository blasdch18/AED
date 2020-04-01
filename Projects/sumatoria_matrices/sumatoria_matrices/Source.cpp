#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <mutex>
#include <time.h>
/*
*/

int **matriz1, filas, columnas;
long long suma_total = 0;
using namespace std;
mutex io_mote;

void create()
{
	cout << "Matriz en memoria ....\n\nDimensiones de la Matriz\nFilas=";
	cin >> filas;
	cout << "columnas=";
	cin >> columnas;
	matriz1 = new int*[filas];
	for (int i = 0; i<filas; i++)
	{
		matriz1[i] = new int[columnas];
	}
	for (int i = 0; i<filas; i++) {
		for (int j = 0; j<columnas; j++) {
			int tmp = 1;//rand() % 100;   // elementos aleatorios
			*(*(matriz1 + i) + j) = tmp;
		}
	}
}
void mostrar(int **matriz1, int filas, int columnas)
{
	for (int i = 0; i<filas; i++) {
		for (int j = 0; j<columnas; j++) {
			cout << *(*(matriz1 + i) + j) << "\t";
		}cout << "\n";
	}
}
void sumatoria(int **matriz1, int filas, int columnas)
{
		for (int j = 0; j < columnas  ; j++) {
			io_mote.lock();
			suma_total += *(*(matriz1 + filas) + j);
			//cout << filas ;
			io_mote.unlock();					
		}
		int tmp = filas;
		//cout <<"Hilo"<<filas<< endl;	
	//cout << endl << suma_total<<endl;
}
int main()
{
	int nThreads = 2;// thread::hardware_concurrency();
	vector<thread> ths(nThreads);
	cout << "\t\tMatrices Dinamicas\n\nnThreads="<<nThreads<<endl;
	srand(time(NULL));
	clock_t t_ini, t_fin;
	double secs;
	create();
	//mostrar(matriz1, filas, columnas);
	//sumatoria(matriz1, filas, columnas);
	
	int tmp_filas = 0;

	t_ini = clock();

	for (int i = 0; i < nThreads; i++) {	
		if (filas != nThreads) {
			for (int j = 0; j < (filas/nThreads); j++) {
				ths[i] = thread(sumatoria, matriz1, tmp_filas ++, columnas);
				ths[i].join();
			}
		}
		else
		{
			ths[i]= thread(sumatoria, matriz1, tmp_filas ++, columnas);
			ths[i].join();
		}
	}
	//for (int i = 0; i < nThreads; i++) {
		//ths[i].join();
	//}

	t_fin = clock();

	cout <<"Sumatoria de Elementos=" <<suma_total<<endl;
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	printf("%.16g milisegundos\n", secs * 1000.0);

	system("pause");
	return 0;

}