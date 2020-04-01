#include <iostream>
#include <windows.h>

const int tam = 1000000, LLEN = 1000000;

/*              Polimorfismo             */

template<class T>
class Cpadre
{
public:
   // Cpadre();
    virtual bool cmp(T a, T b)=0;

};
template<class T>
class Chijo1:public Cpadre<T>
{
public:
  //  Chijo1();
    bool cmp(T a,T b)
    {
        return a<b;
    }
};

template<class T>
class Chijo2:public Cpadre<T>
{
public:
    //Chijo2();
    bool cmp(T a,T b)
    {
        return a>b;
    }
};

template<class T>
class cocktailSort
{
public:
    Cpadre<T> *pointer;

    cocktailSort(Cpadre<T> &h)
    {
        pointer= &h;
    }

    void sort( int* arr, int len )
    {
        bool notSorted = true;
        while( notSorted )
        {
            notSorted = false;
            for( int i = 0; i < len - 1; i++ )
            {
                if( pointer->cmp( arr[i] , arr[i + 1] ))
                {
                    sSwap( arr[i], arr[i + 1] );
                    notSorted = true;
                }
            }

            if( !notSorted ) break;
            notSorted = false;

            for( int i = len - 1; i > 0; i-- )
            {
                if( pointer->cmp( arr[i - 1] , arr[i]) )
                    {
                        sSwap( arr[i], arr[i - 1] );
                        notSorted = true;
                    }
            }
        }
    }

private:
    void sSwap( int& a, int& b )
    {
        int t = a;
        a = b; b = t;
    }
};

int main( )
{
    Chijo1<int> w;
    Chijo2<int> t;
    srand( GetTickCount() );
    int arr[tam];
    cocktailSort<int> cs(t);

    for( int x = 0; x < tam; x++ )
        arr[x] = rand() % tam + 1;

    std::cout << "Original: " << std::endl << "==========" << std::endl;
  /*  for( int x = 0; x < tam; x += LLEN )
        {
        for( int s = x; s < x + LLEN; s++ )
            //std::cout << arr[s] << ", ";

        std::cout << std::endl;
        }
*/
    DWORD now = GetTickCount();
    cs.sort( arr, tam );
    now = GetTickCount() - now;

    std::cout << std::endl << std::endl << "Sorted: " << std::endl << "========" << std::endl;
    /*for( int x = 0; x < tam; x += LLEN )
        {
            for( int s = x; s < x + LLEN; s++ )
            std::cout << arr[s] << ", ";

        std::cout << std::endl;
    }*/

    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << now << std::endl << std::endl;
    return 0;
}
