#ifndef ITERATOR_H
#define ITERATOR_H
#include <stack>
#include "RedBlackNode.h"
#include "TrIterator.h"

using namespace std;

template <typename tr>
class Iterator
{
    private:
        template<typename T> friend class InOr;
        template<typename T> friend class PreOr;
        template<typename T> friend class PostOr;
        typedef typename tr::N N;
        typedef typename tr::iterator_move iterator_move;
        typedef RedBlackNode<N> node_type;

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

            N operator*() const
            {
                return current->get_data();
            }



};

#endif // ITERATOR_H
