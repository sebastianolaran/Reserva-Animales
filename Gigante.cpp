#include "Gigante.h"

Gigante :: Gigante() : Tamanio("gigante") {
}

bool Gigante :: puede_vivir(int espacio) {
    return (espacio > 50) && (espacio < 1000);
}
