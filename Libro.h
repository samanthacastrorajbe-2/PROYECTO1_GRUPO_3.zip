#ifndef LIBRO_H 
#define LIBRO_H
#include <iostream>
#include <string>

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
struct libro {
    std:: string autor, titulo, año, area, editorial;
    int num_ejem; 
};



#endif