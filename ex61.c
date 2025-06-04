#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numero_existe(int *vetor, int tamanho, int numero) {
    int *ptr;
    for (ptr = vetor; ptr < vetor + tamanho; ptr++) {
        if (*ptr == numero) {
            return 1;
        }
    }
    return 0; 
}

int main() {
    int vetor[6];
    int *ptr_vetor = vetor; 
    int numeros_gerados = 0;
    int numero_aleatorio;

    srand(time(NULL));

    printf("Gerando vetor com 6 números aleatórios entre 1 e 60 sem repetição:\n");

  
    while (numeros_gerados < 6) {
        numero_aleatorio = (rand() % 60) + 1; 

        if (!numero_existe(vetor, numeros_gerados, numero_aleatorio)) {
            *(ptr_vetor + numeros_gerados) = numero_aleatorio; 
            numeros_gerados++;
        }
    }

  
    printf("Vetor gerado: [");
    for (ptr_vetor = vetor; ptr_vetor < vetor + 6; ptr_vetor++) {
        printf("%d", *ptr_vetor);
        if (ptr_vetor < vetor + 5) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;