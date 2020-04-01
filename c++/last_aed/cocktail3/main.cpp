#include <iostream>
#include <windows.h>

const int tam = 100000    , LLEN = 100000;

/*        FUNCTORES                */

class operacion
{
public:
    inline bool operator ()(int a , int b)
    {
        return a>b;
    };
};


/*
template<class T>
bool Cless( T a , T b)
    {
        return a<b ;
    }
template<class T>
    bool Cgreater( T a , T b)
    {
        return a>b ;
    }
  //return 1;

*/
template<class T>
class cocktailSort
{
public:
    void sort( int* arr, int len )
    {
        bool notSorted = true;
        while( notSorted )
        {
            notSorted = false;
            for( int i = 0; i < len - 1; i++ )
            {
                if( op( arr[i] , arr[i + 1] ) )
                {
                    sSwap( arr[i], arr[i + 1] );
                    notSorted = true;
                }
            }

            if( !notSorted ) break;
            notSorted = false;

            for( int i = len - 1; i > 0; i-- )
            {
                if( op( arr[i - 1] , arr[i]) )
                    {
                        sSwap( arr[i], arr[i - 1] );
                        notSorted = true;
                    }
            }
        }
    }
private:
    T op;
    void sSwap( int& a, int& b )
    {
        int t = a;
        a = b; b = t;
    }
};

int main( )
{
    srand( GetTickCount() );
    int arr[tam];
    cocktailSort<operacion> cs;

    for( int x = 0; x < tam; x++ )
        arr[x] = rand() % tam + 1;

    std::cout << "Original: " << std::endl << "==========" << std::endl;
    /*for( int x = 0; x < tam; x += LLEN )
        {
        for( int s = x; s < x + LLEN; s++ )
            std::cout << arr[s] << ", ";

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
    }
*/
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << now << std::endl << std::endl;
    return 0;
}
