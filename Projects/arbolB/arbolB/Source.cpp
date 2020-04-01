#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template<class T>
struct nodo
{
	T info;
	nodo <T> *left_link;
	nodo <T> *right_link;
};

template <class T>
class arbol_binario
{
private:
	nodo<T> *root;
	public:
		arbol_binario() {
			root = NULL;
		}


		void insert(T & item) {// --------------------------------------------
			nodo<T> * current;
			nodo<T> * trail_current = 0;
			nodo<T> * new_nodo;
			new_nodo = new nodo<T>;
			assert(new_nodo != NULL);
			new_nodo->info=item;
			new_nodo->left_link = NULL;
			new_nodo->right_link = NULL;
			if (root == NULL) {
				root = new_nodo;
			}
			else {
				current = root;
				while (current != NULL) {
					trail_current = current;
					if (current->info == item) {
						cout << "El item insertado esta listo en la lista -";
						cout << "Duplicar no esta permitido." << item << endl;
						return;
					}
					else if (current->info < item) {
						current = current->left_link;
					}
					else {
						current = current->right_link;
					}
				}//fin while
				if (trail_current->info > item) {
					trail_current->left_link = new_nodo;
				}
				else {
					trail_current->right_link = new_nodo;
				}
			}
		}//fin insert ---------------------------------------------------------------------------------


		bool search(T & item) {
			nodo<T> * current;
			bool found = false;
			if (root == NULL) {
				cout << "No se puede buscar en un arbol vacio" << endl;
			}
			else {
				current = root;
				while (current != NULL &&!found) 
				{
					if (current->info == item) {
						found = true;
					}
					else if (current->info > item) {
						current = current->left_link;
					}
					else {
						current = current->right_link;
					}
				}//fin while
			}return found;
		}// fin bool search--------------------------------------------------------------------------------
		void delete_Tree(arbol_binario<T>* &p)
		{
			arbol_binario<T> *current;//pointer to traverse the tree
			arbol_binario<T> *trailCurrent; //pointer behind current
			arbol_binario<T> *temp; //pointer to delete the node
			if (p == NULL)
				cerr << "Error: El nodo que sera borrado esta NULL." << endl;
			else if (p->left_link == NULL && p->right_link == NULL)
			{
				temp = p;
				p = NULL;
				delete temp;
			}
			else if (p->left_link == NULL)
			{
				temp = p;
				p = temp->right_link;
				delete temp;
			}
			else if (p->right_link == NULL)
			{
				temp = p;
				p = temp->left_link;
				delete temp;
			}
			else
			{
				current = p->left_link;
				trailCurrent = NULL;
				while (current->right_link != NULL)
				{
					trailCurrent = current;
					current = current->right_link;
				}//end while
				p->info = current->info;
				if (trailCurrent == NULL) //current did not move;
										  //current == p->llink; adjust p
					p->left_link = current->left_link;
				else
					trailCurrent->right_link = current->left_link;
				delete current;
			}//end else
		}//end deleteFromTree
	
		void delete_nodo( T & item) {
			nodo<T> *current;
			nodo<T> *trailcurrent;
			bool found = false;
			if (root == NULL)
			{
				cout << "No se puede borrar desde un arbol vacio" << endl;
			}
			else
			{
				current = root;
				trailcurrent = root;
				while (current != NULL && !found)
				{
					if (current->info == item)
					{
						found = true;
					}
					else
					{
						trailcurrent = current;
						if (current->info > item)
						{
							current = current->left_link;
						}
						else
						{
							current = current->right_link;
						}
					}

				}//fin while
				if (current == NULL) {
					cout << "El item no esta en el arbol" << endl;
				}
				else if (found) {
//					if (current == root)
						//delete_Tree(root);
					else if (trailcurrent->info > item)
						delete_Tree(trailcurrent->left_link);
					else
						delete_Tree(trailcurrent->right_link);
				}
			}

		}
		//~arbol_binario();

};

int main()
{
	int num = 0;
	int num1 = 5;
	int num2 = 8;
	int num3 = 2;
	int num4 = 9;
	int num5 = 33;
	arbol_binario <int> arbolito_nectar;
	while (num < 101)
	{
		arbolito_nectar.insert(num);
		num++;
	}
	
	cout<<arbolito_nectar.search(num2)<<endl;
	arbolito_nectar.delete_nodo(num5);
	

	system("pause");
}