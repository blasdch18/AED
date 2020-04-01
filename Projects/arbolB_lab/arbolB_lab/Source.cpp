#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
template <class T>
struct nodo
{
	nodo(T x)
	{
		t data;
		nodo<T> *nodos[2];
		data = x;
		nodos = [0] = nodos[1] = 0;
	}
};
template<class T>
class arbol_binario
{
private:
	nodo<T> *root;
public:
	arbol_binario() {
		root = NULL;
	}
	bool find(T x, nodo <T> **&p) {
		p = &root;
		for (p = &root; *p && (*p)->data != x; p = &(*p)->nodos[(*p)->data < x]) {
			return *p != 0;
		}
	}
	bool insert(T x) {
		nodo<T> **p;
		if (find(x, p))return 0;
		*p = new nodo <T>(x);
		return 1;
	}
	bool remove(T x) {
		nodo <T> **p;
		if (!find(x, p))return 0;
		{
			if ((*p)->nodos[0] && (*p)->nodos[1])
			{

			}
		}
	}

};
