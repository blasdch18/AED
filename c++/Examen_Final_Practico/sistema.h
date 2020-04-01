    #ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include <iostream>
#include <limits.h>

#include "avltree.h"
#include "listaenlazada.h"

using namespace std;


class Jugador
{
public:
    int nro_camiseta;
    string apellido;
    int edad;
    int orden_ingreso;
    string posicion;
    string seleccion;
    Jugador(){}
    Jugador(string apellido, int nro_camiseta, int edad, int orden_ingreso, string posicion){
        this->nro_camiseta = nro_camiseta;
        this->apellido = apellido;
        this->edad = edad;
        this->orden_ingreso = orden_ingreso;
        this->posicion = posicion;
        this->seleccion = "";
    }
    friend ostream& operator<<(ostream& os, const Jugador& target){
        os << target.apellido << " " << target.nro_camiseta << " " << target.edad << " " << target.orden_ingreso << " " << target.posicion;
        if(target.seleccion != ""){
            os << " " << target.seleccion;
        }
        return os;
    }

    friend bool operator== (const Jugador &c1, const Jugador &c2){
        return c1.apellido == c2.apellido && c1.nro_camiseta == c2.nro_camiseta && c1.seleccion == c2.seleccion;
    }
    friend bool operator> (const Jugador &c1, const Jugador &c2){
        return c1.nro_camiseta > c2.nro_camiseta;
    }
};


class Seleccion
{
public:
    string nombre;
    lista<Jugador> porteros;
    lista<Jugador> defensas;
    lista<Jugador> medios;
    lista<Jugador> delanteros;
    Seleccion(){}
    Seleccion(string nombre) {
        this->nombre = nombre;
    }
    int nro_jugadores(){
        return defensas.count + delanteros.count + medios.count + porteros.count;
    }
    friend ostream& operator<<(ostream& os, const Seleccion& target){
        os << target.nombre << "... nro jugadores.. " << target.defensas.count + target.delanteros.count + target.medios.count + target.porteros.count << endl;
        os << target.porteros << target.defensas << target.medios << target.delanteros;
        return os;
    }
    friend bool operator> (const Seleccion &c1, const Seleccion &c2){
        int n_jugadores_c1 = c1.defensas.count + c1.delanteros.count + c1.medios.count + c1.porteros.count;
        int n_jugadores_c2 = c2.defensas.count + c2.delanteros.count + c2.medios.count + c2.porteros.count;
        return n_jugadores_c1 > n_jugadores_c2;
    }
    friend bool operator!= (const Seleccion &c1, const Seleccion &c2){
        return c1.nombre != c2.nombre;
    }

    void insertar_jugador(string apellido, int nro_camiseta, int edad, int orden_ingreso, string posicion){
        //cout << "insertando" << endl;
        if(posicion == "portero"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "portero");
            j.seleccion = this->nombre;
            this->porteros.Insert(j);
        }
        else if(posicion == "defensa"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "defensa");
            j.seleccion = this->nombre;
            this->defensas.Insert(j);
        }
        else if(posicion == "medio"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "medio");
            j.seleccion = this->nombre;
            this->medios.Insert(j);
        }
        else if(posicion == "delantero"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "delantero");
            j.seleccion = this->nombre;
            this->delanteros.Insert(j);
        }
    }

    bool eliminar_jugador(string apellido, int nro_camiseta, int edad, int orden_ingreso, string posicion){
//        cout << "insertando" << endl;
        if(posicion == "portero"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "portero");
            j.seleccion = this->nombre;
            this->porteros.borrado(j);
            return true;
        }
        else if(posicion == "defensa"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "defensa");
            j.seleccion = this->nombre;
            this->defensas.borrado(j);
            return true;
        }
        else if(posicion == "medio"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "medio");
            j.seleccion = this->nombre;
            this->medios.borrado(j);
            return true;
        }
        else if(posicion == "delantero"){
            Jugador j(apellido, nro_camiseta, edad, orden_ingreso, "delantero");
            j.seleccion = this->nombre;
            this->delanteros.borrado(j);
            return true;
        }
        return false;
    }

    void obtener_todos_jugadores(lista<Jugador> *resultado, int lim_inf_edad=0, int lim_sup_edad=INT_MAX){
        lista<Jugador> resultante;
        nodo<Jugador> *p;
        for (p = porteros.head; p; p = p->next)
        {
            if(p->data.edad >= lim_inf_edad && p->data.edad<=lim_sup_edad)
                resultante.Insert(p->data);
        }
        for (p = defensas.head; p; p = p->next)
        {
            if(p->data.edad >= lim_inf_edad && p->data.edad<=lim_sup_edad)
                resultante.Insert(p->data);
        }
        for (p = medios.head; p; p = p->next)
        {
            if(p->data.edad >= lim_inf_edad && p->data.edad<=lim_sup_edad)
                resultante.Insert(p->data);
        }
        for (p = delanteros.head; p; p = p->next)
        {
            if(p->data.edad >= lim_inf_edad && p->data.edad<=lim_sup_edad)
                resultante.Insert(p->data);
        }
        resultado->aniadir_lista(resultante);
    }

    lista<Jugador> obtener_jugadores_posicion(string posicion){
        if(posicion == "portero"){
            return this->porteros;
        }
        else if(posicion == "defensa"){
            return this->defensas;
        }
        else if(posicion == "medio"){
            return this->medios;
        }
        else if(posicion == "delantero"){
            return this->delanteros;
        }
    }
};



