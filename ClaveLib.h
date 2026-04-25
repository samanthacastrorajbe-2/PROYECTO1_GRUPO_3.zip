#ifndef CLAVELIB_H
#define CLAVELIB_H
#include <iostream>
#include <string>

/*
* struct ClaveLib
* Descripción: Estructura para representar una clave de biblioteca
* autor es el autor del libro
* titulo es el título del libro
* Precondición: true
* Postcondición: Devuelve una estructura con el autor y título del libro
*/
struct ClaveLib {
    std::string autor, titulo; 
};

void crear_clavelib();

#endif