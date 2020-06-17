#include "AVL.h"
#include "Operaciones.h"
#include<time.h>
// Poda: borrar todos los nodos a partir de uno, incluido

void AVL::Podar(NodoV* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}
NodoV* retornarMatriz(NodoV* raiz){
    return raiz;
}
NodoV* AVL::insertar(NodoV* raiz,int dato, string nombre,string alpa,bool disponible,string descripcion){
    //Si el arbol esta vacio
    if (raiz==NULL){
        raiz = new NodoV(dato,nombre,alpa,true);
    } else if(dato<raiz->dato){
        raiz->izquierdo= this->insertar(raiz->izquierdo,dato,nombre,alpa,true,descripcion);
        //1
        //altura es para valancear
        if((Altura(raiz->izquierdo) - Altura(raiz->derecho))==2){
            if(dato<raiz->izquierdo->dato){
                raiz= simplederechaizquierda(raiz);
            }else{
                raiz= doblederechaizquierda(raiz);
            }
        }
    } else if (dato>raiz->dato){
        raiz->derecho = this->insertar(raiz->izquierdo,dato,nombre,alpa,true,descripcion);
        //2
        //altura es para valancear
        int der,izq;
        der=Altura(raiz->derecho);
        izq=Altura(raiz->izquierdo);
        if( (der - izq)==2){
            if(dato>raiz->derecho->dato){
                raiz= simplederechaderecha(raiz);
            }else{
                raiz= doblederechaderecha(raiz);
            }
        }
    }else{
        cout<<"No se puede insertar datos duplicados"<<endl;
    }
    int maximo,de,iz;
    de= this->Altura(raiz->derecho);
    iz= this->Altura(raiz->izquierdo);
    if(de>iz){maximo=de;}else{maximo=iz;}
    raiz->altura=maximo+1;
    return raiz;
}
int AVL::Altura(NodoV* raiz){
    if(raiz==NULL){return -1;}
    int alturaD,alturaI;
    alturaI = Altura(raiz->izquierdo);
    alturaD = Altura(raiz->derecho);
    if(alturaI==-1 && alturaD==-1){return 0;}
    if(alturaI>alturaD){ return alturaI+1; }else{ return alturaD+1; }
}

NodoV* AVL::simplederechaizquierda(NodoV *temp){
    NodoV* temp2;
    temp2= temp->izquierdo;
    temp->izquierdo=temp2->derecho;
    temp2->derecho=temp;
    temp2->altura = this->AlturaAux2(temp2);
    return temp2;
}
NodoV* AVL::simplederechaderecha(NodoV *temp){
    NodoV* temp2;
    temp2= temp->derecho;
    temp->derecho=temp2->izquierdo;
    temp2->izquierdo=temp;
    temp2->altura=this->AlturaAux2(temp2);
    return temp2;
}
NodoV* AVL::doblederechaizquierda(NodoV *temp){
    temp->izquierdo=this->simplederechaderecha(temp->izquierdo);
    return simplederechaizquierda(temp);
}
NodoV* AVL::doblederechaderecha(NodoV *temp){
    temp->derecho=this->simplederechaizquierda(temp->derecho);
    return simplederechaderecha(temp);
}

int AVL :: AlturaAux2(NodoV* raiz){
    if(raiz==NULL){return -1;}
    int alturaD0,alturaI0;
    alturaI0 = AlturaAux2(raiz->izquierdo);
    alturaD0 = AlturaAux2(raiz->derecho);
    if(alturaI0==-1 && alturaD0==-1){raiz->altura=0; return 0;}
    if(alturaI0>alturaD0){ raiz->altura=alturaI0+1; return alturaI0+1; }else{ raiz->altura=alturaD0+1; return alturaD0+1; }
}





void AVL::preorder(NodoV *raiz){
    if(raiz==NULL){ return; }

    cout<<raiz->nombre<<"),";
    preorder(raiz->izquierdo);
    preorder(raiz->derecho);
}

void AVL::enorder(NodoV *raiz){
    if(raiz==NULL){return;}

    enorder(raiz->izquierdo);
    if(raiz->estado){
        cout<<"-*- Id: "<<raiz->dato<<"; nombre: "<<raiz->nombre<<endl;
    }
    enorder(raiz->derecho);
}

