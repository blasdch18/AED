#include <iostream>

using namespace std;

template<class T>

struct nodo {

	T data;
	nodo<T>* nodos[2];

	nodo(T x) {

		data = x;
		nodos[0] = 0;
		nodos[1] = 0;
	}
};
template<class T>
class nodo_list
{
public:
	T num;
	nodo_list<T> *next;
	nodo_list<T> *beck;
	nodo_list()
	{
		next = beck = 0;
	}
	nodo_list(T x1, nodo_list*sgte = 0, nodo_list*prev = 0)
	{
		num = x1;
		next = sgte;
		beck = prev;
	}
};

template <class T>
class lista
{
private:
	nodo_list<T> * head, *tail;
public:
	lista()
	{
		head = tail = 0;
	}
	void add(T x1 )
	{
		if (tail != 0)
		{
			tail = new nodo_list<T>(x1, 0, tail);
			tail->beck->next = tail;
		}
		else head = tail = new nodo_list<T>(x1);
		//cout<<"&="<<&(head)<<endl;
	}
	void print()
	{
		nodo_list<T> *p;
		int elemt = 1;
		for (p = head; p; p = p->next) {
			cout << "Elem " << elemt << "=" << p->num << "\t direccion=" << &(p->num) << endl;
			elemt++;
		}
	}
};

template<class Tr>

class arbol_binario
{
public:

	arbol_binario();
	typedef typename Tr::T T;
	typedef typename Tr::C C;

	bool find(T, nodo<T>**&);
	bool insert(T);
	bool remove(T);
	void inorden(nodo<T>*);
	void print_h(string orden, nodo<T>*p);

	//void preorden(nodo<T>*);
	//void postorden(nodo<T>*);
	void convert(nodo<T>*&x);

	C cmp;
	nodo<T>*root;

	nodo_list<T> *nodo2lista;
	lista<T> lista2arbol;
};

template<class Tr>
arbol_binario<Tr>::arbol_binario()
{
	root = 0;
}

template<class Tr>
bool arbol_binario<Tr>::find(T x, nodo<T>**&p)
{
	for (p = &root; (*p) && (*p)->data != x; p = &(*p)->nodos[cmp((*p)->data, x)]);
	return (*p);
}

template<class Tr>
bool arbol_binario<Tr>::insert(T x)
{
	nodo<T>**p;

	if (find(x, p)) return 0;

	*p = new nodo<T>(x);

	return 1;
}

template<class Tr>
bool arbol_binario<Tr>::remove(T x)
{
	nodo<T>** p;
	nodo<T>* temp;

	if (!find(x, p)) return 0;
	temp = (*p);
	if ((*p)->nodos[0] && (*p)->nodos[1]) {

		for (p = &((*p)->nodos[0]); (*p)->nodos[1]; p = &((*p)->nodos[1]));
		swap((*p)->data, temp->data);
	}
	temp = (*p);
	(*p) = (*p)->nodos[!!(*p)->nodos[1]];
	return 1;
}
template<class Tr>
void arbol_binario<Tr>::print_h(string orden, nodo<T>*p)
{
	int estado = 0;
	while (estado<3)
	{
		if (orden[estado] == '1')
			cout << p->data << " ";
		else if (orden[estado] == '2' && p->nodos[1])
			print_h(orden, p->nodos[1]);
		else if (orden[estado] == '3' && p->nodos[0])
			print_h(orden, p->nodos[0]);
		estado++;
	}
}
template<class Tr>
void arbol_binario<Tr>::inorden(nodo<T> *p)
{
	if (p != 0) {

		inorden(p->nodos[0]);
		cout << p->data << " ";
		inorden(p->nodos[1]);
	}
}
/*
void arbol_binario<Tr>::preorden(nodo<T> *p)
{
	if (p != nullptr) {

		cout << p->data << " ";
		preorden(p->nodos[0]);
		preorden(p->nodos[1]);
	}
}
void arbol_binario<Tr>::postorden(nodo<T> *p)
{
	if (p != nullptr) {
		postorden(p->nodos[0]);
		postorden(p->nodos[1]);
		cout << p->data << " ";
	}
}
*/

template<class Tr>
void arbol_binario<Tr>::convert(nodo<T> *&x)
{
    nodo<T> **p;
    *p=x;

	lista2arbol.add(((*p)->nodos[0])->data);
	while(*p)
	{
	    lista2arbol.add(((*p)->nodos[1])->data);
	    convert((*p)->nodos[0]);
	}
	lista2arbol.print();
}

///MAIN

template <class T>

struct c_less
{
	inline bool operator() (T a, T b)
	{
		return a<b;
	}
};

template <class T>

struct c_greater
{
	inline bool operator() (T a, T b)
	{
		return a>b;
	}
};

struct traits {

	typedef int T;
	typedef c_less<T> C;
};

int main()
{

	arbol_binario<traits> nectar;

	string text;
	int a, b, c, d, e, f, g;

	a = 10;
	b = 60;
	c = 20;
	d = 15;
	e = 80;
	f = 5;
	g = 56;

	nectar.insert(a);
	nectar.insert(b);
	nectar.insert(c);
	nectar.insert(d);
	nectar.insert(e);
	nectar.insert(f);
	nectar.insert(g);
	cout << "Inorder = ";
	nectar.inorden(nectar.root);
	cout << endl;
	nectar.remove(b);
	cout << endl;
	nectar.convert(nectar.root);

	//nectar.print_h(text, nectar.root);
	//nectar.inorden(nectar.root);
	//cout << endl;
	//nectar.preorden(nectar.root);
	//cout << endl;
	//nectar.postorden(nectar.root);
	//cout << endl;

	//system("pause");

}





