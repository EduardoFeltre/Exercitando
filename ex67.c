#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int soma_acima_diagonal_principal(int **matriz, int n) {
    int soma = 0;
    int i, j;

  
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            
            if (j > i) {
                soma += matriz[i][j];
            }
        }
    }
    return soma;
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

    
    srand(time(NULL));

    
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

    
    printf("\nPreenchendo a matriz %d x %d com valores aleatórios (1-100):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz_dinamica[i][j] = (rand() % 100) + 1;
        }
    }

    
    printf("\nMatriz Gerada:\n");
     for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matriz_dinamica[i][j]);
        }
        printf("\n");
    }

    
    int soma_acima = soma_acima_diagonal_principal(matriz_dinamica, n);

    
    printf("\nA soma dos elementos estritamente acima da diagonal principal é: %d\n", soma_acima);

    
    for (i = 0; i < n; i++) {
        free(matriz_dinamica[i]);
    }
    
    free(matriz_dinamica);

    return 0;
}