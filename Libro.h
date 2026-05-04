#ifndef LIBRO_H 
#define LIBRO_H
#include <iostream>
#include <string>
#include "ClaveLibro.h"

/*
* struct libro
* Descripción: Estructura para representar un libro de la biblioteca
* autor es el autor del libro
* titulo es el título del libro
* año es el año de publicación del libro
* area es el área a la que pertenece el libro
* editorial es la editorial del libro
* num_ejem es el número de ejemplares del libro que hay en la biblioteca
* Precondición: autor debe seguir las reglas sintácticas sobre un autor
*               area debe ser un área válida de la biblioteca
*               año debe ser un año válido, no puede ser un año futuro
* Postcondición: Devuelve un objeto tipo libro (una estructura con el autor, título, año, área, editorial y número de ejemplares del libro)
*/
struct Libro {
    std:: string autor, titulo, año, area, editorial;
    int num_ejem; 
};

/* 
* crear_libro(autor, titulo, año, area, editorial, num_ejem)
* Descripción: Crea un nuevo libro con los datos proporcionados
* autor es el autor del libro
* titulo es el título del libro
* año es el año de publicación del libro
* area es el área a la que pertenece el libro
* editorial es la editorial del libro
* num_ejem es el número de ejemplares del libro que hay en la biblioteca
* Precondición: autor debe seguir las reglas sintácticas sobre un autor
*               area debe ser un área válida de la biblioteca
*               año debe ser un año válido, no puede ser un año futuro
* Postcondición: Devuelve un objeto tipo libro (una estructura con el autor, título, año, área, editorial y número de ejemplares del libro)
*/
Libro crear_libro (std::string autor, std::string titulo, std::string año, std::string area, std::string editorial, unsigned short num_ejem);


/*
* autor_libro(libro)
* Descripción: Obtiene el autor de un libro
* libro es el libro del que se quiere obtener el autor
* Precondición: true
* Postcondición: Devuelve el autor de libro
*/
std::string autor_libro (const Libro& libro);

/*
* titulo_libro(libro)
* Descripción: Obtiene el título de un libro
* libro es el libro del que se quiere obtener el título
* Precondición: true
* Postcondición: Devuelve el título de libro
*/
std::string titulo_libro (const Libro& libro); 

/*
* año_libro(libro)
* Descripción: Obtiene el año de publicación de un libro
* libro es el libro del que se quiere obtener el año de publicación
* Precondición: true
* Postcondición: Devuelve el año de publicación de libro
*/
std::string año_libro (const Libro& libro); 

/*
* area_libro(libro)
* Descripción: Obtiene el área a la que pertenece un libro
* libro es el libro del que se quiere obtener el área
* Precondición: true
* Postcondición: Devuelve el área del libro
*/
std::string area_libro (const Libro& libro);

/*
* num_ejem(libro)
* Descripción: Obtiene el número de ejemplares de un libro
* libro es el libro del que se quiere obtener el número de ejemplares
* Precondición: true
* Postcondición: Devuelve el número de ejemplares de libro
*/
unsigned short num_ejem (const Libro& libro); 

/*
* clave_libro(libro)
* Descripción: Obtiene la clave de un libro
* libro es el libro del que se quiere obtener la clave
* Precondición: true
* Postcondición: Devuelve la clave conformada por el autor y el título de libro
*/
ClaveLibro clave_libro (const Libro& libro); 

/*
* num_ejem(libro, ejem)
* Descripción: Asigna un número de ejemplares a un libro
* libro es el libro al que se le quiere asignar el número de ejemplares
* ejem es el número de ejemplares que se le quiere asignar al libro
* Precondición: true
* Postcondición: Asigna ejem al número de ejemplares de libro
*/
void num_ejem (const Libro& libro, unsigned short ejem); 

/*
* es_clave(libro, clave)
* Descripción: Verifica si una clave corresponde a un libro
* libro es el libro del que se quiere verificar la clave
* clave es la clave que se quiere verificar si corresponde al libro
* Precondición: true
* Postcondición: Devuelve true si la clave de libro es clave
*/
bool es_clave (const Libro& libro, ClaveLibro clave); 

/*
* destruir_libro(libro)
* Descripción: Elimina de memoria toda la información de un libro
* libro es el libro del que se quiere eliminar toda la información de memoria
* Precondición: true
* Postcondición: elimina de memoria toda la información de libro. Esta operación se usa en caso de que un libro se cree en forma dinámica
*/
void destruir_libro (Libro& libro);


#endif