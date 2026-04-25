#include "ClaveLib.h"
#include <string>
#include <iostream>

ClaveLib crear_clave_lib();

std::string autor_clave (const ClaveLib& clave);

std::string titulo_clave (const ClaveLib& clave);

unsigned short compara_claves(const ClaveLib& clave1, const ClaveLib& clave2);
