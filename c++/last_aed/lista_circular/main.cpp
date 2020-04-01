#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>

using namespace std;

template< class T >
class nodo
{
public:
    T data ;
    nodo<T>*next;
    nodo<T>*prev;
    nodo()
    {
        //data=x;
        next=prev=0;
    }
    nodo (T x , nodo *n=0 , nodo *p=0)
    {
        data=x;
        next=n;
        prev=p;
    }
};

template<class T>
class CirLista
{
private:
    nodo<T>*head;
    nodo<T>*min_;
public:

    CirLista()
    {
        head=min_=0;
    }/*
    CirLista(T x)
    {
        head=new nodo<T>(x);
    }*/
    bool buscar(T x,nodo<T>**&p)
    {
        p = &head;
		while (((x>(*p)->data) && (*p)->next != head))// && (x > (*p)->data))
		{
			p = &((*p)->next);
		}
		return (*p)->data == x;
    }
    bool insertar(T x)
    {/*
        nodo<T> *last;
        if(head == 0)
        {
            head = new nodo<T> (x,0);
            head->next=head;
            head->prev=head;
        }
        else
        {
            last= head->next->prev;
            last->next= new nodo<T> (x,0);

            head->next = new nodo<T> (x, head->next);
            head= head->next;
        }*/
        nodo <T> **p;
	if (head == 0) {
		nodo<T> * temp = new nodo<T>(x);
		head = temp;
		temp->next = temp;
		temp->prev = temp;
		return 1;
	}
	else {
		if (buscar(x, p)) return 0;

		nodo<T> * temp = new nodo<T>(x);
		if ((*p) == head)		//Caso especial cabeza
		{
			temp->prev = head->prev->next;
			temp->next = head;
			head->prev->next = temp;
			head->prev = temp;

			if (x < head->data) {					//nueva cabeza
				head = temp;
			}
			return 1;

		}
		else if ((*p) != head && (*p)->next == head)	//final
		{
			if (x>(*p)->data) {					//nueva final
			temp->next = head;
			temp->prev = (*p);
			(*p)->next = temp;
			head->prev = temp;
			}
			else {
				temp->prev = (*p)->prev;			//Previo final
				temp->next = (*p);
				(*p)->prev = temp;
				(*p) = temp;
			}

			return 1;
		}
		else if ((*p) != head && (*p)->next != head ){//elemento Medio
			temp->prev = (*p)->prev;
			temp->next = (*p);
			(*p)->prev = temp;
			(*p) = temp;
			return 1;
		}
		return 0;
	}


    }
    bool eliminar(T x)
    {
        nodo<T> **p;
        if(buscar(x,p))
        {
            return 0;
        }
        nodo<T>* tmp = *p;
        (*p) = (*p)->next;
        delete tmp;
        return 1;
    }
    void imprimir ()
    {
        nodo<T>* aux;
        aux = head;
       // int i=0;

        do
        {
            cout<<aux->data <<"°° " <<&(aux->data) <<"  ";//endl;
            aux=aux->next;
            //system("pause");
            //i++;
        }while(aux != head);
    }
    bool josephus(T num , T tam)
    {

    nodo <T> **p;
	nodo <T> *t;
	int m=num-1;

	p = &head;
	for (int i = tam; i > 2; i--)
        {
            cout << "Quedan ->" <<i<<"   ";
            for (int j = 0; j < m; j++)    // numero de saltos sobre persona
            {
                p = &(*p)->next;
            }
            cout <<" X -> "<< (*p)->data << endl;
            if ((*p) == head)
            {				//Eliminamos la cabeza
                head = (*p)->next;
                t = (*p);
                (*p) = t->next;
                (*p)->prev = t->prev;
                delete t;
			//i--;
            }else
            {							//Caso generico
                t = (*p);
                (*p)->next->prev = t->prev;
                t->prev->next = (*p)->next;
                (*p) = t->next;
                delete t;
			//print();

			//i--;
            }
	}
	return 1;
    }
};

int main()
{
    CirLista <int> li ;
    cout << "++++++++++++++++++++++ lista circular ++++++++++++++++++++++ \n";
	cout << "Ingrese tamanho de lista = ";
	int tam, num;
	num=1;
	cin >> tam;
	for (int i = 0; i<tam; i++)
	{
		int elemento;
		//cout << "Ingrese elemento =";
		//cin >> elemento;
		//CirLista <int> li(elemento);
		//li.insertar(elemento);}
		li.insertar(num);                                                                                                                                       num++;
	}
	li.imprimir();

	cout<<endl<<endl<<"JosePhus Papus!!   . .. . "<<endl;
	li.josephus(30 ,tam);
	li.imprimir();


    return 0;
}

