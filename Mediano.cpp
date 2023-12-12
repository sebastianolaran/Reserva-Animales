#include "Mediano.h"

Mediano :: Mediano() : Tamanio("mediano") {
}

bool Mediano :: puede_vivir(int espacio) {
    return (espacio > 10) && (espacio < 1000);
}

