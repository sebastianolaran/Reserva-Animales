#ifndef _GIGANTE_H_
#define _GIGANTE_H_
#include "Tamanio.h"

class Gigante : public Tamanio {
    //Metodos
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de tamaño y crea uno gigante.
    Gigante();

    //PRE: Espacio ingresado por el usuario.
    //POS: Devuelve true si el espacio es mayor a su minimo y
    //     menor a su maximo.
    bool puede_vivir(int espacio);

};

#endif //_GIGANTE_H_