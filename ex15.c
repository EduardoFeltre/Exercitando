#include <stdio.h>

int main(){
    int a, b, divisao;

    printf("Digite os numeros a e b respectivamente:\n");
    scanf("%d %d", &a, &b);

    divisao = b / a;

    if(b != 0)
        printf("%d", divisao);

    return 0;
}