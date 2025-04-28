#include <stdio.h>

// Função que troca os valores de dois inteiros
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    // Lê dois números do usuário
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // Mostra os valores antes da troca
    printf("Antes da troca: num1 = %d, num2 = %d\n", num1, num2);

    // Chama a função para trocar os valores
    troca(&num1, &num2);

    // Mostra os valores após a troca
    printf("Depois da troca: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}