#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
std::vector<int> vctor;

using namespace std;

/*
				1.-bubble sort
				2.-insertion sort
				3.-quick sort
				4.-heap sort
				5.-merge sort
*/
void mostrar(vector <int>& num)
{
	int tam = num.size();
	for (int i = 0; i <tam; i++)
		cout << num[i] << "  " <<endl;
	cout << endl;
}
void mostrar2(int* num, int tam)
{
	for (int i = 1; i <= tam; i++)
		cout << num[i] << "  ";
	cout << endl;
}
void mostrar3(int* num, int tam)
{
	for (int i = 0; i < tam; i++)
		cout << num[i] << "  ";
	cout << endl;
}
void mostrar4(int num[], int tam)
{
	for (int i = 0; i < tam; i++)
		cout << num[i] << "  ";
	cout << endl;
}
template <class T>
vector <T> burbuja(vector <T> & num)
	{
	    int if_counter=0;
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
					if_counter++;
				}
				if_counter++;
			}
		}
		cout<<"#if="<<if_counter<<endl;
		return num;
	}

template <class T>
vector <T> insertion(vector<T>& num) //++++++++++++++++++++++++++++++++++++++++++++++InsertionSort++++++++++++++++++++
{
    int if_counter=0;
	//clock_t start = clock();
	int tam = num.size();
	int i, j, tmp;
	for (i = 1; i < tam; i++) {
		j = i;
		if_counter++;
		while (j > 0 && num[j - 1] > num[j])
		{
			tmp = num[j];
			num[j] = num[j - 1];
			num[j - 1] = tmp;
			j--;
			if_counter++;
			if_counter++;
		}

	}
	cout<<"#if="<<if_counter<<endl;
	return num;
}
int *heapsort(int * num ,int tam)//++++++++++++++++++++++++++++++++++++++++++++++++heapsort+++++++++++++++++++++++++++
{
	int item,tmp,k,if_counter;
	if_counter=0;
	for (int i = tam; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			item = num[j];
			k = j / 2;
			if_counter++;
			while (k > 0 && num[k] < item) {
				num[j] = num[k];
				j = k;
				k = k / 2;
				if_counter++;

			}
			num[j] = item;
		}
		tmp = num[1];
		num[1] = num[i];
		num[i] = tmp;
	}
	cout<<"#if="<<if_counter<<endl;
	return num;
}
void quicksort(int *num, int izq, int der) {//
	int if_counter = 0;
	int i = izq;
	int j = der;
	int tmp=0;
	int pivot = num[(izq + der) / 2];
	while (i <= j)
	{
		while (num[i] < pivot) 	{i++;}
		while (num[j] > pivot) 	{j--;}
		if (i <= j) {
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i++; j--;
			if_counter++;
		}
		if_counter++;
	}
	if_counter++;
	if (izq < j) {

		quicksort(num, izq, j);
	}
	if_counter++;
	if (i < der) {

		quicksort(num, i, der);
	}
	cout << "if_counter =" << if_counter << endl;
}
void merge(int arr[], int izq, int med, int der);//++++++++++++++++++++++++++++   Merge Sort    ++++++++++++++++++++++++++++++++++
void mergesort(int arr[], int izq, int der)
{
    //int if_counter=0;
	if (izq < der)
	{
        int med = izq + (der - izq) / 2;
		mergesort(arr, izq, med);//reduce izq
		mergesort(arr, med + 1, der);
		merge(arr, izq, med, der);
	}
	//cout << "if_counter =" << if_counter << endl;
}
void merge(int arr[], int izq, int med, int der)
{
    int if_counter=0;
	int i, j, k;
	int n1 = med - izq + 1;
	int n2 = der - med;
	int L[n1], R[n2];
    for (i = 0; i < n1; i++){
		L[i] = arr[izq + i];
	}
	for (j = 0; j < n2; j++){
		R[j] = arr[med + 1 + j];

	}
	i = 0;
	j = 0;
	k = izq;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
			if_counter++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			if_counter++;
		}
		k++;
	}
	while (i < n1)// copia los restantes en R[] , si hay
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)  // copia los restantes en R[] , si hay
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	cout << "if_counter =" << if_counter << endl;
}

int main()
{
	int ale, tam_vector;
	vector <int> tmp;

	cout << "ALGORITMOS DE ORDENACION" << endl;
	cout << "Ingresar cantidad de datos:";
	cin >> tam_vector;
	int *vec2 = new int[tam_vector];
	int *ptr = new int[tam_vector];
	int *ptr2 = new int[tam_vector];
	int arr[tam_vector];
	for (int i = 0; i < tam_vector; i++) {
		ale = rand() % 40;
		ptr[i]=ptr2[i]=vec2[i + 1] = ale;
		arr[i] = ale;
		tmp.push_back(ale);

	}
	cout << "Imprimiendo..."<<endl<<endl;
	mostrar(tmp);
	vctor = tmp;
	cout <<endl<<"\tOr. BURBUJA ------------------------ n2----------------" <<endl<<endl;
	burbuja(tmp);
	mostrar(tmp);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar(tmp);
	cout <<endl<<"\tOr. INSERTION ------------------------- n2-------------"<< endl<<endl;
	insertion(tmp);
	mostrar(tmp);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar2(vec2,tam_vector);
	cout << endl << "\tOr. HEAPSORT --------------------   n log n ------------------" <<endl<< endl;
	heapsort(vec2,tam_vector);
	mostrar2(vec2, tam_vector);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar(tmp);
	cout << endl << "\tOr. QUICKSORT ---------------   n*log n-----------------------" << endl << endl;
	//int t = tmp.size();
	//cout << "t=" << t<<endl;
	quicksort(ptr,0,tam_vector);
	mostrar3(ptr,tam_vector);
	system("pause");
	//mostrar3(ptr2, tam_vector);
	mostrar(tmp);
	cout << endl << "\tOr. MERGESORT ----------------- n*log n---------------------" << endl << endl;
	mergesort(arr, 0, tam_vector);
	mostrar4(arr,tam_vector);


	system("pause");

}
