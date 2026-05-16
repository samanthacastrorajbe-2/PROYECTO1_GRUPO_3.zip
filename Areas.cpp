#include "Areas.h"
#include <iostream>

Area& operator*(const Iterador_areas& it) {
    return it.actual->area;
}

Iterador_areas& operator++(Iterador_areas& it) {
    if (it.actual != nullptr) {
        it.actual = it.actual->sig; 
    }
    return it;
}

bool operator!=(const Iterador_areas& it, const Iterador_areas& otro) {
    return it.actual != otro.actual;
}

Iterador_areas begin(const Areas& areas) {
    Iterador_areas it;
    it.actual = areas.cabeza; 
    return it;
}

Iterador_areas end(const Areas& areas) {
    Iterador_areas it;
    it.actual = nullptr; 
    return it;
}


// --- OPERACIONES DE AREAS ---

Areas crear_areas() {
    Areas nuevas_areas;
    nuevas_areas.cabeza = nullptr; 
    return nuevas_areas;
}

bool es_vacio_areas(const Areas& areas) {
    return areas.cabeza == nullptr;
}

bool esta_area(const Areas& areas, std::string codigo) {
    // Uso del iterador para recorrer ocultando los punteros
    for (Iterador_areas it = begin(areas); it != end(areas); ++it) {
        if (codigo_area(*it) == codigo) {
            return true;
        }
    }
    return false;
}

Area obtener_area(const Areas& areas, std::string codigo) {
    // Uso del iterador para recorrer ocultando los punteros
    for (Iterador_areas it = begin(areas); it != end(areas); ++it) {
        if (codigo_area(*it) == codigo) {
            return *it;
        }
    }
    return crear_area("ERR"); 
}

void insertar_area(Areas& areas, const Area& nueva_area) {
    if (esta_area(areas, codigo_area(nueva_area))) {
        return; 
    }

    NodoArea* nuevo = new NodoArea; 
    nuevo->area = nueva_area;
    nuevo->sig = areas.cabeza; 
    areas.cabeza = nuevo;      
}

void eliminar_area(Areas& areas, std::string codigo) {
    NodoArea* act = areas.cabeza;
    NodoArea* ant = nullptr;

    while (act != nullptr) {
        if (codigo_area(act->area) == codigo) {
            if (ant == nullptr) {
                areas.cabeza = act->sig; 
            } else {
                ant->sig = act->sig; 
            }

            destruir_area(act->area); // limpia la lista interna
            delete act;               // libera la memoria del nodo
            return;
        }
        ant = act;
        act = act->sig; 
    }
}

void destruir_areas(Areas& areas) {
    NodoArea* act = areas.cabeza;
    
    while (act != nullptr) {
        NodoArea* a_eliminar = act;
        act = act->sig; 
        
        destruir_area(a_eliminar->area); // limpia la lista interna de libros
        delete a_eliminar;               // libera la memoria del nodo
    }
    
    areas.cabeza = nullptr; 
}