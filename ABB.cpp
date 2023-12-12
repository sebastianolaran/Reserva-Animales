#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <fstream>
#include "ABB.h"


Arbol::Arbol() {
    this->raiz = NULL;
}



// INSERT, COMPLEXITY WORST CASE: O(h) = O(log2(n)) = recorro como mucho la mitad del arbol
// h: height, n: #nodes
//metodo privado

int Arbol::obtener_cantidad(){
    return cantidad_animales;
}


Nodo* Arbol::poner(Nodo* nodo,Animal* animal) {
    if (nodo == NULL)
        nodo = new Nodo(animal);
    else if (nodo -> Es_hoja() ){
        nodo -> poner_dato(animal); 
        if (nodo ->es_nesecario_separar()){
            separar(nodo);} 
       }
    else if (!(nodo -> Es_hoja()) ){
            //el nodo tiene una sola llave
            if (animal -> obtener_nombre() < nodo ->obtener_llaves(0)  )
                nodo->poner_izquierdo(poner(nodo-> obtener_izquierdo(), animal), nodo);
            //si el nodo tiene 2 llaves
            else if ( nodo ->obtener_cantidad_llaves() == 2 ){ 
                if (animal -> obtener_nombre() < nodo ->obtener_llaves(1) )
                    nodo->poner_medio(poner(nodo->obtener_medio(), animal), nodo);
                else
                    nodo->poner_derecho(poner(nodo->obtener_derecho(), animal), nodo);}
            
            else  
                nodo->poner_medio(poner(nodo->obtener_medio(), animal), nodo);
}
     
    return nodo;
    
    }

void Arbol::poner(Animal* animal)
{
    
    this->raiz = poner(this->raiz, animal);
    

}


//restringe a los animales adoptados
void Arbol::imprimir_en_orden(Nodo* nodo){
    
    if (nodo != NULL)
    {
        imprimir_en_orden(nodo->obtener_izquierdo());
        if (!(nodo -> obtener_animal(0) ->esta_adoptado()))
            cout << nodo ->obtener_llaves(0)<<endl;
        imprimir_en_orden(nodo->obtener_medio());
        if (nodo -> obtener_cantidad_llaves() == 2 && !(nodo -> obtener_animal(1) ->esta_adoptado())) 
            cout << nodo ->obtener_llaves(1)<<endl;
        imprimir_en_orden(nodo->obtener_derecho());
        }
    }
    
            
void Arbol::imprimir_en_orden()
{
    this->imprimir_en_orden(this->raiz);
}

Nodo* Arbol::buscar(Nodo* nodo, string animal){ 
    if (nodo == NULL || nodo -> obtener_llaves(0) == animal){
        return nodo;
    }
    if (animal < nodo -> obtener_llaves(0) ){
        return buscar(nodo->obtener_izquierdo(), animal);
    }
    
    if (nodo ->obtener_cantidad_llaves() == 2 ){
        
        if (nodo -> obtener_llaves(1) == animal)
            return nodo;
        if (animal < nodo ->obtener_llaves(1))
            return buscar(nodo->obtener_medio(), animal);
        else
            return buscar(nodo->obtener_derecho(), animal);    
        }      
        
    return buscar(nodo->obtener_medio(), animal) ;   
        }
    

//se fija si hay nodo con esa animal
Nodo* Arbol::buscar(string animal)
{
    Nodo* resultado = buscar(this->raiz, animal);
 
    return resultado;
}



