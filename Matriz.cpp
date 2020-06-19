#include "Matriz.h"
#include "NodoArbol.h"
#include "Interfaz.h"
#include <bits/stdc++.h>
#include <windows.h>

Matriz::Matriz()
{
    this->root = new NodoMatriz("root",-1,"admin","admin");
    this->contadorN = 0;
}
void Matriz::obtenerRaices(){
    NodoMatriz *aux=this->root;

    while(aux!=NULL){
        if(aux->derecho!=NULL){

        }
        aux= aux->derecho;
    }
    aux=this->root;
    while(aux!=NULL){
        if(aux->abajo!=NULL){

        }
        aux= aux->abajo;
    }
    aux=this->root;
    aux=aux->derecho;
    while(aux!=NULL){
        NodoMatriz *temp= aux;
        NodoArbol *temp3;
        Avlt*temp4;
        Interfaz*temp5;
        temp=temp->abajo;

        while(temp!=NULL){
            cout<<temp->nombre+" v "<<" ";

            temp4->inorden(temp->tAvl->root);

            temp4->enorderR(temp->tAvl->root);


            temp=temp->abajo;
        }
        aux=aux->derecho;
    }
    aux=this->root;
    aux=aux->abajo;
    while(aux!=NULL){
        NodoMatriz *temp2= aux;
        temp2=temp2->derecho;

        while(temp2!=NULL){

            temp2=temp2->derecho;
        }
        aux=aux->abajo;
    }
}

NodoMatriz* Matriz::crearEmpresa(string nombre){
    NodoMatriz* creada = new NodoMatriz(nombre,contadorN++,"","");
    NodoMatriz* aux = this->root;
    while(aux->abajo!=NULL){
        aux=aux->abajo;
    }
    aux->abajo=creada;
    creada->arriba=aux;

    return creada;
}


NodoMatriz* Matriz::crearDepartamento(string nombre){
    NodoMatriz* creada = new NodoMatriz(nombre,contadorN++,"","");

    NodoMatriz* aux = this->root;
    while(aux->derecho!=NULL){
        aux=aux->derecho;
    }
    aux->derecho=creada;
    creada->izquierdo=aux;
    return creada;
}
NodoMatriz* Matriz::siExisteEmp(string empresa)
{
    NodoMatriz *usuarioNodo=NULL;
    NodoMatriz *empresaNodo;

    empresaNodo= this->BuscarEmpresa(empresa);

    if(empresaNodo!=NULL){
        NodoMatriz *tempE=empresaNodo->derecho;

        while(tempE!=NULL){

            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }

                NodoMatriz *tempU=tempE;
                return tempU;
                cout<<"usuario ya existenete\n"<<tempU->nombre;
                while(tempU->atras!=NULL){
                    tempU=tempU->atras;
                    return tempU;
                cout<<"usuario ya existenete\n"<<tempU->nombre;
                }

            tempE=tempE->derecho;

        }
    }
    return usuarioNodo;
}


NodoMatriz* Matriz::BuscarEmpresa(string nombre){
    NodoMatriz *aux = this->root;
    while(aux!=NULL){
        if(aux->nombre==nombre){
            return aux;
        }
        aux=aux->abajo;
    }
    return NULL;
}

NodoMatriz* Matriz::BuscarDepartamento(string nombre){
    NodoMatriz *aux = this->root;
    while(aux!=NULL){
        if(aux->nombre==nombre){
            return aux;
        }
        aux=aux->derecho;
    }
    return NULL;
}


