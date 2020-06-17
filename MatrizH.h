#ifndef MATRIZH_H
#define MATRIZH_H
#include <iostream>
#include "Nodo.h"
//#include "AVL.h"


using namespace std;


class MatrizH{
public:
    NodoMa* Cabecera;
    MatrizH(){

        Cabecera = new NodoMa ("admin",-1,"");
    }
    void InsertarElemento(string usuario, string contra,int numero, string empresa, string departamento);
    NodoMa* eliminarElemento(string usuario, string empresa, string departamento);
    void print();
    NodoMa* crearEmpresa(string empresa);
    NodoMa* crearDepartamento(string departamento);

    NodoMa* buscarEmpresa(string empresa, NodoMa* inicio);
    NodoMa* buscarDepa(string departamento, NodoMa* inicio);

    bool VerificarEmpresa(string empresa, NodoMa* Inicio, NodoMa* USR);
    bool VerificarDepartamento(string departamento, NodoMa* Inicio, NodoMa* USR);

    bool busquedaEmp(string empresa);
    bool busquedaDepa(string departamento);
    bool busquedaUsuario(string usuario,string contra,string departamento, string empresa);
    NodoMa* busquedaUsuarioNodo(string usuario,string departamento, string empresa);
    NodoV* serachActivo(int id);
    bool busquedaSoloUsuario(string usuario,string departamento, string empresa);
    //NodoActivo* serachActivo(string id);
};

#endif // MATRIZH_H
