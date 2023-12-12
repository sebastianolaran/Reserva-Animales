#include "Jugueton.h"

Jugueton :: Jugueton() : Personalidad("jugueton") {
}

int Jugueton :: obtener_valor_de_aumento_de_hambre() {
    return (AUMENTO_NORMAL_DE_HAMBRE * 2);
}

int Jugueton :: obtener_valor_de_disminucion_de_higiene() {
    return DISMINUCION_NORMAL_DE_HIGIENE;
}
