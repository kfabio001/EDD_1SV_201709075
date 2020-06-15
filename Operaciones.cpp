#include "Operaciones.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>

using namespace std;
MatrizH *mate=new MatrizH();
Operaciones::Operaciones(){
	this->dimension = 0;
	this->auxJ1 = 0;
	this->auxJ2=0;
	this->usuaios = new Arbol();
	this->matriz = new Matriz();
	this->listaDiccionario = new ListaDobleCircular();
	this->fichas = new ListaDoble();
	this->fichasCopia = new ListaDoble();
	this->fichasDisponibles = new Cola();
	this->scoreboard = new ListaSimple();
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

    case 1:
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
    entrada=1;
    }
    break;
    case 2:
    system("cls");
    prueba();
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
    cout<<" Si existe:\n";
    primero();
    }else{
    cout<<"  No existe:\n";
    }
}

        break;
     case 3:
            system("cls");
            prueba();
            mate->print();

            cout<<"fin";
           // mat->print();
      break;
    }


    //menu();
}
void Operaciones::prueba(){
   // MatrizH *mate=new MatrizH();
    mate->InsertarElemento("Mynor","contra",1,"max","Guatemala");
    mate->InsertarElemento("Izabel","contra",2,"wallmart","Jutiapa");
    mate->InsertarElemento("Hello","contra",3,"panasonic","Jalapa");
    mate->InsertarElemento("wiiii","contra",4,"sony","peten");
    mate->InsertarElemento("pink","contra",5,"nintendo","Izabal");
    mate->InsertarElemento("pink","contra",5,"wallmart","Jutiapa");
    mate->InsertarElemento("pinky","contra",5,"wallmart","Jutiapa");
    mate->InsertarElemento("derecha","contra",5,"panasonic","peten");
   // mate->InsertarElemento("abajo","contra",5,"sony","Jalapa");

   // cout<<"fin";
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
    }


    //menu();
}

void Operaciones::menuUsuario(){
    int opcion;
    AVL ArbolInt;

    system("cls");
    string entrada;
    int dat;
    string nombre;
    string disponible;
    string descripcion;

    Nodo *j1,*j2;
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

        case 1:
            system("cls");



           //    Inserción de nodos en árbol:
              //ArbolInt.Insertar(dat,nombre,disponible,descripcion);


              cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

              // Mostrar el árbol en tres ordenes distintos:

              //aver();


            break;
    case 2:
        system("cls");

        cout<<"Jugadores disponibles\n";
        usuaios->insertar("Fabio");
        usuaios->insertar("Andre");
        usuaios->insertar("Andrew");
        SeleccionarJugador();
        break;
        case 3:
            system("cls");
            cout<<"1.  Reporte Diccionario \n";
            cout<<"2.  Fichas del juego \n";
            cout<<"3.  Jugadores \n";
            cout<<"4.  Reporte jugadores (Preorden) \n";
            cout<<"5.  Reporte jugadores (Inorden) \n";
            cout<<"6.  Reporte jugadores (Postorden) \n";
            cout<<"7.  Mejores puntajes \n";
            cout<<"8.  Scoreboard \n";
            cout<<"9.  Tablero \n";
            cout<<"10.  Fichas jugador1 \n";
            cout<<"11.  Ficjas jugador 2 \n";
            cin>>opcion;
            reportes(opcion);
            menu();
            break;
    }

}

void Operaciones::menu(){
    int opcion;
    int llas;
	system("cls");
	string entrada;

	Nodo *j1,*j2;
    cout<<"***********************\n";
    cout<<"***********************\n";
    cout<<"1. Ingresar Nuevo Jugador\n";
    cout<<"2. Jugar\n";
    cout<<"3. Generar Reportes\n";
    cout<<"************************\n";
    cout<<"************************\n";


	cin>>opcion;
	switch(opcion){

        case 1:
            //system("cls");
             llas=1;
            cout<<" Ingrese el nombre del nuevo jugador\n";
            if(llas ==1){

            }
			break;
    case 2:
        system("cls");

        cout<<"Jugadores disponibles\n";
        usuaios->insertar("Fabio");
        usuaios->insertar("Andre");
        usuaios->insertar("Andrew");
        SeleccionarJugador();
        break;
        case 3:
			system("cls");
            cout<<"1.  Reporte Diccionario \n";
            cout<<"2.  Fichas del juego \n";
            cout<<"3.  Jugadores \n";
            cout<<"4.  Reporte jugadores (Preorden) \n";
            cout<<"5.  Reporte jugadores (Inorden) \n";
            cout<<"6.  Reporte jugadores (Postorden) \n";
            cout<<"7.  Mejores puntajes \n";
            cout<<"8.  Scoreboard \n";
            cout<<"9.  Tablero \n";
            cout<<"10.  Fichas jugador1 \n";
            cout<<"11.  Ficjas jugador 2 \n";
			cin>>opcion;
			reportes(opcion);
			menu();
			break;
	}
		
}