void Matriz::obtenerRaicesUsuario(string* usuario){
    NodoMatriz *aux=this->root;

    while(aux!=NULL){
        if(aux->derecho!=NULL){

        }
        aux= aux->derecho;
    }
    aux=this->root;
    while(aux!=NULL){
        if(aux->abajo!=NULL){

        }
        aux= aux->abajo;
    }
    aux=this->root;
    aux=aux->derecho;
    while(aux!=NULL){
        NodoMatriz *temp= aux;
        NodoArbol *temp3;
        Avlt*temp4;
        Interfaz*temp5;
        temp=temp->abajo;

        while(temp!=NULL){
            cout<<temp->nombre+" v "<<" ";

            if(temp->nombre==usuario->c_str()){
               cout<<" lo encontro";

            }

            temp4->inorden(temp->tAvl->root);

            temp4->enorderR(temp->tAvl->root);

            temp=temp->abajo;
        }
        aux=aux->derecho;
    }
    aux=this->root;
    aux=aux->abajo;
    while(aux!=NULL){
        NodoMatriz *temp= aux;
        temp=temp->derecho;

        while(temp!=NULL){

            temp=temp->derecho;
        }
        aux=aux->abajo;
    }
}
void Matriz::obtenerUsuario(string us,string nombre,string user){
    NodoMatriz *temp=this->root;

    while(temp!=NULL){
        if(temp->derecho!=NULL){

        }
        temp= temp->derecho;
    }
    temp=this->root;
    while(temp!=NULL){
        if(temp->abajo!=NULL){

        }
        temp= temp->abajo;
    }
    temp=this->root;
    temp=temp->derecho;
    while(temp!=NULL){
        NodoMatriz *temp2= temp;
        NodoArbol *temp3;
        Avlt*temp4;
        Interfaz*temp5;
        temp2=temp2->abajo;

        while(temp2!=NULL){
            cout<<temp2->nombre+" v "<<" ";

            temp4->cambio(temp2->tAvl->root,nombre);



            temp2=temp2->abajo;
        }
        temp=temp->derecho;
    }
    temp=this->root;
    temp=temp->abajo;
    while(temp!=NULL){
        NodoMatriz *temp2= temp;
        temp2=temp2->derecho;

        while(temp2!=NULL){

            temp2=temp2->derecho;
        }
        temp=temp->abajo;
    }
}

void Matriz::insertarNodoMatriz(string name,string empresa,string departamento,string nameuser,string password,int contador){
    NodoMatriz *NodoUser;
    NodoMatriz *empresaNodo;
    NodoMatriz *departamentoNodo;

    NodoUser = new NodoMatriz(name,contador++,nameuser,password);

    empresaNodo= this->BuscarEmpresa(empresa);
    departamentoNodo = this->BuscarDepartamento(departamento);

    if(empresaNodo!=NULL && departamentoNodo!=NULL){
        NodoMatriz *tempE=empresaNodo->derecho;

        while(tempE!=NULL){

            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }
            if(tempD->nombre==departamento){
                NodoMatriz *tempU=tempE;
                if(tempU->nick==NodoUser->nick)
                {cout<<"usuario ya existenete\n";
                    return;}
                while(tempU->atras!=NULL){
                    tempU=tempU->atras;
                    if(tempU->nick==NodoUser->nick)
                    {cout<<"usuario ya existenete\n";
                        return;
                    }
                }
                tempU->atras=NodoUser;
                NodoUser->adelante=tempU;
                return;
            }
            tempE=tempE->derecho;

        }
    }

    if(empresaNodo==NULL){
        empresaNodo = this->crearEmpresa(empresa);
    }
    if(departamentoNodo==NULL){
        departamentoNodo = this->crearDepartamento(departamento);
    }


    if(departamentoNodo->abajo==NULL){
        departamentoNodo->abajo=NodoUser;
        NodoUser->arriba=departamentoNodo;
    }else if (empresaNodo->abajo==NULL){
        NodoMatriz* auxiliar = departamentoNodo->abajo;
        while(auxiliar->abajo!=NULL){
            auxiliar = auxiliar->abajo;
        }
        auxiliar->abajo = NodoUser;
        NodoUser->arriba = auxiliar;
    }else{
        NodoMatriz* auxD = departamentoNodo;

        do{
            auxD = auxD->abajo;
            NodoMatriz* auxE = auxD->izquierdo;
            while(auxE->izquierdo!=NULL){
                auxE=auxE->izquierdo;
            }
            while(auxE->arriba!=NULL){
                if(auxE->nombre==empresa){
                    NodoUser->abajo=auxD;
                    NodoUser->arriba=auxD->arriba;

                    auxD->arriba->abajo=NodoUser;
                    auxD->arriba=NodoUser;
                }
                auxE=auxE->arriba;
            }
        }while(auxD->abajo!=NULL && NodoUser->arriba==NULL);

        if(NodoUser->arriba==NULL){
            auxD->abajo=NodoUser;
            NodoUser->arriba=auxD;
        }
    }


    if(empresaNodo->derecho==NULL){
        empresaNodo->derecho = NodoUser;
        NodoUser->izquierdo =empresaNodo;
    }else if(departamentoNodo->derecho==NULL){
        NodoMatriz * auxiliar2 = empresaNodo->derecho;
        while(auxiliar2->derecho!=NULL){
            auxiliar2=auxiliar2->derecho;
        }
        auxiliar2->derecho=NodoUser;
        NodoUser->izquierdo = auxiliar2;
    }else{
        NodoMatriz* auxE = empresaNodo;

        do{
            auxE = auxE->derecho;
            NodoMatriz* auxD = auxE->arriba;
            while(auxD->arriba!=NULL){
                auxD=auxD->arriba;
            }
            while(auxD->izquierdo!=NULL){
                if(auxD->nombre==departamento){
                    NodoUser->derecho=auxE;
                    NodoUser->izquierdo=auxE->izquierdo;

                    auxE->izquierdo->derecho=NodoUser;
                    auxE->izquierdo=NodoUser;
                    break;
                }
                auxD=auxD->izquierdo;
            }
        }while(auxE->derecho!=NULL && NodoUser->izquierdo==NULL);
        if(NodoUser->izquierdo==NULL){
            auxE->derecho=NodoUser;
            NodoUser->izquierdo=auxE;
        }
    }

}

