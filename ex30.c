#include <stdio.h>

int par(int n){
    return 2*n;
}




int main(){

    int n;

    printf("DIgite n:\n");
    scanf("%d", &n);
    printf("O n-esimo termo eh: %d \n", par(n));
    printf("sequencia exercicio 2: ");

    return 0;
}