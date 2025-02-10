#include <stdio.h>

int main(void) {

    int X, Y, Z, soma, media, produto;

    printf("Digite o primeiro numero: ");
    scanf("%d",&X);
    printf("Digite o segundo numero: ");
    scanf("%d",&Y);
    printf("Digite o terceiro numero: ");
    scanf("%d",&Z);

    soma = X + Y + Z;
    media = soma / 3;
    produto = X * Y * Z;
    
    printf("A soma deles eh %d\n",soma);
    printf("A media deles eh %d\n",media);
    printf("O produto deles eh %d\n",produto);


    return 0;


}