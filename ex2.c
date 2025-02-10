#include <stdio.h>

int main () {

    int A, B;

    printf("Digite os valores de A e B\n");
    scanf("%d %d", &A,&B);
    printf("A eh %d e B eh %d\n", A, B);

    int temp = A;
    A = B;
    B = temp;

    printf("agora A eh %d e B eh %d", A, B);

    return 0;
}