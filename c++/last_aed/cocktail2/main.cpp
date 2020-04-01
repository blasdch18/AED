#include <iostream>
#include <windows.h>

const int tam = 10, LLEN = 10;

/*        punteros a funcion               */

template<class T>
class cocktailSort
{
public:
    //bool (*cmp)(T , T );
    static bool menor(T a, T b)
    {
        return a<b;
    }
    static bool mayor(T a,T b)
    {
        return a>b;
    }
    bool orden(bool (*pf)(T,T),T a , T b)
    {
        pf(a,b);
    }
    void sort( int* arr, int len )
    {
        //cmp=p;
        bool notSorted = true;
        while( notSorted )
        {
            notSorted = false;
            for( int i = 0; i < len - 1; i++ )
            {
                if( orden( &mayor, arr[i] , arr[i + 1] ))
                {
                    sSwap( arr[i], arr[i + 1] );
                    notSorted = true;
                }
            }

            if( !notSorted ) break;
            notSorted = false;

            for( int i = len - 1; i > 0; i-- )
            {
                if( orden (&mayor , arr[i - 1] , arr[i]) )
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
    srand( GetTickCount() );
    int arr[tam];
    //Comparacion<T> *
    cocktailSort<int> cs;

    for( int x = 0; x < tam; x++ )
        arr[x] = rand() % tam + 1;

    std::cout << "Original: " << std::endl << "==========" << std::endl;
    for( int x = 0; x < tam; x += LLEN )
        {
        for( int s = x; s < x + LLEN; s++ )
            std::cout << arr[s] << ", ";

        std::cout << std::endl;
        }

    //DWORD now = GetTickCount();
    cs.sort( arr, tam);
    //now = GetTickCount() - now;

    std::cout << std::endl << std::endl << "Sorted: " << std::endl << "========" << std::endl;
    for( int x = 0; x < tam; x += LLEN )
        {
            for( int s = x; s < x + LLEN; s++ )
            std::cout << arr[s] << ", ";

        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl << std::endl << std::endl;
    //std::cout << now << std::endl << std::endl;
    return 0;
}
