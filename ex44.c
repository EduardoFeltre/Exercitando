#include <stdio.h>


int fatorial(int n) {
    int resultado = 1;

    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main() {
    int n;

    
    printf("Digite um numero inteiro nao-negativo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Numero invalido! O fatorial nao existe para negativos.\n");
        return 1;
    }

    
    int resultado = fatorial(n);
    printf("O fatorial de %d eh: %d\n", n, resultado);

    return 0;
}
