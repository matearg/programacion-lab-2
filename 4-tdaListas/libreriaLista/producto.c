#include "producto.h"
#include <stdio.h>

stProducto cargarProducto() {
    stProducto aux;

    printf("Ingrese la marca: ");
    fflush(stdin);
    scanf("%s", aux.marca);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", aux.nombre);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%f", &aux.precio);

    return aux;
}

void mostrarProducto(stProducto dato) {
}
