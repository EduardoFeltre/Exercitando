#include <stdio.h>

int main() {
    int n;

    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, digite um numero inteiro positivo.\n");
        return 1; 
    }

    
    for (int i = n; i > 0; i--) { 
        for (int j = 1; j <= i; j++) { 
            printf("%d", j);
        }
        printf("\n"); 
    }

    return 0;
}
