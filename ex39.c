#include <stdio.h>


int soma_divisores(int n) {
    int soma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int num;

    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Numero invalido. Deve ser positivo.\n");
        return 1;
    }

    
    int resultado = soma_divisores(num);
    printf("A soma dos divisores proprios de %d eh: %d\n", num, resultado);

    return 0;
}
