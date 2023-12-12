#include "Grande.h"

Grande :: Grande() : Tamanio("grande") {
}

bool Grande :: puede_vivir(int espacio) {
    return (espacio > 20) && (espacio < 1000);
}