#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct nodo
{
	T data;
	nodo<T> *nodos[2];
	nodo(T x)
	{
		data = x ;
		nodos[0] ;
		nodos[1] ;
	}
};

template <class T>
struct arbol_binario
{
private:
	nodo<T> *root;
public:
	arbol_binario()
	{
		root = 0;
	}
	bool Find(T x, nodo<T> **&p)
	{
		p = &root;
		for (p = &root; *p && (*p)->data != x; p = &(*p)->nodos[(*p)->data < x])
		{
			return *p != 0;
		}
	}
	bool Insert(T x)
	{
		nodo <T> **p;
		if (Find(x, p))
		{
			return 0;
		}
		*p = new nodo<T>(x);
		return 1;
	}
	bool Remove(T x)
	{
		nodo<T> **p;
		if (!Find(x, p))
		{
			return 0;
		}
		if ((*p)->nodos[0] != 0 && (*p)->nodos[1] != 0)
		{
			nodo<T> **q = ref(p);
			(*p)->data = (*q)->data;
			p = q;
		}
	}
	void InOrder(nodo<T> *p)
	{
		if (!p) { return 0; }
		InOrder(p->nodos[0]);
		cout << p->data;
		InOrder(p->nodos[1]);
	}
};

int main()
{
	nodo<int> *p;
	arbol_binario<int> nectar;
	nectar.Insert(20);
	nectar.Insert(2);
	nectar.Insert(25);
	nectar.Insert(4);
	nectar.Insert(30);
	nectar.Insert(10);
	nectar.Insert(1);
	nectar.InOrder();

	system("pause");



}



