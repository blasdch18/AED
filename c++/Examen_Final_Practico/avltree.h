#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "avlstack.h"

using namespace std;
int c=0;

template<class T>
class Cnode
{
public:
    T m_data;

    Cnode<T> *m_children[2]; ///0 apunta hacia la izquierda 1 apunta hacia la derecha
    Cnode(T x)
    {
        m_data = x;
        m_children[0] = m_children[1] = NULL;
        m_nivel =1;
    }
    int m_nivel;
};

template<class T>
class CAvlTree
{
public:
    ///datos
    Cnode<T> *m_root;

    ///funciones
    CAvlTree(){m_root = NULL;}

    ///buscar
    bool lookFor(T x, Cnode<T> ** &p,CStack<Cnode<T> **> &camino)
    {

        for(p=&m_root;!!(*p) && (*p)->m_data != x;p=&(*p)->m_children[x>(*p)->m_data]){
            camino.push(p);
        }
        return !!(*p);
    }

    bool find(T x, Cnode<T> ** &p)
    {
        for(p=&m_root;!!(*p) && (*p)->m_data != x;p=&(*p)->m_children[x>(*p)->m_data]){}
        return !!(*p);
    }

    ///insertar
    bool inserteichon(T x)
    {

        Cnode<T> **p;
        CStack<Cnode<T> **> camino;
        T sub = x;
        //--insercion--//

        if(lookFor(sub,p,camino)){
            return 0;
        }
        Cnode<T> *n = new Cnode<T>(x);
        *p = n;


        //--proceso de reequilibrio y reajustado de niveles
        equilibration(camino);

        return 1;
    }

    ///eliminar
    bool deleteichon(T x)
    {
        Cnode<T> **p;
        CStack<Cnode<T> **> camino;
        if(!lookFor(x,p,camino))return 0;
        Cnode<T> *n;
        if(!!(*p)->m_children[0] && !!(*p)->m_children[1])
        {
            Cnode<T> **q = rep(p);
            (*p)->m_data = (*q)->m_data;
            p=q;
        }
        Cnode<T> *d;
        *p = (*p)->m_children[(*p)->m_children[0] == 0];
        delete d;
        return 1;
    }
    ///funcion auxiliar para eliminar
    Cnode<T>** rep(Cnode<T> **p)
    {
        Cnode<T> **q;
        q= &(*p)->m_children[1];
        while(!!(*q)->m_children[0])
            q = &(*q)->m_children[0];
        return q;
    }

