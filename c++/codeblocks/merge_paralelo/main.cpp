#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include <vector>

using namespace std;
void mezclar(int *num, int izq, int der, int centro)
{
  int i=izq;
  int j=centro+1;
  int* aux= new int[der-izq+1];
  int k=0;
  while ((i<=centro) &&(j<=der)){
      if(num[i]<num[j]){
          aux[k]=num[i];
          i++;
      }
      else{
          aux[k]=num[j];
          j++;
      }
      k++;
  }

  while (i<=centro){
      aux[k]=num[i];
      i++;
      k++;
  }

  while (j<=der){
      aux[k]=num[j];
      j++;
      k++;
  }
  for(i=0;i<k;i++)
  {
      num[i+izq]=aux[i];
  }
}
void ordenarMezcla(int *num, int p, int q)
{
  thread th1,th2;
  int centro=0;
  if (p<q)
  {
      centro=(p+q)/2;
      th1= thread(ordenarMezcla,num,p,centro);
      th2= thread(ordenarMezcla,num,centro+1,q);
      th1.join();
      th2.join();
      mezclar(num,p,q,centro);
  }
}
void mostrar(int num[], int tam)
{
	for (int i=0; i<tam; i++)
		cout << num[i] << "  ";
	cout << endl;
}
int main()
{
    int tam_vector;
    int nThreads = 2;//numero de hilos
    cout << "ALGORITMOS DE ORDENACION PARALELO : MERGESORT" << endl;
	cout << "Ingresar cantidad de datos:";
	cin >> tam_vector;
	//int num[tam_vector];
	int *num=new int[tam_vector];
	for (int j = 0; j<tam_vector; j++){
		num[j] = rand() % 100;
		cout << num[j] << " ";
	}
    vector<thread> ths(nThreads);
    for (int i=0; i<nThreads; i++){
        ths[i] = thread(ordenarMezcla,num,0,tam_vector);
    }
    for (int i=0; i <nThreads; i++){
        ths[i].join();
    }
    cout<<endl<<endl;
    mostrar(num,tam_vector);
    return 0;
}
