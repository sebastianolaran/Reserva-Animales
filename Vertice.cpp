#include "Vertice.h"


Vertice::Vertice(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->costo = INFINITO;
    this->contenido = ' ';
    this->camino = ' ';
    this->animal = nullptr;
    this->vertice_arriba = nullptr;
    this->vertice_abajo = nullptr;
    this->vertice_izquierda = nullptr;
    this->vertice_derecha = nullptr;

}

Vertice::Vertice() {

}

int Vertice::obtener_fila() {
    return this -> fila;
}

int Vertice::obtener_columna(){
    return this -> columna;
}

void Vertice::setear_columna(int columna) {
    this -> columna = columna;
}

void Vertice::setear_fila(int fila) {
    this -> fila = fila;
}

int Vertice::obtener_costo(){
    return this -> costo;
}

char Vertice::obtener_contenido(){
    return this -> contenido;
}

char Vertice::obtener_camino() {
    return this -> camino;
}

Animal *Vertice::obtener_animal() {
    return this->animal;
}

void Vertice::setear_costo(int costo) {
    this -> costo = costo;
}

void Vertice::setear_contenido(char contenido){
    this -> contenido = contenido;
}

void Vertice::setear_camino(char camino) {
    this -> camino = camino;
}

void Vertice::setear_animal(Animal *animal) {
    this -> animal = animal;
    this -> contenido = animal -> obtener_especie() [0];
}

Vertice* Vertice::obtener_vertice_arriba() {
    return this -> vertice_arriba;
}

Vertice* Vertice::obtener_vertice_abajo() {
    return this -> vertice_abajo;
}

Vertice* Vertice::obtener_vertice_izquierda() {
    return this -> vertice_izquierda;
}

Vertice* Vertice::obtener_vertice_derecha() {
    return this -> vertice_derecha;
}

void Vertice::setear_vertice_arriba(Vertice *vertice_arriba) {
    this->vertice_arriba = vertice_arriba;
}

void Vertice::setear_vertice_abajo(Vertice *vertice_abajo) {
    this -> vertice_abajo = vertice_abajo;
}

void Vertice::setear_vertice_izquierda(Vertice *vertice_izquierda) {
    this -> vertice_izquierda = vertice_izquierda;
}

void Vertice::setear_vertice_derecha(Vertice *vertice_derecha) {
    this -> vertice_derecha = vertice_derecha;
}
