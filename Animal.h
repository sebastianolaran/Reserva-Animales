#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include "Personalidad.h"
#include "Dormilon.h"
#include "Jugueton.h"
#include "Sociable.h"
#include "Travieso.h"
#include "Tamanio.h"
#include "Pequenio.h"
#include "Diminuto.h"
#include "Mediano.h"
#include "Grande.h"
#include "Gigante.h"

using namespace std;
//TAMAÑOS
const char PEQUENIO = 'q';
const char DIMINUTO = 'm';
const char MEDIANO = 'd';
const char GRANDE = 'a';
const char GIGANTE = 'g';
//PERSONALIDAD
const char DORMILON = 'd';
const char SOCIABLE = 's';
const char TRAVIESO = 't';
const char JUGUETON = 'j';

const int MAX_EDAD = 101;
const int MAX_ESPECIE = 7;
const int MAX_PERSONALIDAD = 4;
const int MAX_TAMANIO = 5;



class Animal {
    //Atributos
protected:
    int higiene;
    int hambre;
    Personalidad* personalidad;
    Tamanio* tamanio;
    string nombre;
    string edad;
    string especie;
    bool adoptado;
    bool escapado;

public:
    //Constructor
    //PRE: Recibe el nombre ingresado por el usuario.
    //POS: Crea un animal con el dato recibido como parametro, ademas 
    //     genera aleatoriamente sus caracteristicas, y setea su hambre 
    //      e higiene en 0 y 100 respectivamente.
    Animal (string nombre, string especie);

    //Constructor
    //PRE: -
    //POS: Crea un animal con los datos recibidos como parametros y ademas 
    //      setea su hambre e higiene en 0 y 100 respectivamente.
    Animal(string nombre ,string edad ,string tamanio ,string especie ,string personalidad);

    //Destructor
    //PRE: -
    //POS: Libera la memoria usada de un respectivo animal.
    virtual ~Animal();

    //PRE: Que el animal exista en la lista.
    //POS: Setea el hambre en 0.
    virtual void alimentar() = 0;

    //PRE: Que el animal exista en la lista.
    //POS: Setea la higiene en 100.
    virtual void baniar() = 0;

    //PRE: -
    //POS: Devuelve el nombre del animal.
    string obtener_nombre();

    //PRE: -
    //POS: Devuelve la edad del animal.
    string obtener_edad();

    //PRE: -
    //POS: Devuelve el tamaño del animal.
    string obtener_tamanio();

    //PRE: -
    //POS: Devuelve la especie del animal.
    string obtener_especie();

    //PRE: -
    //POS: Devuelve el nombre de la especie del animal en forma completa.
    virtual string obtener_especie_completa() = 0;

    //PRE: -
    //POS: Devuelve la personalidad del animal
    string obtener_personalidad();

    //POS: Espacio ingresado por el usuario.
    //PRE: Llama al metodo puede vivir de la clase tamanio y devuelve true 
    //      si el animal puede vivir en ese espacio.
    bool acceder_a_puede_vivir(int espacio);

    //PRE: -
    //POST:Devuelve el valor de la higiene del animal.
    int obtener_higiene();

    //PRE: -
    //POST: Devuelve el valor del hambre del animal.
    int obtener_hambre();

    //PRE: -
    //POST: Devuelve el true si el animal escapo y false si no.
    bool obtener_escapado();

    //PRE: Que el animal exista en la lista y hambre <= 100.
    //POS: Aumenta el hambre del animal.
    virtual void aumentar_hambre() = 0;

    //PRE: Que el animal exista en la lista y higiene >= 0.
    //POS: Disminuye la higiene del animal.
    virtual void disminuir_higiene() = 0;

    //PRE: Que el animal exista en la lista.
    //POS: Setea el atributo escapado en true.
    virtual bool se_escapo() = 0;

    //PRE: -
    //POS: Setea el atributo adoptado a True
    void adoptar();

    bool esta_adoptado();

    //PRE: -
    //POS: Devuelve una edad aleatoria >= 0 y <= 100.
    string generar_edad_rand();

    //PRE: -
    //POS: Devuelve una personalidad aleatoria.
    string generar_personalidad_rand();

    //PRE: -
    //POS: Devuelve un tamanio aleatorio.
    string generar_tamanio_rand();

    //PRE: Recibe el numero maximo que se puede generar.
    //POS: Devuelve un numero aleatorio.
    int generar_num_rand(int numero);

};

#endif //_ANIMAL_H_

