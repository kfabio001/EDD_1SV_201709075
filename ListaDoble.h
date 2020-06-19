#include "NodoListaDoble.h"
#include <iostream>

using namespace std;

class ListaDoble
{
public:
    NodoListaDoble* cabeza;
    int longitud;
    ListaDoble() {
		this -> cabeza = nullptr;
        this->longitud = 0;
	}

    void insertar(string IdTran ,string id_arbol ,string arbol ,string desc,string usuario ,int dias,bool estad);
	void Mostrar(string);
    NodoListaDoble * Buscar(string,string);
    int tamanoS();
	void graficar();
    void generarDot(FILE*,NodoListaDoble*);
};