void Arbol:: separar (Nodo * nodo){
	//caso no tiene padre
    if (nodo == raiz || nodo != NULL){
        separar_sin_padre(nodo);
    }
    else if(nodo->obtener_padre()->obtener_cantidad_llaves() == 1) {
        separar_con_padre_1llave(nodo) ;  
        }
    else
        separar_con_padre_2llaves(nodo);
}

    
void Arbol :: separar_con_padre_1llave(Nodo * nodo){
   //Caso de que el hijo izquierdo tenga que separarse
    //if (nodo->obtener_padre()->obtener_cantidad_llaves() == 1){
      if(nodo ->obtener_izquierdo()->obtener_cantidad_llaves() > nodo->obtener_padre()->obtener_cantidad_llaves() ) { 
        Nodo* nodo_hm=nodo->obtener_padre()->obtener_medio();
        Nodo* nuevo_nodo_hm= new Nodo(nodo->obtener_animal(2));
        nodo -> obtener_padre()->poner_dato(nodo->obtener_animal(1));
        nodo -> vaciar();
        nodo->obtener_padre()-> poner_padre(nodo->obtener_padre()->obtener_padre());
        nuevo_nodo_hm ->poner_padre(nodo->obtener_padre());
        nodo_hm ->poner_padre(nodo->obtener_padre());
        nodo->obtener_padre()->poner_medio(nuevo_nodo_hm);
        nodo->obtener_padre()->poner_derecho(nodo_hm);
    }
    //Caso de que el hijo medio tenga que separarse
    else {
        Nodo* nodo_hi=nodo->obtener_padre()->obtener_izquierdo();
        Nodo* nuevo_nodo_hd= new Nodo(nodo->obtener_animal(2));
        nodo -> obtener_padre()->poner_dato(nodo->obtener_animal(1));
        nodo -> vaciar();
        nodo->obtener_padre()-> poner_padre(nodo->obtener_padre()->obtener_padre());
        nuevo_nodo_hd ->poner_padre(nodo->obtener_padre());
        nodo_hi ->poner_padre(nodo->obtener_padre());
        nodo->obtener_padre()->poner_medio(nodo);
        nodo->obtener_padre()->poner_derecho(nuevo_nodo_hd);
    }
    if (nodo ->obtener_padre() -> obtener_padre() == NULL){
        raiz = nodo ->obtener_padre();
    }
}


void Arbol :: separar_con_padre_2llaves(Nodo * nodo){
        Nodo* nodo_padre = nodo ->obtener_padre();
        //caso de que el padre tenga dos llave //caso izquierdo mayor a medio
        if (nodo ->obtener_izquierdo()->obtener_cantidad_llaves() > (nodo_padre ->obtener_medio()->obtener_cantidad_llaves() && nodo_padre ->obtener_derecho()->obtener_cantidad_llaves())){
           separar_con_padre_2llaves_hi(nodo);
        }
        //caso izqueirdo menor que derecho
        else if(nodo-> obtener_medio() ->obtener_cantidad_llaves() > (nodo_padre ->obtener_izquierdo()->obtener_cantidad_llaves() && nodo_padre ->obtener_derecho()->obtener_cantidad_llaves())) {
            separar_con_padre_2llaves_hm(nodo);
        }
        else{
            separar_con_padre_2llaves_hd(nodo);
        }
    if (nodo-> obtener_padre() ->es_nesecario_separar()){
        separar(nodo-> obtener_padre());
    }
    }   

void Arbol :: separar_con_padre_2llaves_hi(Nodo * nodo){
                Nodo * nuevo_nodo_padre= new Nodo(nodo->obtener_padre()->obtener_animal(0));
                Nodo * nuevo_nodo_hi= new Nodo(nodo->obtener_animal(2));
                Nodo * nuevo_nodo_hd= new Nodo(nodo->obtener_padre()->obtener_animal(1));
                Nodo * nuevo_nodo_hi_hd= new Nodo(nodo->obtener_animal(2));
                Nodo * nodo_pm= (nodo->obtener_padre()->obtener_medio());
                Nodo * nodo_pd= (nodo->obtener_derecho());
                nuevo_nodo_padre -> poner_padre(nodo->obtener_padre()->obtener_padre());
                nuevo_nodo_hi ->poner_padre(nuevo_nodo_padre);
                nuevo_nodo_hd ->poner_padre(nuevo_nodo_padre);
                if (nuevo_nodo_padre ->obtener_padre() == NULL){
                    this -> raiz = nuevo_nodo_padre;}
                nodo -> poner_padre(nuevo_nodo_hi);
                nuevo_nodo_hi_hd ->poner_padre(nuevo_nodo_hi);
                nodo_pd ->poner_padre(nuevo_nodo_hd);
                nodo_pm ->poner_padre(nuevo_nodo_hd);
                nuevo_nodo_padre->poner_izquierdo(nuevo_nodo_hi);
                nuevo_nodo_padre->poner_medio(nuevo_nodo_hd);
                nuevo_nodo_hi ->poner_izquierdo(nodo);
                nuevo_nodo_hi ->poner_medio(nuevo_nodo_hi_hd);
                nuevo_nodo_hd ->poner_izquierdo(nodo_pm);
                nuevo_nodo_hd ->poner_medio(nodo_pd);
}

