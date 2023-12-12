#include "Grafo.h"

Grafo::Grafo(){
    Vertice* matriz_vertices [LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA];
    inicializar_matriz_vertices(matriz_vertices);
    inicializar_aristas(matriz_vertices);
    origen = matriz_vertices[0][0];
    setear_contenido(0,0,'A');
    this->fila_auto = 0;
    this->columna_auto = 0;
    inicializar_animales();
    //Poner el auto de verdad en el origen

}

void Grafo::inicializar_matriz_vertices(Vertice* matriz_vertices [LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA]) {
    int contador = 0;
    for (int i = 0; i < LONGITUD_LADO_MAPA; i++){
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++){
            matriz_vertices[i][j] = new Vertice(i,j);
            matriz_vertices[i][j]->setear_costo(LISTA_COSTOS[contador]);
            contador++;
        }
    }
}

void Grafo::inicializar_aristas(Vertice* matriz_vertices [LONGITUD_LADO_MAPA][LONGITUD_LADO_MAPA]) {
    for (int i = 0; i < LONGITUD_LADO_MAPA; i++){
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++){
            if (j != 0) matriz_vertices[i][j]->setear_vertice_izquierda(matriz_vertices[i][j-1]);
            if (j != LONGITUD_LADO_MAPA - 1) matriz_vertices[i][j]->setear_vertice_derecha(matriz_vertices[i][j+1]);
            if (i != 0) matriz_vertices[i][j]->setear_vertice_arriba(matriz_vertices[i-1][j]);
            if (i != LONGITUD_LADO_MAPA - 1) matriz_vertices[i][j]->setear_vertice_abajo(matriz_vertices[i+1][j]);
        }
    }
}

void Grafo::mover_cursor_al(Vertice*& cursor, int fila, int columna) {
    cursor = this->origen;
    for (int i = 0; i < fila; i++) { cursor = cursor->obtener_vertice_abajo(); }
    for (int j = 0; j < columna; j++) { cursor = cursor->obtener_vertice_derecha(); }
}

Vertice* Grafo::obtener_origen() {
    return this->origen;
}

int Grafo::obtener_costo(int fila, int columna) {
    Vertice* cursor = origen;
    mover_cursor_al(cursor,fila,columna);
    return cursor->obtener_costo();
}

char Grafo::obtener_contenido(int fila, int columna) {
    Vertice* cursor = origen;
    mover_cursor_al(cursor,fila,columna);
    return cursor->obtener_contenido();
}

void Grafo::setear_contenido(int fila, int columna, char contenido) {
    Vertice* cursor = origen;
    mover_cursor_al(cursor,fila,columna);
    cursor->setear_contenido(contenido);
}

void Grafo::setear_animal(int fila, int columna, Animal *animal) {
    Vertice* cursor = origen;
    mover_cursor_al(cursor,fila,columna);
    cursor -> setear_animal(animal);
}

void Grafo::setear_camino(int fila, int columna, char camino) {
    Vertice* cursor = origen;
    mover_cursor_al(cursor,fila,columna);
    cursor -> setear_camino(camino);
}

void Grafo::mover_auto_al(int fila, int columna) {
    Vertice* cursor;
    mover_cursor_al(cursor, this->fila_auto,this->columna_auto);
    cursor->setear_contenido(' ');
    this->fila_auto = fila;
    this->columna_auto = columna;
    mover_cursor_al(cursor,this->fila_auto,this->columna_auto);
    cursor->setear_contenido('A');
}

void Grafo::mostrar_contenidos() {
    Vertice* cursor = origen;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < LONGITUD_LADO_MAPA; i++){
        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
            cout << cursor->obtener_costo() << " " << cursor->obtener_contenido() << "\t";
            cursor = cursor->obtener_vertice_derecha();
        }
        cout << cursor->obtener_costo() << " " << cursor->obtener_contenido() ;
        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++) {
            cursor = cursor->obtener_vertice_izquierda();
        }
        cursor = cursor->obtener_vertice_abajo();
        cout << endl << "-------------------------------------------------------------" << endl;
    }
}

void Grafo::mostrar_camino_del_camino_minimo() {
    Vertice* cursor = origen;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < LONGITUD_LADO_MAPA; i++){
        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
            cout << cursor->obtener_costo() << " " << cursor->obtener_camino() << "\t";
            cursor = cursor->obtener_vertice_derecha();
        }
        cout << cursor->obtener_costo() << " " << cursor->obtener_camino() ;
        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++) {
            cursor = cursor->obtener_vertice_izquierda();
        }
        cursor = cursor->obtener_vertice_abajo();
        cout << endl << "-------------------------------------------------------------" << endl;
    }
}

