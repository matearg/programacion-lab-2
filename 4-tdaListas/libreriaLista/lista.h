#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

typedef struct _nodo{
    persona dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista(); // hecho
nodo * crearNodo(persona dato);
nodo * agregarNodo(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista); // hecho
void mostrarLista(nodo * lista); // hecho
void mostrarNodo(nodo * lista); // hecho
