#include <iostream>
#include "Avl.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Avl<int> arbol;
    /*arbol.add(30);
    arbol.add(10);
    arbol.add(20);
   */

   for(int i=0; i<=14; i++){
   arbol.add(i);
   arbol.print2();

   }

   // arbol.add(40);
   // arbol.add(15);

    //rbol.show();

    return 0;
}
