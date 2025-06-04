#include <stdio.h>
#include <stdlib.h>


double soma_maiores_que_media(int **matriz, int n) {
    double soma_total = 0;
    double media;
    double soma_maiores = 0;
    int i, j;

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            soma_total += matriz[i][j];
        }
    }

    
    if (n * n > 0) {
        media = soma_total / (n * n);
    } else {
        media = 0; 
    }

    printf("\nMédia de todos os elementos: %.2f\n", media);

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] > media) {
                soma_maiores += matriz[i][j];
            }
        }
    }

    return soma_maiores;
}

int main() {
    int n;
    int **matriz_dinamica;
    int i, j;

    
    printf("Digite o tamanho n da matriz quadrada (n x n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O tamanho da matriz deve ser um número positivo.\n");
        return 1;
    }

    
    matriz_dinamica = (int **)malloc(n * sizeof(int *));
    if (matriz_dinamica == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return 1;
    }

    
    for (i = 0; i < n; i++) {
        matriz_dinamica[i] = (int *)malloc(n * sizeof(int));
        if (matriz_dinamica[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da linha %d.\n", i);
            
            for (j = 0; j < i; j++) {
                free(matriz_dinamica[j]);
            }
            free(matriz_dinamica);
            return 1;
        }
    }

    
    printf("\nDigite os elementos da matriz %d x %d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz_dinamica[i][j]);
        }
    }

    
    printf("\nMatriz inserida:\n");
     for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matriz_dinamica[i][j]);
        }
        printf("\n");
    }

    
    double soma = soma_maiores_que_media(matriz_dinamica, n);
    printf("\nA soma dos elementos maiores que a média é: %.2f\n", soma);

    
    for (i = 0; i < n; i++) {
        free(matriz_dinamica[i]);
    }
    
    free(matriz_dinamica);

    return 0;
}