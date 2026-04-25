#ifndef CLAVELIB_H
#define CLAVELIB_H
#include <iostream>
#include <string>

/*
* struct ClaveLib
* Descripción: Estructura para representar una clave de biblioteca
* autor es el autor del libro
* titulo es el título del libro
* Precondición: autor debe seguir las reglas sintácticas sobre un autor
* Postcondición: Devuelve un objeto tipo ClaveLib (una estructura con el autor y título del libro)
*/
struct ClaveLib {
    std::string autor, titulo; 
};

/*
* crear_clave_lib()
* Descripción: Crea una una nueva clave libro a partir de la entrada del usuario
* Precondición: true 
* Postcondición: devuelve el Autor de clave
*/
ClaveLib crear_clave_lib();

/* 
* autor_clave(clave)
* Descripción: !!!!!!!!!!!!!!!!!!!!!!
* clave es la clave de la que se quiere obtener el autor
* Precondición: true
* Postcondición: Devuelve el autor de la clave
*/
std::string autor_clave (const ClaveLib& clave);

/* 
* titulo_clave(clave)
* Descripción: !!!!!!!!!!!!!!!!!!!!!
* clave es la clave de la que se quiere obtener el título
* Precondición: true
* Postcondición: Devuelve el título de la clave
*/
std::string titulo_clave (const ClaveLib& clave);

/* 
* compara_claves(clave1, clave2)
* Descripción: Compara dos claves de libros para saber cuál va antes en orden lexicográfico
* clave1 es la clave de un libro
* clave2 es la clave de otro libro
* Precondición: true
* Postcondición: devuelve -1 si clave1 es menor que clave2, devuelve 0 si son iguales y devuelve 1 si clave1 es mayor que clave2. El orden que se utiliza es el orden lexicográfico. Si dos claves tienen los mismos autores, una será menor que la otra si el título es menor lexicigráficamente que la otra
*/
unsigned short compara_claves(const ClaveLib& clave1, const ClaveLib& clave2);


#endif