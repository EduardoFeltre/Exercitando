#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    float altura;
    Data nascimento;
} Pessoa;

Data gerarDataAleatoria() {
    Data d;
    d.ano = 2000 + rand() % 25;       
    d.mes = 1 + rand() % 12;          
    d.dia = 1 + rand() % 30;          
    return d;
}

int main() {
    Pessoa pessoas[10];
    int i, total;

    srand(time(NULL));

    printf("Quantas pessoas deseja cadastrar (até 10)? ");
    scanf("%d", &total);

    if (total < 1 || total > 10) {
        printf("Número inválido! Encerrando o programa.\n");
        return 1;
    }

    
    for (i = 0; i < total; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome);

        printf("Altura (em metros): ");
        scanf("%f", &pessoas[i].altura);

        pessoas[i].nascimento = gerarDataAleatoria();
    }

    printf("\n--- Dados Cadastrados ---\n");
    for (i = 0; i < total; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Altura: %.2f metros\n", pessoas[i].altura);
        printf("Data de nascimento: %02d/%02d/%04d\n",
               pessoas[i].nascimento.dia,
               pessoas[i].nascimento.mes,
               pessoas[i].nascimento.ano);
    }

    return 0;
}
