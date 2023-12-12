#ifndef _SOCIABLE_H_
#define _SOCIABLE_H_
#include "Personalidad.h"

class Sociable : public Personalidad {
    //Metodos
public:

    //Constructor
    //PRE: -
    //POS: llama al constructor de personalidad y crea uno sociable. 
    Sociable();

    //PRE: -
    //POS: Devuelve el valor del aumento del hambre para la personalidad.
    int obtener_valor_de_aumento_de_hambre();

    //PRE: -
    //POS: Devuelve el valor de la disminucion de higiene para la personalidad.
    int obtener_valor_de_disminucion_de_higiene();
};
#endif //_SOCIABLE_H_