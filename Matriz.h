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
    string cuerpoArbolDot;
    int contadorCata;
    int contadorN;
    virtual ~Matriz();
    void imprimir();
    void graficar();
    void obtenerRaices();
    void obtenerRaicesUsuario(string *usuario);
    void obtenerUsuario(string us,string id,string user);
    void insertarNodoMatriz(string name,string empresa,string departamento,string nameuser,string password,int contador);
    void graficarMatriz(string nombre);
    void cuerpoArbol(NodoArbol *temp);
    NodoMatriz* existe(string user,string departamento,string empresa);
    NodoMatriz* existeEmp(string empresa);
    NodoMatriz* createEmpresa(string name);
    NodoMatriz* createDepartamento(string name);
    NodoMatriz* searchEmpresa(string name);
    NodoMatriz* searchDepartamento(string name);
    NodoArbol* serachActivo(string id);
protected:

private:
};

#endif // MATRIZ_H
