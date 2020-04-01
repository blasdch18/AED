#ifndef ROUTES_H
#define ROUTES_H
#include "RedBlackTree.h"
#include "RedBlackNode.h"

using namespace std;

template <typename N>
class InOr
{
    public:
        typedef RedBlackNode<N> node_type;
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


template <typename N>
class PostOr
{
    public:
        typedef RedBlackNode<N> node_type;
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

template <typename N>
class PreOr
{
    public:
        typedef RedBlackNode<N> node_type;
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
#endif // ROUTES_H
