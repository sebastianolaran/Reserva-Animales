#include "Travieso.h"

Travieso :: Travieso() : Personalidad("travieso") {

}
int Travieso :: obtener_valor_de_aumento_de_hambre() {
    return AUMENTO_NORMAL_DE_HAMBRE;
}

int Travieso :: obtener_valor_de_disminucion_de_higiene() {
    return (DISMINUCION_NORMAL_DE_HIGIENE * 2);
}