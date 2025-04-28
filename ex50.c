#include <stdio.h>

void maiorMenor(int a, int b, int *maior, int *menor) {
    if (a > b) {
        *maior = a;
        *menor = b;
    } else {
        *maior = b;
        *menor = a;
    }
}

int main() {
    int num1, num2, maior, menor;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    maiorMenor(num1, num2, &maior, &menor);

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}