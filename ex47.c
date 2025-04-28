#include <stdio.h>


void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    
    printf("Antes da troca: num1 = %d, num2 = %d\n", num1, num2);

    
    troca(&num1, &num2);

    
    printf("Depois da troca: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}