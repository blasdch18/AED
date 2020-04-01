#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void leerPasw(char frase[])
{
    int i=0;
    //cout.flush();
    do
    {
        frase[i] = getch();
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
      //  cout.flush();

    }while(frase[i-1]!=13);  // si presiona ENTER
    cout<<endl<<frase;
    //frase[i-1] = NULL;
    cout << endl;
}

bool AlphaNumber(string pass)
{
    //cout<<"v="<<pass.length();
    for(int i=0; i<pass.length() ;i++)
    {
        if(isdigit(pass[i]))
        {
            return 1;
        }

    }
}

void palidromo() {
 // your code goes here
 int I = 0;
 char frase[15];
    int i=0;
    cout<<"Escribe tu Password sin Palindromo =";
    do
    {
        frase[i] = getch();
        if(frase[i]!=8)  // no es retroceso
        {
            cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
    }while(frase[i-1]!=13);  // si presiona ENTER
 int J = sizeof(frase)/sizeof(*frase) - 1;
 int mitad = J / 2;
 cout<<endl;
 while(frase[I] == frase[J]){
  if(mitad == I){
   cout << "Es palindromo";
   break;
  }
 J--;
 I++;
 }
 if(mitad != I)
 cout << "No es palindromo";
// return 0;
}

bool NotIdNotPass(string pass , string name , string Sname)
{
    name=name+Sname;
    int con=0;
    int pos=-1;
    bool ya=true;
    for(int i=0 ;i<pass.length();i++){
        if(pass[i] == name[con])
        {
            con++;
            if(!ya){
                pos=i;
            }
            ya=false;
        }
    }
    return ya;
}
int main ()
{
    /*char frase[15];
    int i=0;
    cout<<"Escribe tu Password con alfanumericos =";
    do
    {
        frase[i] = getch();
        if(frase[i]!=8)  // no es retroceso
        {
            cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
    }while(frase[i-2]!=13);  // si presiona ENTER
    cout<<endl<<AlphaNumber(frase);
    cout<<endl<<"Pass correcto : "<<frase<< endl;

    palidromo();
    cout<<endl<<endl<<"Password Invisible : .. ";
    leerPasw(frase);
    */
    string pass , name ,sname;
    cout<<endl<<"escribe tu pass , nombre y apellido.. ";
    cin>>pass;
    cin>>name;
    cin>>sname;
    cout<<NotIdNotPass(pass,name, sname);

    return 0;
}
