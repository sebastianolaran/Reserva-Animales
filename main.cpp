#include <iostream>

#include "ABB.h"

#include "ABB_NODO.h"


#include "Menu.h"

int main () {
    Arbol* arbol = new Arbol;
    Menu* menu = new Menu;
    menu ->funcionalidad_del_menu(arbol);
    return 0;
}