#include <stdio.h>
#include <math.h>  

typedef struct {
    float x;
    float y;
} ponto2d;

int main() {
    ponto2d ponto_inicial = {0.0, 0.0};
    ponto2d ponto_final = {0.0, 0.0};
    int opcao;
    float distancia;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Digitar os valores do ponto inicial\n");
        printf("2. Digitar os valores do ponto final\n");
        printf("3. Calcular e exibir a distância entre os dois pontos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor de x do ponto inicial: ");
                scanf("%f", &ponto_inicial.x);
                printf("Digite o valor de y do ponto inicial: ");
                scanf("%f", &ponto_inicial.y);
                break;

            case 2:
                printf("Digite o valor de x do ponto final: ");
                scanf("%f", &ponto_final.x);
                printf("Digite o valor de y do ponto final: ");
                scanf("%f", &ponto_final.y);
                break;

            case 3:
                distancia = sqrt(pow(ponto_final.x - ponto_inicial.x, 2) + 
                                 pow(ponto_final.y - ponto_inicial.y, 2));
                printf("A distância entre os pontos é: %.2f\n", distancia);
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 4);

    return 0;
}
