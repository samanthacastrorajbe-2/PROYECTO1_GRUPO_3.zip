#include "ClaveLibro.h"
#include <string>
#include <iostream>

ClaveLibro crear_clave_lib();

std::string autor_clave (const ClaveLibro& clave);

std::string titulo_clave (const ClaveLibro& clave);

unsigned short compara_claves(const ClaveLibro& clave1, const ClaveLibro& clave2);
