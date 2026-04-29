#ifndef LIBROS_H 
#define LIBROS_H
#include <iostream>
#include "Libro.h"

/*
* struct NodoLibro
* Descripción: Estructura para representar un nodo en la lista enlazada de libros 
* info es la información del libro almacenada en el nodo
* sig es un puntero al siguiente nodo en la lista enlazada
* Precondición: true
* Postcondición: Devuelve un objeto tipo NodoLibro (una estructura con la información del libro y un puntero al siguiente nodo)
*/
struct NodoLibro {
    Libro info;     // Información del libro almacenada en el nodo
    NodoLibro* sig; // Puntero al siguiente nodo en la lista enlazada
};

/*
* struct Libros
* Descripción: Estructura para representar la lista enlazada de libros de la biblioteca
* primero es un puntero al inicio de la lista enlazada de libros
* cantidad es un entero que representa la cantidad de libros en la lista enlazada
* Precondición: true
* Postcondición: Devuelve un objeto tipo Libros (una estructura con un puntero al inicio de la lista enlazada de libros y la cantidad de libros en la lista enlazada) 
*/
struct Libros {
    NodoLibro* primero; // Puntero al inicio de la lista enlazada
    int cantidad;       // Para saber cuántos libros hay en total
};

#endif