    ///funcion imprimir mandando orden
    void print(Cnode<T> *p,string orden) //1 imprimir // 2 hijoizq 3 hijo der
    {
        if(!p)return;
        int fase=0;
        while(fase<3)
        {
            if(orden[fase] == '1')
            {
                cout << p->m_data << " ";
            }
            else if(orden[fase] == '2')
            {
                print(p->m_children[0],orden);
            }
            else if(orden[fase] == '3')
            {
                print(p->m_children[1],orden);
            }
            fase++;
        }
    }
    void print_In_Tree(Cnode<T> *p)
    {
        if(!p)return;
        if(p->m_children[0] && p->m_children[1])
        {
            cout <<"    P-"<< p->m_data << " "<<endl;
            cout <<"HI-"<<p->m_children[0]->m_data <<"   HD-"<<p->m_children[1]->m_data<<endl;
            cout <<".............."<<endl;
            print_In_Tree(p->m_children[0]);
            print_In_Tree(p->m_children[1]);

        }
        else if(p->m_children[0] && !p->m_children[1])
        {
            cout <<"    P-"<< p->m_data << " "<<endl;
            cout <<"HI-"<<p->m_children[0]->m_data<<"  "<<endl;
            cout <<".............."<<endl;
            print_In_Tree(p->m_children[0]);

        }
        else if(!p->m_children[0] && p->m_children[1])
        {
            cout <<"    P-"<< p->m_data << " "<<endl;
            cout <<"       HD-"<<p->m_children[1]->m_data<<"  "<<endl;
            cout <<".............."<<endl;
            print_In_Tree(p->m_children[1]);
        }

    }
    ///funcion de altura
    int height(Cnode<T> *p)
    {

        if(!p)return 0;
        return max_f(height(p->m_children[0])+1,height(p->m_children[1])+1);
    }
    ///funcion de ayuda para la altura
    int max_f(int a,int b)
    {
        if(a>b)return a;
        return b;
    }
    ///funciones propias del avl
    ///rotacion a la izquierda
    void rotateLeft(Cnode<T> **p)
    {
        ///actualizando los niveles
        if(!!(*p)->m_children[1]->m_children[1])
            (*p)->m_nivel = (*p)->m_children[1]->m_nivel-1;

        /* int l = (*p)->m_nivel;
            (*p)->m_nivel = (*p)->m_children[1]->m_nivel;
            (*p)->m_children[1]->m_nivel =l;*/

        //rotacion
        Cnode<T> *q =*p;
        *p = (*p)->m_children[1];
        q->m_children[1] = (*p)->m_children[0];
        (*p)->m_children[0]=q;
    }
    ///rotacion a la derecha
    void rotateRight(Cnode<T> **p)
    {
        ///actualizando los niveles
        if(!!(*p)->m_children[0]->m_children[0])
            (*p)->m_nivel = (*p)->m_children[0]->m_nivel-1;

        int l = (*p)->m_nivel;
        (*p)->m_nivel = (*p)->m_children[0]->m_nivel;
        (*p)->m_children[0]->m_nivel =l;

        //rotacion
        Cnode<T> *q = *p;
        *p = (*p)->m_children[0];
        q->m_children[0] = (*p)->m_children[1];
        (*p)->m_children[1]=q;
    }
    ///funcion para verificar el balanceo
    int balance(Cnode<T> *p)
    {
        ///funcion que retorna :
        /// 0  si sus dos hijos tienen la misma altura
        ///1 si su hijo derecho es un nivel mas alto
        ///-1 si su arbol izquierdo es un nivel ams alto
        ///cualquier otro numero si el arbol esta desbalanceado (generalmente es 2 o -2)

        int n_izq,n_der;
        if(!p->m_children[0])
            n_izq = 0;
        else
            n_izq = p->m_children[0]->m_nivel;
        if(!p->m_children[1])
            n_der = 0;
        else
            n_der = p->m_children[1]->m_nivel;

        return n_der - n_izq;
    }
    ///funcion de equilibrio
    void equilibration(CStack<Cnode<T> **> &camino)
    {
        int n_balance,n_hijo_balance;
        Cnode<T> **p;
        int n_act_nivel= 2; ///se inicializa en dos por que el vector de nodos empieza a actuar desde el padre del nodo insertado osea nivel 2
        while(!!camino.head)
        {
            p=camino.head->m_data;
            /*if((*p)->m_children[0] && (*p)->m_children[1])
                {
                    camino.pop();
                    (*p)->m_nivel = n_act_nivel;
                    n_act_nivel++;
                    continue;
                }*/
            //actualizacion de nivel
            if(n_act_nivel <= (*p)->m_nivel)
                n_act_nivel=(*p)->m_nivel;
            (*p)->m_nivel = n_act_nivel;


            ///sacando balances de hijo y padre para saber cual rotacion usar
            n_balance = balance(*p);
            n_hijo_balance = balance((*p)->m_children[!!(*p)->m_children[1]]);

            ///casos
            if(n_balance>1)
            {
                if(n_hijo_balance>0)
                {

                    rotateLeft(p);

                }
                else
                {
                    rotateRight(&(*p)->m_children[1]);
                    rotateLeft(p);
                }

            }
            else if(n_balance<-1)
            {
                if(n_hijo_balance<0)
                {
                    rotateRight(p);
                }
                else
                {
                    rotateLeft(&(*p)->m_children[0]);
                    rotateRight(p);
                }

            }
            camino.pop();
            n_act_nivel++;
        }///finaliza el for
    }///finaliza la funcion de equiibrio

}; ///finaliza la clase avltree

#endif // AVLTREE_H_INCLUDED
