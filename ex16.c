#include <stdio.h>

int main(){

    char caractere;

    printf("Digite um caractere:\n");
    scanf("%c", &caractere);

    switch (caractere)
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