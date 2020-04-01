#include <iostream>
using namespace std;
class operacion  // functor
{    public:
    int operator() ( int a , int b)
    {return a+b;}
};
template < typename T >
class operador
{private :
    T op;
public:
    void operator () (int *b)
    {
        int temp= *(b+1);
        *(b+1)= op(*b, *(b+1));
        *b= temp;
    }
};
int main()
{
    int *a= new int [2];
    *a= 0;
    *(a+1)=1;
    operador< operacion > tavo;
    for(int i=0; i <=10 ; i++)
    {
        tavo(a);
        cout<<*a<<endl;
    }
    return 0;
}
