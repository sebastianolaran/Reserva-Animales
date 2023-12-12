#include "Caballo.h"

Caballo :: Caballo(string nombre) : Animal(nombre,"C") {

}

Caballo :: Caballo(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "C", personalidad) {

}

void Caballo :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100; 
    
}

void Caballo :: disminuir_higiene() {

    higiene -= (personalidad -> obtener_valor_de_disminucion_de_higiene());

    if (higiene < 0) higiene = 0;
}

string Caballo :: obtener_especie_completa() {

    return "Caballo";
}

void Caballo :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if ( hambre != 0 ) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con manzanas." << endl;
    }

}

void Caballo :: baniar() {

    if (higiene == 100) cout << obtener_nombre() << " ya esta limpio." << endl;

    else {
        if (higiene != 100) higiene = 100;

        cout << "Bañaste a " << obtener_nombre() << endl;
    }
}

bool Caballo :: se_escapo(){
    return(escapado = true);
}