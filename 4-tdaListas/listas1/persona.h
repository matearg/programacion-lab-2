#include <stdio.h>
#include <string.h>

typedef struct {
    int dni;
    char nombre[20];
    char apellido[20];
    int edad;
} persona;

persona cargarPersona(); // hecho
void mostrarPersona(persona dato); // hecho
