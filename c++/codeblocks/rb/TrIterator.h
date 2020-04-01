#ifndef TRITERATOR_H
#define TRITERATOR_H

#include "Routes.h"

using namespace std;

template <typename tr>
struct InOrder
{
    typedef typename tr::N N;
    typedef InOr<N> iterator_move;
};

template <typename tr>
struct PostOrder
{
    typedef typename tr::N N;
    typedef PostOr<N> iterator_move;
};

template <typename tr>
struct PreOrder
{
    typedef typename tr::N N;
    typedef PreOr<N> iterator_move;
};


#endif // TRITERATOR_H
