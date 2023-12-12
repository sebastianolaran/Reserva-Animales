#ifndef _CABALLO_H_
#define _CABALLO_H_
#include "Animal.h"

class Caballo : public Animal {
    
public:
    //Constructor
    //PRE: -
    //POS: Llama al constructor de animal y crea un caballo.
    Caballo(string nombre);

    //Constructor
    //PRE: -
    //POS: Llama al constructor de animal y crea un caballo.
    Caballo(string nombre, string edad, string tamanio, string personalidad);

    
    //PRE: Que el animal exista en la lista y hambre <= 100.
    //POS: Según la respectiva personalidad del animal aumenta su hambre.
    void aumentar_hambre();

    //PRE: Que el animal exista en la lista y higiene >= 0.
    //POS: Según la respectiva personalidad del animal disminuye su higiene.
    void disminuir_higiene();

    //PRE: -
    //POS: Devuelve el nombre de la especie del animal en forma completa.
    string obtener_especie_completa();

    //PRE: Que el animal exista en la lista.
    //POS: Alimenta al animal y el hambre disminuye a 0.
    void alimentar();

    //PRE: Que el animal exista en la lista.
    //POS: Baña al animal y la higiene aumenta a 100.
    void baniar();

    //PRE: Que el animal exista en la lista.
    //POS: Setea el atributo escapado en true.
    bool se_escapo();

};
#endif //_CABALLO_H_