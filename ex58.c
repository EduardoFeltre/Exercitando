#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double somaAbaixoDiagonal(double *matriz, int tamanho) {
    double soma = 0.0;
    for (int i = 1; i < tamanho; i++) {
        for (int j = 0; j < i; j++) {
            soma += *(matriz + i * tamanho + j);
        }
    }
    return soma;
}


double somaDiagonalPrincipal(double *matriz, int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(matriz + i * tamanho + i);
    }
    return soma;
}