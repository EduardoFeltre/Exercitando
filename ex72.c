#include <stdio.h>
#include <string.h>


typedef struct {
    char nomeCompanhia[50];
    char areaAtuacao[30];
    float valorAtual;
    float valorAnterior;
    double variacaoPorcentagem;
} Acao;

int main() {
    Acao a;

    
    printf("Digite o nome da companhia: ");
    scanf(" %[^\n]", a.nomeCompanhia);

    printf("Digite a área de atuação: ");
    scanf(" %[^\n]", a.areaAtuacao);

    printf("Digite o valor atual da ação (R$): ");
    scanf("%f", &a.valorAtual);

    printf("Digite o valor da ação na abertura (R$): ");
    scanf("%f", &a.valorAnterior);

   
    if (a.valorAnterior != 0) {
        a.variacaoPorcentagem = ((a.valorAtual - a.valorAnterior) / a.valorAnterior) * 100.0;
    } else {
        a.variacaoPorcentagem = 0.0;  
    }

    // Exibindo os dados
    printf("\n--- Dados da Ação ---\n");
    printf("Companhia: %s\n", a.nomeCompanhia);
    printf("Área de atuação: %s\n", a.areaAtuacao);
    printf("Valor atual: R$ %.2f\n", a.valorAtual);
    printf("Valor na abertura: R$ %.2f\n", a.valorAnterior);
    printf("Variação percentual: %.2f%%\n", a.variacaoPorcentagem);

    return 0;
}
