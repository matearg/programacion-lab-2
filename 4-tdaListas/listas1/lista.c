#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo *)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

// Uso persona para ejemplo
nodo * agregarNodo(nodo * lista, nodo * nuevo)
{
    nodo * ultimo;

    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

void mostrarLista(nodo *lista)
{
    nodo * seg = lista;

    if (seg != NULL)
    {
        while (seg != NULL)
        {
            mostrarNodo(seg);
            seg = seg->siguiente;
        }
    }
    else
    {
        printf("Lista vacia\n\n");
    }
}

void mostrarNodo(nodo *lista)
{
    mostrarPersona(lista->dato);
}

// EJEMPLO
// void mostrarNodo(nodo *lista) {
//     printf("dato");
// }

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;

    if (seg != NULL)
    {
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}
