#include <stdio.h>

int main() {
    int n, soma = 0, contador = 0, impares = 0;
    float media;

    printf("Digite uma sequencia de numeros inteiros (0 para encerrar): \n");

    while (1) {
        scanf("%d", &n);

        if (n == 0)
            break;

        soma += n;
        contador++;

        if (n % 2 != 0)
            impares++;
    }

    if (contador > 0) {
        media = (float)soma / contador;
        printf("Media dos numeros informados eh: %.2f\n", media);
        printf("Quantidade de numeros impares: %d\n", impares);
    } else {
        printf("Nenhum numero foi informado.\n");
    }

    return 0;
}
