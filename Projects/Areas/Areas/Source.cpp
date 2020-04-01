#include <iostream>
#include <stdlib.h>

using namespace std;


class nodo {
	int x, y;
	nodo * next;
	nodo() {
		next = 0;
	}
	nodo(int x1, int y1, nodo*sgte = nullptr) {
		x = x1;
		y = y1;
		next = sgte;
	}
};

class lista {
	lista() {
		head = tail = nullptr;
	}
	~lista();
	int empty() {
		return head == 0;
	}
	void add_head(int x1, int y1) {
		head = new nodo(x1, y1, head);
		if (tail == 0)
		{
			tail == head;
		}
	}
	void add_tail(int x1, int y1) {
		if (tail != 0)
		{
			tail->next = new nodo(x1, y1);
			tail = tail->next;
		}
		else
		{
			head = tail = new nodo(x1, y1);
		}
	}
	int delete_head() {
		int x1, y1;
		x1 = head->x;
		y1 = head->y;
		nodo * tmp = head;
		if (head == tail)
		{
			head = tail = 0;
		}
		else
		{
			head = head->next;
		}
		delete tmp;
		return int;
	}
	//T delete_tail();
	void delete_nodo();
private:
	nodo *head, *tail;
};






int main()
{
	int tam;
	lista<int> puntos;
	cout << "-----------Lista de Puntos XY--------------" << endl;
	cout << "Tamaño de la lista = "; cin >> tam;
	for (int i = 0; i < tam; i++)
		int x, y;
		cout << "Escriba sus puntos =>     x=";
		cin >> x;
		cout << "\t y=";
		cin >> y;
		puntos.add_head(x, y);
	cout << "hola"<<endl;
	system("pause");
}