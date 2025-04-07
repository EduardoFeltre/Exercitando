#include <stdio.h>

float somatorio(int n){
    float soma = 0;
    for(int den = 1; den <= n; den++){
        soma = soma + 1.0/den;
    }
    return soma;
}

int main(){

    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    printf("soma: %.2f", somatorio(n));

    return 0;
}