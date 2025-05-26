#include <stdio.h>
#include <math.h>

int main() {
    // --- Variaveis ---
    double metaPoupanca, saldoAtual, contribuicaoMensal, taxaJurosAnual;
    double saldoCorrente, jurosMensal, taxaJurosMensal;
    int meses = 0;
    int metadeMetaAlcancada = 0; // Flag para mensagem motivacional

    // --- Entrada de Dados ---
    printf("--- Simulador de Meta de Poupanca ---\n");
    printf("Digite sua meta de poupanca (R$): ");
    scanf("%lf", &metaPoupanca);
    printf("Digite seu saldo atual (R$): ");
    scanf("%lf", &saldoAtual);
    printf("Digite sua contribuicao mensal planejada (R$): ");
    scanf("%lf", &contribuicaoMensal);
    printf("Digite a taxa de juros anual estimada (%%, ex: 5 para 5%%): ");
    scanf("%lf", &taxaJurosAnual);

    // --- Validacao ---
    if (contribuicaoMensal <= 0 && (saldoAtual * (1 + (taxaJurosAnual / 100.0) / 12.0)) <= saldoAtual) {
        printf("\nCom contribuicao mensal zero ou negativa e sem rendimentos, voce nao alcancara a meta.\n");
        return 0;
    }

    saldoCorrente = saldoAtual;
    taxaJurosMensal = (taxaJurosAnual / 100.0) / 12.0;
    
    printf("\n--- Simulacao Mes a Mes ---\n");
    
    while (saldoCorrente < metaPoupanca) {
        // Calcula juros do mes
        jurosMensal = saldoCorrente * taxaJurosMensal;
        
        // Adiciona juros e contribuicao
        saldoCorrente += jurosMensal;
        saldoCorrente += contribuicaoMensal;
        
        // Incrementa o contador de meses
        meses++;
        
        // Imprime status a cada 6 meses (para nao poluir a saida)
        if (meses % 6 == 0) {
            printf("Mes %d: Saldo = R$ %.2f\n", meses, saldoCorrente);
        }
        
        // Mensagem Motivacional
        if (!metadeMetaAlcancada && saldoCorrente >= metaPoupanca / 2.0) {
            printf("\n*** Otimo progresso! Voce ja passou da metade da sua meta! Continue assim! ***\n\n");
            metadeMetaAlcancada = 1;
        }
        
        // Seguranca para evitar loop infinito
        if (meses > 12000) { // Limite de 1000 anos
            printf("\nA simulacao excedeu 1000 anos. Verifique os valores de entrada.\n");
            return 1;
        }
    }

    // --- Resultado Final ---
    printf("\nParabens! Voce alcancara sua meta de R$ %.2f em:\n", metaPoupanca);
    
    int anos = meses / 12;
    int mesesRestantes = meses % 12;
    
    if (anos > 0) {
        printf("%d ano(s) ", anos);
    }
    if (mesesRestantes > 0) {
        printf("e %d mes(es)\n", mesesRestantes);
    }
    if (anos == 0 && mesesRestantes == 0) {
        printf("menos de 1 mes (ou ja alcancado).\n");
    } else if (anos > 0 && mesesRestantes == 0) {
        printf("\n");
    }
    
    printf("Saldo final estimado: R$ %.2f\n", saldoCorrente);
    return 0;
}