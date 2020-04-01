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
	numeros_.mostrar();
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
	numeros.print();

	system("pause");
}