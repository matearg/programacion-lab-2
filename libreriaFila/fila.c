#include "fila.h"

Fila * inicFila(Fila * fila) {
    fila->inicio = NULL;
    fila->fin = NULL;

    return fila;
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
    return 0;
}

int filaVacia(Fila * fila) {
    return(fila->inicio)?0:1;
}
