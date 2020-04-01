#ifndef NODE_H
#define NODE_H
#include <stack>

using namespace std;

template<class T>
class Node
{
    public:
        Node(T);
        T& get_data();
        int& get_high();
        void set_highN(int);
        Node* sons[2];
        virtual ~Node();
    protected:
    private:
    T data;
    int high;
};



template<class T>
Node<T>::Node(T dat)
{
    data=dat;
    sons[0]=NULL;
    sons[1]=NULL;
    high=-1;
}



template<class T>
T& Node<T>::get_data(){
    return data;
}

template<class T>
int& Node<T>::get_high(){
    return high;
}

template<class T>
void Node<T>::set_highN(int dat){
    high=dat;
}

template<class T>
Node<T>::~Node()
{
    //dtor
}


#endif // NODE_H
