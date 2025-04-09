#include <stdio.h>
int main(){

    int num;

    printf("DIgite um numero inteiro: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
       printf("%d \n", i * 3);
    }

    printf("\n");

    return 0;
   
}