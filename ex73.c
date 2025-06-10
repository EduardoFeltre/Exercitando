#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[50];
    char estiloMusical[30];
    int numeroIntegrantes;
    int posicaoRanking;
} Banda;

int main() {
    Banda bandas[5];
    int i;

    
    for (i = 0; i < 5; i++) {
        printf("\n--- Banda %d ---\n", i + 1);

        printf("Nome da banda: ");
        scanf(" %[^\n]", bandas[i].nome);

        printf("Estilo musical: ");
        scanf(" %[^\n]", bandas[i].estiloMusical);

        printf("Número de integrantes: ");
        scanf("%d", &bandas[i].numeroIntegrantes);

        printf("Posição no ranking: ");
        scanf("%d", &bandas[i].posicaoRanking);
    }

    
    printf("\n=== Bandas Cadastradas ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nBanda %d:\n", i + 1);
        printf("Nome: %s\n", bandas[i].nome);
        printf("Estilo Musical: %s\n", bandas[i].estiloMusical);
        printf("Número de Integrantes: %d\n", bandas[i].numeroIntegrantes);
        printf("Posição no Ranking: %d\n", bandas[i].posicaoRanking);
    }

    return 0;
}
