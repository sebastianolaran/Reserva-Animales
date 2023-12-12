#include "Sociable.h"

Sociable :: Sociable() : Personalidad("sociable") {

}

int Sociable :: obtener_valor_de_aumento_de_hambre() {
    return AUMENTO_NORMAL_DE_HAMBRE;
}

int Sociable :: obtener_valor_de_disminucion_de_higiene() {
    return (DISMINUCION_NORMAL_DE_HIGIENE / 2);
}
