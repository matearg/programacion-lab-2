#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArray(int *A, int dim);
int buscarMenor(int *A, int validos, int i);
void mostarArray(int *A, int validos, int i);

int main()
{
    int *array = malloc(sizeof(int) * 10);
    int validos = 0;
    printf("Hello menor array!\n");

    validos = cargarArray(array, 10);

    mostarArray(array, validos, 0);

    printf("\nEl menor es %d", buscarMenor(array, validos, 0));

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

void mostarArray(int *A, int validos, int i)
{
    if(i == validos)
    {
        puts("");
    }
    else
    {
        printf("%d ", A[i]);
        mostarArray(A, validos, i + 1);
    }
}

int buscarMenor(int *A, int validos, int i)
{
    int menor;

    if(i == validos)
    {
        menor = A[i - 1];
    }
    else
    {
        menor = buscarMenor(A, validos, i + 1);
        if(menor > A[i])
        {
            menor = A[i];
        }
    }
    return menor;
}
