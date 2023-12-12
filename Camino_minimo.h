#ifndef GITHUB_GRAFOS_TP3_CAMINO_MINIMO_H
#define GITHUB_GRAFOS_TP3_CAMINO_MINIMO_H
#include "Vertice.h"

const int LONGITUD_LADO_MAPA = 8;
enum LADO{Arriba,Abajo,Izquierda,Derecha,Default};

class Camino_minimo{
    //Atributos
private:
    Vertice* origen;
    int fila_origen;
    int columna_origen;
    int matriz_distancia[LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA];
    int matriz_recorrido[LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA];
    bool matriz_vertices_visitados[LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA];

    //Metodos
public:
    //Constructor
    Camino_minimo(Vertice* origen, int fila_origen, int columna_origen);

    //Calcula las matrices del camino minimo
    void dijkstra ();

    //Me dice si todos los vertices fueron visitados y donde esta el que no
    bool todos_los_vertices_visitados(int vector_posicion_de_corte [2]);

    //Inicializa todas las matrices por default
    void inicializar_matrices ();

    //Me pone en el vector_vertices_adyacentes punteros a los vertices de cada lado
    void inicializar_vector_vertices_adyacentes(Vertice* vector_vertices_adyacentes[4], Vertice* cursor);

    //Me mueve el cursor al lado indicado
    void mover_cursor (Vertice*& cursor, int lado);

    //Me mueve el cursor a la posicion indicada
    void mover_cursor_al(Vertice*& cursor,int fila,int columna);

    //Devuelve el coste minimo a ese vertice
    int costo_minimo_a(int fila, int columna);

    void cargar_camino_minimo_al(int fila, int columna);

    void borrar_camino_minimo();

    //Es un ciclo que se hace dentro del Dijkstra
    void ciclo_dijkstra(Vertice* vector_vertices_adyacentes[4], Vertice* cursor, int& costo_minimo, int& vertices_adyacentes_que_pueden_ser_visitados, int& lado_minimo);

    //Chequea en la matriz_vertices_visitados si los adyacentes habian sido visitados
    bool algun_adyacente_fue_visitado(int fila, int columna);

    //Muestra por pantalla las matrices del camino minimo
    void mostrar_matrices();

};
#endif
