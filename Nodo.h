#ifndef NODO_H
#define NODO_H
#include <iostream>
//using namespace std;
class NodoMa
{
public:

    NodoMa * derecha;
    NodoMa * izquierda;
    NodoMa * arriba;
    NodoMa * abajo;
    NodoMa * adelante;
    NodoMa * atras;

    std::string Nombre;
    std::string contra;
    int numero;

    NodoMa(std::string dato1, int dato2, std::string dato3){

    derecha =nullptr;
    izquierda =nullptr;
    arriba =nullptr;
    abajo =nullptr;
    adelante =nullptr;
    atras =nullptr;
    Nombre=dato1;
    numero=dato2;
    contra=dato3;
}
};
#endif // NODO_H
