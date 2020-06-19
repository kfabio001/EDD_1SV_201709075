#include "Avl.h"
#include "NodoMatriz.h"
#include "Matriz.h"
#include <bits/stdc++.h>
#include <windows.h>
Avlt::Avlt()
{
    this->root=NULL;
    this->cuerpoDot="";
}

void Avlt::yoRente(NodoArbol *raiz){
    if(raiz==NULL){return;}

    yoRente(raiz->izquierda);
    if(raiz->estado==false){
        cout<<"-*- Id: "<<raiz->id<<"; nombre: "<<raiz->nombre<<endl;
    }
    yoRente(raiz->derecha);
}
void Avlt::meRentaron(NodoArbol *raiz){
    if(raiz==NULL){return;}

    meRentaron(raiz->izquierda);
    if(raiz->descripcion=="rentado"){
        cout<<"-*- Id: "<<raiz->id<<"; nombre: "<<raiz->nombre<<endl;
    }
    meRentaron(raiz->derecha);
}


NodoArbol* Avlt::RsimpleDerechaIzquierda(NodoArbol *temp){
    NodoArbol* temp2;
    temp2= temp->izquierda;
    temp->izquierda=temp2->derecha;
    temp2->derecha=temp;
    temp2->altura = this->AlturaR(temp2);
    return temp2;
}

NodoArbol* Avlt::RdobleDerechaIzquierda(NodoArbol *temp){
    temp->izquierda=this->RsimpleDerechaDerecha(temp->izquierda);
    return RsimpleDerechaIzquierda(temp);
}
NodoArbol* Avlt::RdobleDerechaDerecha(NodoArbol *temp){
    temp->derecha=this->RsimpleDerechaIzquierda(temp->derecha);
    return RsimpleDerechaDerecha(temp);
}

int Avlt :: AlturaR(NodoArbol* raiz){
    if(raiz==NULL){return -1;}
    int alturaD0,alturaI0;
    alturaI0 = AlturaR(raiz->izquierda);
    alturaD0 = AlturaR(raiz->derecha);
    if(alturaI0==-1 && alturaD0==-1){raiz->altura=0; return 0;}
    if(alturaI0>alturaD0){ raiz->altura=alturaI0+1; return alturaI0+1; }else{ raiz->altura=alturaD0+1; return alturaD0+1; }
}

string Avlt::grafoArbol(){
    this->cuerpoDot="";
    this->cuerpoDot+="node [height=0.8, width=1.4];\n";
    this->bodyArbol(this->root);
    return this->cuerpoDot;
}
NodoArbol* Avlt::RsimpleDerechaDerecha(NodoArbol *temp){
    NodoArbol* temp2;
    temp2= temp->derecha;
    temp->derecha=temp2->izquierda;
    temp2->izquierda=temp;
    temp2->altura=this->AlturaR(temp2);
    return temp2;
}
int Avlt::Altura(NodoArbol* raiz){
    if(raiz==NULL){return -1;}
    int alturaD,alturaI;
    alturaI = Altura(raiz->izquierda);
    alturaD = Altura(raiz->derecha);
    if(alturaI==-1 && alturaD==-1){return 0;}
    if(alturaI>alturaD){ return alturaI+1; }else{ return alturaD+1; }
}
void Avlt::bodyArbol(NodoArbol *temp){

    if(temp!=NULL){
        this->bodyArbol(temp->izquierda);
        if(temp->estado){
            this->cuerpoDot+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=gray] \n";
        }else{
            this->cuerpoDot+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=red] \n";
        }

        if(temp->derecha!=NULL){
            this->cuerpoDot+= "\""+ temp->id + "\" -> \""+ temp->derecha->id+"\" \n";
        }
        if(temp->izquierda!=NULL){
            this->cuerpoDot+="\""+temp->id+"\" -> \""+temp->izquierda->id+"\" \n";
        }
        this->bodyArbol(temp->derecha);
    }
}

