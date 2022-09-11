#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista(); // hecho
nodo * crearNodo(int dato);
nodo * agregarNodo(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista); // hecho
void mostrarLista(nodo * lista); // hecho
void mostrarNodo(nodo * lista); // hecho
