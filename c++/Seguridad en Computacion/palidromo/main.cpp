#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void palidromo() {
 // your code goes here
 int I = 0;
 string frase;
    int i=0;
    cout<<"escribe tu Password con alfanumericos =";
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

 int J = frase.length();
 int mitad = J / 2;
 cout<<endl<<frase<<endl;
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

int main()
{

    palidromo();
}
