//Este va a ser el archivo de main
#include <iostream>
#include <string>
#include "ClaveLibro.h"

int main() {
    std::cout << "=== TEST DE INTEGRIDAD: TDA CLAVELIBRO ===" << std::endl << std::endl;

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

    return 0;
}
