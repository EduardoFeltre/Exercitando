#include <stdio.h>

int main(){

    char caracetere;

    printf("Digite um caractere:\n");
    scanf("%c", &caracetere);

    switch (caracetere)
    {
    case '.':
        printf("O caractere eh um ponto.\n");
        break;
    case ',' :
        printf("O caractere eh uma virgula.\n");
        break;    

    default:
        printf("O caractere eh outro sinal.\n");
        break;
    }


    return 0;
}