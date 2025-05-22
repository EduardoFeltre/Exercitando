
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, randomNumber;

    printf("Quantos numeros aleatorios deseja gerar? ");
    scanf("%d", &n);

    srand(time(NULL)); 

    printf("Numeros aleatorios entre 1 e 15:\n");
    for (i = 0; i < n; i++) {
        randomNumber = (rand() % 15) + 1; 
        printf("%d ", randomNumber);
    }

    printf("\n");
    return 0;
}