#include <stdio.h>

void fatorial(int n, int *resultado) {
    *resultado = 1;
    for (int i = 1; i <= n; i++) {
        *resultado *= i;
    }
}

int main() {
    int numero, resultado;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Número inválido! Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    fatorial(numero, &resultado);

    printf("O fatorial de %d é %d.\n", numero, resultado);

    return 0;
}