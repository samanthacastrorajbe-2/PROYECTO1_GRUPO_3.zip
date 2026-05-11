#include "Area.h"
#include "Libros.h"
#include <iostream>

// Crea una seccion individual con su lista de libros vacia
Area crear_area(std::string codigo) {
    Area nueva;
    nueva.codigo = codigo;
    nueva.libros = crear_conj_libros();
    return nueva;
}

// Devuelve el codigo del area
std::string codigo_area(const Area& area) {
    return area.codigo;
}

// Verifica si el area esta vacia 
bool es_area_vacia(const Area& area) {
    return es_vacio_libros(area.libros);
}