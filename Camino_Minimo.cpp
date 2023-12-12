#include "Camino_minimo.h"

Camino_minimo::Camino_minimo(Vertice* origen, int fila_origen, int columna_origen) {
    this->origen = origen;
    this->fila_origen = fila_origen;
    this->columna_origen = columna_origen;
    dijkstra();
}

void Camino_minimo::inicializar_matrices () {
    for (int i = 0; i < LONGITUD_LADO_MAPA; i++){
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++){
            matriz_distancia [i][j] = INFINITO;
            matriz_vertices_visitados[i][j] = false;
            matriz_recorrido [i][j] = Default;
        }
    }
    matriz_distancia [fila_origen][columna_origen] = 0;
}

void Camino_minimo::inicializar_vector_vertices_adyacentes(Vertice* vector_vertices_adyacentes[4], Vertice* cursor) {
    vector_vertices_adyacentes[Arriba] = cursor->obtener_vertice_arriba();
    vector_vertices_adyacentes[Abajo] = cursor->obtener_vertice_abajo();
    vector_vertices_adyacentes[Izquierda] = cursor->obtener_vertice_izquierda();
    vector_vertices_adyacentes[Derecha] = cursor->obtener_vertice_derecha();
}

bool Camino_minimo::algun_adyacente_fue_visitado(int fila, int columna) {
    bool algun_adyacente_fue_visitado = false;
    if (columna != 0) {
        if (matriz_vertices_visitados[fila][columna-1]) algun_adyacente_fue_visitado =true;
    }
    if (columna != LONGITUD_LADO_MAPA - 1){
        if( matriz_vertices_visitados[fila][columna+1]) algun_adyacente_fue_visitado =true;
    }
    if (fila != 0) {
        if(matriz_vertices_visitados[fila-1][columna]) algun_adyacente_fue_visitado =true;
    }
    if (fila != LONGITUD_LADO_MAPA - 1) {
        if(matriz_vertices_visitados[fila+1][columna]) algun_adyacente_fue_visitado =true;
    }
    return algun_adyacente_fue_visitado;
}

bool Camino_minimo::todos_los_vertices_visitados(int vector_posicion_de_corte [2]) {
    int contador_fila = 0;
    int contador_columna;
    do{
        contador_columna = 0;
        while(contador_columna < LONGITUD_LADO_MAPA && (matriz_vertices_visitados [contador_fila][contador_columna] || !algun_adyacente_fue_visitado(contador_fila,contador_columna) )){
            contador_columna++;
        }
        contador_fila++;
    } while((contador_fila < LONGITUD_LADO_MAPA) && (contador_columna == LONGITUD_LADO_MAPA));

    vector_posicion_de_corte [0] = contador_fila -1;
    vector_posicion_de_corte [1] = contador_columna;

    return  (vector_posicion_de_corte [0] * vector_posicion_de_corte [1]) == ((LONGITUD_LADO_MAPA - 1) * (LONGITUD_LADO_MAPA));
}

void Camino_minimo::mover_cursor(Vertice *&cursor, int lado) {
    switch (lado) {
        case Arriba:
            cursor = cursor->obtener_vertice_arriba();
            break;
        case Abajo:
            cursor = cursor->obtener_vertice_abajo();
            break;
        case Izquierda:
            cursor = cursor->obtener_vertice_izquierda();
            break;
        case Derecha:
            cursor = cursor->obtener_vertice_derecha();
            break;
        default:
            break;
    }
}

void Camino_minimo::mover_cursor_al(Vertice *&cursor, int fila, int columna) {
    cursor = this->origen;
    for (int i = 0; i < fila; i++) {cursor = cursor->obtener_vertice_abajo();}
    for (int j = 0; j < columna; j++) {cursor = cursor->obtener_vertice_derecha();}

}

void Camino_minimo::dijkstra () {
    inicializar_matrices();
    Vertice *vector_vertices_adyacentes[4];
    int posicion_del_corte [2] = {fila_origen,columna_origen};
    Vertice* cursor = this->origen;

    do {
        mover_cursor_al(cursor,posicion_del_corte[0],posicion_del_corte[1]);
        int vertices_adyacentes_que_pueden_ser_visitados;
        do {
            int costo_minimo = INFINITO;
            int lado_minimo = Default;
            vertices_adyacentes_que_pueden_ser_visitados = 0;
            inicializar_vector_vertices_adyacentes(vector_vertices_adyacentes, cursor);
            ciclo_dijkstra(vector_vertices_adyacentes,cursor,costo_minimo,vertices_adyacentes_que_pueden_ser_visitados,lado_minimo);
            matriz_vertices_visitados[cursor->obtener_fila()][cursor->obtener_columna()] = true;
            mover_cursor(cursor, lado_minimo);
        }while (vertices_adyacentes_que_pueden_ser_visitados != 0);
    }while(!todos_los_vertices_visitados(posicion_del_corte));
}

