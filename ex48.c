#include <stdio.h>

void atualizaNota(float *nota) {
    if (*nota + 0.5 > 10.0) {
        *nota = 10.0;
    } else {
        *nota += 0.5;
    }
}

int main() {
    float nota;

    printf("Digite a nota: ");
    scanf("%f", &nota);

    atualizaNota(&nota);

    printf("Nota atualizada: %.2f\n", nota);

    return 0;
}