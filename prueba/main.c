#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArray(int *arr, int dim);
void ordenarArray(int *arr, int validos);
void mostrarArrayR(int *arr, int validos, int i);
void mostrarArrayParesR(int *arr, int validos, int i);

int main() {
  int dim = 30;
  int *arreglo = (int *)malloc(sizeof(int) * dim);

  int validos = 0;

  validos = cargarArray(arreglo, dim);

  printf("Array Cargado:\n");
  mostrarArrayR(arreglo, validos, 0);
  printf("\n\n");

  ordenarArray(arreglo, validos);

  printf("Array Ordenado:\n");
  mostrarArrayR(arreglo, validos, 0);
  printf("\n\n");

  printf("Array Pares:\n");
  mostrarArrayParesR(arreglo, validos, 0);
  printf("\n\n");

  return 0;
}

int cargarArray(int *arr, int dim) {
  srand(time(NULL));
  int i = 0;

  for (i = 0; i < dim; i++) {
    arr[i] = rand() % 101;
  }

  return i;
}

void mostrarArrayR(int *arr, int validos, int i) {
  if (i < validos) {
    printf("%d ", arr[i]);
    mostrarArrayR(arr, validos, i + 1);
  }
}

void mostrarArrayParesR(int *arr, int validos, int i) {
  if (i < validos) {
    if (arr[i] % 2 == 0) {
      printf("%d ", arr[i]);
    }
    mostrarArrayParesR(arr, validos, i + 1);
  }
}

void ordenarArray(int *arr, int validos) {
  int i, j, aux, menor;

  for (i = 0; i < validos; i++) {
    menor = i;

    for (j = i + 1; j < validos; j++) {
      if (arr[j] < arr[menor]) {
        menor = j;
      }
    }
    aux = arr[i];
    arr[i] = arr[menor];
    arr[menor] = aux;
  }
}
