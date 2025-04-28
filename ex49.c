#include <stdio.h>

void calculaOperacoes(int a, int b, int *soma, int *produto) {
    *soma = a + b;
    *produto = a * b;
}

int main() {
    int num1, num2, soma, produto;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    calculaOperacoes(num1, num2, &soma, &produto);

    printf("A soma dos numeros e: %d\n", soma);
    printf("O produto dos numeros e: %d\n", produto);

    return 0;
}