#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;


enum colors {RED,BLACK};
template < typename data_type>
class RedBlackNode
{
    public:
        template<typename tr> friend class RedBlackTree;
        template<typename tr> friend class InOr;
        template<typename tr> friend class PreOr;
        template<typename tr> friend class PostOr;

        RedBlackNode()
        {
            color = RED;
            sons[0] = NULL;
            sons[1] = NULL;
        }

        RedBlackNode(data_type x) : data(x)
        {
            color = RED;
            sons[0] = NULL;
            sons[1] = NULL;
        }

        RedBlackNode(RedBlackNode & x) : data(x.data),color(x.color)
        {
            sons[0]= x.sons[0];
            sons[1]= x.sons[1];
        }


        void setColor()
        {
            if(color == RED)
            {
                color = BLACK;
                return;
            }
            color = RED;
            return;
        }


        int get_bh()
        {
            return bh;
        }

        virtual ~RedBlackNode() {}

    private:

        data_type data;
        RedBlackNode * sons[2];
        colors color;
        int bh;
};

template<typename tr>
class RedBlackTree
{
    private:

        typedef typename tr::data_type data_type;
        typedef typename tr::cmp_type  cmp_type;
        typedef RedBlackNode<data_type> node_type;

        node_type * root;

        bool find(data_type e, node_type ** & p, stack<node_type** > &tmp)
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
            cout<< p->data<<"(";
            if(p->sons[0])  cout<<(p->sons[0])->data<<",";
            else    cout<<"sn,";
            cout<<p->color <<",";
            if(p->sons[1])  cout<<(p->sons[1])->data<<")   ";
            else    cout<<"sn)   ";
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

        virtual ~RedBlackTree()
        {
            /*node_type * &p = root;
            borrar(p);
            delete p;*/
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void print()
        {
            print_Inorder(root);
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool add(data_type e)
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
        bool remove(data_type e)
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

template <typename data_type>
class InOr
{
    public:
        typedef RedBlackNode<data_type> node_type;
        void operator()(node_type * &p,stack<node_type *> & q)
        {
            if((p)->sons[1])
            {
                p =  & * p->sons[1];
                while((p)->sons[0])
                {
                    q.push(p);
                    p =  & * p->sons[0];
                }
                return;
            }

            if(!p->sons[1] && q.empty())
            {
                    p = NULL;
                    return;
            }
            p=q.top();
            q.pop();
            return;
        }

};


template <typename data_type>
class PostOr
{
    public:
        typedef RedBlackNode<data_type> node_type;
        void operator()(node_type * &p,stack<node_type *> & q)
        {
                if( q.empty())
                {
                    p = NULL;
                    return;
                }

                if(q.top()->sons[1] && q.top()->sons[1] != p)
                {
                    p = &* q.top()->sons[1];
                    while((p)->sons[0] || (p)->sons[1])
                    {
                        q.push(p);
                        if((p)->sons[0])
                            p =  (p)->sons[0];
                        else
                            p =  (p)->sons[1];
                    }
                    return;
                }
                p=q.top();
                q.pop();
                return;
        }

};

template <typename data_type>
class PreOr
{
    public:
        typedef RedBlackNode<data_type> node_type;
        void operator()(node_type * &p,stack<node_type *> & q)
        {
           if(p->sons[1])
           {
               q.push(p->sons[1]);
           }
           if(p->sons[0])
            {
                p= &* p->sons[0];
                return;
            }
            if(!p->sons[1] && q.empty())
            {
                    p = NULL;
                    return;
            }

           p=q.top();
           q.pop();


        }

};


template <class T>
class More
{
    public:
        More() {}
        virtual ~More() {}

        int operator()(const T &x , const T &y)
        {
            if(x<y)     return -1;
            if(x>y)     return 1;
            return 0;
        }
    protected:
    private:
};


template <typename T>
struct AscTreeTrait
{
    typedef T data_type;
    typedef More<data_type> cmp_type;
};

template <typename tr>
struct InOrder
{
    typedef typename tr::data_type data_type;
    typedef InOr<data_type> iterator_move;
};

template <typename tr>
struct PostOrder
{
    typedef typename tr::data_type data_type;
    typedef PostOr<data_type> iterator_move;
};

template <typename tr>
struct PreOrder
{
    typedef typename tr::data_type data_type;
    typedef PreOr<data_type> iterator_move;
};


template <typename tr>
class Iterator
{
    private:
        template<typename T> friend class InOr;
        template<typename T> friend class PreOr;
        template<typename T> friend class PostOr;
        typedef typename tr::data_type data_type;
        typedef typename tr::iterator_move iterator_move;
        typedef RedBlackNode<data_type> node_type;

        stack<node_type* > ref;
        node_type * current;
        iterator_move move;

    public:

        Iterator(): current(NULL)  {}
        Iterator(const Iterator & it) : current(it.current),ref(it.ref) {}
        Iterator(node_type *p) : current(p)   {}
        Iterator(node_type * p , stack<node_type* > temp) : current(p),ref(temp)   {}

        virtual ~Iterator() {}


            const Iterator & operator = (const Iterator & it)
            {
              current=it.current;
              ref=it.ref;
                return * this;
            }


            bool operator ==(const Iterator &it)
            {
                return current == it.current;
            }

            bool operator !=(const Iterator &it)
            {
                return current != it.current;
            }

            Iterator operator ++(int)
            {
                move(current,ref);
                return * this;
            }

            data_type operator*() const
            {
                return current->get_data();
            }

};

int main()
{
    RedBlackTree<AscTreeTrait<int> > arbol;
    /*arbol.add(8);
    arbol.add(69);
    arbol.add(0);
    arbol.add(64);
    arbol.add(28);
    arbol.add(11);
    arbol.add(46);
    arbol.add(14);
    arbol.add(60);
    arbol.add(100);
    arbol.add(1);
    arbol.add(7);
    arbol.add(20);
    arbol.add(21);
    arbol.add(55);
    arbol.add(70);
    arbol.add(24);*/
    int f;
    for(int a = 0 ; a < 1000 ; a++)
        {for(int i = 1 ; i< 1000000 ;i++){
            f=rand()%100000;
            //cout<<f<<endl;
            arbol.add(f);
           // arbol.print();
        }
        //arbol.print();
        /*for(int j = 1 ; j< 3000 ;j++)
        {
            int t= (rand()%1000);
            //cout<<endl<<t<<endl;
            //cout<< t<<endl;
            //arbol.print();
            arbol.remove(t);
        }*/
        }

    cout<<endl<<endl;
    arbol.print();
    return 0;
}
