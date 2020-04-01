#include <iostream>


using namespace std;

class nodo
{
public:
	int num;
	nodo *next;
	nodo()
	{
		next = 0;
	}
	nodo(int x1, nodo*sgte = 0)
	{
		num = x1;
		next = sgte;
	}
};
class lista
{
private:
	nodo * head, *tail;
public:
	lista() 
	{ 
		head = tail = 0; 
	}
	void add_head(int x1)
	{
		head = new nodo(x1, head);
		if (tail == 0)
		{
			tail = head;
		}
		//cout<<"&="<<&(head)<<endl;
	}
	void add_tail(int x1)
	{
		if (tail != 0)
		{
			tail->next = new nodo(x1);
			tail = tail->next;
		}
	}
	int buscar(int x1)
	{ 
		nodo *tmp= head;
		while ( tmp != 0 && !(tmp->num == x1) );
		tmp = tmp->next;
		return tmp != 0;
	}

    



	void mostrar()
	{
		int elemt = 1;
		while (head)
		{
			cout << "Elem " << elemt << "=" << head->num << "\t direccion=" << &(head->num) << endl;
			elemt++;
			head = head->next;
		}
	}
	void print()
	{
		nodo*p;
		int elemt = 1;
		for (p = head; p; p = p->next) {
			cout << "Elem " << elemt << "=" << p->num << "\t direccion=" << &(p->num) << endl;
			elemt++;
		}
	}
	void remove_nodo(int x1)
	{
		if (head != 0) //  si no es lista vacia
		{
			if (head == tail && x1 == head->num) //si solo un nodo esta en la lista)
			{
				delete head;
				head = tail = 0;
			}
			else if (x1 == head->num)// si mas de uno nodo esta en la lista
			{
				nodo * tmp = head->next;
				head = head->next;
				delete tmp; // una vieja cabeza es borrada
			}
			else
			{
				nodo * pred, *tmp;
				for (pred = head, tmp = head->next; //agrega un nodo no cabeza
					tmp != 0 && !(tmp->num == x1); // es borrado 
					pred = pred->next, tmp = tmp->next);
				if (tmp != 0)
				{
					pred->next = tmp->next;
					if (tmp == tail)
						tail = pred;
					delete tmp;
				}

			}
		}
	}
	void invertir()
		{
			int elemt = 1;
			nodo *prev = NULL;
			nodo *next = NULL;
			nodo *temp = head;
			while (temp)
			{
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			head = prev;
			/*while (head)
			{
				cout << "Elem " << elemt << "=" << head->num << "\t direccion=" << &(head->num) << endl;
				elemt++;
				head = head->next;
			}*/
		}



};

int main()
{
	lista numeros;
	cout << "++++++++++++++++++++++ LISTA +++++++++++++++++++++++ \n";
	cout << "Ingrese tamaño de lista = ";
	int tam;
	cin >> tam;
	for (int i = 0; i<tam; i++)
	{
		int elemento;
		cout << "Ingrese elemento =";
		cin >> elemento;
		numeros.add_head(elemento);
	}
	lista numeros_ = numeros;
	cout << "Lista Actual \n";
	numeros_.mostrar();/*
	cout << endl << "Lista invertida:" << endl;
	system("pause");
	numeros.invertir();
	numeros.print();
	system("pause");
	cout << "\nOtra vez1\n";
	numeros.invertir();
	numeros.print();
	system("pause");
	cout << "\nOtra vez2\n";
	numeros.invertir();
	numeros.print();
	system("pause");
	cout << "\nOtra vez3\n";
	numeros.invertir();
	numeros.print();*/


	system("pause");

	cout<<endl<<"buscanndo .. "<<numeros_.buscar(7);

}