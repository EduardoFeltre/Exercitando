#include <stdio.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_PESSOAS 100


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


typedef struct {
    char nome[MAX_NOME];
    float altura;
    Data nascimento;
} Pessoa;


void pessoaMaisAlta(Pessoa lista[], int n) {
    if (n == 0) {
        printf("Lista vazia.\n");
        return;
    }
    int idx_mais_alta = 0;
    for (int i = 1; i < n; i++) {
        if (lista[i].altura > lista[idx_mais_alta].altura) {
            idx_mais_alta = i;
        }
    }
    printf("Pessoa mais alta:\n");
    printf("Nome: %s\n", lista[idx_mais_alta].nome);
    printf("Altura: %.2f\n", lista[idx_mais_alta].altura);
    printf("Ano de nascimento: %d\n", lista[idx_mais_alta].nascimento.ano);
}


int main() {
    int n;
    Pessoa grupo[MAX_PESSOAS];

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: ");
        fgets(grupo[i].nome, MAX_NOME, stdin);
        grupo[i].nome[strcspn(grupo[i].nome, "\n")] = 0;
        printf("Altura (em metros): ");
        scanf("%f", &grupo[i].altura);
        printf("Data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &grupo[i].nascimento.dia, &grupo[i].nascimento.mes, &grupo[i].nascimento.ano);
        getchar(); 
    }

    pessoaMaisAlta(grupo, n);

    return 0;
}