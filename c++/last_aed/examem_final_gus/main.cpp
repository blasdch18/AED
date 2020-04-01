#include <iostream>

using namespace std;

template<class T>
class nodoTeam
{
public:
    T seleccion;
    nodoTeam<T>*next_team;
    nodoTeam()
    {
        next_team=0;
    }
    nodoTeam(T x , nodoTeam * n=0)
    {
        seleccion=x;
        next_team=n;
    }
};

template<class T>
class nodoNumero
{
public:
    T numero;
    nodoNumero<T>*next_num;
    nodoTeam()
    {
        next_num=0;
    }
    nodoTeam(T x , nodoNumero * n=0)
    {
        numero=x;
        next_num=n;
    }
};

template<class T>
class nodoApellido
{
public:
    T apellido;
    nodoApellido<T>*next_apellido;
    nodoApellido()
    {
        next_apellido=0;
    }
    nodoApellido(T x ,nodoApellido * n=0)
    {
        apellido=x;
        next_apellido=n;
    }
};

template<class T>
class nodoPos


{

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
