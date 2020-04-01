#include <iostream>
#include <vector>
std::vector<int> vc;    // vector global 
#include <string.h>
#include <thread>
#include <mutex>
#include <time.h>
#include <stdlib.h>


using namespace std;
mutex semaforo;


void Paral_Selection( int i, int min)
{
	int n = vc.size();
	min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (vc[j] < vc[min])
		{
			min = j;
		}
	}swap(vc[i], vc[min]);
}
void SelectionSort_Paral()
{
	int n = vc.size();
	int min;
	thread thx;
	for (int i = 0; i < n - 1; i++) // threads
	{
		min = i;
		thx = thread((Paral_Selection), int(i), int(min));//hilo x it
		thx.join();
	}
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
	cout << "                     ALGORITMOS DE ORDENAMIENTO SECUENCIAL                      \n\n";
	cout << " Ingresar Cantidad de Datos : ";
	cin >> tam_vector;
	int tmp = tam_vector;
	srand(time(NULL));
	//vector <int> vc;
	vector <int> vc_temp;
	//	int temp;
	for (int i = 0; i < tam_vector; i++)
	{
		ale = rand() % 10000000;
		vc.push_back(ale);
		//	cout << "ale=" << ale<<" "<<"temp="<<temp<<endl;
		//vc.push_back(ale);
		//myvector[i] = ale;
	}
	vc_temp = vc;
	cout << "\n Numeros Aleatorios :\n";
	mostrar(vc);
	cout << "\n\n***************SelectionSort Paralelo \n\n\n";

	SelectionSort_Paral();
	mostrar(vc);
	system("pause");
}