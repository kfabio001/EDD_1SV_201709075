#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(string nombre, int contador,string nick,string contra)
{
    this->abajo = NULL;
    this->arriba = NULL;
    this->derecho = NULL;
    this->izquierdo = NULL;
    this->atras=NULL;
    this->adelante=NULL;
    this->nombre = nombre;
    this-> contador =contador;
    this->nick = nick;
    this->contra=contra;
    this->tAvl= new Avlt();
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}

