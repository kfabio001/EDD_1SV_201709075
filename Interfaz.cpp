#include "Interfaz.h"
#include "Matriz.h"
#include<time.h>


Interfaz::Interfaz(Matriz* ma)
{
    this->mate=ma;
    this->auxNodo=NULL;

}
void Interfaz::primero(){
    int entrada;
    string usuario;
    string contra;string departamento;string empresa;
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
        cout<<"  Iniciar sesion Administrador:\n\n";
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

        cout<<"  Iniciar sesion Usuario:\n";
        cout<<"  Ingrese Nombre de usuario:\n";
        cin>>usuario;
        cout<<"  Ingrese Contraseña:\n";
        cin>>contra;
        cout<<"  Ingrese Departamento:\n";
        cin>>departamento;
        cout<<"  Ingrese Empresa:\n";
        cin>>empresa;

        this->auxNodo=this->mate->siExiste(usuario,departamento,empresa);
        if(auxNodo!=NULL && auxNodo->contra==contra){

            this->menuUsuario();
        }else{
            cout << "Datos incorrecots" << endl;
            cout << "pulsa 1 para regresar" << endl;
            cin>>entrada;
            if(entrada==1){
                primero();
            }
        }

        break;
    case 3:
        system("cls");

        mate->obtenerRaices();

        cout<<"fin";
        cout<<" :\n presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            primero();
        }

        break;

    }


}

int main()
{

    Matriz *matriz = new Matriz();

    //matriz->insertarNodoMatriz("Fabio","max","Guate","Fabio","contra",matriz->contadorN++);
    //  matriz->insertarNodoMatriz("andre","sony","Peten","andre","contra",matriz->contadorN++);
    matriz->insertarNodoMatriz("1","1","1","1","1",matriz->contadorN++);
    matriz->insertarNodoMatriz("2","2","2","2","2",matriz->contadorN++);
    matriz->insertarNodoMatriz("3","3","3","3","3",matriz->contadorN++);


    Interfaz *user = new Interfaz(matriz);

    cout << " " << endl;
    user->primero();

    return 0;
}

