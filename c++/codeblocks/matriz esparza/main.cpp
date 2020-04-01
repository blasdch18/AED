#include <iostream>
#include  <vector>
using namespace std;

template<class T>
class Nodo
{
public:
    Nodo(Nodo<T> &p)
    {
        m_dato=p->m_dato;
        coor_x=p->coor_x;
        coor_y=p->coor_y;
        m_child[0] = m_child[1] = 0;
    }
    Nodo(T dato,unsigned int x,unsigned int y)
    {
        m_dato = dato;
        coor_x = x;
        coor_y = y;
        m_child[0] = m_child[1] = 0;
    }
    T m_dato;
    unsigned int coor_x;
    unsigned int coor_y;
    Nodo<T>*m_child[2];// [0] down [1] right
    Nodo<T> *next;

};

template<class T>
class matrix_sparse;    //prototype

template<class T>
class class_temp
{
public:
    unsigned int m_x,m_y;
    matrix_sparse<T>*m_m;

    class_temp( unsigned int &x , unsigned int &y , matrix_sparse<T> *m)
    {
        m_x=x;
        m_y=y;
        m_m=m;
    }

    T operator =(T n)
    {
        cout<<" \n\t++  uso de operator << = >>  ++\n"<<endl;
        Nodo<T> **p,**q;
        if (m_m->find( m_x , p , m_m->m_columnas[m_y] , m_m->headers_filas , 1 ) )
        {
            (*p)->m_dato=n;
            cout<<" ---->repetido \n "<<endl;
            //(*q)->m_dato=n;
        }
        else
        {
            m_m->insertar(n,m_x,m_y);
            //cout<<"entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        }
        //return 0;//no lo encontro lo crea
    }
    operator T ()
    {
        Nodo<T> **p,**q;

        if (m_m->find( m_x , p , m_m->m_columnas[m_y] , m_m->headers_filas , 1) && m_m->find( m_y , q , m_m-> m_filas[m_x] , m_m->headers_columnas , 0 ) );
        return (*p)->m_dato;
    }
};

template<class T>
class matrix_sparse
{
public:

    matrix_sparse *m_m;
    vector<Nodo<T>*> m_columnas;
    vector<Nodo<T>*> m_filas;
    unsigned int m_x;
    unsigned int m_y;

    Nodo<T> *head;//lista

    matrix_sparse( unsigned int , unsigned int );
    bool find( T , Nodo<T>**& , Nodo<T>*& , vector<T> , bool );
    void insertar( T , unsigned int ,unsigned int );
    bool insert_filas( T , unsigned int , unsigned int );
    bool insert_columnas( T , unsigned int , unsigned int);
    bool remove( T );
    void imprimir_columna();
    void imprimir_fila();

    class_temp<T> operator() ( unsigned int x , unsigned int y )
    {
        class_temp<T> t( x , y , m_m ) ;
        return t;
    }

    bool convertion_to_list();

