#include "Gato.h"

Gato :: Gato(string nombre) : Animal(nombre, "G") {

}

Gato :: Gato(string nombre, string edad, string tamanio, string personalidad) : Animal(nombre, edad, tamanio, "G", personalidad) {

}

void Gato :: aumentar_hambre() {

    hambre += (personalidad -> obtener_valor_de_aumento_de_hambre());

    if (hambre > 100) hambre = 100;
}

void Gato :: disminuir_higiene() {
    return;
}

string Gato :: obtener_especie_completa() {
    return "Gato";
}


void Gato :: alimentar() {

    if (hambre == 0) cout << obtener_nombre() << " ya esta lleno." << endl;

    else {
        if (hambre != 0) hambre = 0;

        cout << "Alimentaste a " << obtener_nombre() << " con atun." << endl;
    }

}

void Gato :: baniar() {
    cout << obtener_nombre() << " no nesecita bañarse." << endl;

}

bool Gato :: se_escapo(){
    return(escapado = true);
}