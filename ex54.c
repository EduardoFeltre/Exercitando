#include <stdio.h>

int main() {
    int copias;
    float valor;

    while (1) {
        scanf("%d", &copias);
        if (copias < 0) {
            break;
        }

        if (copias <= 100) {
            valor = 0.25 * copias;
        } else {
            valor = 0.25 * 100 + 0.20 * (copias - 100);
        }

        printf("%.2f\n", valor);
    }

    return 0;
}
