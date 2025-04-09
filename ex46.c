#include <stdio.h>
#include <stdbool.h>


bool pertence_fibonacci(int n) {
    int a = 0, b = 1, temp;

    if (n == 0 || n == 1)
        return true;

    while (b <= n) {
        if (b == n)
            return true;

        temp = b;
        b = a + b;
        a = temp;
    }

    return false;
}

int main() {
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Numeros negativos nao pertencem a sequencia de Fibonacci.\n");
    } else {
        
        if (pertence_fibonacci(num)) {
            printf("%d pertence à sequência de Fibonacci.\n", num);
        } else {
            printf("%d nao pertence à sequência de Fibonacci.\n", num);
        }
    }

    return 0;
}
