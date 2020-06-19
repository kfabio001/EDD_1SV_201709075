#ifndef AVLT_H
#define AVLT_H
#include "NodoArbol.h"
#include <iostream>
#include <string>
using namespace std;
class Avlt
{
public:
    Avlt();
    int contadorCata;

    void preorden(NodoArbol *raiz);
    void inorden(NodoArbol *raiz);
    void inordenTodos(NodoArbol *raiz);
    void yoRente(NodoArbol *raiz);
    void meRentaron(NodoArbol *raiz);
    void enorderR(NodoArbol *raiz);
    void cambio(NodoArbol *raiz,string nombre);
    NodoArbol* root;
    NodoArbol* buscarRaiz(NodoArbol* raizr,string dato);
    NodoArbol* insertar(NodoArbol* raiz, string dato,string nombre,string descripcion);
    NodoArbol* modificar(NodoArbol* raiz, string dato,string nuevo);
    NodoArbol* RsimpleDerechaIzquierda(NodoArbol *aux);
    NodoArbol* RsimpleDerechaDerecha(NodoArbol *aux);
    NodoArbol* RdobleDerechaIzquierda(NodoArbol *aux);
    NodoArbol* RdobleDerechaDerecha(NodoArbol *aux);
    NodoArbol* balanceo(NodoArbol *raiz,string dato);
    string cuerpoDot;
    string graficarArbol();
    void graficar(string cu);
    void cuerpoArbol(NodoArbol *temp);
    int Altura(NodoArbol* raiz);
    int AlturaR(NodoArbol* raiz);
    NodoArbol* eliminar(NodoArbol* raiz, string dato);
    NodoArbol* inorderE(NodoArbol* raiz);
    virtual ~Avlt();

protected:

private:
};

#endif // AVLT_H
