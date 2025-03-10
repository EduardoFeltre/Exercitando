#include <stdio.h>

int main(){

    int n, numero, soma = 0;

    printf("Digite n:\n");
    scanf("%d", &n);
    
    while (n > 0)
    {
        printf("Digite um numero: \n");
        scanf("%d", &numero);
        soma = soma + numero;

        printf("O somatorio eh: %d\n", soma);
    }
    

    return 0;
}