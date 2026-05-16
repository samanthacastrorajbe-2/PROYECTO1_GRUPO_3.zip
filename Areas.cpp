#include "Areas.h"
#include <iostream>

Areas crear_areas() {
    Areas nuevas_areas;
    nuevas_areas.cabeza = nullptr; // lista vacia
    return nuevas_areas;
}

bool es_vacio_areas(const Areas& areas) {
    return areas.cabeza == nullptr;
}

bool esta_area(const Areas& areas, std::string codigo) {
    NodoArea* act = areas.cabeza;
    
    while (act != nullptr) {
        if (codigo_area(act->area) == codigo) {
            return true;
        }
        act = act->sig; // apunta al proximo
    }
    return false;
}

Area obtener_area(const Areas& areas, std::string codigo) {
    NodoArea* act = areas.cabeza;
    
    while (act != nullptr) {
        if (codigo_area(act->area) == codigo) {
            return act->area;
        }
        act = act->sig; // apunta al proximo
    }
    return crear_area("ERR"); 
}

void insertar_area(Areas& areas, const Area& nueva_area) {
    if (esta_area(areas, codigo_area(nueva_area))) {
        return; // ya existe
    }

    NodoArea* nuevo = new NodoArea; // crea nodo
    nuevo->area = nueva_area;
    nuevo->sig = areas.cabeza; // conecta al resto
    areas.cabeza = nuevo;      // nueva cabeza
}

void eliminar_area(Areas& areas, std::string codigo) {
    NodoArea* act = areas.cabeza;
    NodoArea* ant = nullptr;

    while (act != nullptr) {
        if (codigo_area(act->area) == codigo) {
            if (ant == nullptr) {
                areas.cabeza = act->sig; // elimina el primero
            } else {
                ant->sig = act->sig; // salta el nodo actual
            }

            destruir_area(act->area); // limpia la lista interna
            delete act;               // libera la memoria
            return;
        }
        ant = act;
        act = act->sig; // apunta al proximo
    }
}

void destruir_areas(Areas& areas) {
    NodoArea* act = areas.cabeza;
    
    while (act != nullptr) {
        NodoArea* a_eliminar = act;
        act = act->sig; // apunta al proximo
        
        destruir_area(a_eliminar->area); // limpia la lista interna
        delete a_eliminar;               // libera la memoria
    }
    
    areas.cabeza = nullptr; // vacia la cabeza
}