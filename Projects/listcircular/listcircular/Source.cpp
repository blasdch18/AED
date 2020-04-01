// ListaCircularJosephus.cpp: define el punto de entrada de la aplicación de consola.
//

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;


template<class T>
struct CNode
{
	CNode(T newData) {
		m_data = newData;
		m_next = nullptr;
		m_prev = nullptr;
	}
	CNode * m_next;
	CNode * m_prev;
	T m_data;

};
template <class T>
class CircularListJosephus {
public:
	CircularListJosephus() {
		m_head = nullptr;
	}
	void filllist(T x);
	bool insert(T x);
	bool remove(T x);
	bool josephus(T rz, T size);
	bool find(T x, CNode<T> **&p);
	void print();

private:
	CNode<T> * m_head;

};
template<class T>
void CircularListJosephus<T>::filllist(T x)
{
	for (int i = 1; i <= x; i++) {
		insert(i);
	}
}
template <class T>
bool CircularListJosephus<T>::find(T x, CNode<T> **&p)
{
	p = &m_head;
	while (((x>(*p)->m_data) && (*p)->m_next != m_head)) {
		p = &(*p)->m_next;
	}
	return ((*p)->m_data == x);
}
template<class T>
bool CircularListJosephus<T>::insert(T content)
{
	CNode <T> **p;
	if (m_head == nullptr) {	//Preguntanos si es lista vacia
		CNode<T> * newNode = new CNode<T>(content);
		m_head = newNode;		//si lo es decimos q la cabeza es igual al nuevo nodo
		newNode->m_next = newNode;
		newNode->m_prev = newNode;
		return 1;
	}
	else {
		if (find(content, p)) return 0;
		CNode<T> * newNode = new CNode<T>(content);
		if ((*p) == m_head)		//Caso especial cabeza
		{
			newNode->m_prev = m_head->m_prev->m_next;
			newNode->m_next = m_head;
			m_head->m_prev->m_next = newNode;
			m_head->m_prev = newNode;

			if (content<m_head->m_data) {					//nueva cabeza
				m_head = newNode;
			}
			return 1;
		}
		else if ((*p) != m_head && (*p)->m_next == m_head)	//final
		{
			if (content>(*p)->m_data) {					//nueva final
				newNode->m_next = m_head;
				newNode->m_prev = (*p);
				(*p)->m_next = newNode;
				m_head->m_prev = newNode;
			}
			else {
				newNode->m_prev = (*p)->m_prev;			//Previo final
				newNode->m_next = (*p);
				(*p)->m_prev = newNode;
				(*p) = newNode;
			}

			return 1;
		}
		else if ((*p) != m_head && (*p)->m_next != m_head) {//elemento Medio
			newNode->m_prev = (*p)->m_prev;
			newNode->m_next = (*p);
			(*p)->m_prev = newNode;
			(*p) = newNode;
			return 1;
		}
		return 0;
	}
}
template<class T>
bool CircularListJosephus<T>::josephus(T rz, T size)
{
	CNode <T> **p;
	CNode <T> *t;
	int m = rz - 1;

	p = &m_head;
	for (int i = size; i > 2; i--) {
		cout << "size:" << i << endl;
		for (int j = 0; j < m; j++) {
			p = &(*p)->m_next;
		}
		cout << "eliminar: " << (*p)->m_data << endl;
		if ((*p) == m_head) {				//Eliminamos la cabeza
			m_head = (*p)->m_next;
			t = (*p);
			(*p) = t->m_next;
			(*p)->m_prev = t->m_prev;
			delete t;
			//i--;
		}
		else {							//Caso generico en medio
			t = (*p);
			(*p)->m_next->m_prev = t->m_prev;
			t->m_prev->m_next = (*p)->m_next;
			(*p) = t->m_next;
			delete t;
			//print();

			//i--;
		}
	}
	return 1;
}
template<class T>
bool CircularListJosephus<T>::remove(T x)
{
	CNode <T> **p;
	CNode <T> *t;

	if (!find(x, p)) return 0;

	if ((*p) == m_head) {				//Eliminamos la cabeza
		t = (*p);
		m_head = t->m_next;
		m_head->m_prev = t->m_prev;
		m_head->m_prev->m_next = m_head;
		delete t;
		//i--;
	}
	else {							//Caso generico en medio
		t = (*p);
		(*p) = t->m_next;
		(*p)->m_prev = t->m_prev;
		delete t;
		//print();

		//i--;
	}
	return 1;
}
template <class T>
void CircularListJosephus<T>::print()
{
	CNode<T> *p;		//el print es diferente ya que debe imprimir desde la cabeza hasta que llegue nuevamente a la cabeza
	p = m_head;
	do {
		cout << p->m_data << " - ";
		p = p->m_next;
	} while (p != m_head);
}
int main()
{
	CircularListJosephus<int> list;
	//list.filllist(41);
	
	list.insert(20);
	list.insert(23);
	list.insert(35);
	list.insert(15);
	list.insert(36);
	list.insert(30);
	list.insert(38);
	list.insert(10);
	//list.josephus(3, 41);
	list.print();
	cout << endl;
	//list.remove(30);
	list.print();
	cout << endl;
	//list.remove(1);
	list.print();
	cout << endl;
	//list.remove(10);
	//list.remove(15);
	//list.remove(19);
	//list.remove(2);
	list.print();
	cout << endl;


	system("pause");
	return 0;
}
