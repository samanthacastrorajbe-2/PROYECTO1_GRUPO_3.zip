#include "Area.h"
#include <iostream>

Area crear_area(std::string codigo_area) {
    Area nueva_area;
    nueva_area.codigo = codigo_area;
    // se asume que en Libros.h hay una función para inicializar la lista
    nueva_area.libros = crear_conj_libros(); 
    return nueva_area;
}

std::string codigo_area(const Area& area) {
    return area.codigo;
}

bool es_area_vacia(const Area& area) {
    //verificación al TDA Libros
    return es_vacio_libros(area.libros); 
}

bool esta_libro(const Area& area, const ClaveLibro& clave_libro) {
    //busqueda a la lista de libros
    return esta_libro(area.libros, clave_libro);
}

Libro obtener_libro_area(const Area& area, const ClaveLibro& clave_libro) {
    //obtención al TDA Libros
    return obtener_libro(area.libros, clave_libro);
}

void insertar_libro_area(Area& area, const Libro& libro) {
    //el libro debe pertenecer a esta area
    if (area_libro(libro) == area.codigo) {
        insertar_libro(area.libros, libro);
    } else {
        std::cout << "Error: El libro no pertenece al area " << area.codigo << std::endl;
    }
}

void insertar_ejemplar_libro_area(Area& area, const ClaveLibro& clave) {
    // Delega al TDA Libros
    insertar_ejemplar(area.libros, clave);
}

void eliminar_libro_area(Area& area, const ClaveLibro& clave) {
    //eliminación del nodo al TDA Libros
    eliminar_libro(area.libros, clave);
}

void eliminar_ejemplar_libro_area(Area& area, const ClaveLibro& clave) {
    //resta del ejemplar al TDA Libros
    eliminar_ejemplar(area.libros, clave);
}

bool existe_ejemplar_libro_area(Area& area, const ClaveLibro& clave) {
    //verificación al TDA Libros
    return hay_ejemplares(area.libros, clave); 
}

void destruir_area(Area& area) {
    //esto es lo mas importante
    // Destruir toda la lista enlazada de libros que vive dentro de esta area
    destruir_libros(area.libros);
}