void Arbol :: separar_con_padre_2llaves_hm(Nodo * nodo){
                Nodo * nuevo_nodo_padre= new Nodo(nodo->obtener_animal(1));
                Nodo * nuevo_nodo_hi= new Nodo(nodo->obtener_padre()->obtener_animal(0));
                Nodo * nuevo_nodo_hd= new Nodo(nodo->obtener_padre()->obtener_animal(1));
                Nodo * nuevo_nodo_hd_hi= new Nodo(nodo->obtener_animal(2));
                Nodo * nodo_pi= (nodo->obtener_padre()->obtener_izquierdo());
                Nodo * nodo_pd= (nodo->obtener_derecho());
                nodo->vaciar();
                nuevo_nodo_padre -> poner_padre(nodo->obtener_padre()->obtener_padre());
                nuevo_nodo_hi ->poner_padre(nuevo_nodo_padre);
                nuevo_nodo_hd ->poner_padre(nuevo_nodo_padre);
                if (nuevo_nodo_padre ->obtener_padre() == NULL){
                    this -> raiz = nuevo_nodo_padre;}
                nodo -> poner_padre(nuevo_nodo_hi);
                nodo_pi ->poner_padre(nuevo_nodo_hi);
                nodo_pd ->poner_padre(nuevo_nodo_hd);
                nuevo_nodo_hd_hi ->poner_padre(nuevo_nodo_hd);
                nuevo_nodo_padre->poner_izquierdo(nuevo_nodo_hi);
                nuevo_nodo_padre->poner_medio(nuevo_nodo_hd);
                nuevo_nodo_hi ->poner_izquierdo(nodo);
                nuevo_nodo_hi ->poner_medio(nodo_pi);
                nuevo_nodo_hd ->poner_izquierdo(nuevo_nodo_hd_hi);
                nuevo_nodo_hd ->poner_medio(nodo_pd);

}

void Arbol :: separar_con_padre_2llaves_hd(Nodo * nodo){
            Nodo * nuevo_nodo_padre= new Nodo(nodo->obtener_padre()->obtener_animal(1));
            Nodo * nuevo_nodo_hi= new Nodo(nodo->obtener_padre()->obtener_animal(0));
            Nodo * nuevo_nodo_hd= new Nodo(nodo->obtener_animal(1));
            Nodo * nuevo_nodo_hd_hd= new Nodo(nodo->obtener_animal(2));
            Nodo * nodo_pi= (nodo->obtener_padre()->obtener_izquierdo());
            Nodo * nodo_pm= (nodo->obtener_medio());
            nodo->vaciar();
            nuevo_nodo_padre -> poner_padre(nodo->obtener_padre()->obtener_padre());
            nuevo_nodo_hi ->poner_padre(nuevo_nodo_padre);
            nuevo_nodo_hd ->poner_padre(nuevo_nodo_padre);
            nodo_pm -> poner_padre(nuevo_nodo_hi);
            nodo_pi ->poner_padre(nuevo_nodo_hi);
            if (nuevo_nodo_padre ->obtener_padre() == NULL){
                    this ->raiz = nuevo_nodo_padre;}
            nodo ->poner_padre(nuevo_nodo_hd);
            nuevo_nodo_hd_hd ->poner_padre(nuevo_nodo_hd);
            nuevo_nodo_padre->poner_izquierdo(nuevo_nodo_hi);
            nuevo_nodo_padre->poner_medio(nuevo_nodo_hd);
            nuevo_nodo_hi ->poner_izquierdo(nodo_pi);
            nuevo_nodo_hi ->poner_medio(nodo_pm);
            nuevo_nodo_hd ->poner_izquierdo(nodo);
            nuevo_nodo_hd ->poner_medio(nuevo_nodo_hd_hd);
}


