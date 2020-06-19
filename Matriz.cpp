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

NodoMatriz* Matriz::createEmpresa(string name){
    NodoMatriz* empresaC = new NodoMatriz(name,contadorN++,"","");

    NodoMatriz* temp = this->root;
    while(temp->abajo!=NULL){
        temp=temp->abajo;
    }
    temp->abajo=empresaC;
    empresaC->arriba=temp;

    return empresaC;
}


NodoMatriz* Matriz::createDepartamento(string name){
    NodoMatriz* departamentoC = new NodoMatriz(name,contadorN++,"","");

    NodoMatriz* temp = this->root;
    while(temp->derecho!=NULL){
        temp=temp->derecho;
    }
    temp->derecho=departamentoC;
    departamentoC->izquierdo=temp;
    return departamentoC;
}



NodoMatriz* Matriz::searchEmpresa(string nombre){
    NodoMatriz *temp = this->root;
    while(temp!=NULL){
        if(temp->nombre==nombre){
            return temp;
        }
        temp=temp->abajo;
    }
    return NULL;
}

NodoMatriz* Matriz::searchDepartamento(string nombre){
    NodoMatriz *temp = this->root;
    while(temp!=NULL){
        if(temp->nombre==nombre){
            return temp;
        }
        temp=temp->derecho;
    }
    return NULL;
}

void Matriz::obtenerRaices(){
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

            temp4->inorden(temp2->tAvl->root);

            temp4->enorderR(temp2->tAvl->root);


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
void Matriz::obtenerRaicesUsuario(string* usuario){
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

            if(temp2->nombre==usuario->c_str()){
               cout<<" lo encontro";

            }

            temp4->inorden(temp2->tAvl->root);

            temp4->enorderR(temp2->tAvl->root);

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
    NodoMatriz *user;
    NodoMatriz *empresaN;
    NodoMatriz *departamentoN;

    user = new NodoMatriz(name,contador++,nameuser,password);

    empresaN= this->searchEmpresa(empresa);
    departamentoN = this->searchDepartamento(departamento);

    if(empresaN!=NULL && departamentoN!=NULL){
        NodoMatriz *tempE=empresaN->derecho;

        while(tempE!=NULL){

            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }
            if(tempD->nombre==departamento){
                NodoMatriz *tempU=tempE;
                if(tempU->nick==user->nick){cout<<"usuario ya existenete\n"; return;}
                while(tempU->atras!=NULL){
                    tempU=tempU->atras;
                    if(tempU->nick==user->nick){cout<<"usuario ya existenete\n"; return;}
                }
                tempU->atras=user;
                user->adelante=tempU;
                return;
            }
            tempE=tempE->derecho;

        }
    }

    if(empresaN==NULL){ empresaN = this->createEmpresa(empresa); }
    if(departamentoN==NULL){ departamentoN = this->createDepartamento(departamento); }


    if(departamentoN->abajo==NULL){
        departamentoN->abajo=user;
        user->arriba=departamentoN;
    }else if (empresaN->abajo==NULL){
        NodoMatriz* auxiliar = departamentoN->abajo;
        while(auxiliar->abajo!=NULL){
            auxiliar = auxiliar->abajo;
        }
        auxiliar->abajo = user;
        user->arriba = auxiliar;
    }else{
        NodoMatriz* auxD = departamentoN;

        do{
            auxD = auxD->abajo;
            NodoMatriz* auxE = auxD->izquierdo;
            while(auxE->izquierdo!=NULL){
                auxE=auxE->izquierdo;
            }
            while(auxE->arriba!=NULL){
                if(auxE->nombre==empresa){
                    user->abajo=auxD;
                    user->arriba=auxD->arriba;

                    auxD->arriba->abajo=user;
                    auxD->arriba=user;
                }
                auxE=auxE->arriba;
            }
        }while(auxD->abajo!=NULL && user->arriba==NULL);

        if(user->arriba==NULL){
            auxD->abajo=user;
            user->arriba=auxD;
        }
    }


    if(empresaN->derecho==NULL){
        empresaN->derecho = user;
        user->izquierdo =empresaN;
    }else if(departamentoN->derecho==NULL){
        NodoMatriz * auxiliar2 = empresaN->derecho;
        while(auxiliar2->derecho!=NULL){
            auxiliar2=auxiliar2->derecho;
        }
        auxiliar2->derecho=user;
        user->izquierdo = auxiliar2;
    }else{
        NodoMatriz* auxE = empresaN;

        do{
            auxE = auxE->derecho;
            NodoMatriz* auxD = auxE->arriba;
            while(auxD->arriba!=NULL){
                auxD=auxD->arriba;
            }
            while(auxD->izquierdo!=NULL){
                if(auxD->nombre==departamento){
                    user->derecho=auxE;
                    user->izquierdo=auxE->izquierdo;

                    auxE->izquierdo->derecho=user;
                    auxE->izquierdo=user;
                    break;
                }
                auxD=auxD->izquierdo;
            }
        }while(auxE->derecho!=NULL && user->izquierdo==NULL);
        if(user->izquierdo==NULL){
            auxE->derecho=user;
            user->izquierdo=auxE;
        }
    }

}

