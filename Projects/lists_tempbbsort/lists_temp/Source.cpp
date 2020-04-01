#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
struct nodo
{
	nodo(T x)
	{
		data = x;
		next = 0;
	}
	T data;
	nodo<T> *next;
};

template<class T>
class lista
{
private:
	//nodo *tail;
	nodo<T> * head;
	T tam;
public:
	lista() {
		head  = 0;
	}
	~lista() {
		/*for (nodo<T> *p; head;) {
			p = head->next;
			delete head;
			head = p;
		}*////insertar o borra  arboles 

		nodo<T> *q = head;
		for (nodo<T> *t = head; q; t=q) {
			q = t->next;
			delete t;
		}
		head = 0;
	}
	bool Find(T x, nodo<T> **&p) {
		p = &head;
		while ((*p) && (x > (*p)->data))
		{
			p = &((*p)->next);
		}
		return *p && (*p)->data == x;
	}
	bool Insert(T x){
		nodo <T> **p;
		if (Find(x, p)) {
			return 0;
		}
		nodo <T> *w;
		w = new nodo<T>(x);
		w->next = *p;
		*p = w;
		return 1;
	}
	bool remove(T x){
		nodo <T> **P;
		if (Find(x, P)) {
			return 0;
		}
		nodo<T> *r;
		r = (**p).next;
		delete *p;
		*p = r;
		return 1;
	}
	void print(){
		nodo<T> *p;
		int elemt = 1;
		for (p = head; p; p = p->next) {
			cout << "Elem " << elemt << "=" << p->data << "\t direccion=" << &(p->data) << endl;
			elemt++;
		}
	}
	void bubblesort() {
		nodo <T> *tmp;
		for (nodo <T> **p = &head; p; p = &(*p)->next) {
			for (nodo <T> **i = &head; (*i)->next!=NULL; i = &(*i)->next) {
				if ((*i)->data > ((*i)->next)->data)
					tmp = (*i)->next;
					(*i)->next = tmp->next;	
					tmp->next = *i;
					*i = tmp;
			}
		}
	}
};

int main()
{
	int a = 3;
	nodo <int> **p;
	lista <int> lista1;
	lista1.Insert(a);
	lista1.Insert(4);
	lista1.Insert(3);
	lista1.Insert(6);
	lista1.print();
	//lista1.~lista();
	//lista1.print();
	cout<<endl<<lista1.Find(3,p)<<endl;
	system("pause");
	cout << endl;
	lista1.bubblesort();
	lista1.print();


}




