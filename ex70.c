#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
} Livro;

int main() {
    Livro livro;

   
    printf("Digite o título do livro: ");
    scanf(" %[^\n]", livro.titulo);  

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", livro.autor);   

    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.anoPublicacao);

  
    printf("\n--- Informações do Livro ---\n");
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicação: %d\n", livro.anoPublicacao);

    return 0;
}
