#include "Libro.h"


std::string autor_libro (const Libro& libro);

std::string titulo_libro (const Libro& libro); 

std::string año_libro (const Libro& libro); 

std::string area_libro (const Libro& libro);

unsigned short num_ejem (const Libro& libro); 

ClaveLibro clave_libro (const Libro& libro); 

void num_ejem (const Libro& libro, unsigned short ejem); 

bool es_clave (const Libro& libro, ClaveLibro clave); 

void destruir_libro (Libro& libro);
