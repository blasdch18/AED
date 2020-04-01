#include <vector>
#include <thread>
#include <iostream>
#include <stdlib.h>
using namespace std;
int num_nucleos=4;

void heaping(vector<int>& num,int i, int max)
{
    int root, izq, der;
    while(i < max) {
        root = i;
        izq = (2*i) + 1; // ubicados la posicion diferente del root
        der = izq + 1; // ubicados en la posicion diferente al root pero a la derecha
        if( izq<max && num[izq]>num[root] )   root = izq;
        if( der<max && num[der]>num[root] )   root = der;
        if(root == i) return;
        swap(num[i],num[root]);
        i = root;
    }
}
void to_heap(vector<int>& num)
{
    int i = (num.size()/2) - 1;
    while(i >= 0) {
        heaping(num, i, num.size());
        --i;
    }
}
void heapsort_paralelo(vector<int>& num, int cores)
{
    num_nucleos=cores;
    to_heap(num); // lo arma, lo ordena como un tree
    int fin = num.size() - 1;
    int contador;
    while (fin > 0) { // iteracion para que busque los padres cada vez
        swap(num[0], num[fin]);//manda un ultimo elemento al final
        if(contador++<=num_nucleos)
        {
            thread t=thread(heaping,ref(num), 0, fin);
            t.join();
        }
        else
            heaping(num,0,fin);
        --fin;
    }
}
void mostrar(vector <int>& num)
{
	int tam = num.size();
	for (int i = 0; i <tam; i++)
		cout << num[i] << "  ";
	cout << endl;
}
int main (){

    vector<int> num;
    srand(time(NULL));
    //int num_nucleos;
    int tam_vector;
    cout << "ALGORITMOS DE ORDENACION PARALELO : HEAP SORT " << endl;
	cout << "Ingresar cantidad de datos:";
	cin >> tam_vector;
	for (int i = 0; i<tam_vector; i++){
        num.push_back(rand()%1000);
	}
    clock_t t;
    t=clock();
    mostrar(num);
    cout<<endl<<endl;
    heapsort_paralelo(num,num_nucleos);
    mostrar(num);
    return 0;
}