    vector<T> headers_filas;//indices
    vector<T> headers_columnas;
};

template <class T>
bool matrix_sparse<T>::convertion_to_list()
{
    Nodo<T> **p;
    Nodo<T> *w;
    //(*p)=m_filas[0];
    //Nodo<T>*temporal;
	for (int i = 0 ; i < m_x ; i++)
	{
		w= m_filas[i];
		while (w)
		{
		    //w=new Nodo<T>(temporal->m_dato , temporal->coor_x , temporal->coor_y);
            w->next=*p;
            *p=w;
			cout <<"-->" << w->m_dato << "°" << w->coor_x << "|" << w->coor_y ;
			w = w->m_child[0];
		}
	}

    return 1;

}

template <class T>
matrix_sparse<T>::matrix_sparse( unsigned int x , unsigned int y )
{
	m_x = x;
	m_y = y;
	Nodo<T>*ptr = 0;
	head=0;
	/*Cada posicion es un "m_head"*/
	for (int i = 0; i < m_x; i++)
		m_filas.push_back(ptr);

	for (int i = 0; i < m_y; i++)
		m_columnas.push_back(ptr);

	for (int i = 0; i < m_x; i++)
		headers_filas.push_back(i);
	for (int i = 0; i < m_x; i++)
		headers_columnas.push_back(i);
}

template <class T>
bool matrix_sparse<T>::find( T posicion , Nodo<T>**&p ,  Nodo<T>*&m_head , vector<T>cabecera,bool dir )
{
	unsigned int i = 0;
	for ( p = & m_head ; (*p) && posicion > cabecera[i] ; p = &((*p)->m_child[dir]) )
	{
		i++;
	}
	return (*p) && posicion == headers_filas[i];

}

template<class T>
void matrix_sparse<T>::insertar( T dato , unsigned int x , unsigned int y )
{
	insert_columnas( dato , x , y);
	insert_filas   ( dato , x , y);
}

template<class T>
bool matrix_sparse<T>::insert_columnas( T dato , unsigned int x , unsigned int y )
{
	Nodo<T>**p;
	if ( find( x , p , m_columnas[y] , headers_filas , 1 )) return 0;
	Nodo<T>*temp = new Nodo<T>( dato , x , y );
	temp->m_child[1] = (*p);
	*p = temp;
	return 1;
}

template<class T>
bool matrix_sparse<T>::insert_filas( T dato , unsigned int x , unsigned int y )
{
	Nodo<T>**p;
	if (find( y , p , m_filas[x] , headers_columnas , 0 )) return 0;
	Nodo<T>*temp = new Nodo<T>( dato , x , y );
	temp->m_child[0] = (*p);
	*p = temp;
	return 1;
}

template <class T>
void matrix_sparse<T>::imprimir_columna()
{
	Nodo<T>*temporal;
	for (int i = 0 ; i < m_y ; i++)
	{
		temporal = m_columnas[i];
		while (temporal)
		{
			cout << temporal->m_dato << " --> \tx: " << temporal->coor_x << "\ty: " << temporal->coor_y << endl;
			temporal = temporal->m_child[1];
		}
	}
}

template <class T>
void matrix_sparse<T>::imprimir_fila()
{
	Nodo<T>*temporal;
	for (int i = 0 ; i < m_x ; i++)
	{
		temporal = m_filas[i];
		while (temporal)
		{
			cout << temporal->m_dato << " -->\tx: " << temporal->coor_x << " \ty: " << temporal->coor_y << endl;
			temporal = temporal->m_child[0];
		}
	}
}

int main()
{

    matrix_sparse<int> matrix_01(5,3);
    matrix_01.m_m=&matrix_01;

    //matrix_01.insertar(11,0,1);
    //matrix_01.insertar(22,1,2);
    //matrix_01.insertar(33,2,1);
    //matrix_01.insertar(44,4,1);

    cout<<" --------> operador = ";
    int a ;
    //int a= matrix_01(2,1);
    matrix_01(0,1)=8;
    matrix_01(2,1)=9;
    matrix_01(1,2)=1;
    //matrix_01(3,1)=
    a=matrix_01(0,1);
    matrix_01(3,1)=a;


    //cout<<a<<endl;

    cout <<endl<< "\t-->Filas " << endl;
    matrix_01.imprimir_fila();

    cout <<endl<< "\t-->Columnas " << endl;
    matrix_01.imprimir_columna();

    //matrix_01.remove(11);

    cout <<endl<< "\t-->Filas " << endl;
    matrix_01.imprimir_fila();

    cout <<endl<< "\t-->Columnas " << endl;
    matrix_01.imprimir_columna();
    // matrix_01_sparse<int> *p=&x;

   /* matrix_01(2,1)=99;

    a= matrix_01(2,1);
    cout<<" --------> operador = ";
    cout<<a<<endl;

    cout <<endl<< "\t-->Filas " << endl;
    matrix_01.imprimir_fila();

    cout <<endl<< "\t-->Columnas " << endl;
    matrix_01.imprimir_columna();
*/
    cout<<"\n\nLista de nodos"<<endl;
    matrix_01.convertion_to_list();
    cout<<"\n\n";
  return 0;

}
