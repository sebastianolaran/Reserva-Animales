#include "Pequenio.h"

Pequenio :: Pequenio() : Tamanio("pequenio") {
}

bool Pequenio :: puede_vivir(int espacio) {
    return (espacio > 0) && (espacio < 10);
}