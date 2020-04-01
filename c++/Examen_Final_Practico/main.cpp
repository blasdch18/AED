#include <iostream>
#include "avltree.h"
#include "sistema.h"

using namespace std;

int main()
{
    ///DECLARACION DEL SISTEMA
    Sistema sis;
    ///BASE DE DATOS
    sis.insertar_jugador("diaz", 5, 32, 1, "medio", "Chile");
    sis.insertar_jugador("vargas", 9, 26, 1, "delantero", "Chile");
    sis.insertar_jugador("isla", 4, 31, 1, "defensa", "Chile");
    sis.insertar_jugador("bravo", 1, 33, 1, "portero", "Chile");
    ///SELECCION FRANCIA
    sis.insertar_jugador("lloris", 1, 30, 1, "portero", "Francia");
    sis.insertar_jugador("mandanda", 2, 32, 1, "portero", "Francia");
    sis.insertar_jugador("jallet", 17, 34, 1, "defensa", "Francia");
    sis.insertar_jugador("kurzawa", 19, 25, 1, "defensa", "Francia");
    sis.insertar_jugador("varane", 22, 24, 1, "defensa", "Francia");
    sis.insertar_jugador("umtiti", 4, 24, 1, "defensa", "Francia");
    sis.insertar_jugador("digne", 8, 24, 1, "defensa", "Francia");
    sis.insertar_jugador("tolisso", 7, 23, 1, "medio", "Francia");
    sis.insertar_jugador("lemar", 13, 22, 1, "medio", "Francia");
    sis.insertar_jugador("payet", 12, 30, 1, "medio", "Francia");
    sis.insertar_jugador("griezmann", 10, 26, 1, "delantero", "Francia");
    sis.insertar_jugador("benzema", 9, 29, 1, "delantero", "Francia");
    ///SELECCION DINAMARCA
    sis.insertar_jugador("schmeichel", 1, 31, 1, "portero", "Dinamarca");
    sis.insertar_jugador("ankersen", 4, 27, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("vestergaard", 7, 25, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("durmisi", 8, 32, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("christensen", 10, 21, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("kvist", 14, 32, 1, "medio", "Dinamarca");
    sis.insertar_jugador("delaney", 13, 26, 1, "medio", "Dinamarca");
    sis.insertar_jugador("bjelland", 9, 29, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("jorgensen", 25, 27, 1, "defensa", "Dinamarca");
    sis.insertar_jugador("sisto", 22, 22, 1, "delantero", "Dinamarca");
    sis.insertar_jugador("falk", 24, 25, 1, "delantero", "Dinamarca");
    ///SELECCION PERUANA
    sis.insertar_jugador("zela", 5, 22, 1, "delantero", "Peru");
    sis.insertar_jugador("guerrero", 9, 11, 1, "defensa", "Peru");
    sis.insertar_jugador("corzo", 4, 11, 1, "medio", "Peru");
    sis.insertar_jugador("gallese", 23, 21, 1, "portero", "Peru");
    sis.insertar_jugador("caceda", 22, 26, 1, "portero", "Peru");
    sis.insertar_jugador("araujo", 6, 23, 1, "defensa", "Peru");
    sis.insertar_jugador("loyola", 7, 23, 1, "defensa", "Peru");
    sis.insertar_jugador("advincula", 4, 27, 1, "defensa", "Peru");
    sis.insertar_jugador("tapia", 17, 22, 1, "medio", "Peru");
    sis.insertar_jugador("yotun", 16, 27, 1, "medio", "Peru");
    sis.insertar_jugador("farfan", 10, 33, 1, "delantero", "Peru");
    sis.insertar_jugador("ruidiaz", 3, 27, 1, "delantero", "Peru");

    cout << "Examen Final Practico - AED" << endl;
    for(int i=1;i!=0;){
        system("cls");
        cout<<"MINI-SISTEMA : RUSSIA 2018"<<endl;
        ///drlexe.view();
        cout<<endl;
        cout<<"Seleccione: "<<endl;
        cout<<"1) Insertar Jugador"<<endl;
        cout<<"2) Borrar Jugador"<<endl;
        cout<<"3) Listar en Orden Ingresado"<<endl;
        cout<<"4) Listar Jugadores por Seleccion"<<endl;
        cout<<"5) Listado de Jugadores por Posicion"<<endl;
        cout<<"6) Listado de Jugadores por Rango de Edad"<<endl;
        cout<<"Option: ";
        cin>>i;
        cout<<endl;
        int N_camiseta_,Edad_,Edad_Minima,Edad_Maxima;
        string Apellido_,Pos_,Seleccion_,Seleccion_A;
        switch(i){
            case 1:
                cout<<"IMPORTANTE: TODOS LOS DATOS SON EN MINUSCULA MENOS LA SELECCION (PRIMERA LETRA CON MAYUSCULA)"<<endl;
                cout<<"Apellido: ";cin>>Apellido_;
                cout<<"Nro de camiseta: ";cin>>N_camiseta_;
                cout<<"Edad: ";cin>>Edad_;
                cout<<"posicion: ";cin>>Pos_;
                cout<<"Seleccion: ";cin>>Seleccion_;
                sis.insertar_jugador(Apellido_, N_camiseta_, Edad_, 1, Pos_, Seleccion_);
                break;
            case 2:
                sis.eliminar_jugador("corzo", 4, 11, 1, "medio", "Peru");
                break;
            case 3: sis.consultar_jugadores_orden();
                system("pause");
                break;
            case 4:
                cout<<"IMPORTANTE: LA SELECCION (PRIMERA LETRA CON MAYUSCULA)"<<endl;
                cout<<"Seleccion: ";cin>>Seleccion_A;
                sis.consultar_seleccion(Seleccion_A);
                system("pause");
                break;
            case 5:
                cout<<"IMPORTANTE: EN MINUSCULAS"<<endl;
                cout<<"Posicion: ";cin>>Pos_;
                sis.consultar_posicion(Pos_);
                system("pause");
                break;
            case 6:
                cout<<"Edad Minima: ";cin>>Edad_Minima;
                cout<<"Edad Maxima: ";cin>>Edad_Maxima;
                sis.consultar_edad(Edad_Minima,Edad_Maxima);
                system("pause");
                break;
        }
    }
    return 0;



































/*
    cout << "-------" << endl;
    sis.consultar_jugadores_orden();
    cout << "-------" << endl;

    sis.eliminar_jugador("corzo", 4, 11, 1, "medio", "Peru");

    cout << "-------" << endl;
    sis.consultar_jugadores_orden();
    cout << "Por seleccion Peru" << endl;
    sis.consultar_seleccion("Peru");
    cout << "Por seleccion Chile" << endl;
    sis.consultar_seleccion("Chile");
    cout << "-------" << endl;
    cout << endl;
    cout << "Por Edad" << endl;
    sis.consultar_edad(1,16);
    cout << endl;
    cout << "Por Posicion" << endl;
    sis.consultar_posicion("medio");


    return 0;
*/
}
