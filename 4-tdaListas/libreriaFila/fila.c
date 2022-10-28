#include "fila.h"
#include <stdlib.h>

void inicFila(Fila * fila) {
    fila->inicio = inicLstaD();
    fila->fin = inicLstaD();
}

void agregarFila(Fila * fila, int dato) {
    nodoDoble * nuevo = crearNodoD(dato);
    fila->fin = agregarAlFinalD(fila->fin, nuevo);
    if (!fila->inicio) {
        fila->inicio = fila->fin;
    }
    fila->fin = nuevo;
}

void muestraFila(Fila * fila) {
    mostrarListaD(fila->inicio);
}

int extraerFila(Fila * fila) {
    int resp;

    if (fila->inicio) {
        resp = verPrimero(fila->inicio);
        fila->inicio = borrarPrimero(fila->inicio);
        if (!fila->inicio) {
            fila->fin = inicLstaD();
        }
    }

    return resp;
}

int filaVacia(Fila * fila) {
    return(fila->inicio)?0:1;
}

int verPrimero(nodoDoble * lista) {
    int rta = 0;

    if (lista)
        rta = lista->dato;

    return 0;
}

nodoDoble * borrarPrimero(nodoDoble * lista) {
    nodoDoble * aBorrar = lista;
    if (lista) {
        lista = lista->siguiente;
        if (lista)
            lista->anterior = NULL;
        free(aBorrar);
    }
    return lista;
}
