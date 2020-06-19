
#include <iostream>

using namespace std;

class NodoListaDoble
{
public:
    NodoListaDoble* Siguiente;
    NodoListaDoble* Anterior;
    string IdTran;
    string id_arbol;
	string usuario;


    string arbol;
    string desc;
	int dias;
    bool estad;
	
    NodoListaDoble(string IdTran, string id_arbol,string arbol ,string desc, string usuario, int dias,bool estad)
	{
		Siguiente = nullptr;
		Anterior = nullptr;

        this->IdTran = IdTran;
        this->id_arbol = id_arbol;
        this->arbol = arbol;
        this->desc = desc;
		this->usuario = usuario;
        this->estad = estad;
		this->dias = dias;
		
	}
};
