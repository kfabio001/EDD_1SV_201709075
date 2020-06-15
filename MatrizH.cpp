#include "MatrizH.h"
#include "Nodo.h"
void MatrizH::InsertarElemento(string usuario, string contra,int numero, string empresa, string departamento){
    NodoMa* NodoUrs;
    NodoMa* NodoDepa;
    NodoMa* NodoEmpresa;

    NodoUrs = new NodoMa(usuario, numero, contra);


    NodoDepa = buscarDepa(departamento, Cabecera);
    NodoEmpresa=buscarEmpresa(empresa, Cabecera);
//revisar si existe encabezado
    if(NodoDepa==nullptr)
        NodoDepa=crearDepartamento(departamento);
    if(NodoEmpresa==nullptr)
        NodoEmpresa =crearEmpresa(empresa);
// insertar en depa
    //inicio
    if(NodoDepa->abajo==nullptr){
        NodoDepa->abajo=NodoUrs;
        NodoUrs->arriba=NodoDepa;
    }
    //insertar final
    else if(NodoEmpresa->abajo==nullptr){
        NodoMa* aux=NodoDepa->abajo;
        while(aux->abajo!=nullptr){
            aux=aux->abajo;
        }
        if(!VerificarEmpresa(empresa,aux, NodoUrs))
        {
            aux->abajo=NodoUrs;
            NodoUrs->arriba=aux;
        }
    }
    //insertar enmedio
    else{
        NodoMa* aux=NodoDepa;
        do{
            aux=aux->abajo;
            if(!VerificarEmpresa(empresa, aux, NodoUrs)){
              NodoMa *auxEmpr=aux->izquierda;
              while(auxEmpr->izquierda!=nullptr){
                  auxEmpr=auxEmpr->izquierda;
              }
              while(auxEmpr->arriba!= nullptr){
                  if(auxEmpr->Nombre== empresa){
                      NodoUrs->abajo=aux;
                      NodoUrs->arriba=aux->arriba;
                      aux->arriba->abajo=NodoUrs;
                      aux->arriba=NodoUrs;
                      break;
                  }
                  auxEmpr=auxEmpr->arriba;
              }
            }

        }while(aux->abajo!=nullptr && NodoUrs->arriba==nullptr);
        if(NodoUrs->arriba==nullptr&&NodoUrs->adelante==nullptr){
            aux->abajo=NodoUrs;
            NodoUrs->arriba=aux;
        }
    }
    if(NodoUrs->adelante!=nullptr){
        return;
    }
    //insertar en nodo empresa
    //insertando inicio
    if(NodoEmpresa->derecha==nullptr){
        NodoEmpresa->derecha=NodoUrs;
        NodoUrs->izquierda=NodoEmpresa;
    }
    else if(NodoDepa->derecha==nullptr){
        NodoMa*aux =NodoEmpresa->derecha;
        while(aux->derecha!= nullptr)
        {
            aux=aux->derecha;
        }if(!VerificarDepartamento(departamento, aux, NodoUrs)){
            aux->derecha=NodoUrs;
            NodoUrs->izquierda=aux;
        }
    }
    else{
        NodoMa*aux=NodoEmpresa;
        do{
            aux=aux->derecha;
            if(!VerificarDepartamento(departamento,aux, NodoUrs)){
                NodoMa*auxDepa=aux->arriba;
                while(auxDepa->arriba!=nullptr){
                    auxDepa=auxDepa->arriba;
                }
                while(auxDepa->izquierda!=nullptr){
                    if(auxDepa->Nombre==departamento){
                        NodoUrs->derecha=aux;
                        NodoUrs->izquierda=aux->izquierda;

                        aux->izquierda->derecha=NodoUrs;
                        aux->izquierda=NodoUrs;
                        break;
                    }
                    auxDepa=auxDepa->izquierda;
                }
            }

        }while(aux->derecha!=nullptr&&NodoUrs->izquierda==nullptr);
    if(NodoUrs->izquierda==nullptr&&NodoUrs->adelante==nullptr){
        aux->derecha=NodoUrs;
        NodoUrs->izquierda=aux;
    }
    }
}