Grafo::~Grafo() {
    //Crea el cursor y va haciendo el ciclo borrando todos los de la derecha, baja uno, borra todos los de la izquierda, baja uno,.....
    Vertice* cursor = origen;
    for (int i = 0; i < LONGITUD_LADO_MAPA/2; i++){

        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
            cursor = cursor->obtener_vertice_derecha();
            delete cursor->obtener_vertice_izquierda();
        }

        cursor = cursor->obtener_vertice_abajo();
        delete cursor->obtener_vertice_arriba();

        for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
            cursor = cursor->obtener_vertice_izquierda();
            delete cursor->obtener_vertice_derecha();
        }

        if (cursor->obtener_vertice_abajo() != nullptr){
            cursor = cursor->obtener_vertice_abajo();
            delete cursor->obtener_vertice_arriba();
        }
        else delete cursor;
    }
}


int Grafo::generar_numero_random(int maximo){
    return rand() % maximo;
}

Animal* Grafo :: generar_animal_random() {
    int especie_num = generar_numero_random(6);
    Animal* animal;
    switch (especie_num) {
        case 0: animal = new Caballo ("Default"); break;
        case 1: animal = new Conejo ("Default"); break;
        case 2: animal = new Erizo ("Default"); break;
        case 3: animal = new Gato ("Default"); break;
        case 4: animal = new Perro ("Default"); break;
        case 5: animal = new Roedor ("Default"); break;
        case 6: animal = new Lagartija ("Default"); break;
        default: cout << "Error en la creacion del animal random" << endl;
    }
    return animal;
}

void Grafo::generar_coordenadas_random(int coords[2]) {
    int fila = generar_numero_random(LONGITUD_LADO_MAPA);
    int columna = generar_numero_random(LONGITUD_LADO_MAPA);
    while (obtener_contenido(fila,columna) != ' '){
        fila = generar_numero_random(LONGITUD_LADO_MAPA);
        columna = generar_numero_random(LONGITUD_LADO_MAPA);
    }
    coords[0] = fila;
    coords[1] = columna;
}

void Grafo::inicializar_animales() {
    int coords_animal_1 [2];
    int coords_animal_2 [2];
    int coords_animal_3 [2];
    int coords_animal_4 [2];
    int coords_animal_5 [2];
    Animal* animal_1 = generar_animal_random();
    Animal* animal_2 = generar_animal_random();
    Animal* animal_3 = generar_animal_random();
    Animal* animal_4 = generar_animal_random();
    Animal* animal_5 = generar_animal_random();
    generar_coordenadas_random(coords_animal_1);
    setear_animal(coords_animal_1[0],coords_animal_1[1],animal_1);
    mover_cursor_al(this->animal_1,coords_animal_1[0],coords_animal_1[1]);
    generar_coordenadas_random(coords_animal_2);
    setear_animal(coords_animal_2[0],coords_animal_2[1],animal_2);
    mover_cursor_al(this->animal_2,coords_animal_2[0],coords_animal_2[1]);
    generar_coordenadas_random(coords_animal_3);
    setear_animal(coords_animal_3[0],coords_animal_3[1],animal_3);
    mover_cursor_al(this->animal_3,coords_animal_3[0],coords_animal_3[1]);
    generar_coordenadas_random(coords_animal_4);
    setear_animal(coords_animal_4[0],coords_animal_4[1],animal_4);
    mover_cursor_al(this->animal_4,coords_animal_4[0],coords_animal_4[1]);
    generar_coordenadas_random(coords_animal_5);
    setear_animal(coords_animal_5[0],coords_animal_5[1],animal_5);
    mover_cursor_al(this->animal_5,coords_animal_5[0],coords_animal_5[1]);
}

int Grafo::consultar_movimiento_grafo() {
    string opcion;
    cout << endl<<"A que animal desea rescatar?"<<endl;
    if (animal_1 != nullptr) cout << "1) Al " << animal_1->obtener_animal()->obtener_especie_completa() << " de la casilla (" << animal_1->obtener_fila() << " - " << animal_1->obtener_fila() << ")" << endl;
    if (animal_2 != nullptr) cout << "2) Al " << animal_2->obtener_animal()->obtener_especie_completa() << " de la casilla (" << animal_2->obtener_fila() << " - " << animal_2->obtener_fila() << ")" << endl;
    if (animal_3 != nullptr) cout << "3) Al " << animal_3->obtener_animal()->obtener_especie_completa() << " de la casilla (" << animal_3->obtener_fila() << " - " << animal_3->obtener_fila() << ")" << endl;
    if (animal_4 != nullptr) cout << "4) Al " << animal_4->obtener_animal()->obtener_especie_completa() << " de la casilla (" << animal_4->obtener_fila() << " - " << animal_4->obtener_fila() << ")" << endl;
    if (animal_5 != nullptr) cout << "5) Al " << animal_5->obtener_animal()->obtener_especie_completa() << " de la casilla (" << animal_5->obtener_fila() << " - " << animal_5->obtener_fila() << ")" << endl;
    cout << "6) Salir" << endl;
    cin >> opcion;
    // ! Menu::es_una_opcion_valida    while (){    }
    return stoi(opcion);
}

void Grafo::inicio_buscar_animales() {
    bool quiere_seguir_buscando_animales = true;
    while (quiere_seguir_buscando_animales){
        mostrar_contenidos();
        Camino_minimo camino_minimo (this->origen,this->fila_auto,this->columna_auto);
        quiere_seguir_buscando_animales = false;
    }
}