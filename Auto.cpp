#include "Auto.h"

Auto :: Auto(){ 
    combustible = 100;
}

int Auto :: consulta_combustible(){
    return combustible;
}

void Auto :: cargar_combustible(int carga){

    combustible += carga;

    if (combustible > MAX_COMBUSTIBLE) combustible = MAX_COMBUSTIBLE;
    
}

void Auto :: consumir_combustible(int costo){

    combustible -= costo;

    if (combustible < MIN_COMBUSTIBLE) combustible = MIN_COMBUSTIBLE;

}