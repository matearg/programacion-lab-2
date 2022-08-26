#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArray(int *A, int dim);
void mostrarArrayIterando(int *A, int validos);
void mostrarArrayRecursivo(int *A, int validos, int i);

int main()
{
    int * array = malloc(sizeof(int) * 10);
    int validos = 0;

    validos = cargarArray(array, 10);
    puts("\nmostrarArrayIterando:");
    mostrarArrayIterando(array, validos);
    printf("\n");
    puts("\nmostrarArrayRecursivo:");
    mostrarArrayRecursivo(array, validos, 0);
    printf("\n");

    return 0;
}

int cargarArray(int *A, int dim)
{
    int i = 0;

    srand(time(NULL));

    for(i = 0; i < dim; i++)
    {
        A[i] = rand()%11;
    }

    return i;
}

void mostrarArrayIterando(int *A, int validos)
{
    int i = 0;
    for(i = 0; i < validos; i++)
    {
        printf("%d ", A[i]);
    }
}

void mostrarArrayRecursivo(int *A, int validos, int i)
{
    if(i == validos)
    {
        puts("");
    }
    else
    {
        printf("%d ", A[i]);
        mostrarArrayRecursivo(A, validos, i + 1);
    }
}