NodoMatriz* Matriz::siExiste(string usuarioN,string departamento,string empresa)
{
    NodoMatriz *NodoUsuario=NULL;
    NodoMatriz *empresaNodo;
    NodoMatriz *departamentoNodo;
    empresaNodo= this->BuscarEmpresa(empresa);
    departamentoNodo = this->BuscarDepartamento(departamento);
    if(empresaNodo!=NULL && departamentoNodo!=NULL){
        NodoMatriz *tempEmpre=empresaNodo->derecho;

        while(tempEmpre!=NULL){

            NodoMatriz *tempDep=tempEmpre->arriba;
            while(tempDep->arriba!=NULL){
                tempDep=tempDep->arriba;
            }
            if(tempDep->nombre==departamento){
                NodoMatriz *tempUser=tempEmpre;
                if(tempUser->nombre==usuarioN)
                {cout<<"usuario ya existenete\n";
                    return tempUser;
                }
                while(tempUser->atras!=NULL){
                    tempUser=tempUser->atras;
                    if(tempUser->nombre==usuarioN)
                    {cout<<"usuario ya existenete\n";
                        return tempUser;
                    }
                }
            }
            tempEmpre=tempEmpre->derecho;
        }
    }
    return NodoUsuario;
}


void Matriz::grafhMatriz(string nombre){
    NodoMatriz *temp= this->root;
    string cuerpoM="";
    ofstream escribe;
    escribe.open("matriz.dot", ios::out);
    escribe << "digraph Sparce_Matrix { \n node [shape=box];\n";
    cuerpoM+= to_string(temp->contador)+"[ label = \"root\", width = 1.5, style = filled, color = green, group = 1 ]; \n e0[ shape = point, width = 0 ]; \n e1[ shape = point, width = 0 ]; \n";

    temp=temp->abajo;

    int e=0;
    while(temp!=NULL){
        cuerpoM+= "\n /* Empresas */ \n";
        cuerpoM+= to_string(temp->contador) + " [label = \"" + temp->nombre + "\"    pos = \"5.3,3.5!\" width = 1.5 style = filled, color = gray, group = 1 ]; \n" ;
        if(temp->derecho!=NULL){
            string rankF="{ rank = same; "+to_string(temp->contador);
            NodoMatriz *tempf= temp->derecho;

            while(tempf!=NULL){
                rankF+=" ; "+to_string(tempf->contador);
                tempf= tempf->derecho;
            }
            rankF+=" }\n";
            cuerpoM+=rankF;

            tempf= temp->derecho;
            cuerpoM+= to_string(temp->contador)+" -> "+to_string(tempf->contador)+"\n" ;
            cuerpoM+= to_string(tempf-> contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempf->derecho!=NULL){
                cuerpoM+= to_string(tempf->contador)+" -> "+to_string(tempf->derecho->contador)+"\n" ;
                cuerpoM+= to_string(tempf->derecho->contador)+" -> "+to_string(tempf->contador)+"\n" ;
                tempf= tempf->derecho;
            }
        }
        cuerpoM+= "e"+to_string(e)+"[ shape = point, width = 0 ];";
        cuerpoM+= "{ rank = same; "+to_string(temp->contador)+"; e"+to_string(e)+" }";
        e++;
        temp=temp->abajo;

    }

    temp=this->root;
    temp=temp->abajo;
    while(temp->abajo!=NULL){
        cuerpoM+= "\n   /* Enlacex entre empresas */ \n";
        cuerpoM+= to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n" ;
        cuerpoM+= to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n" ;
        temp=temp->abajo;
    }


    temp=this->root;
    temp=temp->derecho;
    int contadorg=1;
    while(temp!=NULL){
        contadorg++;
        cuerpoM+= "\n /* Departamentos */ \n";
        cuerpoM+= to_string(temp->contador)+ " [label = \""+ temp->nombre +"\"   width = 1.5 style = filled, color = darkolivegreen2, group ="+to_string(contadorg) +" ];\n";

        if(temp->abajo!=NULL){
            NodoMatriz *tempc= temp->abajo;
            while(tempc!=NULL){

                string usuarios="";
                NodoMatriz *tempU = tempc;
                while(tempU!=NULL){
                    usuarios+="<tr><td>"+ tempU->nombre +"</td></tr>";
                    tempU=tempU->atras;
                }
                cuerpoM+=to_string(tempc->contador)+" [label = <<table border = \"0\">"+usuarios+"</table>>, width = 1.5, group = "+to_string(contadorg) +" ];\n";
                tempc= tempc->abajo;
            }
            tempc= temp->abajo;
            cuerpoM+= to_string(temp->contador)+" -> "+to_string(tempc->contador)+"\n" ;
            cuerpoM+= to_string(tempc->contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempc->abajo!=NULL){
                cuerpoM+= to_string(tempc->contador)+" -> "+to_string(tempc->abajo->contador)+"\n" ;
                cuerpoM+= to_string(tempc->abajo->contador)+" -> "+to_string(tempc->contador)+"\n" ;
                tempc=tempc->abajo;
            }

        }
        temp=temp->derecho;
    }

    temp=this->root;
    temp=temp->derecho;
    while(temp->derecho!=NULL){
        cuerpoM+= "\n   /* Enlaces entre departamentos */ \n";
        cuerpoM+= to_string(temp->contador)+" -> "+to_string(temp->derecho->contador) +"\n" ;
        cuerpoM+= to_string(temp->derecho->contador)+" -> "+to_string(temp->contador) +"\n";
        temp=temp->derecho;
    }
    cuerpoM+=to_string(temp->contador) + " -> e0 -> e1[ dir = none ];" ;
    temp=this->root;

    cuerpoM+=to_string(temp->contador)+" -> "+to_string(temp->derecho->contador)+"\n";
    cuerpoM+=to_string(temp->derecho->contador)+" -> "+to_string(temp->contador)+"\n";
    cuerpoM+=to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n";
    cuerpoM+=to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n";

    cuerpoM+=" { rank = same; -1; ";
    temp=temp->derecho;
    while(temp!=NULL){
        cuerpoM+=to_string(temp->contador)+"; ";
        temp=temp->derecho;
    }
    cuerpoM+=" }\n";
    temp=this->root;

    escribe << cuerpoM;
    escribe << "}";

    escribe.close();
nombre="matriz";
    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";

}

NodoArbol* Matriz::BuscarActivo(string id){
    NodoMatriz* aux1= this->root->derecho;

    while(aux1!=NULL){

        NodoMatriz* aux2= aux1->abajo;
        while(aux2!=NULL){

            NodoMatriz* aux3=aux2;
            while(aux3!=NULL){
                NodoArbol* activo= aux3->tAvl->buscarRaiz(aux3->tAvl->root,id);
                if(activo!=NULL){
                    return activo;
                }
                aux3=aux3->atras;
            }
            aux2=aux2->abajo;
        }
        aux1=aux1->derecho;
    }
    return NULL;
}

Matriz::~Matriz()
{

}
