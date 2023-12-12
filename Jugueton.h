#ifndef _JUGUETON_H_
#define _JUGUETON_H_
#include "Personalidad.h"

class Jugueton : public Personalidad {
    //Metodos
public:

    //Constructor
    //PRE: -
    //POS: Llama al constructor de personalidad y crea uno jugueton.
    Jugueton();

    //PRE: -
    //POS: Devuelve el valor del aumento del hambre para la personalidad.
    int obtener_valor_de_aumento_de_hambre();

    //PRE: -
    //POS: Devuelve el valor de la disminucion de higiene para la personalidad.
    int obtener_valor_de_disminucion_de_higiene();

};

#endif //_JUGUETON_H_