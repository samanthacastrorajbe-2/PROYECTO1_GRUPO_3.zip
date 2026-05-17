#include "ClaveLibro.h"
#include <string>
#include <iostream>

ClaveLibro crear_clave_libro(std::string autor, std::string titulo) {
    ClaveLibro nueva_clave;
    nueva_clave.autor = autor;
    nueva_clave.titulo = titulo;
    return nueva_clave;
}

std::string autor_clave (const ClaveLibro& clave){
    return clave.autor;
}

std::string titulo_clave (const ClaveLibro& clave){
    return clave.titulo;
}


/* 
 * Compara dos claves por orden lexicográfico.
 * Primero compara autores; si son iguales, compara títulos.
 * Devuelve:
 * -1 si clave1 < clave2
 * 0 si clave1 == clave2
 * 1 si clave1 > clave2
 */
short compara_claves(const ClaveLibro& clave1, const ClaveLibro& clave2){
    // Comparación de autores
    if (clave1.autor < clave2.autor) {
        return -1;
    } else if (clave1.autor > clave2.autor) {
        return 1;
    } else {
        // Si los autores son iguales, comparamos títulos
        if (clave1.titulo < clave2.titulo) {
            return -1;
        } else if (clave1.titulo > clave2.titulo) {
            return 1;
        } else {
            return 0; // Son idénticas
        }
    }
}