void Interfaz::menuAdmin(){
    int entrada;
    string usuario;
    string contra;string departamento;string empresa;
    string enteer;
    Lista_Doble*lista=new Lista_Doble();

    char admin[]= "admin";
    char adminC[]= "admin";

    cout<<"******************************************************\n";
    cout<<"******************************************************\n";
    cout<<"               BIENVENIDO ADMINISTRADOR\n";
    cout<<"                 RENTA DE ARCHIVOS\n";
    cout<<"  Escriba una opcion de inicio de sesion:\n";
    cout<<"  1.Crear usuario:\n";
    cout << "2. Reporte de Matriz" << endl;
    cout << "3. Reporte Activos Disponibles de un Departamento" << endl;
    cout << "4. Reporte Activos Disponibles de una Empresa" << endl;
    cout << "5. Reporte Transacciones" << endl;
    cout << "6. Reporte Activos de usuarios" << endl;
    cout << "7. Activos rentados por un usuario" << endl;
    cout << "8. Ordenar Transacciones " << endl;
    cout << "9. Exit" << endl;
    cout<<"\n";
    cin>>entrada;

    switch(entrada){

    case 1://             crear usuario
        //
        system("cls");
        cin.ignore();

        cout<<"  Ingrese datos del usuario:\n\n";
        cout<<"  Ingrese Nombre de usuario:\n";
        cin>>usuario;
        cout<<"  Ingrese Contraseña:\n";
        cin>>contra;
        cout<<"  Ingrese Departamento:\n";
        cin>>departamento;
        cout<<"  Ingrese Empresa:\n";
        cin>>empresa;
        this->mate->insertarNodoMatriz(usuario,empresa,departamento,usuario,contra,this->mate->contadorN++);


        cout<<"  Usuario ingresado \n"<<usuario;

        cout<<"  Nodo insertado:\n presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuAdmin();
        }
        break;
    case 2://                   Matriz
        system("cls");
        this->mate->grafhMatriz("Prueba");
        //cout << "datos incorrectos" << endl;
        cout << "pulsas 1 para regresar!" << endl;
        cin>>entrada;
        if(entrada==1){
            menuAdmin();
        }

        break;
    case 3: //                      activos disponibles departamento
        system("cls");
        //cout << "datos incorrectos" << endl;
        cout << "pulsas 1 para regresar!" << endl;
        cin>>entrada;
        if(entrada==1){
            menuAdmin();

        }

        break;
    case 4: //                      activos disponibles empresa
        system("cls");
        cout<<"  Ingrese Empresa:\n";
        cin>>empresa;
        this->auxNodo=this->mate->siExisteEmp(empresa);
        if(auxNodo!=NULL){
            cout<<" lo encontro";
            grafoVarios(auxNodo->tAvl->grafoArbol());

            menuAdmin();
        }else{
            cout << "datos incorrectos" << endl;
            cout << "pulsas 1 para regresar!" << endl;
            cin>>entrada;
            if(entrada==1){
                menuAdmin();
            }


            break;
    case 5://                    activos disponibles   empresa

                lista->graficar();
                menuAdmin();
                break;
            case 6:  //                  transacciones
                cout<<"  Ingrese Nombre de usuario:\n";
                cin>>usuario;
//                cout<<"  Ingrese Contraseña:\n";
//                cin>>contra;
                cout<<"  Ingrese Departamento:\n";
                cin>>departamento;
                cout<<"  Ingrese Empresa:\n";
                cin>>empresa;


                this->auxNodo=this->mate->siExiste(usuario,departamento,empresa);
                if(auxNodo!=NULL){
                    cout<<" lo encontro";
                    grafo(auxNodo->tAvl->grafoArbol());
                    menuAdmin();
                }else{
                    cout << "Datos incorrecots" << endl;
                    cout << "pulsa 1 para regresar" << endl;
                    cin>>entrada;
                    if(entrada==1){
                        menuAdmin();
                    }
                }
                menuAdmin();
                break;
            case 7://                    activos de un usuario
                cout<<"  Ingrese Nombre de usuario:\n";
                cin>>usuario;
//                cout<<"  Ingrese Contraseña:\n";
//                cin>>contra;
                cout<<"  Ingrese Departamento:\n";
                cin>>departamento;
                cout<<"  Ingrese Empresa:\n";
                cin>>empresa;

                this->auxNodo=this->mate->siExiste(usuario,departamento,empresa);
                if(auxNodo!=NULL){
                    cout<<" lo encontro";
                    grafo(auxNodo->tAvl->grafoArbol());
                    menuAdmin();
                }else{
                    cout << "Datos incorrectos" << endl;
                    cout << "Pulsa 1 para regresar " << endl;
                    cin>>entrada;
                    if(entrada==1){
                        menuAdmin();
                    }
                }
                menuAdmin();

                break;
            case 8://                  activos rentados

                break;
            case 9:// c                 cerra sesion

                primero();
                break;

        }
    }


    //menu();
}
void Interfaz::addActivo(){
    cin.ignore();
    string nombre,descripcion,ideny;
    NodoArbol* exist;
    cout << ">> Ingresar Nombre del activo" << endl;
    cin>>nombre;
    cout << ">> Ingresar Descripcion del activo" << endl;
    cin>>descripcion;
    do{
        ideny=this->cadenaIDActivo();
        exist=this->mate->BuscarActivo(ideny);
    }while(exist!=NULL);
    this->auxNodo->tAvl->root=this->auxNodo->tAvl->insertar(this->auxNodo->tAvl->root,ideny,nombre,descripcion);
    this->auxNodo->tAvl->preorden(this->auxNodo->tAvl->root);

}


void Interfaz::grafo(string llenar){
    string nomb="Arbol";
    ofstream escribir;
    escribir.open("Arbol.dot", ios::out);
    escribir << "digraph Sparce_Matrix { \n";
    escribir << llenar;
    escribir << "}";
    escribir.close();
    string ruta = "dot -Tjpg " + nomb + ".dot -o " + nomb + ".jpg";
    system(ruta.c_str());
    string title = nomb  + ".jpg";

}

void Interfaz::modificarActivo(){
    cin.ignore();
    string idActivo,nuevaDescropcion;
    cout<<"\n Catalogos de activos disponibles"<<endl;
    this->auxNodo->tAvl->enorderR(this->auxNodo->tAvl->root);
    cout<<"\n..- Ingrese el id del activo a moficar \n";
    cin>>idActivo;
    NodoArbol* activoM=this->mate->BuscarActivo(idActivo);
    if(activoM!=NULL){
        cout<<"descripcion: "<< activoM->descripcion <<endl;
        cout<<"\n la nueva descripcion \n";
        cin>>nuevaDescropcion;
        activoM->descripcion=nuevaDescropcion;
        cout<<"\n modificado \n";
        cout<<" Id: "<<activoM->id<<"; nombre: "<<activoM->nombre<< "; Descripcion: " << activoM->descripcion << "\n" << endl;
    }else{
        cout<<"No existe "<<endl;
    }
}

