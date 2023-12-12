#include "Erizo.h"

Erizo :: Erizo(string nombre) : Animal(nombre,"E") {

}

Erizo :: Erizo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "E", personalidad) {

}

void Erizo :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Erizo :: disminuir_higiene() {

    higiene -= (personalidad -> obtener_valor_de_disminucion_de_higiene());

    if (higiene < 0) higiene = 0;
}

string Erizo :: obtener_especie_completa() {

    return "Erizo";
}

void Erizo :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con insectos." << endl;
    }

}

void Erizo :: baniar() {

    if (higiene == 100) cout << obtener_nombre() << " ya esta limpio." << endl;

    else {
        if (higiene != 100) higiene = 100;

        cout << "Bañaste a " << obtener_nombre() << endl;
    }
}

bool Erizo :: se_escapo(){
    return(escapado = true);
}