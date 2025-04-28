#include <stdio.h>

void converteTempo(int segundos, int *horas, int *minutos, int *segRestantes) {
    *horas = segundos / 3600;
    segundos %= 3600;
    *minutos = segundos / 60;
    *segRestantes = segundos % 60;
}

int main() {
    int segundos, horas, minutos, segRestantes;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &segundos);

    converteTempo(segundos, &horas, &minutos, &segRestantes);

    printf("Tempo convertido: %02d:%02d:%02d\n", horas, minutos, segRestantes);

    return 0;
}