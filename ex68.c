#include <stdio.h>
#include <stdlib.h>


int soma_recursiva_vetor(int *ptr_elemento, int tamanho_restante) {
    
    if (tamanho_restante <= 0) {
        return 0;
    }
    
    return *ptr_elemento + soma_recursiva_vetor(ptr_elemento + 1, tamanho_restante - 1);
}

int main() {
    int n;
    int *vetor_dinamico;
    int *ptr; 

    
    printf("Digite o número de elementos (n) do vetor de inteiros: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1;
    }

   
    vetor_dinamico = (int *)malloc(n * sizeof(int));
    if (vetor_dinamico == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    
    printf("Digite os %d números inteiros do vetor:\n", n);
    for (ptr = vetor_dinamico; ptr < vetor_dinamico + n; ptr++) {
        printf("Elemento %ld: ", (ptr - vetor_dinamico) + 1);
        scanf("%d", ptr);
    }

   
    int soma = soma_recursiva_vetor(vetor_dinamico, n);

    
    printf("\nA soma dos elementos do vetor é: %d\n", soma);

    
    free(vetor_dinamico);

    return 0;
}