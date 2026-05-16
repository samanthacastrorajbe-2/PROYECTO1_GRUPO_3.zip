#include <iostream>
#include "Libros.h"

#ifndef AREA_H
#define AREA_H

#include <string>
#include "Libro.h"
#include "ClaveLibro.h"

/*
* struct Area
* Descripción: Estructura que representa una sección o área de la biblioteca
* codigo: string de 3 letras que identifica la sección (ej. "INF")
* libros: TDA Libros, que maneja la lista enlazada de los libros de esta sección
*/
struct Area {
    std::string codigo; 
    Libros libros;      
};

// --- OPERACIONES ESENCIALES DEL TDA AREA ---

/*
* crear_area(codigo_area)
* Descripción: Crea un objeto tipo Area con su código y un conjunto vacío de libros[cite: 144, 146].
* Precondición: true [cite: 145]
* Postcondición: Devuelve un objeto tipo Area
*/
Area crear_area(std::string codigo_area);

/*
* codigo_area(area)
* Descripción: Obtiene el código del objeto area
* Precondición: true
* Postcondición: Devuelve el string del código del área
*/
std::string codigo_area(const Area& area);

/*
* es_area_vacia(area)
* Descripción: Verifica si la sección no tiene libros asignados
* Precondición: true
* Postcondición: Devuelve true si el área no posee libros
*/
bool es_area_vacia(const Area& area);

/*
* esta_libro(area, clave_libro)
* Descripción: Verifica si el área contiene al libro de esa clave
* Precondición: true
* Postcondición: Devuelve true si el libro está en el área
*/
bool esta_libro(const Area& area, const ClaveLibro& clave_libro);

/*
* obtener_libro_area(area, clave_libro)
* Descripción: Devuelve el objeto Libro que coincide con la clave en esa área
* Precondición: true
* Postcondición: Devuelve al libro de la sección
*/
Libro obtener_libro_area(const Area& area, const ClaveLibro& clave_libro);

/*
* insertar_libro_area(area, libro)
* Descripción: Agrega un libro a la sección si su clave no existe en la biblioteca
* Precondición: El área del libro debe ser la misma de la sección area
* Postcondición: Añade el libro a la lista interna del área
*/
void insertar_libro_area(Area& area, const Libro& libro);

/*
* insertar_ejemplar_libro_area(area, clave)
* Descripción: Suma una copia física al libro correspondiente en la sección
* Precondición: Debe existir en el área el libro con esa clave
* Postcondición: Suma un ejemplar al contador del libro
*/
void insertar_ejemplar_libro_area(Area& area, const ClaveLibro& clave);

/*
* eliminar_libro_area(area, clave)
* Descripción: Elimina completamente el libro de la sección
* Precondición: true
* Postcondición: Se elimina el nodo del libro de la lista enlazada
*/
void eliminar_libro_area(Area& area, const ClaveLibro& clave);

/*
* eliminar_ejemplar_libro_area(area, clave)
* Descripción: Resta un ejemplar al libro de la sección
* Precondición: Debe existir al menos un ejemplar del libro
* Postcondición: Disminuye en 1 el número de copias del libro
*/
void eliminar_ejemplar_libro_area(Area& area, const ClaveLibro& clave);

/*
* existe_ejemplar_libro_area(area, clave)
* Descripción: Verifica si el libro existe en la sección y cuenta con ejemplares disponibles
* Precondición: true
* Postcondición: Devuelve true si existe el libro y hay al menos un ejemplar
*/
bool existe_ejemplar_libro_area(Area& area, const ClaveLibro& clave);

/*
* destruir_area(area)
* Descripción: Elimina de memoria toda la información de la sección y sus libros
* Precondición: true
* Postcondición: Libera la memoria dinámica de la lista enlazada de libros
*/
void destruir_area(Area& area);

#endif