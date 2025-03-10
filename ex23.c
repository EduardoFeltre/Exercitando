#include <stdio.h>

int main() {
    int x, y;
    
    printf("Digite as coordenadas X e Y (0 0 para sair):\n");
    
    while (1) {
        scanf("%d %d", &x, &y);
        
        if (x == 0 && y == 0) {
            break;
        }
        
        if (x > 0 && y > 0) {
            printf("Primeiro quadrante\n");
        } else if (x < 0 && y > 0) {
            printf("Segundo quadrante\n");
        } else if (x < 0 && y < 0) {
            printf("Terceiro quadrante\n");
        } else if (x > 0 && y < 0) {
            printf("Quarto quadrante\n");
        } else {
            printf("Sobre um dos eixos\n");
        }
    }
    
    return 0;
}
