#ifndef AREA_H 
#define AREA_H
#include <iostream>
#include "Libros.h"

// El TDA Area (Individual)
struct Area {
    std::string codigo; // Código del area
    Libros libros; //Conjunto de libros del area
};

// El Nodo para la lista de Areas 
struct NodoArea {
    Area area; // Información del area almacenada en el nodo 
    NodoArea* sig; // siguiente 
};

// El TDA Areas (completo)
struct Areas {
    NodoArea* cabeza; // Puntero al inicio de la lista de areas
};

#endif