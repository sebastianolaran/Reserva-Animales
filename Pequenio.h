#ifndef _PEQUENIO_H_
#define _PEQUENIO_H_
#include "Tamanio.h"

class Pequenio : public Tamanio {
    //Metodos
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de tamaño y crea uno pequeño.
    Pequenio();

    //PRE: Espacio ingresado por el usuario.
    //POS: Devuelve true si el espacio es mayor a su minimo y
    //     menor a su maximo.
    bool puede_vivir(int espacio);

};


#endif //_PEQUENIO_H_
