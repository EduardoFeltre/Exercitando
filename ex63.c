#include <stdio.h>
#include <stdlib.h>


double produto_recursivo(double *vetor, int tamanho) {
    
    if (tamanho <= 0) {
        return 1.0; 
    }
    if (tamanho == 1) {
        return *vetor; 
    }

    
    return *vetor * produto_recursivo(vetor + 1, tamanho - 1);
}

int main() {
    int n;
    double *vetor_dinamico;
    double *ptr; 

    
    printf("Digite o número de elementos (n) do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1;
    }

    
    vetor_dinamico = (double *)malloc(n * sizeof(double));
    if (vetor_dinamico == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    
    printf("Digite os %d números reais do vetor:\n", n);
    for (ptr = vetor_dinamico; ptr < vetor_dinamico + n; ptr++) {
        printf("Elemento %ld: ", (ptr - vetor_dinamico) + 1);
        scanf("%lf", ptr);
    }

    
    double produto = produto_recursivo(vetor_dinamico, n);

    
    printf("O produto dos elementos do vetor é: %.2lf\n", produto);

    
    free(vetor_dinamico);

    return 0;
}