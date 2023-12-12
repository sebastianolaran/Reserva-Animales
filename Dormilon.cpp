#include "Dormilon.h" 

Dormilon :: Dormilon() : Personalidad( "dormilon") {
}

int Dormilon :: obtener_valor_de_aumento_de_hambre() {
    return (AUMENTO_NORMAL_DE_HAMBRE / 2);
}

int Dormilon :: obtener_valor_de_disminucion_de_higiene() {
    return DISMINUCION_NORMAL_DE_HIGIENE;
}
