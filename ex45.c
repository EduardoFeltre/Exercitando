#include <stdio.h>

int main() {
    int num, contador = 0;

    printf("Digite uma sequência de números inteiros (-1 para encerrar):\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 4 == 0 && num % 6 == 0) {
            contador++;
        }
    }

    printf("Quantidade de numeros divisiveis por 4 e multiplos de 6: %d\n", contador);

    return 0;
}
