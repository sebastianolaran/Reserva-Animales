#include <iostream>
#include "Menu.h"
#include "ABB.h"

using namespace std;



void Menu :: pasar_opcion(Arbol* arbol, Auto* autos,Nodo* nodo) {
    if (nodo != NULL){
        pasar_opcion(arbol,autos,nodo->obtener_izquierdo());
        nodo ->obtener_animal(0) -> aumentar_hambre();
        nodo ->obtener_animal(0) -> disminuir_higiene();
        pasar_opcion(arbol,autos,nodo->obtener_medio());
        if (nodo -> obtener_cantidad_llaves() == 2 ){
            nodo ->obtener_animal(1) -> aumentar_hambre();
            nodo ->obtener_animal(1) -> disminuir_higiene();
    }
    
        pasar_opcion(arbol,autos,nodo->obtener_derecho());
    }
    autos -> cargar_combustible(CARGA_DEL_MENU);
}

void Menu :: mostrar_menu() {
    cout << endl << "\t - BIENVENIDOS A LA RESERVA SOÑADA -\n" << endl;
    cout << "Por favor ingrese una de las siguientes opciones: " << endl;
    cout << "\t 1. arbolr Animales" << endl;
    cout << "\t 2. Rescatar Animal" << endl;
    cout << "\t 3. Buscar Animal" << endl;
    cout << "\t 4. Cuidar Animal" << endl;
    cout << "\t 5. Adoptar Animal" << endl;
    cout << "\t 6. Guardar y salir" << endl;
}

void Menu :: mostrar_submenu() {
    cout << endl;
    cout << "Por favor ingrese una de las siguientes opciones: " << endl;
    cout << "\t 1. Elegir individualmente" << endl;
    cout << "\t 2. Alimentar a todos" << endl;
    cout << "\t 3. Bañar a todos" << endl;
    cout << "\t 4. Regresar al inicio" << endl;
}

int Menu :: elegir_opcion() {
    string opcion;
    cout << endl << "Ingrese opcion: ";
    cin >> opcion;
    while (! es_una_opcion_valida(opcion,1,7)) {
        cout << "La opcion ingresado es incorrecta" << endl;
        cout << "Ingrese otra opcion: ";
        cin >> opcion;  
    }
    return atoi(opcion.c_str());
}

int Menu :: elegir_opcion_submenu() {
    string opcion;
    cout << "Ingrese opcion: ";
    cin >> opcion;
    while (!es_una_opcion_valida(opcion,1,2)) {
        cout << "La opcion ingresado es incorrecta" << endl;
        cout << "Ingrese otra opcion: ";
        cin >> opcion;  
    }
    return atoi(opcion.c_str());
}

bool Menu :: es_una_opcion_valida(string opcion, int minimo, int maximo) {
    bool es_numerico = true;
    int i = 0;
    while(es_numerico && i < int(opcion.length()) ){
        if (!isdigit(opcion[i])) es_numerico = false;
        i++;
    }
    return (es_numerico && !((stoi(opcion) < minimo) || (stoi(opcion) > maximo)));
}

bool Menu :: procesar_opcion(Arbol* arbol, int opcion, Auto* autos) {
    bool estado;
    if(calcular_escapados(arbol ->obtener_raiz())){
        switch (opcion) {
            
            case listar_Animales:
                //pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                //arbol -> listar_animales(); 
                estado = true ;
            break;

            case rescatar_Animal:
                //pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                //arbol -> ingreso_animal();
                estado = true ;
                break;

            case buscar_Animal:
                //pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                //arbol -> buscar_animal();
                estado = true ;
                break;
            
            
            case cuidar_Animal: 
                pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                mostrar_submenu();
                int opcion_submenu = elegir_opcion_submenu();
                while (procesar_opcion_submenu (arbol, opcion_submenu)) {
                    mostrar_submenu();
                    opcion_submenu = elegir_opcion_submenu();
                } 
                estado = true ;
                break;
            
            case adoptar_Animal:
                //pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                //arbol -> adoptar_animal();
                estado = true ;
                break;

            case cargar_Combustible:
                //pasar_opcion(arbol,autos,arbol ->obtener_raiz());
                //int combustible = arbol -> pedir_combustible();
                //autos -> cargar_combustible(combustible);
                estado = true ;
                break;
            
            case guardar_Y_Salir:
                cout << "----------------FINALIZADO----------------" << endl;
                arbol -> guardar_y_salir(arbol -> obtener_raiz());
                estado = false;
                break;
            
            default:
                cout << "----------ERROR----------" << endl;
                estado = true ;
                break;
                   
        }
    }

    else {
        cout << "JUEGO FINALIZADO" << endl;
        estado = false;
    }
    
    return estado;
}


bool Menu :: procesar_opcion_submenu(Arbol* arbol, int opcion) {
    bool estado;
    switch (opcion) {
        case elejir_Individualmente:
            arbol ->recorrer_arbol_cuidado(arbol -> obtener_raiz());
            estado = true;
            break;

        case regresar_a_Inicio:
            estado = false;
            break;
    
        default :
            cout << "----------ERROR----------" << endl;
            estado = true;
        }
    return estado;
}

void Menu :: funcionalidad_del_menu(Arbol* arbol) {
    Auto* autos = new Auto();
    int opcion = elegir_opcion();
    cout << "LLega aca"<<endl;
    arbol -> leer_datos();
    cout << "LLega aca"<<endl;
    while (procesar_opcion(arbol, opcion, autos)) {
        mostrar_menu();
        opcion = elegir_opcion();
    }
}

string Menu :: ingresar_nombre(){
    string nombre;

    cout << "Ingrese el nombre del animal: ";
    cin.ignore();
    getline(cin, nombre);

    return nombre;
}



int Menu:: cantidad_animales_escapados(){
    return animales_escapados;
}

void Menu:: aumentar_cantidad_animales(){
    animales_escapados++;
}

void Menu:: cantidad_animales_resteo(){
    animales_escapados=0;}


bool Menu :: calcular_escapados(Nodo* nodo){
    bool no_finalizado=true;
    if (nodo != NULL){
    
        calcular_escapados(nodo->obtener_izquierdo());
        if ( nodo ->obtener_animal(0)-> obtener_hambre() == 100 || nodo ->obtener_animal(0) -> obtener_higiene() == 0){
            aumentar_cantidad_animales();
            nodo ->obtener_animal(0) -> se_escapo() ;}
        calcular_escapados(nodo->obtener_medio());
        if (nodo -> obtener_cantidad_llaves() == 2 && (nodo ->obtener_animal(1)-> obtener_hambre() == 100 || nodo ->obtener_animal(1) -> obtener_higiene() == 0)){
            aumentar_cantidad_animales();
            nodo ->obtener_animal(1) -> se_escapo();
    }
        calcular_escapados(nodo->obtener_derecho());
    
    }
    if (cantidad_animales_escapados() == 3) no_finalizado = false;

    return no_finalizado;
}


