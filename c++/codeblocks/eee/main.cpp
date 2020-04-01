#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Compareitor
{
public:
    virtual bool cmp(T a, T b)=0;
};

template <class T>
class lessest:public Compareitor<T>
{
    bool cmp(T a,T b){return a<b;}
};

template <class T>
class greatest:public Compareitor<T>
{
    bool cmp(T a,T b){return a>b;}
};



template <class T>
struct nodo
{
	nodo(T x)
	{
		data = x;
		next = 0;
		prev = 0;
	}
	T data;
	nodo<T> *next;
	nodo<T> *prev;
};

template<class T>
class lista
{
private:
    nodo<T> * head;
	nodo<T> * tail;
	T tam;

public:
	lista() {
		head = 0;
		tail = 0;
		tam=0;
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
		while ((*p))// && (x > (*p)->data))
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
		nodo <T> **p;
		if (Find(x, p)) {
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
	void print_from_tail(){
        nodo<T> *p;
        int elemt = 1;
        for(p=tail ; p ; p=p->prev){
            cout << "Elem " << elemt << "=" << p->data << "\t direccion=" << &(p->data) << endl;
			elemt++;
        }
	}
	void bubblesort() {
		nodo <T> *tmp;
		for (nodo <T> **p = &head; *p!=0; p = &(*p)->next) {
			for (nodo <T> **i = &head; (*i)->next!=0; i = &(*i)->next) {
				if ((*i)->data > ((*i)->next)->data){
					tmp = (*i)->next;
					(*i)->next = tmp->next;
					tmp->next = (*i);
					(*i) = tmp;
                }
            }
        }
	}
	void insertionsort(){
	    nodo<T> *last;
	    nodo<T> *first;
	    nodo<T> *tmp;
	    nodo<T> *p;

	    last=head;
	    while(last->next!=NULL){
            first=last->next;
            if( first->data < head->data){
                last->next = first->next;
                first->next=head;
                head=first;
            }
            else{
                p=head;
                tmp=head->next;
                while( tmp->data < first->data ){
                    p=tmp;
                    tmp=tmp->next;
                }
                if(tmp != first){
                    last->next = first->next;
                    first->next =tmp;
                    p->next =first;
                }
                else
                {
                    last=last->next;
                }
            }
	    }
	    /*for(i=head ; i ; i=i->next){
            j = i;
            while( j == head && j->data > (j->next)->data ){
                tmp=(j->next);
                (j->next) = tmp->next;
                tmp->next = j;
                j=tmp;

                sgte= tmp->next;
                tmp->next=prev;
                prev=tmp;
                tmp=sgte;
            }
	    }*/
	}
};

int main()
{
	int a = 3;
	nodo <int> **p;
	lista <int> lista1;
	lista1.Insert(a);
	lista1.Insert(100);
	lista1.Insert(1);
	lista1.Insert(6);
	lista1.Insert(2);
	lista1.Insert(4);
	lista1.print();
	//lista1.~lista();
	//lista1.print();
	//cout<<endl<<lista1.Find(3,p)<<endl;
	system("pause");
	cout << endl;
	lista1.bubblesort();
	//lista1.insertionsort();
	lista1.print();

	//lista1.print_from_tail();

    system("pause");
}
