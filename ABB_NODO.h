//
// Created by carolina on 3/6/20.
//
#include <iostream>
#include <string>
#include "Animal.h"

#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H
//hecho con templates paa que podamos poner cualquier tipo de dato

class Nodo
{
private:
    int cantidad_llaves_ocupadas;
    string llaves[3];
    Animal* datos[3];
    Nodo* izquierdo; //izquierdo children
    Nodo* medio; // hijo medio
    Nodo* derecho; //derecho children
    Nodo* padre; //padre,para cuando eliminmos nodos

public:
    
    Nodo(Animal* animal);
    int obtener_pos_animal(string nombre);
    Animal* obtener_animal(int pos);
    string obtener_llaves(int pos);
    int obtener_cantidad_llaves();
    void poner_dato(Animal* animal);
    void cambiar_elementos(int pos,Animal* animal);
    void poner_derecho(Nodo* derecho, Nodo* padre);
    void poner_izquierdo(Nodo* izquierdo, Nodo* padre);
    void poner_izquierdo(Nodo* izquierdo);
    void poner_medio(Nodo* medio, Nodo* padre);
    void poner_medio(Nodo* medio);
    void poner_derecho(Nodo* derecho);
    void poner_padre(Nodo* padre);
    Nodo* obtener_derecho();
    Nodo* obtener_medio();
    Nodo* obtener_izquierdo();
    Nodo* obtener_padre();
    bool Es_hoja();
    bool derechoChildOnly();
    bool izquierdoChildOnly();
    bool es_nesecario_separar();
    void vaciar();
    void ordenar();
    void ordenar_por_edad();
    void quick_sort(Animal* vec[], int inicio, int final);

};

#endif 