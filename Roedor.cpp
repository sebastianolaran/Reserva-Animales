#include "Roedor.h"

Roedor :: Roedor(string nombre) : Animal(nombre, "R") {

}

Roedor :: Roedor(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "R", personalidad) {

}

void Roedor :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Roedor :: disminuir_higiene() {
    return;
}

string Roedor :: obtener_especie_completa() {

    return "Roedor";
}


void Roedor :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con queso." << endl;
    }

}

void Roedor :: baniar() {

    cout << obtener_nombre() << " no nesecita bañarse." << endl;

}

bool Roedor :: se_escapo(){
    return(escapado = true);
}