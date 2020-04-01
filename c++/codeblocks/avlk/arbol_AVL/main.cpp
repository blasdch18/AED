#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

template<class T>
struct nodo{

    T data;
    nodo<T>* nodos[2];
    int altura;
    int balance;

    nodo(T dato){

        altura=0;
        balance=0;
        data=dato;
        nodos[0]=0;
        nodos[1]=0;
    }
};


template<class Tr>
class arbol_binario
{
    public:

        arbol_binario();
        typedef typename Tr::T T;
        typedef typename Tr::C C;
        stack<nodo<T>**> recorrido;

        bool find(T , nodo<T>**&);
        int  altura(nodo<T>*);
        bool insert(T);
        bool remove(T);
        void inorden(nodo<T>*);
        void postorden(nodo<T>*);
        void preorden(nodo<T>*);
        void Amplitud();
        void RR(nodo<T>**&);
        void LL(nodo<T>**&);
        void RL(nodo<T>**&);
        void LR(nodo<T>**&);
        void check_balance();
       // void verArbol(arbol_binario, T n);

        C m_cmp;
        nodo<T>*root;

};

template<class Tr>
arbol_binario<Tr>::arbol_binario()
{
    root=0;
}

template<class Tr>
void arbol_binario<Tr>::check_balance()
{
  while (!recorrido.empty()) {

      nodo<T>**temp;
      temp=recorrido.top();
      recorrido.pop();

      (*temp)->altura=altura(*temp);
      cout<<(*temp)->data<<"°alt°"<<(*temp)->altura<<endl;
      (*temp)->balance=altura((*temp)->nodos[1])-altura((*temp)->nodos[0]);
      cout<<(*temp)->data<<"°bal°"<<(*temp)->balance<<endl;

      if((*temp)->balance==2 && (*temp)->nodos[1]->balance==-1)   LR(temp);
      if((*temp)->balance==-2 && (*temp)->nodos[0]->balance==1)   RL(temp);
      if((*temp)->balance==2)                                       RR(temp);
      if((*temp)->balance==-2)                                      LL(temp);

      cout<<"-- --------------++++++++-------------- --"<<endl<<endl;

      preorden(root);
      cout<<endl<<"     Amplitud"<<endl;
      Amplitud();
      cout<<endl;
    }

  cout<<"--------**-------"<<endl;
  return;
}

template<class Tr>

bool arbol_binario<Tr>::find(T x, nodo<T>**&p)
{
    for(p=&root ; (*p) && (*p)->data!=x ; p=&(*p)->nodos[ m_cmp((*p)->data,x)])
    {
        recorrido.push(p);
    }
    return (*p);
}

template<class Tr>

bool arbol_binario<Tr>::insert(T x)
{
    nodo<T>**p;

    if(find(x,p)) return 0;

    *p=new nodo<T>(x);

    check_balance();
    return 1;
}

template<class Tr>

bool arbol_binario<Tr>::remove(T x)
{
    nodo<T>** p;
    nodo<T>* temp;

    if(!find(x,p)) return 0;
    temp=(*p);
    if((*p)->nodos[0] && (*p)->nodos[1]){

        for(p=&((*p)->nodos[0]); (*p)->nodos[1]; p=&((*p)->nodos[1]));
        swap((*p)->data,temp->data);
    }
    temp=(*p);
    (*p)=(*p)->nodos[!!(*p)->nodos[1]];
    check_balance();

    delete temp;
    return 1;
}

//IRD inorder
//RID preorder
//IDR postorder
template<class Tr>

void arbol_binario<Tr>::inorden(nodo<T> *p)
{
    if(p!=0){

        inorden(p->nodos[0]);
        cout<<p->data<<"°";
        inorden(p->nodos[1]);
    }
}

template<class Tr>

void arbol_binario<Tr>::preorden(nodo<T> *p)
{
    if(p!=0){
        cout<<p->data<<"°";
        preorden(p->nodos[0]);
        preorden(p->nodos[1]);
    }
}

template<class Tr>

void arbol_binario<Tr>::postorden(nodo<T> *p)
{
    if(p!=0){

        postorden(p->nodos[0]);
        postorden(p->nodos[1]);
        cout<<p->data<<"°";
    }
}

template<class Tr>
void arbol_binario<Tr>::Amplitud()
{
    queue< nodo<T> *> cola;
    nodo<T> *temp;
    cola.push(root);
    cout<<"root -> ";
    while (! cola.empty())
    {
        temp = cola.front();
        cola.pop();
        cout << temp->data <<"  ";
        if (temp->nodos[0])
        {
            cola.push(temp->nodos[0]);
        }

        if (temp->nodos[1])
        {
            cola.push(temp->nodos[1]);


    }
}}

template<class Tr>
int arbol_binario<Tr>::altura(nodo<T> *a)
{
  if (!a)
    {
      return 0;
    }
  return max(altura(a->nodos[0]),altura(a->nodos[1]))+1;
}

template<class  Tr>
void arbol_binario<Tr>::RR(nodo<T> **&a)
{
    cout<<"RR---->";

    nodo<T> *temp;
    temp=(*a);
    (*a)=(*a)->nodos[1];
    (temp)->nodos[1]=(*a)->nodos[0];
    (*a)->nodos[0]=temp;
    //recorrido.push(a);
    preorden(*a);

  //derecha
    cout<<endl;
}

template<class  Tr>
void arbol_binario<Tr>::LL(nodo<T> **&a)
{
    cout<<"LL---->";
    nodo<T> *temp;
    (temp)=(*a);
    (*a)=(*a)->nodos[0];
    (temp)->nodos[0]=(*a)->nodos[1];
    (*a)->nodos[1]=(temp);
 // recorrido.push(a);
    preorden(*a);
    cout<<endl;
     //derecha
}

template<class  Tr>
void arbol_binario<Tr>::RL(nodo<T> **&a)
{
    cout<<"RL---->";

    nodo<T>**t=&(*a)->nodos[0];
    RR(t);
    LL(a);
        //derecha
    cout<<endl;

}

template<class  Tr>
void arbol_binario<Tr>::LR(nodo<T> **&a)
{
    cout<<"LR---->";

    nodo<T>**t=&(*a)->nodos[1];
    LL(t);
    RR(a);
    cout<<endl;
     //derecha
}
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

    arbol_binario<traits> arbol;

    int a,b,c,d,e,f,g,h,i,j,k,w;

    a=1;
    b=7;
    c=3;
    d=8;
    e=2;
    f=9;
    g=6;
    h=5;
    i=4;
    //j=10;
    //k=33;


    arbol.insert(a);
    arbol.insert(b);
    arbol.insert(c);
    arbol.insert(d);
    arbol.insert(e);
    arbol.insert(f);
    arbol.insert(g);
    arbol.insert(h);
    arbol.insert(i);
    //arbol.insert(j);
    //arbol.insert(k);

  //  arbol.inorden(arbol.root);

    arbol.Amplitud();
    //arbol.verArbol(arbol,5);
    cout<<endl;
   // arbol.remove(c);
   // cout<<"Amplitud"<<endl;
    cout<<endl;
    //arbol.Amplitud();



    return 0;
}
