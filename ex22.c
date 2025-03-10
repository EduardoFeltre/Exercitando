#include <stdio.h>

int main() {
    int valor, positivos = 0, negativos = 0, total = 0;
    float perc_positivos, perc_negativos;

    printf("Digite uma sequencia de números inteiros (0 para sair):\n");
    
    while (1) {
        scanf("%d", &valor);
        
        if (valor == 0) {
            break;
        }
        
        if (valor > 0) {
            positivos++;
        } else {
            negativos++;
        }
        
        total++;
    }

    if (total > 0) {
        perc_positivos = (positivos * 100.0) / total;
        perc_negativos = (negativos * 100.0) / total;
    } else {
        perc_positivos = perc_negativos = 0.0;
    }

    printf("Total de valores positivos: %d (%.2f%%)\n", positivos, perc_positivos);
    printf("Total de valores negativos: %d (%.2f%%)\n", negativos, perc_negativos);

    return 0;
}
