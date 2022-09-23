#include <stdio.h>
#include <string.h>

typedef struct {
   int idProducto;
   char nombre[30];
   char marca[20];
   float precio;
   int eliminado;  // indica 1 o 0 si el producto fue eliminado
} stProducto;

stProducto cargarProducto(); // hecho
void mostrarProducto(stProducto dato); // hecho
