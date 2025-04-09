#include <stdio.h>


int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}

int main() {
    int b, e;

    
    printf("Digite a base: ");
    scanf("%d", &b);

    printf("Digite o expoente: ");
    scanf("%d", &e);

    if (b <= 0 || e < 0) {
        printf("A base e o expoente devem ser positivos.\n");
        return 1;
    }

    
    int resultado = potencia(b, e);
    printf("%d elevado a %d eh: %d\n", b, e, resultado);

    return 0;
}
