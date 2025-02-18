#include <stdio.h>

int main(){

    char nome [50];
    int idade;
    float altura;
            
            printf("Digite seu nome:\n");
            fgets(nome, 50, stdin);
            printf("Digite sua idade:\n");
            scanf("%d", &idade);
            printf("Digite sua altura:\n");
            scanf("%f", &altura);


            printf("Nome:%s", nome);
            printf("Idade:%d anos\n", idade);
            printf("Altura:%.2f metros\n", altura);

  
    return 0;
}