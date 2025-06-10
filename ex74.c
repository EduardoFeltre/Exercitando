#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[50];
    char estiloMusical[30];
    int numeroIntegrantes;
    int posicaoRanking;
} Banda;


void verificarBandaFavorita(Banda bandas[], int tamanho) {
    char nomeBusca[50];
    int i, encontrada = 0;

    printf("\nDigite o nome da banda para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (i = 0; i < tamanho; i++) {
        if (strcmp(bandas[i].nome, nomeBusca) == 0) {
            encontrada = 1;
            break;
        }
    }

    if (encontrada) {
        printf("A banda \"%s\" está entre suas favoritas!\n", nomeBusca);
    } else {
        printf("A banda \"%s\" NÃO está entre suas favoritas.\n", nomeBusca);
    }
}

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

    
    verificarBandaFavorita(bandas, 5);

    return 0;
}
