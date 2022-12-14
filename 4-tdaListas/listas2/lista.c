#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo)
{
    nuevo->siguiente = lista;

    if (lista)
    {
        lista = nuevo;
    }

    return lista;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevo)
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

nodo * agregarEnOrden(nodo * lista, nodo * nuevo)
{
    if (!lista)
    {
        lista = nuevo;
    }
    else
    {
        // if (strcmp(nuevo->dato.nombre, lista->dato.nombre) < 0)
        if (nuevo->dato.dni < lista->dato.dni)
        {
            lista = agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            // while ((seg) && (strcmp(nuevo->dato.nombre, seg->dato.nombre) > 0))
            while ((seg) && (nuevo->dato.dni > seg->dato.dni))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo * subProgramaAgregarAlFinal(nodo * lista, persona dato)
{
    nodo * aux = crearNodo(dato);
    lista = agregarAlFinal(lista, aux);
    return lista;
}

nodo * subProgramaArchivoToLista(nodo * lista, char archivo[])
{
    persona aux;
    FILE * archi = fopen(archivo, "rb");

    if (archi)
    {
        while (fread(&aux, sizeof(persona), 1, archi) > 0)
        {
            lista = subProgramaAgregarAlFinal(lista, aux);
        }
        fclose(archi);
    }
    return lista;
}

nodo * subProgramaCargarLista(nodo * lista)
{
    char control;

    do
    {
        lista = agregarAlFinal(lista, crearNodo(cargarPersona()));

        printf("Quiere agregar otra persona? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');

    return lista;
}

nodo * subProgramaVaciarLista(nodo * lista)
{
    nodo * seg = lista;
    nodo * proximo;

    while (seg)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }

    return seg;
}

nodo * subProgramaCargarOrdenada(nodo * lista)
{
    char control;

    do
    {
        lista = agregarEnOrden(lista, crearNodo(cargarPersona()));

        printf("Quiere agregar otra persona? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');

    return lista;
}

