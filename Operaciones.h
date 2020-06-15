#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "json.hpp"
#include "Matriz.h"
#include "Matriz.cpp"
#include "MatrizH.h"
//#include "MatrizH.cpp"
//#include "Nodo.h"
#include "AVL.h"
#include "ListaDobleCircular.h"
#include "ListaDobleCircular.cpp"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
#include "Cola.h"
#include "Cola.cpp"
#include "Arbol.h"
#include "Arbol.cpp"
#include "ListaSimple.h"
#include "ListaSimple.cpp"
using namespace std;
using json = nlohmann::json;
typedef class Operaciones Operaciones;

class Operaciones
{
	public:
		int dimension, auxDimen;
        char cadena1[20];
        char cadena2[20];


		Nodo *auxJ1, *auxJ2;
		Arbol *usuaios;// = new Arbol();
		Matriz *matriz ;//= new Matriz();
		ListaDobleCircular *listaDiccionario ;//= new ListaDobleCircular();
		ListaDoble *fichas ;//= new ListaDoble();
		ListaDoble *fichasCopia;// = new ListaDoble();
		Cola *fichasDisponibles;// =new Cola();
		ListaSimple *scoreboard;// = new ListaSimple();
       // MatrizH *mat=new MatrizH();
        MatrizH *mat;
		Operaciones();
        void prueba();
        bool busquedaEmp(string empB);
        bool busquedaDepa(string depaB);
		void menu();
        void menuAdmin();
        void menuUsuario();
        void primero();
		void insertarFichas(ListaDoble *fichas);
		void LecturaDeArchivo(string archivo);
		void IngresarPalabraHorizontal(string palabra, int columnaInicio, int  columnaFinal, int fila, Nodo *jugador);
		void IngresarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna,Nodo *jugador);
		void RepartirFichas(Nodo *jugador1, Nodo *jugador2);
		int PosicionRandom();
		int PuntajeHorizontal(string palabra, int fila);
		int PuntajeVertical(string palabra, int columna);
		void reportes(int opcion);
        void jugar();

		void SeleccionarJugador();
		bool turno(string palabra,  Nodo *jugador);
		void sdf(Nodo *Jactual, Nodo *Jsiguiente);
		void CambiarFichas(string letras, Nodo *jugador);
		bool validar();
		bool validar(NodoM *actual);
		void ReportePorJugador();
        void Mostrar(int &d, int FE);

	protected:
};

#endif
