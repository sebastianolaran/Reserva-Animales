#ifndef _DIMINUTO_H_
#define _DIMINUTO_H_
#include "Tamanio.h"

class Diminuto : public Tamanio {
    //Metodos
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de tamaño y crea uno diminuto.
    Diminuto();

    //PRE: Espacio ingresado por el usuario.
    //POS: Devuelve true si el espacio es mayor a su minimo y
    //     menor a su maximo.
    bool puede_vivir(int espacio);

};

#endif //_DIMINUTO_H_
