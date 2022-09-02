#include "lista.h"
#include <stdlib.h>

nodo * inicLista() {
    return NULL;
}

nodo * crearNodo(persona dato) {
    nodo * aux = (nodo *)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

// Uso persona para ejemplo
nodo * agregarNodo(nodo * lista, nodo * nuevo) {
    nodo * ultimo;

    if (!lista) {
        lista = nuevo;
    } else {
        ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

void mostrarLista(nodo *lista) {
    nodo * seg = lista;
    
    while (seg) {
        mostrarNodo(seg);
        seg = seg->siguiente;
    }
}

void mostrarNodo(nodo *lista) {
    mostrarPersona(lista->dato);
}

nodo * buscarUltimo(nodo * lista) {
    nodo * seg = lista;

    if (seg) {
        while (seg->siguiente) {
            seg = seg->siguiente;
        }
    }
    return seg;
}
