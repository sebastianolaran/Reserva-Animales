#include "Conejo.h"

Conejo :: Conejo(string nombre) : Animal(nombre,"O") {

}

Conejo :: Conejo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "O", personalidad) {

}

void Conejo :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Conejo :: disminuir_higiene() {

    higiene -= (personalidad -> obtener_valor_de_disminucion_de_higiene());

    if (higiene < 0) higiene = 0;
}

string Conejo :: obtener_especie_completa() {

    return "Conejo";
}

void Conejo :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con lechuga." << endl;
    }
}

void Conejo :: baniar() {

    if (higiene == 100) cout << obtener_nombre() << " ya esta limpio." << endl;

    else {
        if (higiene != 100) higiene = 100;

        cout << "Bañaste a " << obtener_nombre() << endl;
    }
}

bool Conejo :: se_escapo(){
    return(escapado = true);
}