//Para eliminar
NodoV* AVL::eliminar(NodoV* raiz,int dato){
    if(raiz == NULL){
        return raiz;
    }

    if(dato<raiz->dato){
        raiz->izquierdo = eliminar(raiz->izquierdo,dato);
    }else if(dato>raiz->dato){
        raiz ->derecho = eliminar(raiz->derecho,dato);
    }else{
        if(raiz->izquierdo==NULL){
            return raiz->derecho;
        }else if(raiz->derecho==NULL){
            return raiz->izquierdo;
        }else{
            NodoV* ordenar0=inorderE(raiz->derecho);
            raiz->dato= ordenar0->dato;
            //raiz->descripcion=ordenar0->descripcion;
            raiz->estado=ordenar0->estado;
            raiz->nombre=ordenar0->nombre;
            raiz->derecho=eliminar(raiz->derecho,raiz->dato);
        }

    }
    raiz=this->valancear(raiz,dato);
    return raiz;
}

NodoV* AVL::valancear(NodoV *raiz,int datoE){
    if((Altura(raiz->izquierdo) - Altura(raiz->derecho))==2){
            if(raiz->dato>raiz->izquierdo->dato){
                    //va rotar a la izquierda
                raiz= simplederechaizquierda(raiz);
            //si sigue des equilibrado va rotar doble
                if( (Altura(raiz->derecho) - Altura(raiz->izquierdo))==2){
                raiz= doblederechaderecha(raiz);
                }
            }else{
                raiz= doblederechaizquierda(raiz);
            }
    }else if( (Altura(raiz->derecho) - Altura(raiz->izquierdo))==2){
            if(raiz->dato<raiz->derecho->dato){
                raiz= simplederechaderecha(raiz);
                if((Altura(raiz->izquierdo) - Altura(raiz->derecho))==2){
                    raiz= doblederechaizquierda(raiz);
                }
            }else{
                raiz= doblederechaderecha(raiz);
            }
        }
    return raiz;
}

NodoV* AVL::inorderE(NodoV* right){
    while(right->izquierdo!=NULL){
        right= right->izquierdo;
    }
    return right;
}






// Insertar un dato en el árbol AVL
NodoV* AVL::Insertar(NodoV* raiz,const int dat, string nombre,string alpa, bool estado, string descripcion)
{
NodoV*padre = NULL;
  // NodoV *padre = NULL;
//padre=NodoMaR->activos;
   cout << "Insertar: " << dat << endl;
  // NodoMaR->activos=raiz;
   actual = raiz;
   // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)); //break;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoV(dat,"","",true);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) {
      padre->izquierdo = new NodoV(dat,"","", padre);
      Equilibrar(padre, IZQUIERDO, true);
   }
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) {
      padre->derecho = new NodoV(dat,"","", padre);
      Equilibrar(padre, DERECHO, true);
   }
}
void AVL::InsertarL(const int dat, string nombre,string alpa, bool estado, string descripcion)
{
//padre = NULL;
   NodoV *padre = NULL;
//padre=NodoMaR->activos;
   cout << "Insertar: " << dat << endl;
  // NodoMaR->activos=raiz;
   actual = raiz;
   // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return; //break;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoV(dat,"","",true);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) {
      padre->izquierdo = new NodoV(dat,"","", padre);
      Equilibrar(padre, IZQUIERDO, true);
   }
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) {
      padre->derecho = new NodoV(dat,"","", padre);
      Equilibrar(padre, DERECHO, true);
   }
}
// Equilibrar árbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(NodoV *nodo, int rama, bool nuevo)
{
   bool salir = false;

   // Recorrer camino inverso actualizando valores de FE:
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; // Depende de si añadimos ...
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = true; // La altura de las rama que
                                      // empieza en nodo no ha variado,
                                      // salir de Equilibrar
      else if(nodo->FE == -2) { // Rotar a derechas y salir:
         if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotación doble
         else RSD(nodo);                         // Rotación simple
         salir = true;
      }
      else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
         if(nodo->derecho->FE == -1) RDI(nodo); // Rotación doble
         else RSI(nodo);                        // Rotación simple
         salir = true;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
   }
}