void Operaciones::SeleccionarJugador(){
    string nombre;
    Nodo *j1,*j2;
    this->usuaios->preOrden(usuaios->raiz);
    cout<<"Ingrese el nombre del primer jugador \n";
    cin>>nombre;
    char *d =new char[nombre.length()+1];
    strcpy(d, nombre.c_str());
    char *pa=strtok(d, "");
    j1 =usuaios->buscar(pa);
    if(j1== NULL){

        cout<<"Jugador no existe\n\n";
        SeleccionarJugador();
    }

    cout<<"Ingrese el nombre del segundo jugador \n";
    cin>>nombre;
    d =new char[nombre.length()+1];
    strcpy(d, nombre.c_str());
    pa=strtok(d, "");
    j2 = usuaios->buscar(pa);

    while(j2== NULL){
        cout<<"Jugador no existe\n\n";
        cout<<"Ingrese el nombre del segundo jugador \n";
        cin>>nombre;
        char *d =new char[nombre.length()+1];
        strcpy(d, nombre.c_str());
        char *pa=strtok(d, "");
        j2 = usuaios->buscar(pa);
    }
    auxJ1 =j1;
    auxJ2 = j2;
    insertarFichas(fichas);
    insertarFichas(fichasCopia);
    RepartirFichas(j1, j2);
    system("cls");
    jugar();


}
void Operaciones::jugar(){
    AVL ArbolInt;
    ArbolInt.Insertar(1,"nombre1","disponible1","descripcion1");
    ArbolInt.Insertar(2,"nombre2","disponible2","descripcion2");
    ArbolInt.Insertar(3,"nombre3","disponible3","descripcion3");
    ArbolInt.Insertar(4,"nombre4","disponible4","descripcion4");
    ArbolInt.Insertar(5,"nombre5","No disponible5","descripcion5");
}


