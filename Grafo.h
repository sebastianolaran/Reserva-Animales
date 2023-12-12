#ifndef _GRAFO_H
#define _GRAFO_H
#include "Vertice.h"
#include "Camino_minimo.h"
#include "Caballo.h"
#include "Conejo.h"
#include "Erizo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Perro.h"
#include "Roedor.h"
#include <cstdlib>

const int LISTA_COSTOS [64] = {1,40,2,2,2,2,2,2,
                               1,2,2,2,40,40,40,40,
                               1,1,1,1,1,2,5,5,
                               2,2,2,2,1,2,5,5,
                               5,5,5,2,1,2,5,5,
                               2,2,2,2,1,2,5,5,
                               2,40,40,40,1,2,5,5,
                               2,2,2,2,1,1,1,1};



class Grafo{
    //Atributos
private:
    Vertice* origen;
    int fila_auto;
    int columna_auto;
    Vertice* animal_1;
    Vertice* animal_2;
    Vertice* animal_3;
    Vertice* animal_4;
    Vertice* animal_5;

    //Metodos
public:
    //Constructor
    Grafo();

    //Destructor
    ~Grafo();

    //Inicializa los vertices en una matriz estatica
    void inicializar_matriz_vertices(Vertice* matriz_vertices [LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA]);

    //Inicializa las aristas entre los vertices
    void inicializar_aristas(Vertice* matriz_vertices [LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA]);

    //Mueve el cursor que le pases a la posicion indicada
    void mover_cursor_al (Vertice*& cursor, int fila, int columna);

    //Devuelve el origen del grafo
    Vertice* obtener_origen();

    //Devuelve el contenido
    char obtener_contenido(int fila, int columna);

    //Devuelve el costo del vertice pedido
    int obtener_costo(int fila, int columna);

    //Setea el contenido en el vertice pedido
    void setear_contenido(int fila, int columna, char contenido);

    void setear_animal (int fila, int columna,Animal* animal);

    void setear_camino (int fila, int columna,char camino);

    //Muestra por pantalla todos los costos y contenidos
    void mostrar_contenidos();

    void mostrar_camino_del_camino_minimo();

    int consultar_movimiento_grafo();

    //Genera los 5 animales y los mete en los vertices
    void inicio_buscar_animales();

    //PRE: Recibe el numero maximo que se puede generar.
    //POS: Devuelve un numero aleatorio.
    int generar_numero_random(int maximo);

    Animal* generar_animal_random ();

    void generar_coordenadas_random (int coords[2]);

    void mover_auto_al(int fila, int columna);

    void inicializar_animales();
};
#endif
