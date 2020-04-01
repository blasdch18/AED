#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

template <class T>
class nodo
{
public:
    T data ;
    nodo<T>* nodos[2];
    int altura ;
    int balance ;
    nodo(T dato)
    {
        altura=0;
        balance=0;
        data=dato;
        nodos[0]=0;
        nodos[1]=0;
    }
};

template <class Tr>
class avl_adtor
{
public:
    typedef typename Tr :: T T;
    typedef typename Tr :: C C;

    C cmp;
    nodo<T>*root ;
    stack< nodo<T> ** > recorrido;

    avl_adtor()
    {
        root=0;
    }
    bool find (T x, nodo<T> ** &p)
    {
        for( p=&root ; (*p)->data != x ; p=&(*p)->nodos [cmp ( (*p)->data , x )] )
        {
            recorrido.push(p);
        }
        return (*p);
    }
    void inorder ( nodo<T> *p )
    {
        if ( p!=0 )
        {
            inorder( p->nodos[0] );
            cout << p->data << "°";
            inorder( p->nodos[1] );
        }
    }
    void preorder (  nodo<T> *p )
    {
        if ( p!=0 )
        {
            cout << p->data << "°";
            preorder( p->nodos[0] );
            preorder( p->nodos[1] );
        }
    }
    void postorder ( nodo<T> *p )
    {
        if( p!=0 )
        {
            postorder( p->nodos[0] );
            postorder( p->nodos[1] );
            cout << p->data << "°";
        }
    }

    void RR( nodo<T> **&a)
    {
        cout << "RR" << endl;

        nodo<T> *temp;
        temp = (*a);
        (*a) = (*a)->nodos[1] ;
        (temp)->nodos[1] = (*a)->nodos[0];
        (*a)->nodos[0] = temp ;

        preorder(*a);
        cout<< endl;
    }
    void LL ( nodo<T> **&a )
    {
        cout<<"LL"<<endl;
        nodo<T> *temp;
        (temp)=(*a);
        (*a)=(*a)->nodos[0];
        (temp)->nodos[0]=(*a)->nodos[1];
        (*a)->nodos[1]=(temp);
 // recorrido.push(a);
        preorder(*a);
        cout<<endl;arbol1.insert(a);
    arbol1.insert(2);
    }
    void RL ( nodo<T> **&a )
    {
        cout<<"RL"<<endl;
        nodo<T>**t=&(*a)->nodos[0];
        RR(t);
        LL(a);
     //derecha
        cout<<endl;
    }
    void LR ( nodo<T> **&a )
    {
        cout<<"LR"<<endl;
        nodo<T>**t=&(*a)->nodos[1];
        LL(t);
        RR(a);
        cout<<endl;
    }
    int altura (nodo<T> *a)
    {
        if (!a)     { return 0; }
  //cout<<a->data<<" "<<a->altura<<endl;
        return max(altura(a->nodos[0]),altura(a->nodos[1]))+1;
    }

    void Amplitud ()
    {
        queue< nodo<T> *> cola;
        nodo<T> *temp;
        cola.push(root);
        while (! cola.empty())
        {
            temp = cola.front();
            cola.pop();
            cout << temp->data <<"  ";
            if (temp->nodos[0])
                cola.push(temp->nodos[0]);
            if (temp->nodos[1])
                cola.push(temp->nodos[1]);
        }
    }

    void check_balance()
    {
        while( !recorrido.empty() )
        {
            nodo<T> **temp;
            temp=recorrido.top();
            recorrido.pop();

            (*temp)->altura=altura(*temp);
            cout<< (*temp)->data << "°" << (*temp)->altura <<endl;

            (*temp)->balance = altura ((*temp)->nodos[1]) - altura ((*temp)->nodos[0]);
            cout<< (*temp)->data << "°" << (*temp)->balance << endl;

            if( (*temp)->balance == 2 && (*temp)->nodos[1]->balance==-1 )   {LR(temp);}

            if( (*temp)->balance ==-2 && (*temp)->nodos[0]->balance== 1 )   {RL(temp);}

            if( (*temp)->balance == 2 )     {RR(temp);}

            if( (*temp)->balance ==-2 )     {LL(temp);}

            cout <<"--------------------------" <<endl << endl;
            preorder(root);

            cout <<"Amplitud" <<endl;
            Amplitud();
            cout<< endl;
        }
    }

