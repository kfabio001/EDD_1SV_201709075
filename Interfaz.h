#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Matriz.h"
#include <time.h>
#include <bits/stdc++.h>
#include <windows.h>
#include "NodoMatriz.h"
#include "ListaDoble.h"
#include "Avl.h"
#include <stdlib.h>

using namespace std;
class Interfaz
{
public:
    void primero();
    char cadena1[20];
    char cadena2[20];
    void menuAdmin();
    void menuUsuario();
    Matriz* mate;
    NodoMatriz *auxNodo;
    NodoMatriz* obtener;
    string cuerpoDot;
    NodoArbol* root;
    string grafoArbol();
    int contadorCata;
    void llenar(NodoArbol *temp);
    void addActivo();
    void eliminarActivo();
    void modificarActivo();
    void grafo(string cuerpo);
    void grafoVarios(string cuerpo);
    void obtenerRaices();
    string cadenaIDActivo();
    Interfaz(Matriz* ma);
    virtual ~Interfaz();



protected:

private:
};

#endif // INTERFAZ_H
