#include "ABB_NODO.h"
#include "ABB.h"

Nodo::Nodo(Animal* animal)
{
    this -> llaves[0] = animal -> obtener_nombre();
    this -> datos[0] = animal;
    this -> cantidad_llaves_ocupadas = 1;
    this -> izquierdo = NULL;
    this -> derecho = NULL;
    this -> medio = NULL;
    this -> padre = NULL;
    
}


int Nodo::obtener_pos_animal(string nombre)
{
    bool encontrado=false;
    int posicion_del_vector;
    int i = 0;
    while( i < cantidad_llaves_ocupadas && !encontrado){
        if (llaves[i] == nombre){
            posicion_del_vector = i;
            encontrado = true;}
        i++;
    }
    if (!encontrado){
        return -1;}
    return posicion_del_vector; 

}


Animal* Nodo::obtener_animal(int pos)
{
    if (pos !=-1)
        return this->datos[pos];
    return NULL;
}


string Nodo::obtener_llaves(int pos){
    return llaves[pos];
}

int Nodo ::obtener_cantidad_llaves(){
    return this ->cantidad_llaves_ocupadas;
}


void Nodo::poner_derecho(Nodo* derecho, Nodo* padre){
    this->derecho = derecho;
    this->padre = padre;
}


void Nodo::poner_derecho(Nodo* derecho){
    this->derecho = derecho;
}



void Nodo::poner_medio(Nodo* medio, Nodo* padre){
    this-> medio = medio;
    this-> padre = padre;
}


void Nodo::poner_medio(Nodo* medio){
   
    this-> medio = medio;
}

void Nodo::poner_izquierdo(Nodo* izquierdo, Nodo* padre){
    this->izquierdo = izquierdo;
    this->padre = padre;
}


void Nodo::poner_padre(Nodo *padre) {
    this->padre = padre;
}

void Nodo::poner_dato(Animal* animal) {
	
    llaves[cantidad_llaves_ocupadas]=animal ->obtener_nombre();
    datos[cantidad_llaves_ocupadas]=animal;
    cantidad_llaves_ocupadas++;
    ordenar();

}

void Nodo:: cambiar_elementos(int pos,Animal* animal){
    this -> llaves[pos] = animal -> obtener_nombre();
    this -> datos[pos] = animal;
}

void Nodo::poner_izquierdo(Nodo* izquierdo){
    this->izquierdo = izquierdo;
}



Nodo* Nodo::obtener_derecho()
{
    return this->derecho;
}


Nodo* Nodo::obtener_izquierdo()
{
    return this->izquierdo;
}

Nodo* Nodo::obtener_medio()
{
    return this->medio;
}



Nodo* Nodo::obtener_padre()
{
    return this->padre;
}

 
bool Nodo::Es_hoja() {
    return (obtener_izquierdo() == NULL  && obtener_derecho() == NULL && obtener_medio()== NULL);
}


bool Nodo::derechoChildOnly() {    
    return (this->obtener_izquierdo() == NULL && this->obtener_medio() == NULL && this->obtener_derecho() != NULL);
}


bool Nodo::izquierdoChildOnly() {
    return (this->obtener_izquierdo() != NULL && this->obtener_medio() == NULL && this->obtener_derecho() == NULL);
}


bool Nodo:: es_nesecario_separar(){
    bool separar = false;
    if (cantidad_llaves_ocupadas == 3){
        separar=true;
    }
    return separar;
}

void Nodo :: vaciar(){
    cantidad_llaves_ocupadas = 1;
}


void Nodo :: ordenar(){ 
 int j;
 string aux;
 Animal* aux_animal;
 for (int i= 1;i < cantidad_llaves_ocupadas; i++){
    j=i;
    aux=llaves[i];
    aux_animal=datos[i];
    while (j > 0 && aux < llaves [j-1]){
        llaves[j]=llaves[j-1];
        datos[j]=datos[j-1];
        j--;
    }
    llaves[j]=aux;
    datos[j]=aux_animal;
 }   
}

void Nodo :: ordenar_por_edad(){
    int cantidad = obtener_cantidad_llaves();
    Animal* vec[cantidad];
    for(int i = 1; i< cantidad; i++){
        vec[i] = obtener_animal(i);
    }
    quick_sort(vec, 0, cantidad);
}

void Nodo :: quick_sort(Animal* vec[], int inicio, int fin){
    Animal* piv;
    int izq, der, med;

    if(inicio < fin){
        piv = vec[inicio];
        izq = inicio;
        der = fin;

        while(izq < der){
            while(der > izq && (vec[der] -> obtener_edad()) > (piv -> obtener_edad())){
                der--;
            }
            if(der > izq){
                vec[izq] = vec[der];
                izq++;
            }

            while(izq < der && (vec[izq] -> obtener_edad()) < (piv -> obtener_edad())){
                izq++;
            }
            if(izq < der){
                vec[der] = vec[izq];
                der--;
            }
        }

        vec[der] = piv;
        med = der;

        quick_sort(vec, inicio, med - 1);
        quick_sort(vec, med + 1, fin);
    }
}