#include <iostream>
#include <vector>
std::vector<int> vc;    // vector global
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


void burbuja(vector <int> &num)//++++++++++++++++++++++++++++++++++++++++++++++BubbleSort++++++++++++++++++++++
{
	int i, j;
	int temp;
	int numLength = num.size();
	for (i = 0; i < numLength; i++)
	{
		for (j = 0; j < numLength - 1; j++)
		{
			if (num[j + 1] < num[j])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}
void insertion(vector<int>& num) //++++++++++++++++++++++++++++++++++++++++++++++InsertionSort++++++++++++++++++++
{
	clock_t start = clock();
	int tam = num.size();
	int i, j, tmp;
	for (i = 1; i < tam; i++) {
		j = i;
		while (j > 0 && num[j - 1] > num[j])
		{
			tmp = num[j];
			num[j] = num[j - 1];
			num[j - 1] = tmp;
			j--;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Selection Sort+++++++++++++++
void SelectionSort(vector <int> &num)
{
	int pos_min, temp;
	int n = num.size();
	for (int i = 0; i < n - 1; i++)
	{
		pos_min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < num[pos_min])
				pos_min = j;
		}
		if (pos_min != i)
		{
			temp = num[i];
			num[i] = num[pos_min];
			num[pos_min] = temp;
		}
	}
}

void quickSort(vector <int> &num ,int left , int right)
{
	left = num.front();
	right = num.back();
	int i = left;
	int j = right;
	int tmp;
	int pivot = num[(left + right) / 2];
	while (i <= j) 
	{
		while (num[i] < pivot)
		{
			i++;
		}
		while (num[j] > pivot)
		{
			j--;
		}
		if (i <= j) 
		{
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
	{
		quickSort( num, left ,j);
	}
	if (i < right)
	{
		quickSort( num,i,right);
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
	//srand(time(NULL));
	//vector <int> vc;
	vector <int> vc_temp;
	//	int temp;
	for (int i = 0; i < tam_vector; i++)
	{
		ale = rand() % 1000;
		vc.push_back(ale);
		//	cout << "ale=" << ale<<" "<<"temp="<<temp<<endl;
		//vc.push_back(ale);
		//myvector[i] = ale;
	}
	vc_temp = vc;
	cout << "\n Numeros Aleatorios :\n";
	mostrar(vc);
	cout << "\n\nEMPEZAMOS A ORDENAR :\n";
	cout << "\n\n****************************************************InsertionSort+++++++ \n\n\n";
	vc_temp = vc;//							regresando a los numeros aleatorios
	mostrar(vc_temp);
	insertion(vc_temp);
	mostrar(vc_temp);
	cout << "\n\n*****************************************************SelectionSort+++++++ \n\n\n";
	vc_temp = vc;//							regresando a los numeros aleatorios
	mostrar(vc_temp);
	SelectionSort(vc_temp);
	mostrar(vc_temp);
	cout << "\n\n******************************************************BubbleSort++++++ \n\n\n";
	vc_temp = vc; //						regresando a los numeros aleatorios
	mostrar(vc_temp);
	burbuja(vc_temp);//1
	mostrar(vc_temp);
	cout << "\n\n******************************************************QuickSort++++++ \n\n\n";
	vc_temp = vc; //						regresando a los numeros aleatorios
	mostrar(vc_temp);
	quickSort(vc_temp , vc_temp.back(), vc_temp.front());//1
	mostrar(vc_temp);
	cout << endl << endl;
	system("pause");
}