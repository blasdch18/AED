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
	void print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << num << "°-> ";
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
	bool buscar(int x1)
	{
		nodo *temp = head;
        int cont = 1;
        int cont2 = 0;

        while (temp) {
            if (temp->num == x1) {
                cout << "El dato se encuentra en la posici0n: " << cont << endl;
                cont2++;
            }
            temp = temp->next;
            cont++;
            }

        if (cont2 == 0) {
            cout << "No existe el dato " << endl;
        }
        cout << endl;
    }

    void remove_nodo(int x1)
	{
    nodo *temp = head;
    nodo *temp1 = head->next;

    int cont = 0;

    if (head->num == x1) {
        head = temp->next;
    } else {
        while (temp1) {
            if (temp1->num == x1) {
                nodo *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                //m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
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
		nodo *temp = head;
        if (!head) {
            cout << "La Lista está vacía " << endl;
        } else {
            while (temp) {
                temp->print();
                if (!temp->next) cout << "NULL";
                    temp = temp->next;
            }
        }
        cout << endl << endl;
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
	//numeros_.mostrar();
	numeros_.print();
	/*
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


	//system("pause");

    int bus;

    cout<<endl<<"quitando .. ";
    int quito;
    cin>>quito;
    numeros.remove_nodo(quito);
    //numeros.mostrar();
    numeros.print();
    cout<<endl<<"buscanndo .. ";
	cin>>bus;
	numeros.buscar(bus);
    numeros.print();
    cout<<endl;

}
