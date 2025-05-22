#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vetor[100];
    int i, num, encontrado = 0;

    
    srand((unsigned)time(NULL));

    // Preenche o vetor com valores aleatórios de 1 a 20
    for (i = 0; i < 100; i++) {
        vetor[i] = (rand() % 20) + 1;
    }

    // Solicita ao usuário o número a ser pesquisado
    printf("Informe um numero para pesquisar no vetor (1 a 20): ");
    scanf("%d", &num);

    
    printf("Posiçoes onde o valor %d foi encontrado:\n", num);
    for (i = 0; i < 100; i++) {
        if (vetor[i] == num) {
            printf("%d ", i);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Valor nao encontrado no vetor.");
    }

    printf("\n");
    return 0;
}