NodoMatriz* Matriz::existe(string user,string departamento,string empresa)
{
    NodoMatriz *userR=NULL;
    NodoMatriz *empresaN;
    NodoMatriz *departamentoN;
    empresaN= this->searchEmpresa(empresa);
    departamentoN = this->searchDepartamento(departamento);
    if(empresaN!=NULL && departamentoN!=NULL){
        NodoMatriz *tempE=empresaN->derecho;

        while(tempE!=NULL){

            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }
            if(tempD->nombre==departamento){
                NodoMatriz *tempU=tempE;
                if(tempU->nombre==user){cout<<"usuario ya existenete\n"; return tempU;}
                while(tempU->atras!=NULL){
                    tempU=tempU->atras;
                    if(tempU->nombre==user){cout<<"usuario ya existenete\n"; return tempU;}
                }
            }
            tempE=tempE->derecho;

        }
    }
    return userR;
}
NodoMatriz* Matriz::existeEmp(string empresa)
{
    NodoMatriz *userR=NULL;
    NodoMatriz *empresaN;

    empresaN= this->searchEmpresa(empresa);

    if(empresaN!=NULL){
        NodoMatriz *tempE=empresaN->derecho;

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
    return userR;
}

void Matriz::graficarMatriz(string nombre){
    NodoMatriz *temp= this->root;
    string prueba="";
    ofstream grafica;
    grafica.open("Prueba.dot", ios::out);
    grafica << "digraph Sparce_Matrix { \n node [shape=box];\n";
    prueba+= to_string(temp->contador)+"[ label = \"root\", width = 1.5, style = filled, color = firebrick1, group = 1 ]; \n e0[ shape = point, width = 0 ]; \n e1[ shape = point, width = 0 ]; \n";

    temp=temp->abajo;

    int e=0;
    while(temp!=NULL){
        prueba+= "\n /* Empresas */ \n";
        prueba+= to_string(temp->contador) + " [label = \"" + temp->nombre + "\"    pos = \"5.3,3.5!\" width = 1.5 style = filled, color = coral1, group = 1 ]; \n" ;
        if(temp->derecho!=NULL){
            string rankF="{ rank = same; "+to_string(temp->contador);
            NodoMatriz *tempf= temp->derecho;

            while(tempf!=NULL){
                rankF+=" ; "+to_string(tempf->contador);
                tempf= tempf->derecho;
            }
            rankF+=" }\n";
            prueba+=rankF;

            tempf= temp->derecho;
            prueba+= to_string(temp->contador)+" -> "+to_string(tempf->contador)+"\n" ;
            prueba+= to_string(tempf-> contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempf->derecho!=NULL){
                prueba+= to_string(tempf->contador)+" -> "+to_string(tempf->derecho->contador)+"\n" ;
                prueba+= to_string(tempf->derecho->contador)+" -> "+to_string(tempf->contador)+"\n" ;
                tempf= tempf->derecho;
            }
        }
        prueba+= "e"+to_string(e)+"[ shape = point, width = 0 ];";
        prueba+= "{ rank = same; "+to_string(temp->contador)+"; e"+to_string(e)+" }";
        e++;
        temp=temp->abajo;

    }

    temp=this->root;
    temp=temp->abajo;
    while(temp->abajo!=NULL){
        prueba+= "\n   /* Enlacex entre empresas */ \n";
        prueba+= to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n" ;
        prueba+= to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n" ;
        temp=temp->abajo;
    }


    temp=this->root;
    temp=temp->derecho;
    int contadorg=1;
    while(temp!=NULL){
        contadorg++;
        prueba+= "\n /* Departamentos */ \n";
        prueba+= to_string(temp->contador)+ " [label = \""+ temp->nombre +"\"   width = 1.5 style = filled, color = darkolivegreen2, group ="+to_string(contadorg) +" ];\n";

        if(temp->abajo!=NULL){
            NodoMatriz *tempc= temp->abajo;
            while(tempc!=NULL){

                string usuarios="";
                NodoMatriz *tempU = tempc;
                while(tempU!=NULL){
                    usuarios+="<tr><td>"+ tempU->nombre +"</td></tr>";
                    tempU=tempU->atras;
                }
                prueba+=to_string(tempc->contador)+" [label = <<table border = \"0\">"+usuarios+"</table>>, width = 1.5, group = "+to_string(contadorg) +" ];\n";
                tempc= tempc->abajo;
            }
            tempc= temp->abajo;
            prueba+= to_string(temp->contador)+" -> "+to_string(tempc->contador)+"\n" ;
            prueba+= to_string(tempc->contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempc->abajo!=NULL){
                prueba+= to_string(tempc->contador)+" -> "+to_string(tempc->abajo->contador)+"\n" ;
                prueba+= to_string(tempc->abajo->contador)+" -> "+to_string(tempc->contador)+"\n" ;
                tempc=tempc->abajo;
            }

        }
        temp=temp->derecho;
    }

    temp=this->root;
    temp=temp->derecho;
    while(temp->derecho!=NULL){
        prueba+= "\n   /* Enlaces entre departamentos */ \n";
        prueba+= to_string(temp->contador)+" -> "+to_string(temp->derecho->contador) +"\n" ;
        prueba+= to_string(temp->derecho->contador)+" -> "+to_string(temp->contador) +"\n";
        temp=temp->derecho;
    }
    prueba+=to_string(temp->contador) + " -> e0 -> e1[ dir = none ];" ;
    temp=this->root;

    prueba+=to_string(temp->contador)+" -> "+to_string(temp->derecho->contador)+"\n";
    prueba+=to_string(temp->derecho->contador)+" -> "+to_string(temp->contador)+"\n";
    prueba+=to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n";
    prueba+=to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n";

    prueba+=" { rank = same; -1; ";
    temp=temp->derecho;
    while(temp!=NULL){
        prueba+=to_string(temp->contador)+"; ";
        temp=temp->derecho;
    }
    prueba+=" }\n";
    temp=this->root;

    grafica << prueba;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";

}

NodoArbol* Matriz::serachActivo(string id){
    NodoMatriz* tempNM= this->root->derecho;

    while(tempNM!=NULL){

        NodoMatriz* tempU= tempNM->abajo;
        while(tempU!=NULL){

            NodoMatriz* tempU2=tempU;
            while(tempU2!=NULL){
                NodoArbol* activo= tempU2->tAvl->buscarRaiz(tempU2->tAvl->root,id);
                if(activo!=NULL){
                    return activo;
                }
                tempU2=tempU2->atras;
            }
            tempU=tempU->abajo;
        }
        tempNM=tempNM->derecho;
    }
    return NULL;
}

Matriz::~Matriz()
{

}