    bool insert ( T x )
    {
        nodo<T> **p;
        if( find (x,p) ) {return 0;}
        *p = new nodo <T> (x) ;
        check_balance();
        return 1;
    }
    bool remove (T x )
    {
        nodo<T>** p;
        nodo<T>* temp;

        if(!find(x,p)) return 0;
        temp=(*p);
        if((*p)->nodos[0] && (*p)->nodos[1])
        {
            for(p=&((*p)->nodos[0]); (*p)->nodos[1]; p=&((*p)->nodos[1]));
            swap((*p)->data,temp->data);
        }
        temp=(*p);
        (*p)=(*p)->nodos[!!(*p)->nodos[1]];
        check_balance();

        delete temp;
        return 1;
    }
};


template<class T>
class fx_dispersion
{
public:
    vector < pair< int ,avl_adtor<T> > > avls( vector < avl_adtor<T> > &t )
    {
        vector<int> alturas_avl;

        for( int i=0 ; i<t.size() ; i++ )
        {
            alturas_avl.insert( alturas_avl.begin() , (t->altura() , t));
        }
        return alturas_avl;
    }
    void quick_sort(vector< pair <int & ,avl_adtor<T> & > > &datos, int bajo, int alto)
    {
        bajo= 0;
        alto= datos.size();
        int a;              /* key holder */
        int up, down;
        int temp;           /*  swapping */

        if (bajo >= alto)
            return;

        a = datos[bajo];
        up = alto;
        down = bajo;

        while (down < up)
            {
                while (datos[down] <= a)         // scan from left to right
                    down++;
                while (datos[up] > a)             // scan from right to left
                    up--;
                if (down < up)
                {
                    temp = datos[down];
                    datos[down] = datos[up];
                    datos[up] = temp;
                }
            }
            datos[bajo] = datos[up];
            datos[up] = a;

            quick_sort(datos, bajo, up-1);
            quick_sort(datos, up+1, alto);
    }
};

template <class T , class F , class A>
class hashing_table
{
public:
    A * tree;
    F * disp;
    int h_size;
    hashing_table(int size)
    {
        h_size = size;
        tree = new A[h_size];
    }
    bool h_insert (T x)
    {
        int id = disp(x) % h_size;
        return tree[id].insert(x);
    }
    bool remove (T x)
    {
        int id = disp(x) % h_size;
        return tree[id].remove(x);
    }
    bool find ( T x )
    {
        int id = disp(x) % h_size;
        return tree[id].find(x);
    }
    void imprimir()
    {
        for(int i=0 ; i < h_size ; i++)
        {
            tree[i].imprimir();
        }
    }
};

template <class T>
class c_less
{
public:
    inline bool operator () (T a , T b)
    {
        return a<b;
    }
};

template <class T>
class c_greater
{
public:
    inline bool operator ()(T a, T b)
    {
        return a>b;
    }
};

class traits
{
public:
    typedef int T;
    typedef c_less<T> C ;
};

int main()
{
    avl_adtor <traits>  arbol1;
    //avl_adtor <traits>  arbol2;
    //avl_adtor <traits>  arbol3;
    //avl_adtor <traits>  arbol4;
    //avl_adtor <traits>  arbol5;

    int a=1;
    arbol1.insert(a);
    arbol1.insert(2);
    arbol1.insert(3);
    arbol1.insert(4);
/*
    for(int i=0 ; i <5 ; i++)
    {
        arbol1.insert(i);
    }*/
    //hashing_table < int , fx_dispersion<int> , avl_adtor< traits > > ht(13);
    cout << "Hello world!" << endl;
    return 0;
}
