#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArray(int *A, int dim);
void mostrarArrayRecu(int *A, int validos, int i);
void mostrarArrayInvertRecu(int *A, int validos);

int main()
{
    int *array = malloc(sizeof(int) * 10);
    int validos = 0;

    printf("Hello mostrar array invertido!\n");

    validos = cargarArray(array, 10);

    mostrarArrayRecu(array, validos, 0);
    mostrarArrayInvertRecu(array, validos);

    return 0;
}

int cargarArray(int *A, int dim)
{
    int i = 0;
    srand(time(NULL));
    for(i = 0; i < dim; i++)
    {
        A[i] = rand()%10 + 1;
    }
    return i;
}

void mostrarArrayRecu(int *A, int validos, int i)
{
    if(i == validos)
    {
        puts("\n");
    }
    else
    {
        printf("%d ", A[i]);
        mostrarArrayRecu(A, validos, i + 1);
    }
}

void mostrarArrayInvertRecu(int *A, int validos)
{
    if(validos == 0)
    {
        puts("\n");
    }
    else
    {
        printf("%d ", A[validos - 1]);
        mostrarArrayInvertRecu(A, validos - 1);
    }
}