string Interfaz::cadenaIDActivo(){
    int num, c;
    srand(time(NULL));
    string id="";
    string cadena="abcdefghijklmnopqrstuvwxyz0123456789";
    for(c = 0; c < 15; c++)
    {
        num = 0 + rand() % (cadena.length() - 0);
        id+=cadena[num];
    }
    return id;
}
Interfaz::~Interfaz()
{

}
void Interfaz::grafoVarios(string llenar){
    contadorCata++;
    string nombre="Arbol";
    ostringstream cata;
    cata<<nombre<<contadorCata;
    ofstream escribir;
    escribir.open(cata.str()+".dot", ios::out);
    escribir << "digraph Sparce_Matrix { \n";
    escribir << llenar;
    escribir << "}";
    escribir.close();
    string ruta = "dot -Tjpg " + cata.str() + ".dot -o " + cata.str() + ".jpg";
    system(ruta.c_str());
    string title = cata.str()  + ".jpg";

}

void Interfaz::menuUsuario(){
    int opcion;
    string idActivo;
    string dueno;
    Lista_Doble*lista=new Lista_Doble();
    char digito[15];
    char cadena[36]={'A','B','C','D','E','F','G','H','I','J','K','L',
                     'M','N','O','P','Q','R','S','T','U','V','W','X',
                     'Y','Z','0','1','2','3','4','5','6','7','8','9'};
    int i;
    string alpas;
    system("cls");
    int entrada;
    int dias;
    int dia;
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
        this->addActivo();
        menuUsuario();
        break;
    case 2://Eliminar activo
        system("cls");
        this->eliminarActivo();
        cout<<" presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }
        break;
    case 3://Modificar Activo
        system("cls");
        this->modificarActivo();
        cout<<" presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }
        break;
    case 4://Rentar
        system("cls");
        cout<<"\n Catalogos de todos los activos disponibles a rentar  "<<endl;
        mate->obtenerRaices();
        cout<<"\n Ingrese el nombre del activo a rentar \n";
        cin>>idActivo;
        cout<<"\n Ingrese el nombre del usuario dueño \n";
        cin>>dueno;
        cout<<"\n Ingrese dias a rentar\n";
        mate->obtenerUsuario(dueno,idActivo,auxNodo->nombre);
        //system("cls");
        mate->obtenerRaices();
        cin>>dia;
        this->auxNodo->tAvl->root=this->auxNodo->tAvl->insertar(this->auxNodo->tAvl->root,idActivo,idActivo,"rentado");
        cout<<"\n.activo"<<idActivo<<"rentado\n";
        srand(time(NULL)); //Para que los numeros sean realmente aleatorios
        for(i=0;i<=14;i++)
        {
            digito[i]=cadena[rand() % 35]; //numero aleatorio entre 0 y 35
            alpas+=digito[i];
        }
        lista->insertar(alpas,this->auxNodo->tAvl->root->id,this->auxNodo->tAvl->root->nombre,this->auxNodo->tAvl->root->descripcion,this->auxNodo->nombre,dias,this->auxNodo->tAvl->root->estado);
        //lista->insertar(alpas,this->userE->treeAvl->root->id,this->userE->treeAvl->root->nombre,this->userE->treeAvl->root->descripcion,this->userE->name,dias,this->userE->treeAvl->root->estado);
        cout<<"nose si inserto";

        cout<<" presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }


        break;
    case 5://Activos que yo rente
        system("cls");
        cout<<"\n  Los Activos que rente"<<endl;
        this->auxNodo->tAvl->meRentaron(this->auxNodo->tAvl->root);

        cout<<" presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }

        break;
    case 6://Mis acivos que rentaron
        system("cls");
        cout<<"\n  Los Activos que me han rentado"<<endl;
        this->auxNodo->tAvl->yoRente(this->auxNodo->tAvl->root);
        cout<<" presione 1 para volver";
        cin>>entrada;
        if(entrada==1){
            menuUsuario();
        }

        break;
    case 7://salir
        system("cls");


        primero();

        break;

    }

}


void Interfaz::llenar(NodoArbol *temp){

    if(temp!=NULL){
        this->llenar(temp->izquierda);
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
        this->llenar(temp->derecha);
    }
}
void Interfaz::eliminarActivo(){
    cin.ignore();

    string idActivo;
    cout<<"\n Catalogo activos  "<<endl;
    this->auxNodo->tAvl->inorden(this->auxNodo->tAvl->root);
    cout<<"\n..- Ingrese el id del activo a eliminar \n";
    cin>>idActivo;
    NodoArbol* activoE=this->mate->BuscarActivo(idActivo);
    if(activoE!=NULL){
        cout<<" Activo Eliminado"<<endl;
        cout<<" Id: "<< activoE->id <<endl;
        cout<<" Nombre: "<< activoE->nombre <<endl;
        cout<<" descripcion: "<< activoE->descripcion <<endl;
        this->auxNodo->tAvl->root= this->auxNodo->tAvl->eliminar(this->auxNodo->tAvl->root,idActivo);
    }else{
        cout<<"No existe "<<endl;
    }
}




