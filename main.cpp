#include <iostream>
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"

#include "AVL.h"

using namespace std;


int main(int argc, char** argv) {
   Operaciones *op= new Operaciones();
 //MatrizH *mat=new MatrizH();
 //op->jugar();
op->primero();
 //AVL ArbolInt;
   // cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

 //   // Mostrar el árbol en tres ordenes distintos:
//   cout << "InOrden: ";
//   ArbolInt.inOrden();
//    cout << endl;
//    cout << "Pr* ";
//    ArbolInt.PreOrden(ArbolInt.Mostrar);
//    cout << endl;
//    cout << "PostOrden: ";
//    ArbolInt.PostOrden(Mostrar);
//    cout << endl;

    return 0;
}