void Operaciones::reportes(int opcion){
	
	switch(opcion){
		case 1:
			listaDiccionario->reporte();
			break;
		case 2:
			fichasDisponibles->reporte();
			break;
		case 3:
			usuaios->reporte();
			break;
		case 4:
			usuaios->reportePreorden();
			break;
		case 5:
			usuaios->reporteInorden();
			break;
		case 6:
			usuaios->reportePostorden();
			break;
		case 7:
			ReportePorJugador();
			break;
		case 8:
			scoreboard->reporte();
			break;
		case 9:
			matriz->reporte();
			break;
		case 10:
			auxJ1->jugador->fichasJugador->reporte();
			break;
		case 11:
			auxJ2->jugador->fichasJugador->reporte();
			break;
	}
}
void Operaciones::ReportePorJugador(){
	string nombre;
    cout<<"Escriba el nombre del jugador \n";
	cin>>nombre;
	char *d =new char[nombre.length()+1];
	strcpy(d, nombre.c_str());
	char *pa=strtok(d, "");
	Nodo *aux = usuaios->buscar(pa);
	if(aux!=NULL){
		aux->jugador->listapunteo->reporte();

	}
	else{
        cout<<"Jugador no existe\n";
	}
	
}
void Operaciones::LecturaDeArchivo(string archivo){
	ifstream file(archivo.c_str(), ios::out);
	if(!file.fail()){
		json j3;
		file>>j3;
		this->dimension =j3.at("dimension");
		auxDimen = dimension;
		for(int j=0; j<1;j++){
			int x,y;
			for(int j= 0; j<j3.at("casillas").at("dobles").size();j++){
				 x = j3.at("casillas").at("dobles")[j].at("x");
				 y =j3.at("casillas").at("dobles")[j].at("y");
				matriz->insertar(x,y,"dobles");
			}
			
			for(int j= 0; j<j3.at("casillas").at("triples").size();j++){
				x =j3.at("casillas").at("triples")[j].at("x");
				y= j3.at("casillas").at("triples")[j].at("y");
				matriz->insertar(x,y,"triples");
			}
			
		}
		for(int j= 0; j<j3.at("diccionario").size();j++){
			listaDiccionario->insertar(j3.at("diccionario")[j].at("palabra"));
			
		}
	}
}
void Operaciones::IngresarPalabraHorizontal(string palabra, int columnaInicio, int columnaFinal, int fila, Nodo *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	int columna = columnaInicio;
	columnaFinal = columnaInicio +columnaFinal;
	for(int i = 0; i<p; i++){
		while(columnaInicio < columnaFinal){
				aux= matriz->buscar(fila, columnaInicio);
				c = c+palabra[i];
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d, "");
				if(aux == NULL){
					matriz->insertar(fila, columnaInicio, pa);
					c = "";
					columnaInicio++;
					i++;
				}
				else{
					
					if(aux->valor == "dobles" || aux->valor =="triples"){
						aux->valorAnt = aux->valor;
						aux->valor = pa;
						c = "";
						columnaInicio++;
						i++;
						
					}else{
						if(c!=aux->valor){
							cout<<"Casilla ocupada";
							c = "";
							i=p;
							bandera = false;
							break;
						}else{
							aux->valorAnt = aux->valor;
							c="";
							columnaInicio++;
							i++;
						}
						
					}
				}
		}
	}
	if(bandera == true){
		
		Encabezado * eFila =matriz->eFilas->getEncabezado(fila);
		NodoM *aux = eFila->acceso;
		while(aux->derecha != NULL&& (aux->valor != "dobles" || aux->valor != "triples")){
			if(aux->valor != "dobles"){
				if(aux->valor != "triples"){
					c = c+ aux->valor;
					aux = aux->derecha;
				}else{
					aux= aux->derecha;
				}
			}else
				aux =aux->derecha;
			
		}
		if(aux->valor != "dobles" && aux->valor != "triples")
			c = c+ aux->valor;
		
	}
	
	bool t=listaDiccionario->buscar(c);
	if(t==true){
		nodoC *actualC;
		for(int i = 0; i<=p; i++){
			actualC = fichasDisponibles->primero;
			
			jugador->jugador->fichasJugador->insertar(actualC->letra,1, actualC->punteo);
			
			fichasDisponibles->eliminar();
		}
        cout<<"Correcto sigue asi\n";
		jugador->jugador->puntaje = jugador->jugador->puntaje+PuntajeHorizontal(c,fila);
		
		cout<<"Puntaje de "<<jugador->jugador->puntaje;
	}else{
		NodoLD * actual;
        cout<<"Palabra incorrecta\n\n";
		for(int i= 0; i<=p; i++){
			
			while(columna < columnaFinal){
				c= palabra[i];
				aux= matriz->buscar(fila, columna);
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d,"");
				if(aux->valorAnt == 0){
					matriz->eliminar(fila, columna);
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					columna++;
					i++;
				}
				else{
					aux->valor = aux->valorAnt;
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
					
				}
			}
		}
	}
	
	
}
int Operaciones::PuntajeHorizontal(string palabra, int fila){
	int p = palabra.size();
	int puntaje;
	NodoLD *aux ;
	Encabezado *eFila = matriz->eFilas->getEncabezado(fila);
	NodoM *actual= eFila->acceso;
	string letra;
	for(int i=0; i<=p; i++){
		letra = letra + palabra[i];
		aux = fichasCopia->primero;
		aux->sig->letra;
		
		while(letra != aux->letra&&aux->sig != 0){
			
				aux = aux->sig;
		}
		if(letra== aux->letra){
			while(letra != actual->valor && actual->derecha != 0){
				actual = actual->derecha;
			}
			if(letra == actual->valor && actual->valorAnt == "dobles"){
				puntaje = 2*aux->puntaje + puntaje;
			}else{
				puntaje = puntaje+aux->puntaje;
			}
			
		}
		letra = "";
	}
	return puntaje;
}
int Operaciones::PuntajeVertical(string palabra, int columna){
	int p = palabra.size();
	int puntaje;
	NodoLD *aux ;
	Encabezado *eColumna = matriz->eColumnas->getEncabezado(columna);
	NodoM *actual= eColumna->acceso;
	string letra;
	for(int i=0; i<=p; i++){
		letra = letra + palabra[i];
		aux = fichasCopia->primero;
		while(letra != aux->letra && aux->sig != 0){
			aux = aux->sig;
		}
		if(letra== aux->letra){
			while(letra != actual->valor && actual->abajo != 0){
				actual = actual->abajo;
			}
			if(letra == actual->valor && actual->valorAnt == "dobles"){
				puntaje = 2*aux->puntaje + puntaje;
			}else{
				puntaje = puntaje+aux->puntaje;
			}
			
		}
		letra = "";
	}
	return puntaje;
}
void Operaciones::IngresarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna, Nodo *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	int fila = filaInicio;
	filaFinal = filaInicio + filaFinal;
	for(int i = 0; i<p; i++){
		while(filaInicio < filaFinal){
			//matriz->reporte();
			aux= matriz->buscar(filaInicio, columna);
			c = c+palabra[i];
			char *d =new char[c.length()+1];
			strcpy(d, c.c_str());
			char *pa=strtok(d, "");
			if(aux == NULL){
				matriz->insertar(filaInicio, columna, pa);
				c = "";
				filaInicio++;
				i++;
				
			}
			else{
				
				if(aux->valor == "dobles" || aux->valor =="triples"){
					aux->valorAnt = aux->valor;
					aux->valor = pa;
					c = "";
					filaInicio++;
					i++;
					
				}else{
					if(c!=aux->valor){
						cout<<"Casilla ocupada " ;
						cout<<aux->valor;
						cout<<"fila";
						cout<<aux->fila;
						cout<<"Columna";
						cout<<aux->columna;
						c = "";
						i=p;
						bandera = false;
						break;
					}else{
						aux->valorAnt = aux->valor;
						c = "";
						filaInicio++;
						i++;
					}
				}
			}
		}
	}
	if(bandera == true){
		
		Encabezado * eColumna =matriz->eColumnas->getEncabezado(columna);
		NodoM *aux = eColumna->acceso;
		
		while(aux->abajo != NULL &&(aux->valor!="dobles"|| aux->valor!="triples")&& aux->abajo->fila <= filaFinal+1){
			if((aux->valor != "dobles"&& aux->valor!="triples")){
				
				c = c+ aux->valor;
				aux = aux->abajo;
			}else{
				aux = aux->abajo;
			}
			
			
		}
		if(aux->valor != "dobles"&& aux->valor != "triples" && aux->valor != 0)
			c = c+ aux->valor;
		
	}
	
	bool t = listaDiccionario->buscar(c);
	if(t==true){
		nodoC *actualC;
		for(int i = 0; i<=p; i++){
			actualC = fichasDisponibles->primero;
			jugador->jugador->fichasJugador->insertar(actualC->letra,1, actualC->punteo);
			fichasDisponibles->eliminar();
		}
		
        cout<<"Correcto sigue asi\n";
		jugador->jugador->puntaje = jugador->jugador->puntaje + PuntajeVertical(c,columna);
		
		cout<<"Puntaje de "<<jugador->jugador->puntaje;
		
	}else{
		NodoLD *actual;
        cout<<"Palabra incorrecta\n";
		for(int i= 0; i<=p; i++){
			
			while(fila < filaFinal){
				c= palabra[i];
				aux= matriz->buscar(fila, columna);
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d,"");
				if(aux->valorAnt == 0){
					matriz->eliminar(fila, columna);
					matriz->reporte();
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
				}
				else{
					aux->valor = aux->valorAnt;
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
					
				}
			}
		}
	}
}
void Operaciones::insertarFichas(ListaDoble *fichas){
	fichas->insertar("A",6,1);
	fichas->insertar("E",6,1);
	fichas->insertar("O",3,1);
	fichas->insertar("I",3,1);
	fichas->insertar("S",6,1);
	fichas->insertar("N",5,1);
	fichas->insertar("L",4,1);
	fichas->insertar("R",5,1);
	fichas->insertar("U",5,1);
	fichas->insertar("T",4,1);
	fichas->insertar("D",5,2);
	fichas->insertar("G",2,2);
	fichas->insertar("C",4,3);
	fichas->insertar("A",6,1);
	fichas->insertar("B",2,3);
	fichas->insertar("M",2,3);
	fichas->insertar("P",2,3);
	fichas->insertar("E",6,1);
	fichas->insertar("H",2,4);
	fichas->insertar("F",1,4);
	fichas->insertar("V",1,4);
	fichas->insertar("Y",1,4);
	fichas->insertar("O",3,1);
	fichas->insertar("Q",1,5);
	fichas->insertar("J",1,8);
	fichas->insertar("Ñ",1,8);
	fichas->insertar("I",3,1);
	fichas->insertar("X",1,8);
	fichas->insertar("Z",1,10);
}
int Operaciones::PosicionRandom(){
	int posicion;
	srand((unsigned)time(0));
	posicion=(rand()%25)+1;
	
	
	return posicion;
}
void Operaciones::RepartirFichas(Nodo *j1, Nodo *j2){
	NodoLD *aux = fichas->primero;
	int ingresada=0;
	int i=0;
	int pos;
    while(ingresada<7){
		pos = PosicionRandom();
		aux = fichas->primero;
		while( i!= pos && i<fichas->tamLD ){
			aux = aux->sig;
			i++;
		}
		if(aux->cantidad != 0){
			
			j1->jugador->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
			
		}
		i=0;
	}
		
	
	ingresada =0;
	while(ingresada<10){
		pos = PosicionRandom();
		aux = fichas->primero;
		while( i!= pos&& i<fichas->tamLD){
			aux = aux->sig;
			i++;
		}	
		if(aux->cantidad != 0){
			j2->jugador->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
		}
		i=0;
	}
	
	while(fichas->tamLD>0){
		aux = fichas->primero;
		if(fichas->tamLD >0)
			pos = PosicionRandom();
		while(i != pos&& i<fichas->tamLD){
			aux = aux->sig;
			i++;
		}
		fichasDisponibles->tamC;
		fichasDisponibles->insertar(aux->letra,aux->puntaje);
		fichas->eliminarCantidad(aux->letra,1);
		i=0;
	}
	fichasDisponibles->insertar(fichas->primero->letra,fichas->primero->puntaje);
	fichas->eliminarCantidad(fichas->primero->letra,1);
}
bool Operaciones::turno(string palabra,Nodo* jugador){
	int p = palabra.size();
	string c;
	bool correcta = true;
	
	int i=0;
	while(correcta== true && i<=p){
		c = c+palabra[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, "");
		NodoLD *aux = jugador->jugador->fichasJugador->primero;
		while(c != aux->letra && aux->sig != 0){
			aux = aux->sig;
		}
		if(c == aux->letra){
			c="";
			i++;
		}
		else{
			if(i!=p)
				correcta=false;
			i++;
		}
	}
	i=0;
	if(correcta == false){
        cout<<"incorrecto\n";
		return false;
	}
	while(correcta==true && i<=p){
		c = palabra[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, "");
		NodoLD *aux = jugador->jugador->fichasJugador->primero;
		while(c!=aux->letra && aux->sig !=0){
			aux = aux->sig;
		}
		if(c == aux->letra){
			jugador->jugador->fichasJugador->eliminarCantidad(aux->letra,1);
			c="";
			i++;
		}else {
			if(i!=p)
				correcta=false;
			i++;
			return true;

				
			
			
				
		}
	}
}
void Operaciones::sdf(Nodo *Jactual, Nodo *Jsiguiente){
	string palabra;
	int p, columna,fila, opcion;
    cout<<"Jugador : "<<Jactual->info<<"\n";
    cout<<"PuntajeO ->"<< Jactual->jugador->puntaje<<"\n";
	Jactual->jugador->fichasJugador->print();
    cout<<"-----------Opciones:-------------\n\n";
    cout<<"1. Escribir palabra\n\n";
    cout<<"2. Cambiar Fichas de la pila\n\n";
    cout<<"3. Terminar Juego\n\n";
	cin>>opcion;
	if(opcion==2){
        cout<<"Ingrese las fichas a cambiar\n";
		cin>>palabra;
		CambiarFichas(palabra,Jactual);
	}else if(opcion ==1){
        cout<<"Ingrese palabra\n";
		cin>>palabra;
		p = palabra.size();
		bool t;
		t=turno(palabra,Jactual);
		if(t==true){
            cout<<"Ingrese posicion de la primer ficha (fila y columna)\n";
			cin>>fila;
			cin>>columna;
			while(fila> this->dimension || columna > this->dimension){
                cout<<"Ingrese posicion de la primer ficha (fila y columna)\n";
				cin>>fila;
				cin>>columna;
			}
            cout<<"Seleccione la orientacion: ";
            cout<<"1. Vertical\n";
            cout<<"2. Horizontal\n";
			cin>>opcion;
            if(opcion==2){
				IngresarPalabraHorizontal(palabra,columna, p, fila, Jactual);
				matriz->reporte();
            }else if(opcion == 1){
				IngresarPalabraVertical(palabra, fila, p, columna, Jactual);
				matriz->reporte();
			}
		}
	}
	else if(opcion ==3){
		scoreboard->insertarOrdenada(Jactual->info, Jactual->jugador->puntaje);
		scoreboard->insertarOrdenada(Jsiguiente->info, Jsiguiente->jugador->puntaje);
		Jactual->jugador->listapunteo->insertarOrdenada(Jactual->info, Jactual->jugador->puntaje);
		Jsiguiente->jugador->listapunteo->insertarOrdenada(Jsiguiente->info, Jsiguiente->jugador->puntaje);
		Jactual->jugador->puntaje = 0;
		Jsiguiente->jugador->puntaje = 0;
		
		menu();
	}
	
}
void Operaciones::CambiarFichas(string letras, Nodo * jugador){
	int l = letras.size();
	string c;
	for(int i = 0; i< l; i++){
		c = letras[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, " ");
		char *letra = pa;
		NodoLD*aux = jugador->jugador->fichasJugador->buscar(d);
		if(aux!=NULL){
			fichasDisponibles->insertar(aux->letra, aux->puntaje);
			jugador->jugador->fichasJugador->eliminarCantidad(aux->letra,1);
			nodoC*nuevo = fichasDisponibles->eliminar();
			jugador->jugador->fichasJugador->insertar(nuevo->letra, 1, nuevo->punteo);
		}
		
	}
}
bool Operaciones::validar(){
	Encabezado *eFila = matriz->eFilas->primero;
	Encabezado *eColumna = matriz->eColumnas->primero;
	int i = 0;
	string palabra;
	//verificando horizontalmente
	nodoLC *aux = listaDiccionario->primero;
	NodoM *actual = eFila->acceso;
	bool t ;
	while(eFila->siguiente !=0){
		i=actual->columna;
		while( i==actual->columna && eFila->siguiente != 0){
			if(actual->derecha!= 0){
				if(actual->derecha != 0&&(actual->valor != "dobles" || actual->valor != "triples")){
					palabra = palabra + actual->valor;
					actual = actual->derecha;
					eColumna = eColumna->siguiente;
					i++;
				}else{
					t= listaDiccionario->buscar(palabra);
					if(t==true){
						if(actual->derecha->valor == "dobles" || actual->derecha->valor == "triples")
						actual = actual->derecha;

					}else{
						return false;
					}
					
					
				}
			}else{
				if(actual->valor != "dobles" || actual->valor != "triples"){
					palabra = palabra + actual->valor;
					actual = actual->derecha;
					eFila = eFila->siguiente;
					eColumna= matriz->eColumnas->primero;
					i=0;
				}else{
					
				}
			}
		}
	}
	if(actual->valor != "dobles" || actual->valor != "triples"){
		palabra = palabra+ actual->valor;	
	}
	
	
	
	
	return NULL;
}

