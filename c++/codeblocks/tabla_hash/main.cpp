#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

template <class T>
class ListAdtor
{
public:
   vector<T> l;

   bool find(T x)
   {
       for(int i=0; i<l.size();i++)
       {
           if(l[i]==x) return 1;
       }
       return 0;
   }

   bool insert(T x)
   {
       if(find(x)) return 0;
       l.push_back(x);
       return 1;
   }

   bool remove(T x)
   {
       if(!find(x))return 0;
       l.remove(x);
       return 1;
   }

   void imprimir()
   {
       for(int i=0; i<l.size();i++)
       {
           cout<<l[i]<<endl;
       }
   }
};

template <class T>
class Fx_Disper
{
public:
///metodo de compresion, ascii

    vector<int> binario(int num)
    {
        vector<int>binarios;
        int base=2;
        while(num>=2)
        {
            binarios.insert(binarios.begin(),num%base);
            num=num>>1;
        }
        binarios.insert(binarios.begin(),num);
        return binarios;
    }

    int convert_to_decimal(vector<int> numero)///GENERA EL ALEATORIO EN DECIMAL
    {
        int num_decimal;
        long base=2;
        num_decimal=0;
        long tam=numero.size()-1;
        long i;
        for( i=0; i<=tam;i++)
        {
            if(numero[i]==1)
            {
                num_decimal+=pow(base,tam-i);
            }
        }
        //si es multiplo de 5 lo paso
        if(num_decimal%5==0)
        {
            num_decimal=num_decimal+2;
        }
        return num_decimal;
    }

    int operator()(T num)
    {
        int aux=0;
        vector< vector<int> > contenedor;
        for(int i=0;i<num.size();i++)
        {
            aux=num[i];//caracter ascii
          //  cout<<"numero: "<<aux<<endl;
            contenedor.push_back(binario(aux));
            while(contenedor[i].size()<8)
            {
                contenedor[i].insert(contenedor[i].begin(),0);
            }
        }
        //hacer el xor de
        int resultado=0;
        vector<int> adecimal;
        for(int u=0;u<contenedor[0].size();u++)
        {
            resultado=0;
            for(int w=0;w<contenedor.size();w++)
            {
               // cout<<"DE: "<<w<<" palabra "<<u<<" posicion "<<contenedor[w][u]<<endl;
                 resultado= resultado ^(contenedor[w][u]);

            }
               // cout<<resultado;
            adecimal.push_back(resultado);
        }
        aux=convert_to_decimal(adecimal);
      //  cout<<"este es aux: "<<aux<<endl;
        return aux;
     }
};

template<class T,class F, class E>
class c_HashTable
{
public:
    E *m_ht;
    F m_f;
    int m_size;

    c_HashTable(int size)
    {
        m_size=size;
        m_ht=new E[m_size];
    }

    bool _insert(T x)
    {
        int id=m_f(x)%m_size;
        cout<< x <<" -> "<<id<<endl;
        return m_ht[id].insert(x);
    }

    bool remove(T x)
    {
        int id=m_f(x)%m_size;
        return m_ht[id].remove(x);
    }

    bool find(T x)
    {
        int id=m_f(x)%m_size;
        return m_ht[id].find(x);
    }

    void imprimir()
    {
        for(int i=0; i<m_size;i++)
        {
            m_ht[i].imprimir();
        }
    }
};

int main()
{
    c_HashTable< string , Fx_Disper<string> , ListAdtor< string > > ht(13);
    ht._insert("david");
    ht._insert("amigos");
    ht._insert("programadores");
    ht.imprimir();
    return 0;
}

