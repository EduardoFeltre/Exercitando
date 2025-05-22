#include <stdio.h>
#include <stdlib.h>

// Função recursiva para encontrar o maior elemento da lista
double maior_elemento(double *lista, int n) {
    if (n == 1) {
        return lista[0];
    }
    double max_restante = maior_elemento(lista, n - 1);
    return (lista[n - 1] > max_restante) ? lista[n - 1] : max_restante;
}

int main() {
    int n, i;
    double *lista;

    printf("Informe o tamanho da lista de numeros reais: ");
    scanf("%d", &n);

    lista = (double *)malloc(n * sizeof(double));
    if (lista == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o numero real %d: ", i + 1);
        scanf("%lf", &lista[i]);
    }

    printf("Lista digitada:\n");
    for (i = 0; i < n; i++) {
        printf("%.2lf ", lista[i]);
    }
    printf("\n");

    // Chama a função recursiva e exibe o maior elemento
    double maior = maior_elemento(lista, n);
    printf("Maior elemento da lista: %.2lf\n", maior);

    free(lista);
    return 0;
}