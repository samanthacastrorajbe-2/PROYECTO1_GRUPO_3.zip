#ifndef AREAS_H
#define AREAS_H

#include <string>
#include "Area.h"

// Nodo para la lista enlazada de Areas
struct NodoArea {
    Area area;
    NodoArea* sig;
};

// TDA Areas (Lista maestra)
struct Areas {
    NodoArea* cabeza;
};

// TDA Iterador_areas
struct Iterador_areas {
    NodoArea* actual;
};


Area& operator*(const Iterador_areas& it);
Iterador_areas& operator++(Iterador_areas& it);
bool operator!=(const Iterador_areas& it, const Iterador_areas& otro);


Iterador_areas begin(const Areas& areas);
Iterador_areas end(const Areas& areas);


// --- OPERACIONES DEL TDA AREAS ---

/*
* crear_areas()
* Descripción: Crea un conjunto de áreas (la biblioteca) inicialmente vacío.
* Precondición: true
* Postcondición: Devuelve un objeto Areas con su cabeza apuntando a nullptr.
*/
Areas crear_areas();

/*
* es_vacio_areas(areas)
* Descripción: Verifica si la biblioteca no tiene ninguna sección o área asignada.
* Precondición: true
* Postcondición: Devuelve true si la lista de áreas está vacía.
*/
bool es_vacio_areas(const Areas& areas);

/*
* esta_area(areas, codigo)
* Descripción: Verifica si existe un área con el código indicado en la biblioteca.
* Precondición: true
* Postcondición: Devuelve true si el código de área se encuentra en el conjunto.
*/
bool esta_area(const Areas& areas, std::string codigo);

/*
* obtener_area(areas, codigo)
* Descripción: Devuelve el objeto Area que coincide con el código buscado.
* Precondición: El área con ese código debe existir en la biblioteca.
* Postcondición: Retorna el estante/área correspondiente al código.
*/
Area obtener_area(const Areas& areas, std::string codigo);

/*
* insertar_area(areas, nueva_area)
* Descripción: Agrega una nueva área a la lista enlazada de la biblioteca.
* Precondición: El código de la nueva área no debe existir previamente en el conjunto.
* Postcondición: Inserta el nuevo nodo al principio de la lista de áreas.
*/
void insertar_area(Areas& areas, const Area& nueva_area);

/*
* eliminar_area(areas, codigo)
* Descripción: Elimina un área de la biblioteca y libera la memoria de todos sus libros.
* Precondición: true
* Postcondición: Se elimina el nodo del área y se destruye su lista interna de libros.
*/
void eliminar_area(Areas& areas, std::string codigo);

/*
* destruir_areas(areas)
* Descripción: Limpia toda la lista maestra y sus sublistas al cerrar el programa.
* Precondición: true
* Postcondición: Libera toda la memoria dinámica utilizada por las áreas y sus libros.
*/
void destruir_areas(Areas& areas);

#endif // AREAS_H