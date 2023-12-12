#ifndef _PERSONALIDAD_H_
#define _PERSONALIDAD_H_
#include <iostream>

using namespace std;

const int AUMENTO_NORMAL_DE_HAMBRE = 10;
const int DISMINUCION_NORMAL_DE_HIGIENE = 10;

class Personalidad {
    //Atributos
private:
    string personalidad;

    //Metodos
public:
    //Destructor
    virtual ~Personalidad();

    //Constructor
    //PRE: -
    //POS: Crea una personalidad seteando sus atributos con los parametros recibidos.
    Personalidad(string personalidad);

    //PRE: -
    //POS: Devuelve el valor del aumento del hambre para la personalidad.
    virtual int obtener_valor_de_aumento_de_hambre() = 0;

    //PRE: -
    //POS: Devuelve el valor de la disminucion de higiene para la personalidad.
    virtual int obtener_valor_de_disminucion_de_higiene() = 0;

    //PRE: -
    //POS: Devuelve la presonalidad en formato string.
    string obtener_personalidad();
};

#endif //_PERSONALIDAD_H_