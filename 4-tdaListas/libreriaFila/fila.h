#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"

typedef struct {
    nodoDoble *inicio;
    nodoDoble *fin;
} Fila;

// Fila * inicFila(Fila * fila);
void inicFila(Fila * fila);
void agregarFila(Fila * fila, int dato);
void muestraFila(Fila * fila);
int extraerFila(Fila * fila);
int verPrimero(nodoDoble * lista);
nodoDoble * borrarPrimero(nodoDoble * lista);

#endif // FILA_H_INCLUDED
