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
		cout << num[i] << "  ";
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
		return num;
	}

template <class T>
vector <T> insertion(vector<T>& num) //++++++++++++++++++++++++++++++++++++++++++++++InsertionSort++++++++++++++++++++
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
	return num;
}

int *heapsort(int * num ,int tam)//++++++++++++++++++++++++++++++++++++++++++++++++heapsort+++++++++++++++++++++++++++
{
	int item,tmp,k;
	for (int i = tam; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			item = num[j];
			k = j / 2;
			while (k > 0 && num[k] < item) {
				num[j] = num[k];
				j = k;
				k = k / 2;
			}
			num[j] = item;
		}
		tmp = num[1];
		num[1] = num[i];
		num[i] = tmp;
	}
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
		while (num[i] < pivot) 	i++;
		while (num[j] > pivot) 	j--;
		if_counter++;
		if (i <= j) {
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
			i++; j--;
			
		}
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

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[1000000], R[1000000];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
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
		ale = rand() % 4000;
		ptr[i]=ptr2[i]=vec2[i + 1] = ale;
		arr[i] = ale; 
		tmp.push_back(ale);

	}
	cout << "Imprimiendo..."<<endl<<endl;
	mostrar(tmp);
	vctor = tmp;
	cout <<endl<<"\tOr. BURBUJA ----------------------------------------" <<endl<<endl;
	burbuja(tmp);
	mostrar(tmp);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar(tmp);
	cout <<endl<<"\tOr. INSERTION --------------------------------------"<< endl<<endl;
	insertion(tmp);
	mostrar(tmp);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar2(vec2,tam_vector);
	cout << endl << "\tOr. HEAPSORT --------------------------------------" <<endl<< endl;
	heapsort(vec2,tam_vector);
	mostrar2(vec2, tam_vector);
	cout << endl << endl;
	system("pause");
	cout << endl;
	tmp = vctor;
	mostrar(tmp);
	cout << endl << "\tOr. QUICKSORT --------------------------------------" << endl << endl;
	//int t = tmp.size();
	//cout << "t=" << t<<endl;
	quicksort(ptr,0,tam_vector);
	mostrar2(ptr,tam_vector);
	system("pause");
	//mostrar3(ptr2, tam_vector);
	mostrar(tmp);
	cout << endl << "\tOr. MERGESORT --------------------------------------" << endl << endl;
	mergesort(arr, 0, tam_vector);
	mostrar4(arr,tam_vector);
	
	system("pause");
		
}