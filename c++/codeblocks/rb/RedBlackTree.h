#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "RedBlackNode.h"
#include "RedBlackNode.h"
#include "Iterator.h"
#include "TrIterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

using namespace std;

template<typename tr>
class RedBlackTree
{
    private:

        typedef typename tr::N N;
        typedef typename tr::cmp_type  cmp_type;
        typedef RedBlackNode<N> node_type;

        node_type * root;

        bool find(N e, node_type ** & p, stack<node_type** > &tmp)
        {
            p = &root;
            while(*p)
            {
                tmp.push(p);
                cmp_type cmp;
                int result = cmp(e,(*p)->data);
                if(result ==0)  return true;
                p = & (*p)->sons[result == 1];
            }
            return false;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void print_Inorder(node_type * p)
        {
            if(!p)  return;
            if( (  (p->sons[0]) && p->color == RED && p->sons[0]->color == RED) || ((p->sons[1])  && p->color == RED &&  p->sons[1]->color == RED) )
            {
                cout<<"\n\n ERROR DE INSERCION \n\n";
                return;
            }
            print_Inorder(p->sons[0]);
            cout<< p->data<<" <";
            if(p->sons[0])  cout<<(p->sons[0])->data<<"°";
            else    cout<<"//°";
            cout<<p->color <<"°";
            if(p->sons[1])  cout<<(p->sons[1])->data<<">\t";
            else    cout<<"//>\t";
            print_Inorder(p->sons[1]);
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void r_simple(node_type ** &p ,bool pos)
        {
            node_type * q = *p;
            *p = (*p)->sons[pos];

            if((*p)->sons[!pos])
                (q)->sons[pos] = (*p)->sons[!pos];
            else
                (q)->sons[pos] = NULL;
            (*p)->sons[!pos] =q;

            q=NULL;
            return;
        }


        bool esNegro(node_type* t)
        {
            if( !t || t->color ==BLACK )
                                    return true;
            return false;
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void balance_add(stack<node_type** > &pila)
        {
            node_type ** aux = pila.top();
            pila.pop();
            bool t = 1;
            if( (*pila.top())->sons[0] && (*pila.top())->sons[0] == *aux)
                t = 0;

            if(!esNegro((*pila.top())->sons[!t]))
            {
                (*pila.top())->sons[0]->color = BLACK;
                (*pila.top())->sons[1]->color = BLACK;
                (*pila.top())->color = RED;
                pila.pop();
                return;
            }
            else{
                if(esNegro((*aux)->sons[t]))
                    r_simple(aux,!t);
                r_simple(pila.top(),t);

                (*pila.top())->color = BLACK;
                (*pila.top())->sons[0]->color = RED;
                (*pila.top())->sons[1]->color = RED;
                return;
            }
            return;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public:
        RedBlackTree()
        {
            root = NULL;
            srand(time(0));
        }
/*
        virtual ~RedBlackTree()
        {
            /*node_type * &p = root;
            borrar(p);
            delete p;
                 }
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void print()
        {
            print_Inorder(root);
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool add(N e)
        {
            stack<node_type** > pila;
            node_type ** p;

            if(find(e,p,pila))   return false;
            *p = new node_type(e);

            while( pila.size() > 1  && !esNegro(*pila.top()) )
            {
                balance_add(pila);
            }
            if(root->color == RED)
                root->setColor();

            return true;
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mMayor(stack<node_type** > &pila, node_type** &p)
        {
            node_type ** aux;
            bool t = 1;
            if((*pila.top())->sons[0])
                t = 0;
            aux = & (*pila.top())->sons[t];
            while( (*aux)->sons[!t] )
            {
                pila.push(aux);
                aux = & (*aux)->sons[!t];
            }
            swap((*aux)->data , (*p)->data);
            p = & (*aux);
            if ( (*aux)->sons[t] )
            {
                pila.push(aux);
                swap((*aux)->data,(*aux)->sons[t]->data);
                p = & (*aux)->sons[t];
            }
            return;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        void balance_remove( stack<node_type** > &pila , bool &dNegro)
        {
            if( !esNegro(*pila.top()) )
            {
                (*pila.top())->color = BLACK;
                dNegro = 0;
                return;
            }
            node_type ** aux = pila.top();
            node_type ** q;
            pila.pop();
            bool t = 1;
            if( ((*pila.top())->sons[0] && (*pila.top())->sons[0] == *aux)
               || (!(*aux) && (*pila.top())->sons[1]))    t = 0;


            if(esNegro((*pila.top())->sons[!t]))
            {
                if( esNegro((*pila.top())->sons[!t]->sons[!t]) && esNegro((*pila.top())->sons[!t]->sons[t]))
                {
                    (*pila.top())->sons[!t]->color = RED;
                    return;
                }
                else
                {
                    if( !esNegro((*pila.top())->sons[!t]->sons[t]) && esNegro((*pila.top())->sons[!t]->sons[!t]))
                        {
                            aux = & (*pila.top())->sons[!t];
                            r_simple(aux,t);
                        }
                    colors g = (*pila.top())->color;
                    r_simple(pila.top(),!t);
                    (*pila.top())->color = g;
                    (*pila.top())->sons[0]->color = BLACK;
                    (*pila.top())->sons[1]->color = BLACK;
                    dNegro=0;
                    return;
                }
            }
            else
            {
                q = pila.top();
                r_simple(q,!t);
                (*pila.top())->color = BLACK;
                (*pila.top())->sons[t]->color = RED;
                /*q = & (*q)->sons[t];
                pila.push(q);
                q = & (*q)->sons[t];
                pila.push(q);*/
                pila.push(& (*pila.top())->sons[t]);
                pila.push(& (*pila.top())->sons[t]);
            }
            return;
        }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool remove(N e)
        {
            stack<node_type** > pila;
            node_type ** p;
            node_type * temp;

            if(!find(e,p,pila))     return false;
            if( (*p)->sons[0] || (*p)->sons[1] )
                mMayor(pila,p);
            else pila.pop();
            temp = *p;
            (*p) = NULL;

            pila.push(p);
            if(temp->color == BLACK)
            {
            bool dNegro = 1;
            while(pila.size() > 1 && dNegro)
                balance_remove(pila,dNegro);
            }

            delete temp;
            return true;
        }
};

#endif // REDBLACKTREE_H