// Rotación doble a derechas
void AVL::RDD(NodoV* nodo)
{
   cout << "RDD" << endl;
   NodoV *Padre = nodo->padre;
   NodoV *P = nodo;
   NodoV *Q = P->izquierdo;
   NodoV *R = Q->derecho;
   NodoV *B = R->izquierdo;
   NodoV *C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación doble a izquierdas
void AVL::RDI(NodoV* nodo)
{
   cout << "RDI" << endl;
   NodoV *Padre = nodo->padre;
   NodoV *P = nodo;
   NodoV *Q = P->derecho;
   NodoV *R = Q->izquierdo;
   NodoV *B = R->izquierdo;
   NodoV *C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;

   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

// Rotación simple a derechas
void AVL::RSD(NodoV* nodo)
{
   cout << "RSD" << endl;
   NodoV *Padre = nodo->padre;
   NodoV *P = nodo;
   NodoV *Q = P->izquierdo;
   NodoV *B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->izquierdo = B;
   Q->derecho = P;

   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Rotación simple a izquierdas
void AVL::RSI(NodoV* nodo)
{
   cout << "RSI" << endl;
   NodoV *Padre = nodo->padre;
   NodoV *P = nodo;
   NodoV *Q = P->derecho;
   NodoV *B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir árbol:
   P->derecho = B;
   Q->izquierdo = P;

   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Eliminar un elemento de un árbol AVL
void AVL::Borrar(const int dat)
{
   NodoV *padre = NULL;
   NodoV *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
            // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
               else                         Equilibrar(padre, IZQUIERDO, false);
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::InOrden(void (*func)(int&, int) , NodoV *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato, nodo->FE);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void (*func)(int&, int), NodoV *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato, nodo->FE);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void (*func)(int&, int), NodoV *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato, nodo->FE);
}

// Buscar un valor en el árbol
bool AVL::Buscar(const int dat)
{
   actual = raiz;
   AVL *arbol= new AVL();

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato){
          cout<<actual->nombre;
            cout<<actual->dato;
          return true;} // dato encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}
bool AVL::BuscarNombre(string dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->nombre) return true; // dato encontrado
      else if(dat > actual->nombre) actual = actual->derecho; // Seguir
      else if(dat < actual->nombre) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el dato dat
int AVL::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // dato encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int AVL::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(NodoV *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void AVL::auxAltura(NodoV *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d, int FE)
{
   cout << d << "(" << FE << "),";
}

void AVL::ino()
{
    cout << endl;

    ino(raiz);

}
void AVL::ino(NodoV *raiz){

        if(raiz==NULL){return;}

        ino(raiz->izquierdo);
        if(raiz->estado){
            cout<<"-*- Id: "<<raiz->dato<<"; nombre: "<<raiz->nombre<<endl;
        }
        ino(raiz->derecho);

}

//int main()
//{

//  Operaciones *op= new Operaciones();
//  MatrizH *mat=new MatrizH();

//  //op->jugar();
//  op->primero();
//   // Un árbol de enteros
//   AVL ArbolInt;

   // Inserción de nodos en árbol:

//   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

//   // Mostrar el árbol en tres ordenes distintos:
//   cout << "InOrden: ";
//   ArbolInt.InOrden(Mostrar);
//   cout << endl;
//   cout << "PreOrden: ";
//   ArbolInt.PreOrden(Mostrar);
//   cout << endl;
//   cout << "PostOrden: ";
//   ArbolInt.PostOrden(Mostrar);
//   cout << endl;

//   ArbolInt.Borrar(8);
//   ArbolInt.Borrar(11);

//   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

//   // Mostrar el árbol en tres ordenes distintos:
//   cout << "InOrden: ";
//   ArbolInt.InOrden(Mostrar);
//   cout << endl;
//   cout << "PreOrden: ";
//   ArbolInt.PreOrden(Mostrar);
//   cout << endl;
//   cout << "PostOrden: ";
//   ArbolInt.PostOrden(Mostrar);
//   cout << endl;

/*   // Borraremos algunos elementos:
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   ArbolInt.Borrar(5);
   cout << "Borrar   5: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(8);
   cout << "Borrar   8: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(15);
   cout << "Borrar  15: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(245);
   cout << "Borrar 245: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(4);
   cout << "Borrar   4: ";
   ArbolInt.InOrden(Mostrar);
   ArbolInt.Borrar(17);
   cout << endl;
   cout << "Borrar  17: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   // Veamos algunos parámetros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   cin.get();

   // Arbol de cadenas:
   AVL<Cadena> ArbolCad;

   // Inserción de valores:
   ArbolCad.Insertar("Hola");
   ArbolCad.Insertar(",");
   ArbolCad.Insertar("somos");
   ArbolCad.Insertar("buenos");
   ArbolCad.Insertar("programadores");

   // Mostrar en diferentes ordenes:
   cout << "InOrden: ";
   ArbolCad.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolCad.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolCad.PostOrden(Mostrar);
   cout << endl;

   // Borrar "buenos":
   ArbolCad.Borrar("buenos");
   cout << "Borrar 'buenos': ";
   ArbolCad.InOrden(Mostrar);
   cout << endl; */
//   cin.get();
//   return 0;
//}