NodoMa* MatrizH::crearEmpresa(string empresa){
    NodoMa* emp;
    emp = new NodoMa(empresa, -1,"");
    NodoMa* aux = Cabecera;
    while(aux->abajo != nullptr)
    {
        aux = aux ->abajo;

    }
    aux->abajo=emp;
    emp->arriba=aux;
    return emp;
}
NodoMa* MatrizH::crearDepartamento(string departamento)
{
    NodoMa* depa;
    depa = new NodoMa(departamento, -1,"");
    NodoMa* aux = Cabecera;
    while(aux->derecha!= nullptr){
        aux=aux->derecha;
    }
    aux->derecha=depa;
    depa->izquierda=aux;
    return depa;

}
NodoMa* MatrizH::buscarDepa(string departamento, NodoMa* inicio){
    NodoMa* aux = inicio;
    while (aux!= nullptr){
        if(aux->Nombre == departamento)
            return aux;
        aux=aux -> derecha;
    }
    return nullptr;
}
NodoMa* MatrizH::buscarEmpresa(string empresa, NodoMa* inicio){
    NodoMa* aux = inicio;
    while(aux!= nullptr)
    {
        if(aux->Nombre== empresa)
            return aux;
        aux = aux -> abajo;
    }
    return nullptr;
}
bool MatrizH::VerificarEmpresa(string empresa, NodoMa* Inicio, NodoMa* Usr){
    NodoMa* auxEmp=Inicio->izquierda;
    while (auxEmp->izquierda != nullptr){
        auxEmp=auxEmp->izquierda;
    }
    if(auxEmp->Nombre==empresa)
    {
        while(Inicio->atras!=nullptr){
            Inicio=Inicio->atras;
        }
        Inicio->atras=Usr;
        Usr->adelante=Inicio;
        return true;
    }
    return false;
}
bool MatrizH::VerificarDepartamento(string departamento, NodoMa* Inicio, NodoMa* Usr){
    NodoMa* auxDepa=Inicio->arriba;
    while (auxDepa->arriba != nullptr){
        auxDepa=auxDepa->arriba;
    }
    if(auxDepa->Nombre==departamento)
    {
       while(Inicio->atras!=nullptr){
           Inicio=Inicio->atras;
       }
       Inicio->atras=Usr;
       Usr->adelante=Inicio;
       return true;
    }
    return false;
}
void MatrizH::print(){
    NodoMa* aux = Cabecera;
    while(aux->abajo != nullptr)
    {
        std::cout << aux->Nombre<<" ";
        aux = aux ->abajo;
std::cout << " \n";
    }
    std::cout << " \n";
    aux=Cabecera;
    while(aux->derecha != nullptr)
    {
        std::cout << aux->Nombre<<" ";
        aux = aux ->derecha;
std::cout << " \n";
    }

}
bool MatrizH::busquedaSoloUsuario(string usuario, string departamento, string empresa){

    NodoMa* aux =Cabecera;

    while(aux->abajo != nullptr)
    {
        aux = aux ->abajo;
        if(aux->Nombre==empresa){
            aux=Cabecera;
            while(aux->derecha != nullptr)
            {
                aux = aux ->derecha;

                if(aux->Nombre==departamento){
                    while(aux->abajo != nullptr)
                    {
                        aux = aux ->abajo;


                        if(aux->Nombre==usuario){


                                std::cout <<  aux->Nombre << " datos correctos\n";

                                return true;
                                // break;

                        }else{
                            while(aux->atras!=nullptr){
                                //aux=aux->atras;
                                aux=aux->atras;
                                if(aux->Nombre==usuario){

                                        std::cout <<  aux->Nombre << " datos correctos\n";

                                        return true;
                                        // break;

                                }
                            }
                        }
                    }
                }

            }
        }

    }
}
bool MatrizH::busquedaUsuario(string usuario,string contra, string departamento, string empresa){

    NodoMa* aux =Cabecera;

    while(aux->abajo != nullptr)
    {
        aux = aux ->abajo;
        if(aux->Nombre==empresa){
            aux=Cabecera;
            while(aux->derecha != nullptr)
            {
                aux = aux ->derecha;

                if(aux->Nombre==departamento){
                    while(aux->abajo != nullptr)
                    {
                        aux = aux ->abajo;


                        if(aux->Nombre==usuario){

                            if(aux->contra==contra){
                                std::cout <<  aux->Nombre << " datos correctos\n";

                                return true;
                                // break;
                            }
                        }else{
                            while(aux->atras!=nullptr){
                                //aux=aux->atras;
                                aux=aux->atras;
                                if(aux->Nombre==usuario){
                                    if(aux->contra==contra){
                                        std::cout <<  aux->Nombre << " datos correctos\n";

                                        return true;
                                        // break;
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }

    }
}

NodoMa* MatrizH::eliminarElemento(string usuario, string departamento, string empresa){

    NodoMa* aux =Cabecera;
    NodoMa* eliminado;

    while(aux->abajo != nullptr)
    {
        aux = aux ->abajo;
        if(aux->Nombre==empresa){
            aux=Cabecera;
            while(aux->derecha != nullptr)
            {
                aux = aux ->derecha;

                if(aux->Nombre==departamento){
                    while(aux->abajo != nullptr)
                    {
                        aux = aux ->abajo;


                        if(aux->Nombre==usuario){

                            if((aux->derecha==nullptr)&&(aux->abajo==nullptr)){//derecha nulo y abajo nulo
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" derecho nulo\n";
                                eliminado=aux;
                                aux=  aux->izquierda;
                                aux->derecha=nullptr;
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" eliminado\n";
                                aux=eliminado;
                                aux=aux->arriba;
                                aux->abajo=nullptr;
                                //aux->arriba
                                delete(eliminado);
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" derecho nulo\n";

                            }else if((aux->derecha!=nullptr)&&(aux->abajo!=nullptr)){
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" derecho y abajo hay\n";
                                eliminado=aux;
                                aux=aux->izquierda;
                                aux->derecha=aux->derecha->derecha;
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" eliminado derecha\n";
                                aux=eliminado;
                                aux=aux->arriba;
                                aux->abajo=aux->abajo->abajo;
                                //delete(eliminado);
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<"  abajo eliminado\n";
                            }else if((aux->derecha==nullptr)&&(aux->abajo!=nullptr)){//derecha nulo
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" derecho nulo y abajo hay\n";
                                eliminado=aux;
                                aux=aux->izquierda;
                                aux->derecha=nullptr;
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" eliminado derecha\n";
                                aux=eliminado;
                                aux=aux->arriba;
                                aux->abajo=aux->abajo->abajo;
                                //delete(eliminado);
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<"  abajo eliminado\n";

                            }else if((aux->derecha!=nullptr)&&(aux->abajo==nullptr)){//abajo nulo

                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" derecho hay y abajo nulo\n";
                                eliminado=aux;
                                aux=aux->izquierda;
                                aux->derecha=aux->derecha->derecha;
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" eliminado derecha\n";
                                aux=eliminado;
                                aux=aux->arriba;
                                aux->abajo=nullptr;
                                //delete(eliminado);
                                std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<"  abajo eliminado\n";
                            }

                        }else{
                            while(aux->atras!=nullptr){
                                //aux=aux->atras;
                                aux=aux->atras;
                                if(aux->Nombre==usuario){

                                    if(aux->atras==nullptr){
                                        std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" atras nulo\n";
                                        eliminado=aux;
                                        aux=aux->adelante;
                                        aux->atras=nullptr;
                                        //delete(eliminado);
                                        std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<"eliminado atras nulo\n";
                                    }else{
                                        std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" atras hay\n";
                                        eliminado=aux;
                                        aux=aux->atras;
                                        aux->adelante=aux->adelante->adelante;
                                        std::cout <<  aux->Nombre << " "<<aux->abajo<< " "<<aux->derecha << " "<<aux->izquierda << " "<<aux->arriba  << " "<<aux->atras << " "<<aux->adelante<<" atras nulo\n";
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }

    }
}
bool MatrizH::busquedaEmp(string empB){

    NodoMa* aux = Cabecera;
    while(aux->abajo != nullptr)
    {
        // std::cout << aux->Nombre<<" ";
        aux = aux ->abajo;


        if(aux->Nombre==empB){
            //std::cout <<  " existe emp" << '\n';
            return true;
        }else{
            // return false;
        }
    }
    std::cout << " \n";
    // aux=mate->Cabecera;
}
bool MatrizH::busquedaDepa(string depaB){
    NodoMa* aux = Cabecera;
    while(aux->derecha != nullptr)
    {
        //std::cout << aux->Nombre<<" ";
        aux = aux ->derecha;
        if(aux->Nombre==depaB){
            //std::cout <<  " existe depa" << '\n';
            return true;
        }else{
            //return false;
        }
    }
    std::cout << " \n";
}

