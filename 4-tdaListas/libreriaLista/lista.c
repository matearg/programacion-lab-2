#include "lista.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(stProducto dato)
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
    mostrarProducto(lista->dato);
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
    if (!lista) {
        lista = nuevo;
    } else {
        if (strcmp(nuevo->dato.nombre, lista->dato.nombre) < 0) {
            lista = agregarAlPrincipio(lista, nuevo);
        } else {
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while ((seg) && (strcmp(nuevo->dato.nombre, seg->dato.nombre) > 0)) {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo * buscarNodo(nodo * lista, char nombre[20])
{
    nodo * seg = lista;

    if (lista) {
        while ((seg) && (strcmp(nombre, seg->dato.nombre) != 0)) {
            seg = seg->siguiente;
        }
    }

    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante;

    if ((lista) && (strcmp(nombre, lista->dato.nombre) == 0))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
    } else {
        seg = lista;
        while ((seg) && (strcmp(nombre, seg->dato.nombre) != 0))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if (seg) {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo *eliminarPrimerNodo(nodo *lista) {
    if (lista) {
        nodo *aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}

// SUBPROGRAMAS
nodo * subProgramaAgregarAlFinal(nodo * lista, stProducto dato) {
    nodo * aux = crearNodo(dato);
    lista = agregarAlFinal(lista, aux);
    return lista;
}

nodo * subProgramaArchivoToLista(nodo * lista, char archivo[]) {
    stProducto aux;
    FILE * archi = fopen(archivo, "rb");

    if (archi) {
        while (fread(&aux, sizeof(stProducto), 1, archi) > 0) {
            lista = subProgramaAgregarAlFinal(lista, aux);
        }
        fclose(archi);
    }
    return lista;
}

void subProgramaListaToArchivo(nodo * lista, char archivo[]) {
    stProducto aux;
    FILE * archi = fopen(archivo, "ab");

    if (archi && lista) {
        while (lista) {
            aux = lista->dato;
            fwrite(&aux, sizeof(stProducto), 1, archi);
            lista = lista->siguiente;
        }
        fclose(archi);
    }
}

nodo * subProgramaCargarLista(nodo * lista)
{
    char control;

    do {
        lista = agregarAlFinal(lista, crearNodo(cargarProducto()));

        printf("Quiere agregar otro producto? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    } while (control == 's');

    return lista;
}

nodo * subProgramaVaciarLista(nodo * lista)
{
    nodo * seg = lista;
    nodo * proximo;

    while (seg) {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }

    return seg;
}
nodo * subProgramaCargarOrdenada(nodo * lista)
{
    char control;

    do {
        lista = agregarEnOrden(lista, crearNodo(cargarProducto()));

        printf("Quiere agregar otro producto? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    } while (control == 's');

    return lista;
}

