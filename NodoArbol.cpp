#include "NodoArbol.h"

NodoArbol::NodoArbol(string n,string d,string i)
{
    this->nombre=n;
    this->descripcion=d;
    this->id=i;
    this->estado=true;
    this->izquierda=NULL;
    this->derecha=NULL;
    this->altura=0;
}

NodoArbol::~NodoArbol()
{
    //dtor
}
