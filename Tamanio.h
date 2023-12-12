#ifndef _TAMANIO_H_
#define _TAMANIO_H_
#include <iostream>

using namespace std;

class Tamanio {
    //Atributos
private:
    string tamanio;

    //Metodos
public:
    //Destructor
    virtual ~Tamanio();

    //Constructor
    //PRE: 
    //POS: Crea un tamaño con su respectivo maximo y minimo.
    Tamanio(string tamanio);
    
    //PRE: -
    //POS: Devuelve el tamaño del animal.
    string obtener_tamanio();

    //PRE: El espacio debe ser entero
    //POS: Devuelve true si el animal es apto para vivir en dicho espacio.
    virtual bool puede_vivir(int espacio) = 0;

};

#endif //_TAMANIO_H