#include <iostream>
#include <time.h>
#include <thread>
#include <stdlib.h>
int num_ths =2;// thread::hardware_concurrency();
using  namespace std;

void insertar(int *x,int i)
{   if(x[i]>x[i+1])
    {   swap(x[i],x[i+1]);
    }
    while(x[i]<x[i-1]&&i>=1)
    {
        swap(x[i-1],x[i]);
        i--;//retrocede
    }
}
void insertsort(int *x,int SIZE)//------| ...
{
    thread B,C;

         for(int i=0;i<SIZE-1;i++)
         {
             insertar(x,i);
         }
}
void mostrar(int* num, int tam)
{
	for (int i = 0; i < tam; i++)
		cout << num[i] << " ";
	cout << endl;
}
int main()
{
    int tam_vector;
    cout << "ALGORITMOS DE ORDENACION PARALELO : INSERTION" << endl;
	cout << "Ingresar cantidad de datos:";
	cin >> tam_vector;
	int *num=new int[tam_vector];
	for (int j = 0; j<tam_vector; j++){
		num[j] = rand() % 1000;
		cout << num[j] << " ";
	}
    thread A[num_ths];
    for (int i =0; i < tam_vector; ++i){
        if(i%((tam_vector+1)/num_ths)==0){
            A[i/((tam_vector+1)/num_ths)]= thread(insertsort,num,tam_vector);
        }
    }
    for(int i=0;i<num_ths;i++){
        A[i].join();
    }
    cout<<endl<<endl;
    mostrar(num,tam_vector);
    return 0;
}
