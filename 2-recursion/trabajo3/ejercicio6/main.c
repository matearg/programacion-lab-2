#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArray(int *A, int dim);
int sumArrayRecursivo(int *A, int validos, int i);
void mostrarArrayRecursivo(int *A, int validos, int i);

int main()
{
    int *array = malloc(sizeof(int) * 10);
    int validos = 0;

    printf("Hello sum array!\n");
    validos = cargarArray(array, 5);

    puts("Mostrar array recursivo: ");
    mostrarArrayRecursivo(array, validos, 0);

    printf("Sumatoria array recursivo = %d\n", sumArrayRecursivo(array, validos, 0));

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

void mostrarArrayRecursivo(int *A, int validos, int i)
{
    if (i == validos)
    {
        puts("");
    }
    else
    {
        printf("%d ", A[i]);
        mostrarArrayRecursivo(A, validos, i + 1);
    }
}

int sumArrayRecursivo(int *A, int validos, int i)
{
    if(i == validos)
    {
        return 0;
    }
    else
    {
        return A[i] + sumArrayRecursivo(A, validos, i + 1);
    }
}
