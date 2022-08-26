#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArrayRecu(int *A, int dim, int i);
int cargarArray(int *A, int dim);
void mostrarArray(int *A, int validos);

int main() {
    int dim = 0, validos = 0, validos2 = 0;

    printf("Introduzca la dimension de su arreglo: ");
    scanf("%d", &dim);

    int *array = malloc(sizeof(int) * dim);
    int *array2 = malloc(sizeof(int) * dim);

    validos = cargarArrayRecu(array, dim, 0);
    validos2 = cargarArray(array2, dim);

    puts("\nArray cargardo recu:");
    mostrarArray(array, validos);

    puts("\nArray cargardo:");
    mostrarArray(array2, validos2);

    return 0;
}

int cargarArrayRecu(int *A, int dim, int i) {
    if(i == dim) {
        puts("");
    } else {
        A[i] = rand()%10 + 1;
        i = cargarArrayRecu(A, dim, i + 1);
    }
    return i;
}

int cargarArray(int *A, int dim) {
    srand(time(NULL));
    int i = 0;
    for(i = 0; i < dim; i++) {
        A[i] = rand()%10 + 1;
    }
    return i;
}

void mostrarArray(int *A, int validos) {
    for(int i = 0; i < validos; i++) {
        printf("%d ", A[i]);
    }
}
