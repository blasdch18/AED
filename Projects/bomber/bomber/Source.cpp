#include<iostream>
#define int clock_bomb;

using namespace std;

template <class T>
class nodo
{
public :
	nodo();
	next = prev = 0;
	nodo(T element, nodo * sg = nullptr, nodo *pv = nullptr)
	{
		valor = element;
		next = sg;
		prev = pv;
	}

private:
	int valor;
	nodo*next;
	nodo*prev;
};