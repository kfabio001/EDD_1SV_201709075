#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoMatriz.h"
#include "NodoArbol.h"
#include <string>
#include <iostream>
using namespace std;

class Matriz
{
public:
    NodoMatriz *root;
    Matriz();
    string cuerpoGraph;
    int contadorCata;
    int contadorN;
    virtual ~Matriz();
    void imprimir();
    void grafo();
    void obtenerRaices();
    void obtenerRaicesUsuario(string *usuario);
    void obtenerUsuario(string us,string id,string usuario);
    void insertarNodoMatriz(string name,string empresa,string departamento,string nick,string contra,int contador);
    void grafhMatriz(string nombre);
    NodoMatriz* siExiste(string usuario,string departamento,string empresa);
    NodoMatriz* siExisteEmp(string empresa);
    NodoMatriz* crearEmpresa(string nombre);
    NodoMatriz* crearDepartamento(string temp);
    NodoMatriz* BuscarEmpresa(string temp);
    NodoMatriz* BuscarDepartamento(string temp);
    NodoArbol* BuscarActivo(string id);
protected:

private:
};

#endif // MATRIZ_H
