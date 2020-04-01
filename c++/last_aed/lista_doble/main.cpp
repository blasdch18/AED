#include <iostream>

using namespace std;

class nodo
{
   public:
       nodo()
       {
           siguiente = anterior = 0;
       }
       nodo(int v, nodo *sig = 0, nodo *ant = 0)
       {
           valor = v;
           siguiente = sig ;
           anterior = ant ;
       }
       void print()
       {
        //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
        cout << valor << "°<- -> ";
       }

       int valor;
       nodo *siguiente;
       nodo *anterior;

   //friend class lista;
};

class lista_doble
{
protected:
    nodo * head ,* tail;
public:
    lista_doble()
    {
        head = tail = 0;
    }
    void add_tail(int x1)
    {
        if(tail != 0)
        {
            tail = new nodo(x1 , 0 , tail);
            tail->anterior->siguiente = tail;
        }
        else
        {
            head = tail =new nodo (x1);
        }
    }
    bool buscar(int x1)
	{
		nodo *temp = head;
        int cont = 1;
        int cont2 = 0;

        while (temp) {
            if (temp->valor == x1) {
                cout << "El dato se encuentra en la posici0n: " << cont << endl;
                cont2++;
            }
            temp = temp->siguiente;
            cont++;
            }

        if (cont2 == 0) {
            cout << "No existe el dato " << endl;
        }
        cout << endl;
    }
    int delete_tail()
    {
        int x1 = tail->valor;
        if( head==tail )
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            tail=tail-> anterior;
            delete tail-> siguiente;
            tail->siguiente = 0;
        }
        return x1;
    }
    void print()
	{
		nodo *temp = head;
        if (!head) {
            cout << "La Lista está vacía " << endl;
        } else {
            while (temp) {
                temp->print();
                if (!temp->siguiente) cout << "NULL";
                    temp = temp->siguiente;
            }
        }
        cout << endl << endl;
	}

};

int main()
{
    lista_doble lista;
    cout << "++++++++++++++++++++++ LISTA DOBLEMENTE ENLAZADA +++++++++++++++++++++++ \n";
	cout << "Ingrese tamanho de lista = ";
	int tam;
	cin >> tam;
	for (int i = 0; i<tam; i++)
	{
		int elemento;
		cout << "Ingrese elemento =";
		cin >> elemento;
		lista.add_tail(elemento);
	}
	lista.print();
	lista.delete_tail();
	lista.print();
	int bus;

	cout << "Buscando . . . " ;
	cin>>bus;
	lista.buscar(bus);

    return 0;
}
