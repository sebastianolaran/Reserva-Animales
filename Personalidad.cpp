#include "Personalidad.h"

Personalidad :: Personalidad(string personalidad) {
    this -> personalidad = personalidad;
}

string Personalidad :: obtener_personalidad() {
    return personalidad;
}

Personalidad :: ~Personalidad() {
    
}