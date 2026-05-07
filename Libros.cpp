#include "Libros.h"
/*
* crear_conj_libros()
* Descripción: Crea un conjunto (lista) vacío de libros
* Precondición: true
* Postcondición:devuelve un conjunto vacío de libros 
*/
Libros crear_conj_libros ( ){
    Libros libros;
    libros.primero = nullptr; // Como la lista está vacía, el primer apuntador apunta a nullptr
    libros.cantidad = 0; // No hay libros en el conjunto, entonces la cantidad es 0
    return libros;
} 

/*
* es_vacio_libros()
* Descripción: Verifica si el conjunto de libros está vacío
* libros es el conjunto de libros del que se quiere saber si es vacío
* Precondición: true
* Postcondición: devuelve true si libros es vacío
*/
bool es_vacio_libros (const Libros& libros ){
    return libros.cantidad == 0; // Si la cantidad de libros es 0, entonces el conjunto de libros está vacío
}

/*
* obtener_libro()
* Descripción: Obtiene el libro correspondiente a la clave dada del conjunto de libros
* libros es el conjunto de libros del que se quiere obtener un libro con clave clave
* clave es la clave del libro que se quiere obtener de libros
* Precondición: el libro cuya clave es clave debe estar en libros
* Postcondición: devuelve el libro de libros cuya clave es clave
*/
Libro obtener_libro (const Libros& libros, const ClaveLibro& clave){
    NodoLibro* actual = libros.primero; // Empezamos a recorrer la lista desde el primer nodo
    while (actual != nullptr) { // Mientras no lleguemos al final de la lista
        if (es_clave(actual->data, clave)) { // Si la clave del libro actual es igual a la clave que estamos buscando
            return actual->data; // Devolvemos el libro que corresponde a la clave
        }
        actual = actual->proximo; // Avanzamos al siguiente nodo
    }
    // Si el bucle termina, significa que no se encontró la clave
    std::cout << "No se encontraron libros con esta clave: " << "\n"<< "Autor: " << clave.autor << "\n"<< "Titulo: " << clave.titulo<< std::endl;
    return Libro();

}

/*
* esta_libro()
* Descripción: Verifica si existe un libro con la clave dada en el conjunto de libros
* libros es el conjunto de libros donde se quiere saber si está un libro
* clave es la clave del libro que se quiere saber si está en libros
* Precondición: true
* Postcondición: devuelve true si el libro cuya clave es clave está en libros
*/
bool esta_libro (const Libros& libros, const ClaveLibro& clave) {
    NodoLibro* actual = libros.primero; // Empezamos a recorrer la lista desde el primer nodo
    while (actual != nullptr) { // Mientras no lleguemos al final de la lista
        if (es_clave(actual->data, clave)) { // Si la clave del libro actual es igual a la clave que estamos buscando
            return true; // Devolvemos true si encontramos un libro con la clave dada
        }
        actual = actual->proximo; // Avanzamos al siguiente nodo
    }
    return false; // Si el bucle termina, significa que no se encontró la clave, entonces devolvemos false
}

/*
* eliminar_libro()
* Descripción: Elimina el libro correspondiente a la clave dada del conjunto de libros
* libros es el conjunto de libros del que se quiere eliminar un libro 
* clave es la clave del libro que se quiere eliminar de libros
* Precondición: true
* Postcondición: Se elimina el libro de libros cuya clave es clave
*/
void eliminar_libro (Libros& libros, const ClaveLibro& clave){
    NodoLibro* actual = libros.primero; // Empezamos a recorrer la lista desde el primer nodo
    NodoLibro* anterior = nullptr; // Para mantener un puntero al nodo anterior, que inicialmente es nullptr
    while (actual != nullptr) { // Mientras no lleguemos al final de la lista
        if (es_clave(actual->data, clave)) { // Si la clave del libro actual es igual a la clave que estamos buscando
            if (anterior == nullptr) { // Si el nodo a eliminar es el primero de la lista
                libros.primero = actual->proximo; // El primer nodo ahora será el siguiente del nodo actual
            } else { // Si el nodo a eliminar no es el primero de la lista
                anterior->proximo = actual->proximo; // El nodo anterior ahora apunta al siguiente del nodo actual, saltándose el nodo actual
            }
            delete actual; // Liberamos la memoria del nodo que contiene el libro a eliminar
            libros.cantidad--; // Le quitamos 1 a la cantidad de libros en el conjunto
            return; // Salimos de la función después de eliminar el libro
        }
        anterior = actual; // Actualizamos el nodo anterior al nodo actual antes de avanzar
        actual = actual->proximo; // Avanzamos al siguiente nodo
    }
    std::cout << "No se encontraron libros con esta clave: " << "\n"<< "Autor: " << clave.autor << "\n"<< "Titulo: " << clave.titulo<< std::endl; 
} 

/*
* hay_ejemplares()
* Descripción: Verifica si hay ejemplares disponibles del libro con la clave dada
* libros es el conjunto de libros del que se quiere saber si hay ejemplares de un libro con clave clave
* clave es la clave del libro del que se quiere saber si hay ejemplares 
* Precondición: el libro cuya clave es clave debe estar en libros
* Postcondición: Devuelve true si existe al menos 1 ejemplar del libro cuya clave es clave
*/
bool hay_ejemplares (const Libros& libros, const ClaveLibro& clave); 


/*
* eliminar_ejemplar()
* Descripción: Elimina un ejemplar del libro correspondiente a la clave dada
* libros es el conjunto de libros donde está el libro del que se quiere eliminar un ejemplar
* clave es la clave del libro del que se quiere eliminar un ejemplar
* Precondición: debe existir al menos un ejemplar en libros con esta clave
* Postcondición: Se elimina un ejemplar del libro cuya clave es clave
*/
void eliminar_ejemplar (Libros& libros, const ClaveLibro& clave); 


/*
* insertar_libro()
* Descripción: Inserta un libro en el conjunto de libros
* libros es el conjunto de libros donde se quiere insertar libro
* libro es el libro que se quiere insertar en libros
* Precondición: true
* Postcondición: Se inserta libro en libros. Al ser libros un conjunto no se puede insertar un libro que ya exista en libros, es decir, con igual clave que la de libro
*/
void insertar_libro (Libros& libros, const Libro& libro); 


/*
* insertar_ejemplar()
* Descripción: Inserta un ejemplar de un libro en el conjunto de libros
* libros es el conjunto de libros donde está el libro al que se le quiere insertar un ejemplar
* clave es la clave del libro al que se le quiere insertar un ejemplar
* Precondición: clave debe corresponder a un libro que esté en libros
* Postcondición: Se suma 1 al número de ejemplares del libro cuya clave es clave
*/
void insertar_ejemplar (Libros& libros, const ClaveLibro& clave); 


 /*
* destruir_libros()
* Descripción: Elimina de memoria al objeto libros
* libros es el conjunto de libros del que se quiere eliminar toda la información de memoria
* Precondición: true
* Postcondición: elimina de memoria al objeto libros
*/
void destruir_libros (Libros& libros); 