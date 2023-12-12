#include "Animal.h"
#include <stdlib.h>
#include <time.h>

Animal :: Animal(string nombre ,string edad ,string tamanio ,string especie ,string personalidad) {

    hambre = 0;
    higiene = 100;
    adoptado = false;
    escapado = false;

    this -> nombre = nombre;
    this -> edad = edad;
    this -> especie = especie;

    switch ( personalidad[0] ){
        case DORMILON : this -> personalidad = new Dormilon(); break;
        case SOCIABLE : this -> personalidad = new Sociable(); break;
        case TRAVIESO : this -> personalidad = new Travieso(); break;
        case JUGUETON : this -> personalidad = new Jugueton(); break;
    }

    switch (tamanio[2]){
        case DIMINUTO : this -> tamanio = new Diminuto(); break;
        case PEQUENIO : this -> tamanio = new Pequenio(); break;
        case MEDIANO : this -> tamanio = new Mediano(); break;
        case GRANDE : this -> tamanio = new Grande(); break;
        case GIGANTE : this -> tamanio = new Gigante(); break;
    }

}

Animal :: Animal(string nombre, string especie) {

    hambre = 0;
    higiene = 100;
    adoptado = false;
    escapado = false;

    this -> nombre = nombre;
    this -> edad = generar_edad_rand();
    this -> especie = especie;

    string personalidad_random = generar_personalidad_rand();

    switch ( personalidad_random[0] ){
        case DORMILON : this -> personalidad = new Dormilon(); break;
        case SOCIABLE : this -> personalidad = new Sociable(); break;
        case TRAVIESO : this -> personalidad = new Travieso(); break;
        case JUGUETON : this -> personalidad = new Jugueton(); break;
    }

    string tamanio_random = generar_tamanio_rand();

    switch (tamanio_random[2]){
        case DIMINUTO : this -> tamanio = new Diminuto(); break;
        case PEQUENIO : this -> tamanio = new Pequenio(); break;
        case MEDIANO : this -> tamanio = new Mediano(); break;
        case GRANDE : this -> tamanio = new Grande(); break;
        case GIGANTE : this -> tamanio = new Gigante(); break;
    }
}

Animal :: ~Animal() {
    delete personalidad;
    delete tamanio;
}


string Animal :: obtener_nombre() {
    return nombre;
}

string Animal :: obtener_edad() {
    return edad;
}

string Animal :: obtener_tamanio() {
    return tamanio -> obtener_tamanio();
}

string Animal :: obtener_especie() {
    return especie;
}

string Animal :: obtener_personalidad() {
    return personalidad -> obtener_personalidad();
}

bool Animal :: acceder_a_puede_vivir(int espacio) {
    return tamanio -> puede_vivir(espacio);
}

int Animal :: obtener_hambre() {
    return hambre;
}

int Animal :: obtener_higiene() {
    return higiene;
}

void Animal :: adoptar(){
    adoptado = true;
}

bool Animal :: esta_adoptado(){
    return adoptado;
}

int Animal :: generar_num_rand(int numero){
    srand(time(NULL));
    return (rand() % numero);
}

bool Animal :: obtener_escapado(){
    return escapado;
}

string Animal :: generar_edad_rand(){
    int edad_num = generar_num_rand(MAX_EDAD);
    string edad = to_string(edad_num);

    return edad;
}

/*string Animal :: generar_especie_rand(){
    int especie_num = generar_num_rand(MAX_ESPECIE);

    string especie;
    switch(especie_num){
        case 0:
            especie = "Perro";
            break;
        case 1:
            especie = "Gato";
            break;
        case 2:
            especie = "Caballo";
            break;
        case 3:
            especie = "Roedor";
            break;
        case 4:
            especie = "Conejo";
            break;
        case 5:
            especie = "Erizo";
            break;
        case 6:
            especie = "Lagartija";
            break;
    }

    return especie;
}*/

string Animal :: generar_personalidad_rand(){
    int personalidad_num = generar_num_rand(MAX_PERSONALIDAD);

    string personalidad;
    switch(personalidad_num){
        case 0:
            personalidad = "dormilon";
            break;
        case 1:
            personalidad = "jugueton";
            break;
        case 2:
            personalidad = "sociable";
            break;
        case 3:
            personalidad = "travieso";
            break;
    }

    return personalidad;
}

string Animal :: generar_tamanio_rand(){
    int tamanio_num = generar_num_rand(MAX_TAMANIO);

    string tamanio;
    switch(tamanio_num){
        case 0:
            tamanio = "diminuto";
            break;
        case 1:
            tamanio = "pequenio";
            break;
        case 2:
            tamanio = "mediano";
            break;
        case 3:
            tamanio = "grande";
            break;
        case 4:
            tamanio = "gigante";
            break;
    }

    return tamanio;
}
