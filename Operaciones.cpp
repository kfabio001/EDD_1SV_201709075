#include "Operaciones.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include<time.h>

using namespace std;
MatrizH *mate=new MatrizH();
AVL *arbol=new AVL();

Operaciones::Operaciones(){

}
Operaciones::Operaciones(MatrizH* ma){

this->m=ma;
    this->userE=NULL;

}
void Operaciones::primero(){
    int entrada;
    string usuario;
    string contra;string departamento;string empresa;
    NodoMa*  aux1;
    NodoMa*  aux2;
    char admin[]= "admin";
    char adminC[]= "admin";

    cout<<"******************************************************\n";
    cout<<"******************************************************\n";
    cout<<"                   BIENVENIDO A\n";
    cout<<"                 RENTA DE ARCHIVOS\n";
    cout<<"  Escriba una opcion de inicio de sesion:\n";
    cout<<"  1.Iniciar sesion Administrador:\n";
    cout<<"  2.Iniciar sesion Usuario:\n";
    cout<<"  3.pruebas:\n";
    cout<<"\n";
    cin>>entrada;

    switch(entrada){

    case 1://inicia sesion admin
    system("cls");
    cout<<"  Iniciar sesion Administrador:\n";
    cout<<"  Ingrese usuario administrador:\n";
    cin>>usuario;
    strcpy(cadena1,usuario.c_str());
    cout<<"  Ingrese contraseña administrador:\n";
    cin>>contra;
    strcpy(cadena2,contra.c_str());

    if((strcmp(cadena1,admin)==0)&&(strcmp(cadena1,adminC)==0)){
        cout<<"El usuario o contraseña son correctos\n";
       menuAdmin();


    }else{
    cout<<"El usuario o contraseña son incorrectos\n";
    cout<<" presione 1 para volver";
    cin>>entrada;
    if(entrada==1){
        primero();
    }
    }
    break;
    case 2://inicia sesion usario
    system("cls");
    //prueba();
    mate->InsertarElemento("1","1",1,"1","1");
    cout<<"  Iniciar sesion Usuario:\n";
    cout<<"  Ingrese Nombre de usuario:\n";
    cin>>usuario;
    cout<<"  Ingrese Contraseña:\n";
    cin>>contra;
    cout<<"  Ingrese Departamento:\n";
    cin>>departamento;
    cout<<"  Ingrese Empresa:\n";
    cin>>empresa;

    //mate->print();

    if((mate->busquedaEmp(empresa)==true)&&(mate->busquedaDepa(departamento)==true)){

    if(mate->busquedaUsuario(usuario,contra,departamento,empresa)==true){
        globalUsuario=usuario;
        globalDepartamento=departamento;

    globalEmpresa=empresa;
    cout<<" Si existe:\n";
    menuUsuario();
    }else{
    cout<<"  No existe:\n";
    cout<<" :\n presione 1 para volver";
    cin>>entrada;
    if(entrada==1){
        primero();
    }
    }
}

        break;
     case 3:
            system("cls");
            prueba();
           // mate->print();


//            arbol->Insertar(globalActivos,"nombre1","alpa",true,"descripcion");
//            globalActivos++;
//            arbol->Insertar(globalActivos,"nombre2","alpa",true,"descripcion");
//            globalActivos++;
//            arbol->Insertar(globalActivos,"nombre3","alpa",true,"descripcion");
//            globalActivos++;
//            arbol->Insertar(globalActivos,"nombre4","alpa",true,"descripcion");
//            globalActivos++;
//            arbol->Insertar(globalActivos,"nombre5","alpa",true,"descripcion");
//            globalActivos++;
//            arbol->Insertar(globalActivos,"nombre6","alpa",true,"descripcion");

//            globalActivos++;
            arbol->ino();

            cout<<"fin";
            cout<<" :\n presione 1 para volver";
            cin>>entrada;
            if(entrada==1){
                primero();
            }
           // mat->print();
      break;

    }


}
void Operaciones::prueba(){

    mate->InsertarElemento("Mynor","contra",1,"max","Guatemala");
    mate->InsertarElemento("Izabel","contra",2,"wallmart","Jutiapa");
    mate->InsertarElemento("Hello","contra",3,"panasonic","Jalapa");
    mate->InsertarElemento("wiiii","contra",4,"sony","peten");
    mate->InsertarElemento("pink","contra",5,"nintendo","Izabal");
    mate->InsertarElemento("pink","contra",6,"wallmart","Jutiapa");
    mate->InsertarElemento("pinky","contra",7,"wallmart","Jutiapa");
    mate->InsertarElemento("derecha","contra",8,"panasonic","peten");


}