void Camino_minimo::mostrar_matrices() {

    for (int i = 0; i < LONGITUD_LADO_MAPA; i++) {
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++) {
            cout << matriz_distancia[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < LONGITUD_LADO_MAPA; i++) {
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++) {
            cout << matriz_recorrido [i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;


    for (int i = 0; i < LONGITUD_LADO_MAPA; i++) {
        for (int j = 0; j < LONGITUD_LADO_MAPA; j++) {
            cout << matriz_vertices_visitados[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

int Camino_minimo::costo_minimo_a(int fila, int columna) {
    return matriz_distancia[fila][columna];
}

void Camino_minimo::cargar_camino_minimo_al(int fila, int columna) {
    Vertice* cursor;
    mover_cursor_al(cursor,fila,columna);
    int contador_fila = fila;
    int contador_columna = columna;
    int direccion = matriz_recorrido[contador_fila][contador_columna];
    while (direccion != Default){
        cursor->setear_camino('*');
        switch (direccion){
            case (Arriba): cursor = cursor -> obtener_vertice_abajo();  contador_fila++;break;
            case (Abajo): cursor = cursor -> obtener_vertice_arriba(); contador_fila--;break;
            case (Izquierda): cursor = cursor -> obtener_vertice_derecha(); contador_columna++;break;
            case (Derecha): cursor = cursor -> obtener_vertice_izquierda(); contador_columna--; break;
            default: break;
        }
        direccion = matriz_recorrido[contador_fila][contador_columna];
    }

}

void Camino_minimo::borrar_camino_minimo() {
        Vertice* cursor = origen;
        for (int i = 0; i < LONGITUD_LADO_MAPA/2; i++){
            for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
                cursor ->setear_camino(' ');
                cursor = cursor->obtener_vertice_derecha();
            }
            cursor ->setear_camino(' ');
            cursor = cursor->obtener_vertice_abajo();
            for (int j = 0; j < LONGITUD_LADO_MAPA-1; j++){
                cursor ->setear_camino(' ');
                cursor = cursor->obtener_vertice_izquierda();
            }
            if (cursor->obtener_vertice_abajo() != nullptr){
                cursor ->setear_camino(' ');
                cursor = cursor->obtener_vertice_abajo();
            }
            else cursor ->setear_camino(' ');;
        }
}

void Camino_minimo::ciclo_dijkstra(Vertice* vector_vertices_adyacentes[4], Vertice* cursor, int& costo_minimo, int& vertices_adyacentes_que_pueden_ser_visitados, int& lado_minimo) {
    for (int i = 0; i < 4; i++) {
        Vertice *cursor_adyacente = vector_vertices_adyacentes[i];
        int coste_cursor_matriz = matriz_distancia[cursor->obtener_fila()][cursor->obtener_columna()];
        if (cursor_adyacente != nullptr) {
            int coste_adyacente_matriz = matriz_distancia[cursor_adyacente->obtener_fila()][cursor_adyacente->obtener_columna()];
            if (coste_adyacente_matriz > cursor_adyacente->obtener_costo() + coste_cursor_matriz) {
                matriz_distancia[cursor_adyacente->obtener_fila()][cursor_adyacente->obtener_columna()] = cursor_adyacente->obtener_costo() + coste_cursor_matriz;
                matriz_recorrido[cursor_adyacente->obtener_fila()][cursor_adyacente->obtener_columna()] = i;
            }
            coste_adyacente_matriz = matriz_distancia[cursor_adyacente->obtener_fila()][cursor_adyacente->obtener_columna()];
            if (coste_adyacente_matriz < costo_minimo && !(matriz_vertices_visitados[cursor_adyacente->obtener_fila()][cursor_adyacente->obtener_columna()])) {
                vertices_adyacentes_que_pueden_ser_visitados++;
                costo_minimo = coste_adyacente_matriz;
                lado_minimo = i;
            }
        }
    }
}

