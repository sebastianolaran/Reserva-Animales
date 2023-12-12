#include "Lagartija.h"

Lagartija :: Lagartija(string nombre) : Animal(nombre, "L") {

}

Lagartija :: Lagartija(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "L", personalidad) {

}

void Lagartija :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Lagartija :: disminuir_higiene() {
    return;
}

string Lagartija :: obtener_especie_completa() {

    return "Lagartija";
}


void Lagartija :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con insectos." << endl;
    }

}

void Lagartija :: baniar() {
    cout << obtener_nombre() << " no nesecita bañarse." << endl;
}

bool Lagartija :: se_escapo(){
    return(escapado = true);
}