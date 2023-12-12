#ifndef _VERTICE_H
#define _VERTICE_H
#include <iostream>
#include "Animal.h"

const int INFINITO = 999999;

using namespace std;

class Vertice {
    //Atributos
private:
    int fila;
    int columna;
    int costo;
    char contenido;
    char camino;
    Animal* animal;
    Vertice* vertice_arriba;
    Vertice* vertice_abajo;
    Vertice* vertice_izquierda;
    Vertice* vertice_derecha;

public:
    Vertice();

    Vertice (int fila, int columna);

    int obtener_fila();

    int obtener_columna();

    void setear_fila(int fila);

    void setear_columna(int columna);

    int obtener_costo();

    char obtener_contenido();

    char obtener_camino ();

    Animal* obtener_animal();

    void setear_costo(int costo);

    void setear_contenido(char contenido);

    void setear_camino(char camino);

    void setear_animal(Animal* animal);

    Vertice* obtener_vertice_arriba();

    Vertice* obtener_vertice_abajo();

    Vertice* obtener_vertice_izquierda();

    Vertice* obtener_vertice_derecha();

    void setear_vertice_arriba(Vertice* vertice_arriba);

    void setear_vertice_abajo(Vertice* vertice_abajo);

    void setear_vertice_izquierda(Vertice* vertice_izquierda);

    void setear_vertice_derecha(Vertice* vertice_derecha);


};

#endif
