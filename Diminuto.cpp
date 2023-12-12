#include "Diminuto.h"  

Diminuto :: Diminuto() : Tamanio("diminuto") {
}

bool Diminuto :: puede_vivir(int espacio) {
    return (espacio > 0) && (espacio < 2);
}

