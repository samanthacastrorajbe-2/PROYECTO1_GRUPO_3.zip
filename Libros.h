#ifndef LIBROS_H 
#define LIBROS_H
#include <iostream>
#include "Libro.h"
#include "ClaveLibro.h"

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

/*
* crear_conj_libros()
* Descripción: 
* Precondición: true
* Postcondición:devuelve un conjunto vacío de libros 
*/
Libros crear_conj_libros ( ); 

/*
* es_vacio_libros()
* Descripción: 
* libros es el conjunto de libros del que se quiere saber si es vacío
* Precondición: true
* Postcondición: devuelve true si libros es vacío
*/
bool es_vacio_libros (const Libros& libros );

/*
* obternet_libro()
* Descripción: 
* libros es el conjunto de libros del que se quiere obtener un libro con clave clave
* clave es la clave del libro que se quiere obtener de libros
* Precondición: el libro cuya clave es clave debe estar en libros
* Postcondición: devuelve el libro de libros cuya clave es clave
*/
Libro obtener_libro (const Libros& libros, const ClaveLibro& clave); 

/*
* esta_libro()
* Descripción: 
* libros es el conjunto de libros donde se quiere saber si está un libro
* clave es la clave del libro que se quiere saber si está en libros
* Precondición: true
* Postcondición: devuelve true si el libro cuya clave es clave está en libros
*/
bool esta_libro (const Libros& libros, const ClaveLibro& clave) ;

/*
* eliminar_libro()
* Descripción: 
* libros es el conjunto de libros del que se quiere eliminar un libro 
* clave es la clave del libro que se quiere eliminar de libros
* Precondición: true
* Postcondición: Se elimina el libro de libros cuya clave es clave
*/
void eliminar_libro (Libros& libros, const ClaveLibro& clave); 

/*
* hay_ejemplares()
* Descripción: 
* libros es el conjunto de libros del que se quiere saber si hay ejemplares de un libro con clave clave
* clave es la clave del libro del que se quiere saber si hay ejemplares 
* Precondición: el libro cuya clave es clave debe estar en libros
* Postcondición: Devuelve true ssi existe al menos 1 ejemplar del libro cuya clave es clave
*/
bool hay_ejemplares (const Libros& libros, const ClaveLibro& clave); 


/*
* eliminar_ejemplar()
* Descripción: 
* libros es el conjunto de libros donde está el libro del que se quiere eliminar un ejemplar
* clave es la clave del libro del que se quiere eliminar un ejemplar
* Precondición: debe existir al menos un ejemplar en libros con esta clave
* Postcondición: Se elimina un ejemplar del libro cuya clave es clave
*/
void eliminar_ejemplar (Libros& libros, const ClaveLibro& clave); 


/*
* insertar_libro()
* Descripción: 
* libros es el conjunto de libros donde se quiere insertar libro
* libro es el libro que se quiere insertar en libros
* Precondición: true
* Postcondición: Se inserta libro en libros. Al ser libros un conjunto no se puede insertar un libro que ya exista en libros, es decir, con igual clave que la de libro
*/
void insertar_libro (Libros& libros, const Libro& libro); 


/*
* insertar_ejemplar()
* Descripción: 
* libros es el conjunto de libros donde está el libro al que se le quiere insertar un ejemplar
* clave es la clave del libro al que se le quiere insertar un ejemplar
* Precondición: clave debe corresponder a un libro que esté en libros
* Postcondición: Se suma 1 al número de ejemplares del libro cuya clave es clave
*/
void insertar_ejemplar (Libros& libros, const ClaveLibro& clave); 


 /*
* destruir_libros()
* Descripción: 
* libros es el conjunto de libros del que se quiere eliminar toda la información de memoria
* Precondición: true
* Postcondición: elimina de memoria al objeto libros
*/
void destruir_libros (Libros& libros); 



#endif