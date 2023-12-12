#ifndef _GRANDE_H_
#define _GRANDE_H_
#include "Tamanio.h"

class Grande : public Tamanio {
    //Metodos
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de tamaño y crea uno grande.
    Grande();

    //PRE: Espacio ingresado por el usuario.
    //POS: Devuelve true si el espacio es mayor a su minimo y
    //     menor a su maximo.
    bool puede_vivir(int espacio);

};

#endif //_GRANDE_H_