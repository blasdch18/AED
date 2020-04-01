#include <iostream>
#include "RedBlackTree.h"
#include "Traits.h"

using namespace std;

int main()
{
    RedBlackTree<TreeTrait_cmp<int> > arbol;
    arbol.add(1);
    arbol.add(2);
    arbol.add(3);
    arbol.add(4);
    arbol.add(5);
    arbol.add(6);
    arbol.add(7);
    arbol.add(8);
    arbol.add(9);
    arbol.add(10);
    /*for(int a = 0 ; a < 10 ; a++)
        {for(int i = 1 ; i< 2;i++){
            f=rand()%100;
            //cout<<f<<endl;
            arbol.add(f);
           // arbol.print();
        }*/
        //arbol.print();
        /*for(int j = 1 ; j< 3000 ;j++)
        {
            int t= (rand()%1000);
            //cout<<endl<<t<<endl;
            //cout<< t<<endl;
            //arbol.print();
            arbol.remove(t);
        }*/
        //}

    cout<<endl<<endl;
    arbol.print();
    arbol.remove(1);cout<<endl;
    arbol.print();
    /*cout<<endl<<"-------------------------------------------------------------------- remove ->9"<<endl<<endl;
    arbol.print();
    arbol.remove(4);
    cout<<endl<<"-------------------------------------------------------------------- remove ->4"<<endl<<endl;
    arbol.print();*/
    arbol.remove(6);
    cout<<endl<<"-------------------------------------------------------------------- remove ->6"<<endl<<endl;
    arbol.print();/*
    arbol.remove(7);
    cout<<endl<<"-------------------------------------------------------------------- remove ->7"<<endl<<endl;
    arbol.print();
    arbol.remove(2);
    cout<<endl<<"-------------------------------------------------------------------- remove ->2"<<endl<<endl;
    arbol.print();
    arbol.remove(5);
    cout<<endl<<"-------------------------------------------------------------------- remove ->5"<<endl<<endl;
    arbol.print();*/
    return 0;
}
