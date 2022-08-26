#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void potencia(int num, int i);

int main() {
    srand(time(NULL));
    int num = 0;
    int pot = 0;

    printf("Introduzca un numero: ");
    scanf("%d", &num);

    printf("\nPotencia hasta: ");
    scanf("%d", &pot);

    potencia(num, pot);

    return 0;
}

void potencia(int num, int i) {
    int rta;

    if (num == 0 || num == 1) {
        rta = 1;
        printf("%d", rta);
    } else {
        rta = num * (num * i);
        printf("%d ", rta);
        potencia(num, i - 1);
    }
}