void Operaciones::menuAdmin(){
    int entrada;
    string usuario;
    string contra;string departamento;string empresa;
    string enteer;
    NodoMa*  aux1;
    NodoMa*  aux2;
    char admin[]= "admin";
    char adminC[]= "admin";

    cout<<"******************************************************\n";
    cout<<"******************************************************\n";
    cout<<"               BIENVENIDO ADMINISTRADOR\n";
    cout<<"                 RENTA DE ARCHIVOS\n";
    cout<<"  Escriba una opcion de inicio de sesion:\n";
    cout<<"  1.Crear usuario:\n";
    cout<<"  2.Eliminar usuario:\n";
    cout<<"  3.Modificar usuario:\n";
    cout<<"\n";
    cin>>entrada;

    switch(entrada){

    case 1://             crear usuario
       //
    system("cls");
    cout<<"  Ingrese datos del usuario:\n\n";
    cout<<"  Ingrese Nombre de usuario:\n";
    cin>>usuario;
    cout<<"  Ingrese Contraseña:\n";
    cin>>contra;
    cout<<"  Ingrese Departamento:\n";
    cin>>departamento;
    cout<<"  Ingrese Empresa:\n";
    cin>>empresa;
    mate->InsertarElemento(usuario,contra,1,empresa,departamento);

    cout<<"  Usuario ingresado \n"<<usuario;
    mate->print();
    cout<<"  Nodo insertado:\n presione 1 para volver";
    cin>>entrada;
    if(entrada==1){
        menuAdmin();
    }
    break;
    case 2://                   elimanr
    system("cls");
    prueba();
    mate->print();
    cout<<"  Eliminar Usuario:\n";
    cout<<"  Ingrese Nombre de usuario a eliminar:\n";
    cin>>usuario;
    cout<<"  Ingrese Departamento del usuario:\n";
    cin>>departamento;
    cout<<"  Ingrese Empresa del usuario a eliminar:\n";
    cin>>empresa;


   // if((mate->busquedaEmp(empresa)==true)&&(mate->busquedaDepa(departamento)==true)){
    if(mate->busquedaSoloUsuario(usuario,departamento,empresa)==true){
        cout<<"  Si existe:\n";
    mate->eliminarElemento(usuario,departamento,empresa);
    //prueba();
    mate->print();
    //cout<<"  Nodo eliminado:\n";
   if( mate->busquedaSoloUsuario(usuario,departamento,empresa)!=true){
       cout<<"  Nodo eliminado:\n presione 1 para volver";
       cin>>entrada;
       if(entrada==1){
           menuAdmin();
       }

   }
    }else{
    cout<<"  No existe no se elimino:\n presione 1 para volver";
    cin>>entrada;
    if(entrada==1){
        menuAdmin();
    }
    entrada=2;

    }


        break;
     case 3:
            system("cls");
            cout<<"  Modificar Usuario:\n";
            cout<<"  Ingrese Nombre de usuario a modificar:\n";
            cin>>usuario;
            cout<<"  Ingrese Departamento del usuario:\n";
            cin>>departamento;
            cout<<"  Ingrese Empresa del usuario a modificar:\n";
            cin>>empresa;
            if(mate->busquedaSoloUsuario(usuario,departamento,empresa)==true){

            mate->eliminarElemento(usuario,departamento,empresa);
}else{
                cout<<" Nodo no modificado \n presione 1 para volver";
                cin>>entrada;
                if(entrada==1){
                    menuAdmin();

    }
            }
            //mate->print();
            cout<<"  Nodo encontrado:\n"<<usuario<<"  "<<empresa<<"  "<<departamento;
            cout<<"  Ingrese Nombre de usuario a reemplazar:\n";
            cin>>usuario;
            cout<<"  Ingrese Contraseña de usuario a reemplazar:\n";
            cin>>contra;
            //cout<<"  Ingrese Departamento del usuario a reemplazar:\n";
            //cin>>departamento;
            //cout<<"  Ingrese Empresa del usuario a reemplazar:\n";
            //cin>>empresa;
            mate->InsertarElemento(usuario,contra,1,empresa,departamento);
            cout<<"  Nodo modificado:\n"<<usuario<<" "<<contra<<"  "<<empresa<<"  "<<departamento;
            cout<<"  \n presione 1 para volver";
            cin>>entrada;
            if(entrada==1){
                menuAdmin();

}
      break;
    case 4:

        primero();
        break;
    }


    //menu();
}

