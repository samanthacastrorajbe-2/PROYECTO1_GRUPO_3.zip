//Este va a ser el archivo de main
#include <iostream>
#include <string>
#include "ClaveLibro.h"
#include "Libro.h"
#include "Libros.h"


// Función auxiliar para mostrar el contenido de la biblioteca
void imprimir_biblioteca(const Libros& libros) {
    if (es_vacio_libros(libros)) {
        std::cout << "La biblioteca esta vacia." << std::endl;
        return;
    }
    
    NodoLibro* actual = libros.primero;
    std::cout << "--- Listado de Libros (" << libros.cantidad << ") ---" << std::endl;
    while (actual != nullptr) {
        std::cout << "- " << titulo_libro(actual->data) 
                  << " | Autor: " << autor_libro(actual->data) 
                  << " | Ejemplares: " << num_ejem(actual->data) << std::endl;
        actual = actual->proximo;
    }
    std::cout << "---------------------------------------" << std::endl;
}

int main() {
/*     std::cout << "=== TEST DE INTEGRIDAD: TDA CLAVELIBRO ===" << std::endl << std::endl;

    // 1. Prueba de crear_clave_libro[cite: 1, 5, 6]
    // Verificamos que la función constructora asigne los valores correctamente.
    std::string autor_orig = "Garcia, B. & Hernandez, C.";
    std::string titulo_orig = "Lenguaje C";
    ClaveLibro clave = crear_clave_libro(autor_orig, titulo_orig);
    
    std::cout << "1. Prueba de creacion: OK" << std::endl;

    // 2. Prueba de autor_clave[cite: 1, 5, 6]
    // Extraemos el autor del objeto creado para ver si coincide.
    if (autor_clave(clave) == autor_orig) {
        std::cout << "2. Prueba de autor_clave: OK (Retorna: " << autor_clave(clave) << ")" << std::endl;
    } else {
        std::cout << "2. Prueba de autor_clave: ERROR" << std::endl;
    }

    // 3. Prueba de titulo_clave[cite: 1, 5, 6]
    // Extraemos el título del objeto creado.
    if (titulo_clave(clave) == titulo_orig) {
        std::cout << "3. Prueba de titulo_clave: OK (Retorna: " << titulo_clave(clave) << ")" << std::endl;
    } else {
        std::cout << "3. Prueba de titulo_clave: ERROR" << std::endl;
    }

    // 4. Prueba de compara_claves[cite: 1, 5, 6]
    // Probamos los tres escenarios posibles: menor, mayor e igual.
    std::cout << "4. Pruebas de comparacion lexicografica:" << std::endl;

    ClaveLibro clave_menor = crear_clave_libro("Alvarez, A.", "Z-Libro"); // Autor menor
    ClaveLibro clave_mayor = crear_clave_libro("Zevallos, Z.", "A-Libro"); // Autor mayor
    ClaveLibro clave_igual = crear_clave_libro("Garcia, B. & Hernandez, C.", "Lenguaje C");

    // Caso: Menor (-1)
    if (compara_claves(clave_menor, clave) == -1) 
        std::cout << "   - Menor que: OK" << std::endl;

    // Caso: Mayor (1)
    if (compara_claves(clave_mayor, clave) == 1)
        std::cout << "   - Mayor que: OK" << std::endl;

    // Caso: Igual (0)
    if (compara_claves(clave_igual, clave) == 0)
        std::cout << "   - Igualdad: OK" << std::endl;

    std::cout << std::endl << "=== TODAS LAS FUNCIONES VERIFICADAS ===" << std::endl;

    return 0; */
    std::cout << "--- INICIANDO PRUEBAS SISTEMA BIBLIOTECA ---" << std::endl;

    // 1. Probar TDA Libros (Lista Enlazada)
    Libros mi_biblioteca = crear_conj_libros();
    
    // 2. Crear un par de libros
    Libro l1 = crear_libro("Blanco, M.", "Algoritmos", "2023", "INF", "UCAB", 3);
    Libro l2 = crear_libro("Meza, O.", "Estructuras", "2024", "INF", "UCAB", 1);

    // 3. Insertar y verificar cantidad
    insertar_libro(mi_biblioteca, l1);
    insertar_libro(mi_biblioteca, l2);
    std::cout << "Libros en lista: " << mi_biblioteca.cantidad << " (Esperado: 2)" << std::endl;

    // 4. Probar búsqueda y acceso a Clave
    ClaveLibro busqueda = crear_clave_libro("Blanco, M.", "Algoritmos");
    if (es_clave(l1, busqueda)) {
        std::cout << "Busqueda por clave: OK" << std::endl;
    }

    // 5. Probar insertar ejemplar
    insertar_ejemplar(mi_biblioteca, busqueda);
    Libro aux = obtener_libro(mi_biblioteca, busqueda);
    std::cout << "Ejemplares l1: " << num_ejem(aux) << " (Esperado: 4)" << std::endl;

    // 6. Probar eliminar ejemplar (hasta borrar el nodo)
    ClaveLibro clave_l2 = crear_clave_libro("Meza, O.", "Estructuras");
    eliminar_ejemplar(mi_biblioteca, clave_l2); // Deberia borrar el nodo porque solo habia 1
    std::cout << "Libros tras eliminar l2: " << mi_biblioteca.cantidad << " (Esperado: 1)" << std::endl;

    // 7. Limpieza
    destruir_libros(mi_biblioteca);
    std::cout << "Limpieza de memoria finalizada." << std::endl;

    //return 0;

    std::cout << "=== PRUEBA INTEGRAL DEL SISTEMA ===" << std::endl;

    // 1. Inicialización
    Libros mi_biblioteca1 = crear_conj_libros();
    
    // 2. Creación de libros
    Libro l3 = crear_libro("Blanco, M.", "Algoritmos", "2023", "INF", "UCAB", 3);
    Libro l4 = crear_libro("Meza, O.", "Estructuras", "2024", "INF", "UCAB", 1);
    Libro l5 = crear_libro("Hernandez, J.", "Calculo I", "2022", "MAT", "Editorial X", 5);

    // 3. Inserción
    insertar_libro(mi_biblioteca1, l3);
    insertar_libro(mi_biblioteca1, l4);
    insertar_libro(mi_biblioteca1, l5);

    // LINEA SOLICITADA: Imprimir libros después de insertar
    std::cout << "\nESTADO ACTUAL DE LA BIBLIOTECA:" << std::endl;
    imprimir_biblioteca(mi_biblioteca1);

    // 4. Operación adicional (Prueba de ejemplares)
    std::cout << "Agregando un ejemplar de 'Algoritmos'..." << std::endl;
    insertar_ejemplar(mi_biblioteca1, clave_libro(l3));
    imprimir_biblioteca(mi_biblioteca1);

    // 5. Destrucción
    std::cout << "\nDestruyendo biblioteca..." << std::endl;
    destruir_libros(mi_biblioteca1);

    // LINEA SOLICITADA: Imprimir libros después de destruir
    std::cout << "ESTADO DESPUES DE DESTRUIR:" << std::endl;
    imprimir_biblioteca(mi_biblioteca1);

    return 0;

}
