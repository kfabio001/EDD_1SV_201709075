#ifndef AVL_H
#define AVL_H
// Arbol AVL en C++
// (C) Mayo 2002, Salvador Pozo
// C con Clase: http://c.conclase.net
//#include "Operaciones.h"
#include <iostream>
using namespace std;

class AVL;

// Clase Nodo de Arbol AVL:
class NodoV {
  public:
   // Constructor:
   NodoV(const int dat,string nom, string alp,bool est,NodoV *pad=NULL, NodoV *izq=NULL, NodoV *der=NULL) :
     dato(dat), nombre(nom), alpa(alp),estado(est), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
   // Miembros:
   int dato;
   int FE;
   string nombre;
   string alpa;
   bool estado;
   int altura;
   NodoV *izquierdo;
   NodoV *derecho;
   NodoV *padre;

   friend class AVL;
};

class AVL {
  public:
   enum {IZQUIERDO, DERECHO};
   // Punteros de la lista, para cabeza y nodo actual:
   NodoV *raiz;
   NodoV *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor básicos:
   AVL() : raiz(NULL), actual(NULL) {}
   ~AVL() { Podar(raiz); }
   // Insertar en árbol ordenado:
   NodoV* insertar(NodoV* raiz,int dat, string nombre,string alpa,bool disponible,string descripcion);
   NodoV* modificar(NodoV* raiz, string dato,string datoNew);
   NodoV* simplederechaizquierda(NodoV *temp);
   NodoV* simplederechaderecha(NodoV *temp);
   NodoV* doblederechaizquierda(NodoV *temp);
   NodoV* doblederechaderecha(NodoV *temp);
   NodoV* valancear(NodoV *raiz,int datoE);
   void preorder(NodoV *raiz);
   void enorder(NodoV *raiz);
   string graficarArbol();
   void cuerpoArbol(NodoV *temp);
   int Altura(NodoV* raiz);
   int AlturaAux2(NodoV* raiz);
   NodoV* eliminar(NodoV* raiz, int dato);
   NodoV* inorderE(NodoV* right);

   NodoV* Insertar(NodoV* raiz,const int dat, string nombre,string alpa, bool disponible, string descripcion);
   void InsertarL(const int dat, string nombre,string alpa, bool disponible, string descripcion);
   // Borrar un elemento del árbol:
   void Borrar(const int dat);
   // Función de búsqueda:
   bool Buscar(const int dat);
   bool BuscarNombre(string nombre);
   // Comprobar si el árbol está vacío:
   bool Vacio(NodoV *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(NodoV *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un dato:
   int Altura(const int dat);
   // Devolver referencia al dato del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&, int) ,NodoV *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&, int) , NodoV *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&, int) , NodoV *nodo=NULL, bool r=true);
   void Mostrar();
   void inOrden();
   void inOrden(NodoV * actual);
   void ino(NodoV *raiz);
   void ino();
   NodoV* retornarMatriz(NodoV* raiz);
  private:
   // Funciones de equilibrado:
   void Equilibrar(NodoV *nodo, int, bool);
   void RSI(NodoV* nodo);
   void RSD(NodoV* nodo);
   void RDI(NodoV* nodo);
   void RDD(NodoV* nodo);
   // Funciones auxiliares
   void Podar(NodoV* &);
   void auxContador(NodoV*);
   void auxAltura(NodoV*, int);

};

#endif // AVL_H