void Operaciones::menuUsuario(){
    int opcion;
    AVL ArbolInt;
    NodoV* auxiliar;


    system("cls");
    int entrada;
    int dat;
    string nombre;
    string disponible;
    string descripcion;
    int ID;
    int i; //contador
    char digito[15];
    char cadena[36]={'A','B','C','D','E','F','G','H','I','J','K','L',
                     'M','N','O','P','Q','R','S','T','U','V','W','X',
                     'Y','Z','0','1','2','3','4','5','6','7','8','9'};
//this->userE=this->m->busquedaUsuarioNodo(globalUsuario,globalDepartamento,globalEmpresa);
    cout<<"***********************\n";
    cout<<"***********************\n";
    cout<<"1. Agregar activo\n";
    cout<<"2. Eliminar activo\n";
    cout<<"3. Modificar activo\n";
    cout<<"4. Rentar activo\n";
    cout<<"5. Activos rentados\n";
    cout<<"6. Mis activos rentados\n";
    cout<<"7. Cerrar sesion\n";

    cout<<"************************\n";
    cout<<"************************\n";


    cin>>opcion;
    switch(opcion){

        case 1://Agregar activo
            system("cls");
            cout<<"***********************\n";
            cout<<" Agregar activo\n\n";
            cout<<" Ingresar Nombre\n";
            cin>> nombre;
            cout<<" Ingresar descripcion\n";
            cin>>descripcion;

            srand(time(NULL)); //Para que los numeros sean realmente aleatorios
            for(i=0;i<=14;i++)
            {
                digito[i]=cadena[rand() % 35]; //numero aleatorio entre 0 y 35
                alpas+=digito[i];
            }
            globalActivos++;
            // NodoV* verificar;
            //this->userE->activos->raiz=this->userE->activos->insertar(this->userE->activos->raiz,globalActivos,nombre,alpas,true,descripcion);
            //this->userE->activos->ino(this->userE->activos->raiz);
//this->userE->activos->raiz=arbol->Insertar(this->userE->activos->raiz,globalActivos,nombre,alpas,true,descripcion);
//verificar=this->m->
            auxiliar=mate->busquedaUsuarioNodo(globalUsuario,globalDepartamento,globalEmpresa);
            cout<<"  Nodo insfdfdfdn presione 1 para volver";
           this->userE->activos->Insertar(this->userE->activos->raiz,globalActivos,nombre,alpas,true,descripcion);
//this->userE->activos->raiz
           // arbol->InsertarL(globalActivos,nombre,alpas,true,descripcion);
            cout<<"  Nodo insertado:\n presione 1 para volver";
            cin>>entrada;
            if(entrada==1){
                menuUsuario();
            }

            break;
    case 2://Eliminar activo
        system("cls");
        cout<<" Ingresar ID del activo\n";
        cin>>ID;
        cout<<"Elemento"<<ID<<"Eliminado";
        arbol->Buscar(ID);

        arbol->Borrar(ID);
        cout<<"  Nodo eliminado:\n presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }

        break;
        case 3://Modificar Activo
            system("cls");
            cout<<" Ingresar ID del activo\n";
            cin>>ID;
            ArbolInt.Buscar(ID);

            ArbolInt.Borrar(ID);
            cout<<" Ingresar Nombre\n";
            cin>> nombre;
            cout<<" Ingresar descripcion\n";
            cin>>descripcion;


            srand(time(NULL)); //Para que los numeros sean realmente aleatorios
            for(i=0;i<=14;i++)
            {
                digito[i]=cadena[rand() % 35]; //numero aleatorio entre 0 y 35
                alpas+=digito[i];
            }



            globalActivos++;
          //  ArbolInt.Insertar(globalActivos,nombre,alpas,true,descripcion);
            cout<<"  Nodo modificado:\n presione 1 para volver";
            cin>>entrada;
            if(entrada==1){
                menuUsuario();
            }

            break;
    case 4://Rentar
        system("cls");



        break;
    case 5://Activos
        system("cls");



        break;
    case 6://Mis acivos rentados
        system("cls");



        break;
    case 7://Mis acivos rentados
        system("cls");

primero();

        break;

    }

}





void Operaciones::jugar(){
    AVL ArbolInt;
//    ArbolInt.Insertar(7,"nombre1","alpa","disponible1","descripcion1");
//    ArbolInt.Insertar(2,"nombre2","alpa","disponible2","descripcion2");
//    ArbolInt.Insertar(3,"nombre3","alpa","disponible3","descripcion3");
//    ArbolInt.Insertar(4,"nombre4","alpa","disponible4","descripcion4");
//    ArbolInt.Insertar(5,"nombre5","alpa","No disponible5","descripcion5");
}






int Operaciones::PosicionRandom(){
	int posicion;
	srand((unsigned)time(0));
	posicion=(rand()%25)+1;
	
	
	return posicion;
}
