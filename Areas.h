#ifndef AREAS_H
#define AREAS_H
#include <iostream>
#include <string>
#include "Area.h"

//El Nodo para la lista enlazada de Áreas
struct NodoArea {
    Area area;         // dato
    NodoArea* sig;     // puntero
};

//El TDA Areas
struct Areas {
    NodoArea* cabeza;  //puntero
};

/*
* crear_areas()
* Descripción: Crea una lista de áreas vacía.
* Postcondición: Devuelve un objeto Areas con su cabeza en nullptr.
*/
Areas crear_areas();

/*
* es_vacio_areas(areas)
* Descripción: Verifica si la biblioteca no tiene ninguna sección.
*/
bool es_vacio_areas(const Areas& areas);

/*
* esta_area(areas, codigo)
* Descripción: Verifica si existe un área con ese código en la lista.
*/
bool esta_area(const Areas& areas, std::string codigo);

/*
* obtener_area(areas, codigo)
* Descripción: Devuelve el objeto Area que coincide con el código.
*/
Area obtener_area(const Areas& areas, std::string codigo);

/*
* insertar_area(areas, nueva_area)
* Descripción: Agrega una nueva área a la lista enlazada.
* Precondición: El código del área no debe existir previamente en la lista.
*/
void insertar_area(Areas& areas, const Area& nueva_area);

/*
* eliminar_area(areas, codigo)
* Descripción: Elimina un área y libera la memoria de todos sus libros.
*/
void eliminar_area(Areas& areas, std::string codigo);

/*
* destruir_areas(areas)
* Descripción: Limpia toda la lista maestra al cerrar el programa.
*/
void destruir_areas(Areas& areas);

#endif