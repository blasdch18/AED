#include <iostream>
#include <conio.h>

using namespace std;

string idLogin = "Admi123";
string idPassw = "1234";

void leerPasw(char frase[])
{
    int i=0;
    cout.flush();

    do
    {
        frase[i] = (unsigned char)getch();

        if(frase[i]!=8)  // no es retroceso
        {
            //cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();

    }while(frase[i-1]!=13);  // si presiona ENTER

    frase[i-1] = NULL;
    cout << endl;
}

bool Login(string id ,string pass)
{
    return (id == idLogin && pass == idPassw);
}
int main()
{
    char pasw[20];
    string idL;
    cout <<" Ingrese idLogin: ";
    cin>>idL;
    cout <<" Ingrese password: ";
    leerPasw(pasw);
    cout << endl;
    cout<<Login(idL,pasw)<<endl;
    cout <<" Mostrando password: "<< pasw << endl << endl;
    cout <<" >> Puedes agregar la funcion a tus programas :D! \n";

    return 0;
}
