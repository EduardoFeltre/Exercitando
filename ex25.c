#include <stdio.h>

int main() {
    int n, fatorial = 1, i;
    
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    
    
    if (n < 0) {
        printf("Fatorial nao eh definido para numeros negativos.\n");
        return 1;
    }
    
    i = n;
    

    do {
        fatorial *= i;
        i--;
    } while (i > 0);
    

    printf("%d! = %d\n", n, fatorial);
    
    return 0;
}
