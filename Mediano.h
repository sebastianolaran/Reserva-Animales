#ifndef _MEDIANO_H_
#define _MEDIANO_H_
#include "Tamanio.h"

class Mediano: public Tamanio {
    //Metodos
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de tamaño y crea uno mediano.
    Mediano();

    //PRE: Espacio ingresado por el usuario.
    //POS: Devuelve true si el espacio es mayor a su minimo y
    //     menor a su maximo.
    bool puede_vivir(int espacio);

};

#endif //_MEDIANO_H_