void Arbol :: separar_sin_padre(Nodo * nodo){
        
        Nodo*  nuevo_hi = new Nodo(nodo -> obtener_animal(0));
        Nodo*  nuevo_hm = new Nodo(nodo -> obtener_animal(2));
        nodo ->cambiar_elementos(0,nodo -> obtener_animal(1));
        nodo ->vaciar();
        nodo ->poner_izquierdo(nuevo_hi);
        nodo ->poner_medio(nuevo_hm);
        nuevo_hi -> poner_padre(nodo);
        nuevo_hm -> poner_padre(nodo);
        raiz = nodo;
        
    
}



void Arbol::borrar(string animal)
{
    Nodo* animal_encontrado= buscar(animal);
    if (animal_encontrado != NULL){
        int pos=animal_encontrado ->obtener_pos_animal(animal);
        cout<<pos<<endl;
        animal_encontrado ->obtener_animal(pos) ->adoptar();
    }
     
}



Nodo* Arbol::obtener_raiz(){
    return this->raiz;
}

void Arbol::borrar_arbol(Nodo* nodo)
{
    if(nodo == NULL)
        return;
    this->borrar_arbol(nodo->obtener_izquierdo());
    this ->borrar_arbol(nodo ->obtener_medio());
    this->borrar_arbol(nodo->obtener_derecho());
    delete nodo;
}


void Arbol::borrar_arbol()
{
    this->borrar_arbol(this->raiz);
}

//LECTURA DE DATOS

void Arbol:: leer_datos() {
    ifstream archivo;
    archivo.open(PATH.c_str());
    string linea;
    while (getline(archivo, linea)) {
        stringstream stream(linea);
        string nombre, edad, tamanio, especie, personalidad;
        getline(stream, nombre, DELIMITADOR);
        getline(stream, edad, DELIMITADOR);
        getline(stream, tamanio, DELIMITADOR);
        getline(stream, especie, DELIMITADOR);
        getline(stream, personalidad, DELIMITADOR);
        Animal* agregar = definir_animal(nombre, edad, tamanio, especie, personalidad);
        poner(agregar);
        this -> cantidad_animales++;
    }
}


Animal* Arbol :: definir_animal(string nombre, string edad, string tamanio, string especie,string personalidad) {
    Animal* asignar = 0;
    switch (especie[0]) {
    case 'P':
        asignar = new Perro(nombre, edad, tamanio, personalidad);
        break;
    case 'G':
        asignar = new Gato(nombre, edad, tamanio, personalidad);
        break;
    case 'C':
        asignar = new Caballo(nombre, edad, tamanio, personalidad);
        break;
    case 'R':
        asignar = new Roedor(nombre, edad, tamanio, personalidad);
        break;
    case 'O':
        asignar = new Conejo(nombre, edad, tamanio, personalidad);
        break;
    case 'E':
        asignar = new Erizo(nombre, edad, tamanio, personalidad);
        break;
    case 'L':
        asignar = new Lagartija(nombre, edad, tamanio, personalidad);
        break;
    default:
        break;
    }
    return asignar;
}

/*---------------------VALIDADORES----------------*/


bool Arbol :: es_una_opcion_valida_arbol(string opcion, int minimo, int maximo) {
    bool es_numerico = true;
    int i = 0;
    while(es_numerico &&  i < int(opcion.length())) {
        if (!isdigit(opcion[i])) es_numerico = false;
            i++;
    }
    return (es_numerico && !( (stoi(opcion) < minimo) || (stoi(opcion) > maximo) ) );
}

