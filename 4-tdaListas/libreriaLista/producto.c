#include "producto.h"

stProducto cargarProducto()
{
    stProducto aux;

    printf("Ingrese el id: ");
    fflush(stdin);
    scanf("%d", &aux.idProducto);

    printf("Ingrese la marca: ");
    fflush(stdin);
    scanf("%s", aux.marca);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", aux.nombre);

    printf("Ingrese el precio: ");
    fflush(stdin);
    scanf("%f", &aux.precio);

    aux.eliminado = 0;

    return aux;
}

void mostrarProducto(stProducto dato)
{
    printf("%d %s %s %f\n", dato.idProducto, dato.marca, dato.nombre, dato.precio);
}
