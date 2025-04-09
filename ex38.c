#include <stdio.h>

int main() {
    int x, y;
    int encontrou_impar = 0;


    printf("Digite dois numeros inteiros (x < y): ");
    scanf("%d %d", &x, &y);

    if (x >= y) {
        printf("Erro: o primeiro numero deve ser menor que o segundo.\n");
        return 1;
    }

    printf("Numeros impares entre %d e %d:\n", x, y);

    for (int i = x; i <= y; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
            encontrou_impar = 1;
        }
    }

    if (!encontrou_impar) {
        printf("Nao ha numeros impares nesse intervalo.");
    }

    printf("\n");
    return 0;
}
