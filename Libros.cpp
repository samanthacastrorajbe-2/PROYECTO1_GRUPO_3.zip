#include "Libros.h" 

// OJO REVISAR QUE ESTEN BIEN Y FUNCIONEN TODAS LAS FUNCIONES


/*
* crear_conj_libros()
* Descripción: Crea un conjunto (lista) vacío de libros
* Precondición: true
* Postcondición:devuelve un conjunto vacío de libros 
*/
Libros crear_conj_libros ( ){
    Libros libros; // Declaramos una variable de tipo Libros llamada libros
    libros.primero = nullptr; // Como la lista está vacía, el primer apuntador apunta a nullptr
    libros.cantidad = 0; // No hay libros en el conjunto, entonces la cantidad es 0
    return libros; // Retornamos el conjunto de libros recién creado
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
    return Libro(); // Devolvemos un libro vacío por defecto

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
bool hay_ejemplares (const Libros& libros, const ClaveLibro& clave){    
    NodoLibro* temp = libros.primero;
    while (temp != NULL) {
        if (es_clave(temp->data, clave)) {
            if (temp->data.num_ejem > 0) return true; // tiene ejemplares?
        }
        temp = temp->proximo;
    }
    return false; // no encontrado
}


/*
* eliminar_ejemplar()
* Descripción: Elimina un ejemplar del libro correspondiente a la clave dada
* libros es el conjunto de libros donde está el libro del que se quiere eliminar un ejemplar
* clave es la clave del libro del que se quiere eliminar un ejemplar
* Precondición: debe existir al menos un ejemplar en libros con esta clave
* Postcondición: Se elimina un ejemplar del libro cuya clave es clave
*/
void eliminar_ejemplar (Libros& libros, const ClaveLibro& clave){
    NodoLibro* actual = libros.primero; // Empezamos a recorrer la lista desde el primer nodo
    NodoLibro* anterior = nullptr; // Guardamos el nodo anterior para poder eliminar el nodo actual si es necesario

    while (actual != nullptr) { // Mientras no estemos al final de la lista
        if (compara_claves(clave_libro(actual->data), clave) == 0) { // Si la clave del libro actual coincide con la clave buscada
            unsigned short cant = num_ejem(actual->data); // Obtenemos la cantidad de ejemplares del libro actual
            if (cant > 1) { // Si hay más de un ejemplar
                num_ejem(actual->data, cant - 1); // Reducimos la cantidad de ejemplares en uno
            } else { // Si es el último ejemplar disponible
                if (anterior == nullptr) libros.primero = actual->proximo; // Si el nodo a eliminar es el primero, actualizamos el primer nodo
                else anterior->proximo = actual->proximo; // Si no es el primero, el nodo anterior salta al siguiente
                
                delete actual; // Liberamos la memoria del nodo eliminado
                libros.cantidad--; // Disminuimos la cantidad de libros en el conjunto porque se eliminó el libro completo
            }
            return; // Salimos porque ya se procesó la eliminación
        }
        anterior = actual; // Actualizamos el nodo anterior antes de avanzar
        actual = actual->proximo; // Avanzamos al siguiente nodo
    }
} 


/*
* insertar_libro()
* Descripción: Inserta un libro en el conjunto de libros
* libros es el conjunto de libros donde se quiere insertar libro
* libro es el libro que se quiere insertar en libros
* Precondición: true
* Postcondición: Se inserta libro en libros. Al ser libros un conjunto no se puede insertar un libro que ya exista en libros, es decir, con igual clave que la de libro
*/
void insertar_libro (Libros& libros, const Libro& libro){
    // Debe ser un conjunto (no repetidos) y el orden es IMPORTANTE
    ClaveLibro nueva_clave = clave_libro(libro); // Obtenemos la clave del libro que queremos insertar
    
    NodoLibro* nuevo = new NodoLibro; // Creamos un nuevo nodo para insertar el libro
    nuevo->data = libro; // Guardamos el libro en el nuevo nodo
    
    // Insetamos en lista vacía o al inicio (manteniendo el orden)
    if (libros.primero == nullptr || compara_claves(nueva_clave, clave_libro(libros.primero->data)) == -1) {
        nuevo->proximo = libros.primero; // El nuevo nodo apunta al nodo que actualmente es el primero
        libros.primero = nuevo; // El nuevo nodo se convierte en el primer nodo
    } else {
        NodoLibro* actual = libros.primero; // Empezamos a buscar la posición correcta desde el primer nodo
        // Avanzar hasta encontrar la posición correcta
        while (actual->proximo != nullptr && compara_claves(nueva_clave, clave_libro(actual->proximo->data)) == 1) {
            actual = actual->proximo; // Avanzamos al siguiente nodo mientras la nueva clave sea mayor
        }
        
        // Verificar si ya existe (No se insertan duplicados en un conjunto)
        if (actual->proximo != nullptr && compara_claves(nueva_clave, clave_libro(actual->proximo->data)) == 0) {
            delete nuevo; // Liberamos el nodo creado porque el libro ya existe
            return; // No insertamos duplicados
        }
        
        nuevo->proximo = actual->proximo; // El nuevo nodo apunta al siguiente nodo en la posición correcta
        actual->proximo = nuevo; // El nodo actual apunta ahora al nuevo nodo
    }
    libros.cantidad++; // Incrementamos la cantidad de libros en el conjunto
}



/*
* insertar_ejemplar()
* Descripción: Inserta un ejemplar de un libro en el conjunto de libros
* libros es el conjunto de libros donde está el libro al que se le quiere insertar un ejemplar
* clave es la clave del libro al que se le quiere insertar un ejemplar
* Precondición: clave debe corresponder a un libro que esté en libros
* Postcondición: Se suma 1 al número de ejemplares del libro cuya clave es clave
*/
void insertar_ejemplar (Libros& libros, const ClaveLibro& clave){
    NodoLibro* actual = libros.primero; // Empezamos a recorrer la lista desde el primer nodo
    while (actual != nullptr) { // Mientras no estemos al final de la lista
        if (compara_claves(clave_libro(actual->data), clave) == 0) { // Si la clave del libro actual coincide con la clave buscada
            num_ejem(actual->data, num_ejem(actual->data) + 1); // Incrementamos el número de ejemplares en uno
            return; // Salimos porque ya actualizamos el libro
        }
        actual = actual->proximo; // Avanzamos al siguiente nodo
    }
}


 /*
* destruir_libros()
* Descripción: Elimina de memoria al objeto libros
* libros es el conjunto de libros del que se quiere eliminar toda la información de memoria
* Precondición: true
* Postcondición: elimina de memoria al objeto libros
*/
void destruir_libros (Libros& libros){
    NodoLibro* actual = libros.primero;
    while (actual != nullptr) {
        NodoLibro* siguiente = actual->proximo;
        delete actual;
        actual = siguiente;
    }
    libros.primero = nullptr;
    libros.cantidad = 0;
}