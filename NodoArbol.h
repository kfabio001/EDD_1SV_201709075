#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
#include <string>
using namespace std;

class NodoArbol
{
public:
    NodoArbol* derecha;
    NodoArbol* izquierda;
    string id;
    string nombre;
    string descripcion;
    int altura;
    bool estado;
    NodoArbol(string id,string name,string desc);
    virtual ~NodoArbol();

protected:

private:
};

#endif // NODOARBOL_H
