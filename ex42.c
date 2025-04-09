#include <stdio.h>


double soma_harmonica(int n) {
    double soma = 0.0;

    for (int i = 1; i <= n; i++) {
        soma += 1.0 / i;  
    }

    return soma;
}

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numero invalido. Digite um valor positivo.\n");
        return 1;
    }

    double resultado = soma_harmonica(n);
    printf("A soma eh: %.6f\n", resultado);

    return 0;
}