bool Arbol :: validador_si_no(string opcion) {
    while (!(opcion == "s" || opcion == "S" || opcion == "n" || opcion == "N")) {
        cout << "Por favor ingrese S o N" << endl;
        cin >> opcion;
    }
    return (opcion == "s" || opcion == "S");
}

/*---------------------FUNCION LISTAR ANIMALES----------------*/

char Arbol :: char_a_mayuscula(char letra) {
    if ((letra >= 'a') && (letra <= 'z')) {
        letra = (char) ((int) letra - DISTANCIA_ASCII);
    }
    return letra;
}

string Arbol :: string_a_mayuscula(string texto) {
    texto[0] = char_a_mayuscula(texto[0]);
    return texto;
}

void Arbol :: mostrar_datos_del_animal_completo(Animal* animal) {
    cout << endl
         << "----------------------------------------------------" << endl
         << "Nombre: " << string_a_mayuscula(animal -> obtener_nombre()) << endl
         << "Edad: " << animal -> obtener_edad() << endl
         << "Tamaño: " << string_a_mayuscula(animal -> obtener_tamanio()) << endl
         << "Especie: " << string_a_mayuscula(animal -> obtener_especie_completa()) << endl
         << "Personalidad: " << string_a_mayuscula(animal -> obtener_personalidad()) << endl
         << "Hambre: " << animal -> obtener_hambre() << endl
         << "Higiene: " << animal -> obtener_higiene() << endl;

    if(animal->esta_adoptado()){
        cout << "Adoptado: sí" <<endl;
    }else{
        cout << "Adoptado: no" <<endl;
    }     
    cout << "----------------------------------------------------" << endl;
}

void Arbol::imprimir_en_orden_completo(Nodo* nodo){
    
    if (nodo != NULL){
        imprimir_en_orden_completo(nodo->obtener_izquierdo());
        if (!(nodo -> obtener_animal(0) ->esta_adoptado()))
            mostrar_datos_del_animal_completo(nodo ->obtener_animal(0));
        imprimir_en_orden_completo(nodo->obtener_medio());
        if (nodo -> obtener_cantidad_llaves() == 2 && !(nodo -> obtener_animal(1) ->esta_adoptado())) 
            mostrar_datos_del_animal_completo(nodo ->obtener_animal(1));
        imprimir_en_orden_completo(nodo->obtener_derecho());
    }
}
            
void Arbol :: listar_animales()
{
    imprimir_en_orden_completo(this->raiz);
}


/*---------------------FUNCION CUIDAR ANIMALES----------------*/

void Arbol :: recorrer_arbol_cuidado(Nodo* nodo){
    recorrer_arbol_cuidado(nodo->obtener_izquierdo());
    if (!(nodo -> obtener_animal(0) ->esta_adoptado())){
        elegir_individualmente(nodo->obtener_animal(0));
    recorrer_arbol_cuidado(nodo->obtener_medio());
    if (nodo -> obtener_cantidad_llaves() == 2 && !(nodo -> obtener_animal(1) ->esta_adoptado()))
        elegir_individualmente(nodo -> obtener_animal(1));}
}

void Arbol :: elegir_individualmente(Animal* animal) {
        int opcion_elegida = 0;
        //mostrar_datos_del_animal_completo(animal);
        consulta_elegir_individualmente(opcion_elegida);
        switch (opcion_elegida) {
            case 1 :
            animal -> baniar(); break;
            case 2 : 
            animal -> alimentar(); break;
            case 3 : 
            break;
        }
    }


void Arbol :: consulta_elegir_individualmente (int &opcion_elegida) {
    cout << endl << "Que desea hacer?" << endl
         << "1) Bañar" << endl
         << "2) Alimentar" << endl
         << "3) Saltear" << endl
         << endl;
    string opcion;
    cin >> opcion;
    while (!es_una_opcion_valida_arbol(opcion, 1, 3)) {
        cout << "ERROR: Opcion invalida. Igrese otra opcion."<< endl;
        cin >> opcion;
        cout << endl;
    }
    opcion_elegida = stoi(opcion);
}

