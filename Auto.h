#ifndef _AUTO_H_
#define _AUTO_H_

using namespace std;

const int MAX_COMBUSTIBLE = 100;
const int CARGA_DEL_MENU = 5;
const int MIN_COMBUSTIBLE = 0;

class Auto {

    private:
        int combustible;
    public:
        //CONSTRUCTOR
        Auto();
        //PRE: Carga (valida) ingresada por el ususario.
        //POS: Aumenta el combustible del auto con la carga recibida.
        void cargar_combustible(int carga);

        //PRE: -
        //POS: Devuelve la cantidad de combustible que tiene el auto.
        int consulta_combustible();

        //PRE: 0 < costo <= 40.
        //POS: Disminuye el combustible del auto con el costo recibido.
        void consumir_combustible(int costo);

};

#endif