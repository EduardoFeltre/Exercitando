#include <stdio.h>


int ehPrimo(int num) {
    if (num < 2) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int A, B, Primo = 0;

    
    printf("Digite dois numeros inteiros A e B (A < B): ");
    scanf("%d %d", &A, &B);

    if (A >= B) {
        printf("Erro: A deve ser menor que B.\n");
        return 1;
    }

    printf("Numeros primos no intervalo [%d, %d]: ", A, B);

    
    for (int i = A; i <= B; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
            Primo = 1;
        }
    }

    if (!Primo) {
        printf("Nenhum numero primo encontrado no intervalo.");
    }

    printf("\n");
    return 0;
}