class Sistema
{

public:
    CAvlTree<Seleccion> selecciones;
    lista<Jugador> orden_jugadores;

    Sistema() {}
    void insertar_jugador(string apellido, int nro_camiseta, int edad, int orden_ingreso, string posicion, string seleccion){
        Seleccion target(seleccion);
        Cnode<Seleccion> **iter;

        // Esto solo para llenar la lista en orden de ingreso, no sirve para consultas
        Jugador j(apellido, nro_camiseta, edad, orden_ingreso, posicion);
        j.seleccion = seleccion;
        this->orden_jugadores.Insert_no_order(j);



        if(selecciones.find(target, iter)){
//            cout << "Se encontro" << endl;
//            cout << (*iter)->m_data.nombre << endl;
            (*iter)->m_data.insertar_jugador(apellido, nro_camiseta, edad, orden_ingreso, posicion);
//            cout << "Agregando" << endl << endl;
            return;
        }
        Seleccion to_insert(seleccion);
        this->selecciones.inserteichon(to_insert);
        Cnode<Seleccion> **iter2;
        selecciones.find(to_insert, iter2);
        (*iter2)->m_data.insertar_jugador(apellido, nro_camiseta, edad, orden_ingreso, posicion);
    }


    void eliminar_jugador(string apellido, int nro_camiseta, int edad, int orden_ingreso, string posicion, string seleccion){
        Seleccion target(seleccion);
        Cnode<Seleccion> **iter;

        //Eliminar de la lista de orden
        Jugador j(apellido, nro_camiseta, edad, orden_ingreso, posicion);
        j.seleccion = seleccion;
        if(this->orden_jugadores.borrado_no_order(j)){
            cout << "eliminado " << apellido << endl;
        }


        //Eliminar del arbol
        Cnode<Seleccion> **iter2;
        selecciones.find(target, iter2);
        (*iter2)->m_data.eliminar_jugador(apellido, nro_camiseta, edad, orden_ingreso, posicion);
    }

    void precalcular_consultar_posicion(Cnode<Seleccion> *p,lista<Jugador> *resultado, string posicion, string orden="312") //1 imprimir // 2 hijoizq 3 hijo der
    {
        if(!p)return;
        int fase=0;
        while(fase<3)
        {
            if(orden[fase] == '1')
            {
                resultado->aniadir_lista(p->m_data.obtener_jugadores_posicion(posicion));
            }
            else if(orden[fase] == '2')
            {
                this->precalcular_consultar_posicion(p->m_children[0],resultado, posicion, orden);
            }
            else if(orden[fase] == '3')
            {
                this->precalcular_consultar_posicion(p->m_children[1],resultado, posicion, orden);
            }
            fase++;
        }
    }

    void precalcular_consultar_edad(Cnode<Seleccion> *p,lista<Jugador> *resultado, int lim_inf_edad=0, int lim_sup_edad=INT_MAX, string orden="312") //1 imprimir // 2 hijoizq 3 hijo der
    {
        if(!p)return;
        int fase=0;
        while(fase<3)
        {
            if(orden[fase] == '1')
            {
                lista<Jugador> tmp_lista;
                p->m_data.obtener_todos_jugadores(&tmp_lista,lim_inf_edad,lim_sup_edad);
                resultado->aniadir_lista(tmp_lista);
            }
            else if(orden[fase] == '2')
            {
                this->precalcular_consultar_edad(p->m_children[0],resultado, lim_inf_edad, lim_sup_edad, orden);
            }
            else if(orden[fase] == '3')
            {
                this->precalcular_consultar_edad(p->m_children[1],resultado,lim_inf_edad, lim_sup_edad, orden);
            }
            fase++;
        }
    }

    void consultar_edad(int lim_inf_edad, int lim_sup_edad){
        lista<Jugador> resultado;
        Cnode<Seleccion> *p = this->selecciones.m_root;
        precalcular_consultar_edad(p, &resultado, lim_inf_edad, lim_sup_edad);
        cout << resultado << endl;
    }
    void consultar_seleccion(string seleccion){
        Seleccion consulta(seleccion);
        Cnode<Seleccion> **iter2;
        lista<Jugador> resultado;
        if(selecciones.find(consulta, iter2)){
            (*iter2)->m_data.obtener_todos_jugadores(&resultado);
            cout << resultado << endl;
            return;
        }
        cout << "No se encontro la seleccion consultada" << endl;
    }

    void consultar_jugadores_orden(){
        cout << this->orden_jugadores << endl;
    }

    void consultar_posicion(string posicion){
        lista<Jugador> resultado;
        Cnode<Seleccion> *p = this->selecciones.m_root;
        this->precalcular_consultar_posicion(p, &resultado, posicion);
        cout << resultado << endl;
    }
};

#endif // SISTEMA_H_INCLUDED
