#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <array>
//#define int arreglo[5] = {4,3,1,2,5}
//#define int tam = sizeof(arreglo)

using namespace std;
//array arreglo = { 4,3,1,2,5 };


int * bubblesort()
{
	int arreglo[5] = {4,3,1,2,5 };
	int temp;
	int tam_ = 5;//sizeof(arreglo) / 4;
	cout << "arreglo long =" << tam_ << endl;
	for (int k = 1; k < tam_ - 1; k++)
	{
		int j = 1;
		for (int i = 0; j < tam_ - k; i++)
		{
			if (arreglo[i] > arreglo[j])
			{
				temp = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = temp;
			}
			else
			{
				i++;
			}
			j++;
		}
	}
	cout << "++++++    BUBBLE SORT    +++++++++" << endl;
	for (int i = 0; i < tam_; i++)
	{
		cout << arreglo[i] << " ";
	}
	int*ptr_array = arreglo;
	return ptr_array;
}



int main()
{
	//int arreglo[7] = { 4,3,6,9,1,2,5 };
	//int tam = sizeof(arreglo)/4;
	/*for (int i = 0; i <tam ; i++)
	{
		cout << arreglo[i] << " ";
	}*/
	//cout <<"x"<< tam << endl;
	bubblesort();
//######################################################  BUBBLESORT  ######################################################################################
	/*int tam = 5;
	int temp;
    
	for (int k = 1; k < tam-1;k++)
	{
		int j = 1;
		for (int i = 0; j < tam-k; i++)
		{
			if (arreglo[i] > arreglo[j])
			{
				temp = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = temp;
			}
			else
			{
				i++;
			}
			j++;
		}
	}
	cout << "++++++    BUBBLE SORT    +++++++++" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arreglo[i] << " ";
	}*/
//######################################################  BUBBLESORT  ######################################################################################


//######################################################  SELECTION SORT  ############################################################	
/*	for (int i = 0; i < tam-1; i++)
	{
		int min = i;
		for ( int j = i+1; j < tam; j++)
		{
			if (arreglo[j] < arreglo[min])
			{
				min = j;
			}

		}
		if (min != i)
		{
			int tmp;
			tmp = arreglo[i];
			arreglo[i] = arreglo[min];
			arreglo[min] = tmp;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arreglo[i] << " ";
	}
	*/
//######################################################  SELECTION SORT  ############################################################	

//######################################################  INSERTION SORT   ###########################################################
/*	int i, j, tmp;
	for (int i = 0; i < 5; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;

	for (i = 1; i < tam; i++)
	{
		j = i;
		while (j > 0 && arreglo[j - 1] > arreglo[j])
		{
			tmp = arreglo[j];
			arreglo[j] = arreglo[j - 1];
			arreglo[j - 1] = tmp;
			j--;		
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arreglo[i] << " ";
	}*/
//######################################################  INSERTION SORT   ###########################################################


//######################################################  QUICKSORT   ################################################################
	/*int i = right, j = left;
	int tmp;
	int pivot = arreglo[(left + right) / 2];
	while (i <= j)
	{
		while (arreglo[i] < pivot)
		{
			i++;
		}
		while (arreglo[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			tmp = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
	{

	}



	*/


	system("pause");
}
	
