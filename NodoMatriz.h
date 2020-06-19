#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>
#include <iostream>
#include "Avl.h"
using namespace std;

class NodoMatriz
{
public:
    NodoMatriz *izquierdo;
    NodoMatriz *derecho;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;
    Avlt     *tAvl;

    string nombre;
    string nick;
    string contra;
    int contador;
    NodoMatriz(string nombre, int cont,string nick,string contra);
    virtual ~NodoMatriz();


protected:

private:
};

#endif // NODOMATRIZ_H
