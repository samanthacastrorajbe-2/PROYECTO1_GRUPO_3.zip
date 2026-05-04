#include "Libro.h"
#include "ClaveLibro.h"

Libro crear_libro (std::string autor, std::string titulo, std::string año, std::string area, std::string editorial, unsigned short num_ejem){
    Libro nuevo_libro;
    nuevo_libro.autor = autor;
    nuevo_libro.titulo = titulo;
    nuevo_libro.año = año;
    nuevo_libro.area = area;
    nuevo_libro.editorial = editorial;
    nuevo_libro.num_ejem = num_ejem;
    return nuevo_libro;
} 
// no se donde debo validar que el autor siga las reglas sintacticas que pide el profe ni se donde debo validar lo de año

std::string autor_libro (const Libro& libro){
    return libro.autor;
}

std::string titulo_libro (const Libro& libro){ 
    return libro.titulo;
}

std::string año_libro (const Libro& libro){ 
    return libro.año;
}

std::string area_libro (const Libro& libro){
    return libro.area;
}

unsigned short num_ejem (const Libro& libro){ 
    return libro.num_ejem;
}

ClaveLibro clave_libro (const Libro& libro){
    return crear_clave_libro(libro.autor, libro.titulo);
} //probar
// no se donde debo validar que el autor siga las reglas sintacticas que pide el profe 

// desarrollar

void num_ejem (const Libro& libro, unsigned short ejem);a 
// desarrollar

bool es_clave (const Libro& libro, ClaveLibro clave); 
// desarrollar

void destruir_libro (Libro& libro); 
// desarrollar
