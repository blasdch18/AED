#include <iostream>
#include <vector>
std::vector<int> vc;    // vector global
#include <string.h>
#include <thread>
#include <mutex>
#include <stdlib.h>

using namespace std;
mutex semaforo;

void Intercalar(vector <int>& num, int left, int right, int p)
{
	int i, j, k;
	int n1 = p - left + 1;
	int n2 = right - p;

	vector<int>L;
	vector<int>R;
				// creando arreglos temporales
				//copiar datos a los arrays temporales
	for (i = 0; i < n1; i++)
	{
		L[i] = num[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = num[p + 1 + j];
	}
	//mezclando los arreglos temporales de nuevo
	i = 0;  j = 0;  k = left;
	while (i < n1 && j < n2) 
	{ // compara los elementos de un arreglo con el otro
		if (L[i] <= R[j]) 
		{
			num[k] = L[i];
			i++;
		}
		else 
		{
			num[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)  //copiar los elementos restantes de L
	{
		num[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)    //copiar los elementos restantes de R
	{
		num[k] = R[j];
		j++;
		k++;
	}
}
void MergeSort(vector <int> num, int left, int right)
{
	int p;
	if (left < right)
	{
		p = (left + right) / 2;
		MergeSort(num, left, p);
		MergeSort(num, p + 1, right);
		Intercalar(num, left, right, p);
	}
}
void mergesort_paralelo(vector <int>& num, int left, int right, int cores)
{
	int numero_cores;
	//int numero_cores = thread::hardware_concurrency();
	numero_cores = cores;
	vector<thread> thr(numero_cores);
	//vector<int> copia(20);
	while (numero_cores)
	{
		int razon = right / numero_cores;
		for (int p = 0; p < numero_cores - 1; p++)
		{
			thr[p] = thread(MergeSort, num, left, right);
			left += razon;
		}
		thr[numero_cores - 1] = thread(MergeSort, num, left, right);
		for (int p = 0; p < numero_cores; p++)
			thr[p].join();
		numero_cores = numero_cores / 2;
	}
	MergeSort(num, left, right);
}
void mostrar(vector <int>& num)
{
	int tam = num.size();
	for (int i = 0; i <tam; i++)
		cout << num[i] << " ";
	cout << endl;
}
int main()
{
	int ale;
	int tam_vector;
	cout << "                     ALGORITMOS DE ORDENAMIENTO SECUENCIAL  y PARALELO                    \n\n";
	cout << " Ingresar Cantidad de Datos : ";
	cin >> tam_vector;
	int tmp = tam_vector;
	//srand(time(NULL));
	//vector <int> vc;
	vector <int> vc_temp;
	//	int temp;
	for (int i = 0; i < tam_vector; i++)
	{
		ale = rand() % 1000;
		vc.push_back(ale);
	}
	vc_temp = vc;
	cout << "\n Numeros Aleatorios :\n";
	mostrar(vc);
	MergeSort(vc_temp, 0, vc_temp.size());
	mostrar(vc_temp);
	

	system("pause");
}