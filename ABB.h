//
// Created by carolina on 3/6/20.
//
#ifndef ABB_BST_H
#define ABB_BST_H

#include <iostream>
#include "ABB_NODO.h"
#include "Animal.h"
#include "Auto.h"
#include "Perro.h"
#include "Gato.h"
#include "Conejo.h"
#include "Caballo.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Lagartija.h"



const string PATH = "animales.csv";
const char DELIMITADOR = ',';
const int DISTANCIA_ASCII = (int) 'a' - (int) 'A';
class Arbol
{
private:
    // attributes
    Nodo* raiz;
    int cantidad_animales;
    // methods
    
    Nodo* poner(Nodo* nodo, Animal* animal);
    void imprimir_en_orden(Nodo* nodo);
    void imprimir_en_orden(Nodo* nodo);
    void imprimir_en_orden_completo(Nodo* nodo);

    //PRE: Animal cargado con sus atributos.
    //POS: Imprime cada uno de los atributos del animal recibido.
    void mostrar_datos_del_animal_completo(Animal* animal);

    //PRE: Animal cargado con sus atributos.
    //POS: Imprime el nombre, edad, tamaño, especie y personalidad de un animal.
    void mostrar_datos_del_animal (Animal* animal);

    //PRE: -
    //POS: Convierte las letras de la cadena en minuscula y devuelve
    //     la cadena convertida.
    string en_minuscula(string cadena);

    //PRE: -
    //POS: Devuelve la letra recibida en mayuscula.
    char char_a_mayuscula(char letra);

    //PRE: -
    //POS: Convierte las letras del texto en mayuscula y devuelve
    //     el texto convertido.
    string string_a_mayuscula(string texto);
    Nodo* buscar(Nodo* nodo, string animal);
    void ordenar(Nodo* nodo);
    Nodo* encontrar_minimo(Nodo* nodo);
    //T encontrar_maximo(Nodo* nodo);
    //T successor(Nodo* nodo);
    //T predecessor(Nodo* nodo);
    void borrar_arbol(Nodo* nodo);

public:
    //methods

    // Creates an empty tree
    Arbol();

    int obtener_cantidad();

     // Adds a new nodo to the actual Arbol. If its the tree is empty
     // the nodo inserted will be the raiz
    void poner(Animal* animal);

    // Prints all the animal stored in the Arbol, sorted from the
    // smallest value to the greatest value.
    void imprimir_en_orden();

    //PRE: -
    //POS: Imprime los datos de cada animal del arbol.
    void listar_animales();

    // Prints all the animal stored in the Arbol, sorted from the
    // smallest value to the greatest value.
    void imprimir_en_orden();

    // Finds a given value in the Arbol. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    Nodo* buscar(string animal);

    // Finds the minimum value that exist in the Arbol.
    Nodo* encontrar_minimo();

    // Finds the maximum value that exist in the Arbol.
    //T encontrar_maximo();

    // Finds the successor of a given animal value.
    //T successor(Animal* animal);

    // Finds the predecessor of a given animal value.
    //T predecessor(Animal* animal);

    // Removes a given animal from the Arbol
    void borrar(string animal);

    void ordenar();

    Nodo* obtener_raiz();

    void separar(Nodo* nodo);

    void separar_sin_padre(Nodo * nodo);
    
    //n bool empty();

    // Deletes all the nodes in the Arbol
    void borrar_arbol();

    void separar_con_padre_1llave(Nodo * nodo);

    void separar_con_padre_2llaves(Nodo * nodo);

    void separar_con_padre_2llaves_hi(Nodo * nodo);

    void separar_con_padre_2llaves_hm(Nodo * nodo);

    void separar_con_padre_2llaves_hd(Nodo * nodo);


    //Lectura de datos

    void leer_datos();
    
    Animal* definir_animal(string nombre, string edad, string tamanio, string especie,string personalidad);

    //validadores

    //PRE: -
    //POS: Devuelve true si eligio SI y false si eligio NO.
    bool validador_si_no(string opcion);

    //PRE: 0 <= opcion <= 10000
    //POS: Verifica que la opcion sea correcta dentro del minimo y maximo
    bool es_una_opcion_valida_arbol(string opcion, int minimo, int maximo);

    //Cuidar animales

    void recorrer_arbol_cuidado(Nodo* nodo);

    void elegir_individualmente(Animal* animal);

    void consulta_elegir_individualmente (int &opcion_elegida);

    /* FUNCION ADOPTAR ANIMAL*/

    //PRE: El nombre ingresado debe estar incluido dentro de animales posibles a adoptar.
    //POS:  Establece el animal en ADOPTADO que tiene el mismo nombre
    //     recibido por parametro.
    void establecer_animal_adoptado(string nombre, Nodo* nodo);

    //PRE: Eligio_si validado 
    //POS: Establece el animal en ADOPTADO si eligio_si es true
    void verificar_adopcion(bool eligio_si, Nodo* nodo);

    //PRE: 
    //POS: Muestra los animales que pueden vivir en el tamaño ingresado
    void mostrar_posibles_adopciones(int tamanio_casa, Nodo* nodo);

    //PRE: Arbol tiene que estar cargado.
    //POS: Pide un tamaño  al usuario e imprime los datos de los animales que pueden vivir 
    //     en ese espacio, luego pregunta si desea adoptar un animal y en caso afirmativo
    //     pide su nombre y lo establece como ADOPTADO.
    void adoptar_animal(Nodo* nodo);
    
    //guardar y salir

    void guardar_y_salir(Nodo* nodo);
    
    void recursividad_guardar_y_salir(std :: ofstream& archivo,Nodo* nodo);
    void escribir_archivo(Animal* animal);

    ~Arbol();

};



#endif //ABB_NODO.h