void Avlt::preorden(NodoArbol *raiz){
    if(raiz==NULL){ return; }

    cout<<raiz->nombre<<"),";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void Avlt::inorden(NodoArbol *temp){
    Matriz *m =new Matriz();


    if(temp!=NULL){


        inorden(temp->izquierda);
        if(temp->estado){
            m->cuerpoGraph+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=gray] \n";
        }else{
            m->cuerpoGraph+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=red] \n";
        }

        if(temp->derecha!=NULL){
            m->cuerpoGraph+= "\""+ temp->id + "\" -> \""+ temp->derecha->id+"\" \n";
        }
        if(temp->izquierda!=NULL){
            m->cuerpoGraph+="\""+temp->id+"\" -> \""+temp->izquierda->id+"\" \n";
        }
        inorden(temp->derecha);

    }

}
NodoArbol* Avlt::buscarRaiz(NodoArbol* raiz,string dato){
    if(raiz==NULL || raiz->id ==dato ){
        return raiz;
    }
    if(raiz->id > dato){
        return buscarRaiz(raiz->izquierda,dato);
    }
    return buscarRaiz(raiz->derecha,dato);
}
void Avlt::grafo(string cu){
    Matriz *m =new Matriz();
    contadorCata++;
    string nombre="PruebaArbol";
    ostringstream cata;
    cata<<nombre<<contadorCata;

    ofstream escribir;
    escribir.open(cata.str()+".dot", ios::out);
    escribir << "digraph G { \n";
   // grafica<<"node [height=0.6, width=1.4];\n";
    escribir<<"node [shape= record];\n";
    escribir <<cu;

    escribir << "}";

    escribir.close();

    string creacion = "dot -Tjpg " + cata.str() + ".dot -o " + cata.str() + ".jpg";
    system(creacion.c_str());
    string title = cata.str()  + ".jpg";

}
void Avlt::enorderR(NodoArbol *raiz){
    if(raiz==NULL){return;}

    enorderR(raiz->izquierda);

    if(raiz->estado){
        cout<<"-*- Id: "<<raiz->id<<"; nombre: "<<raiz->nombre<<endl;
    }
    enorderR(raiz->derecha);

}
void Avlt::cambio(NodoArbol *raiz,string nombre){
    if(raiz==NULL){return;}

    cambio(raiz->izquierda,nombre);
    if((raiz->estado)&&(raiz->nombre==nombre)){

        raiz->estado=false;

    }
    cambio(raiz->derecha,nombre);
}
void Avlt::inordenTodos(NodoArbol *raiz){
    if(raiz==NULL){return;}

    inorden(raiz->izquierda);
    if(raiz->estado){
        cout<<"-*- Id: "<<raiz->id<<"; nombre: "<<raiz->nombre<<endl;
    }
    inorden(raiz->derecha);
}

NodoArbol* Avlt::inorderE(NodoArbol* right){
    while(right->izquierda!=NULL){
        right= right->izquierda;
    }
    return right;
}

NodoArbol* Avlt::eliminar(NodoArbol* raiz,string dato){
    if(raiz == NULL){
        return raiz;
    }

    if(dato<raiz->id){
        raiz->izquierda = eliminar(raiz->izquierda,dato);
    }else if(dato>raiz->id){
        raiz ->derecha = eliminar(raiz->derecha,dato);
    }else{
        if(raiz->izquierda==NULL){
            return raiz->derecha;
        }else if(raiz->derecha==NULL){
            return raiz->izquierda;
        }else{
            NodoArbol* ordenar0=inorderE(raiz->derecha);
            raiz->id= ordenar0->id;
            raiz->descripcion=ordenar0->descripcion;
            raiz->estado=ordenar0->estado;
            raiz->nombre=ordenar0->nombre;
            raiz->derecha=eliminar(raiz->derecha,raiz->id);
        }

    }
    raiz=this->balanceo(raiz,dato);
    return raiz;
}

NodoArbol* Avlt::insertar(NodoArbol* raiz, string dato,string nombre,string descripcion){

    if (raiz==NULL){
        raiz = new NodoArbol(nombre,descripcion,dato);
    } else if(dato<raiz->id){
        raiz->izquierda= this->insertar(raiz->izquierda,dato,nombre,descripcion);

        if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
            if(dato<raiz->izquierda->id){
                raiz= RsimpleDerechaIzquierda(raiz);
            }else{
                raiz= RdobleDerechaIzquierda(raiz);
            }
        }
    } else if (dato>raiz->id){
        raiz->derecha = this->insertar(raiz->derecha,dato,nombre,descripcion);

        int der,izq;
        der=Altura(raiz->derecha);
        izq=Altura(raiz->izquierda);
        if( (der - izq)==2){
            if(dato>raiz->derecha->id){
                raiz= RsimpleDerechaDerecha(raiz);
            }else{
                raiz= RdobleDerechaDerecha(raiz);
            }
        }
    }else{
        cout<<"No se puede insertar datos duplicados"<<endl;
    }
    int maximo,de,iz;
    de= this->Altura(raiz->derecha);
    iz= this->Altura(raiz->izquierda);
    if(de>iz){maximo=de;}else{maximo=iz;}
    raiz->altura=maximo+1;
    return raiz;
}

NodoArbol* Avlt::balanceo(NodoArbol *raiz,string datoE){
    if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
        if(raiz->id>raiz->izquierda->id){

            raiz= RsimpleDerechaIzquierda(raiz);

            if( (Altura(raiz->derecha) - Altura(raiz->izquierda))==2){
                raiz= RdobleDerechaDerecha(raiz);
            }
        }else{
            raiz= RdobleDerechaIzquierda(raiz);
        }
    }else if( (Altura(raiz->derecha) - Altura(raiz->izquierda))==2){
        if(raiz->id<raiz->derecha->id){
            raiz= RsimpleDerechaDerecha(raiz);
            if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
                raiz= RdobleDerechaIzquierda(raiz);
            }
        }else{
            raiz= RdobleDerechaDerecha(raiz);
        }
    }
    return raiz;
}


Avlt::~Avlt()
{

}
