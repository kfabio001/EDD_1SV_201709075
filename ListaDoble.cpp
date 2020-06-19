
#include "ListaDoble.h"
#include <iostream>
#include <string>

using namespace std;

void ListaDoble::insertar(string IdTran, string id_arbol,string arbol,string desc, string usuario, int dias,bool estad)
{
    NodoListaDoble* nuevo = new NodoListaDoble(IdTran,id_arbol,arbol,desc,usuario,dias,estad);

    if (longitud == 0)
	{
		cabeza = nuevo;
		cabeza->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
        longitud+= 1;

	}
	else
	{
        NodoListaDoble* ultimo = cabeza->Anterior;
		nuevo->Siguiente = cabeza;
		nuevo->Anterior = ultimo;
		ultimo->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
		ultimo = nuevo;
        longitud += 1;
	}
    cout<<"insertado";
}



NodoListaDoble * ListaDoble::Buscar(string id,string usuario) {
	if (cabeza != NULL)
	{
        NodoListaDoble* aux = cabeza;
		while (aux->Siguiente != cabeza) {
            if (id == aux->id_arbol && usuario ==aux->usuario)
			{
				return aux;
			}
			aux = aux->Siguiente;
		}
        if (aux->id_arbol == id && usuario == aux->usuario)
		{
			return aux;
		}
	}
}


void ListaDoble::graficar()
{
	FILE * file;
	file = fopen("ReporteTransacciones.dot","w+");
	fprintf(file,"digraph Transacciones{\n");
	generarDot(file,cabeza);

	fprintf(file,"}");
	fclose(file);

	system("dot -Tpng ReporteTransacciones.dot -o ReporteTransacciones.png");

}

void ListaDoble::generarDot(FILE* file,NodoListaDoble* n)
{
    NodoListaDoble * aux = n;
	if (aux == nullptr) return;
	do
	{

        string label = aux->IdTran + "[label=\""+aux->IdTran+" "+ aux->usuario+"\"];\n";
		const char * clabel = label.c_str();
		fprintf(file,clabel);

        string enlaces = aux->IdTran + "->" + aux->Siguiente->IdTran+"\n";
        enlaces += aux->Siguiente->IdTran + "->" + aux->IdTran + "\n";
		const char* cenlaces = enlaces.c_str();
		
		fprintf(file,cenlaces);
		
		aux = aux->Siguiente;
	} while (aux!=cabeza);
}
