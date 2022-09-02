#include "persona.h"
#include <stdio.h>

persona cargarPersona() {
    persona aux;

    printf("Ingrese el DNI: ");
    fflush(stdin);
    scanf("%d", &aux.dni);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", aux.nombre);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%s", aux.apellido);

    return aux;
}

void mostrarPersona(persona dato) {
    printf("DNI: %d\n", dato.dni);
    printf("Nombre: %s\n", dato.nombre);
    printf("Apellido: %s\n\n", dato.apellido);
}
