#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "MatrizH.h"
//#include "MatrizH.cpp"
//#include "Nodo.h"
#include "AVL.h"

using namespace std;

typedef class Operaciones Operaciones;

class Operaciones
{
	public:
		int dimension, auxDimen;
        char cadena1[20];
        char cadena2[20];
        int globalActivos=0;
        string globalUsuario;
        string globalEmpresa;
        string globalDepartamento;
        string alpas;

        MatrizH* m;
        NodoMa *userE;
        NodoV* apuntadorAVL;
        Operaciones(MatrizH* ma);


      //  MatrizH *mat=new MatrizH();
        //MatrizH *mat;
		Operaciones();
        void prueba();
        bool busquedaEmp(string empB);
        bool busquedaDepa(string depaB);
		void menu();
        void menuAdmin();
        //void menuUsuario(string Nombre, string departamento, string empresa);
        void menuUsuario();
        void primero();
        void alpa(string alpa);

		int PosicionRandom();
		int PuntajeHorizontal(string palabra, int fila);
		int PuntajeVertical(string palabra, int columna);
		void reportes(int opcion);
        void jugar();

		void SeleccionarJugador();

		void ReportePorJugador();
        void Mostrar(int &d, int FE);

	protected:
};

#endif
