#include "Perro.h"

Perro :: Perro(string nombre) : Animal(nombre, "P") {

}

Perro :: Perro(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "P", personalidad) {

}

void Perro :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Perro :: disminuir_higiene() {

    higiene -= (personalidad -> obtener_valor_de_disminucion_de_higiene());

    if (higiene < 0) higiene = 0;
}

string Perro :: obtener_especie_completa() {

    return "Perro";
}


void Perro :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con huesos." << endl;
    }

}

void Perro :: baniar() {

    if (higiene == 100) cout << obtener_nombre() << " ya esta limpio." << endl;

    else {
        if (higiene != 100) higiene = 100;

        cout << "Bañaste a " << obtener_nombre() << endl;
    }
}

bool Perro :: se_escapo(){
    return(escapado = true);
}