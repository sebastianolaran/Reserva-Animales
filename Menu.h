#ifndef _MENUH
#define _MENUH
#include <iostream>
#include "ABB.h"
#include "Auto.h"

/**/

using namespace std;

enum opcionesMenu {
    listar_Animales = 1,
    rescatar_Animal,
    buscar_Animal,
    cuidar_Animal,
    adoptar_Animal,
    cargar_Combustible,
    guardar_Y_Salir,

};

enum opcionesSubMenu {
    elejir_Individualmente = 1,
    regresar_a_Inicio,
};


class Menu {
    //Atributos
    int animales_escapados;
    //Metodos
    public:
    //constructor
    //Menu();

    //PRE: Lista tiene que estar cargada
    //POS: Llama a los metodos que se encargan de aumentar el hambre y disminuir 
    //     la higiene de cada animal.
    void pasar_opcion(Arbol* arbol, Auto* autos,Nodo* nodo);

    //PRE: -
    //POS: Imprime el menu por pantalla.
    void mostrar_menu();

    //PRE: -
    //POS: Imprime el submenu de la opcion cuidar animales por pantalla.
    void mostrar_submenu();

    //PRE: -
    //POS: Pide al usuario una opcion y si es valido, devuelve el valor.
    int elegir_opcion();

    //PRE: -
    //POS: Pide al usuario una opcion y si es valido, devuelve el valor.
    int elegir_opcion_submenu();

    //PRE: Opcion ingresada por el usuario.
    //POS: Verifica que la opcion sea correcta dentro del minimo y maximo.
    bool es_una_opcion_valida(string opcion,int minimo,int maximo);

    //PRE: Lista tiene que estar cargada y que la opcion sea valida.
    //POS: Llama al procedimiento correspondiente
    //     a la opcion recibida.
    bool procesar_opcion(Arbol* arbol, int opcion, Auto* autos);

    //PRE: Lista tiene que estar cargada y que la opcion sea valida.
    //POS: Llama al procedimiento correspondiente
    //     a la opcion recibida.
    bool procesar_opcion_submenu(Arbol* arbol,int opcion);

    //PRE: -
    //POS: Pide la opcion a realizar en el menu
    void funcionalidad_del_menu(Arbol* arbol);

    //PRE: -
    //POS: Le solicita al usuario un nombre y lo devuelve.
    string ingresar_nombre();

    int cantidad_animales_escapados();

    void aumentar_cantidad_animales();

    void cantidad_animales_resteo();

    bool  calcular_escapados(Nodo* nodo);
};



#endif //_MENUH