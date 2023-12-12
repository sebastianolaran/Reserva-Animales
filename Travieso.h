#ifndef _TRAVIESO_H_
#define _TRAVIESO_H_
#include "Personalidad.h"

class Travieso : public Personalidad {
    //Metodos
public:

    //Constructor
    //PRE: -
    //POS: Llama al constructor de personalidad y crea uno travieso.
    Travieso();

    //PRE: -
    //POS: Devuelve el valor del aumento del hambre para la personalidad.
    int obtener_valor_de_aumento_de_hambre();

    //PRE: -
    //POS: Devuelve el valor de la disminucion de higiene para la personalidad.
    int obtener_valor_de_disminucion_de_higiene();

};

#endif //_TRAVIESO_H_