/*---------------------FUNCION ADOPTAR ANIMALES----------------*/

void Arbol :: establecer_animal_adoptado(string nombre, Nodo* nodo) {
    bool existe_el_nombre = false;
    int posicion = 1;
    while((!existe_el_nombre ) && (posicion <= nodo -> obtener_cantidad_llaves())) {
        if(nombre == nodo -> obtener_animal(posicion) -> obtener_nombre()){
            existe_el_nombre = true;
        }   
        else {
            posicion++;
        }
    }
    borrar(nombre);
}

void Arbol :: verificar_adopcion(bool eligio_si, Nodo* nodo) {
    string nombre;
    if (eligio_si) {
        cout << "Ingrese a continuacion el nombre del animal: ";
        cin.ignore();
        getline(cin, nombre);
        nombre = string_a_mayuscula(nombre);
        establecer_animal_adoptado(nombre, nodo);
        cout << "El animal fue adoptado" << endl;
    }
}

void Arbol :: mostrar_posibles_adopciones(int tamanio_casa, Nodo* nodo){
    for (int i = 1; i <= nodo -> obtener_cantidad_llaves(); i++) {
        if (nodo -> obtener_animal(i) -> acceder_a_puede_vivir(tamanio_casa)) {
            mostrar_datos_del_animal(nodo -> obtener_animal(i));
        }
    }
}

void Arbol :: adoptar_animal(Nodo* nodo) {
    string interruptor, opcion_si_no, tamanio_casa;;
    cout << "Ingrese el tamanio de su hogar en m2: ";
    cin.ignore();
    getline(cin, tamanio_casa);
    while (!(es_una_opcion_valida_arbol(tamanio_casa, 0, 1000))) {
        cout << "La opcion ingresada es incorrecta" << endl << "Ingrese nuevamente : ";
        cin.ignore();
        getline(cin, tamanio_casa);
    }
    nodo -> ordenar_por_edad();
    mostrar_posibles_adopciones(stoi(tamanio_casa), nodo);
    cout << "Desea adoptar algun animal?(s/n): ";
    cin.ignore();
    getline(cin, opcion_si_no);
    bool eligio_si = validador_si_no(opcion_si_no);
    verificar_adopcion(eligio_si,nodo);
}

/*---------------------FUNCION GUARDAR Y SALIR----------------*/

void Arbol :: guardar_y_salir(Nodo* nodo) {
    ofstream archivo(PATH);
    recursividad_guardar_y_salir(archivo,nodo);
    archivo.close();
    }



void Arbol :: recursividad_guardar_y_salir(std :: ofstream& archivo,Nodo* nodo){
    if (nodo != NULL){
        cout << nodo -> obtener_animal(0) << endl;
        recursividad_guardar_y_salir(archivo,nodo -> obtener_izquierdo());
        if (! (nodo -> obtener_animal(0) -> esta_adoptado())){
            archivo << nodo -> obtener_animal(0) -> obtener_nombre() << ','
            << nodo -> obtener_animal(0)-> obtener_edad() << ','
            << nodo -> obtener_animal(0) -> obtener_tamanio() << ','
            << nodo -> obtener_animal(0) -> obtener_especie() << ','
            << nodo -> obtener_animal(0) -> obtener_personalidad() << '\n';
            }
        recursividad_guardar_y_salir(archivo,nodo->obtener_medio());
        if (nodo -> obtener_cantidad_llaves() == 2 && ! (nodo -> obtener_animal(1) ->esta_adoptado())){
            archivo << nodo -> obtener_animal(1) -> obtener_nombre() << ','
            << nodo -> obtener_animal(1)-> obtener_edad() << ','
            << nodo -> obtener_animal(1) -> obtener_tamanio() << ','
            << nodo -> obtener_animal(1) -> obtener_especie() << ','
            << nodo -> obtener_animal(1) -> obtener_personalidad() << '\n';
            
        } 
        recursividad_guardar_y_salir(archivo,nodo -> obtener_derecho());
        
}
}

Arbol::~Arbol()
{
    this->borrar_arbol();
}
