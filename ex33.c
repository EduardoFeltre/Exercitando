#include <stdio.h>


double umSobreImpar(int n) {
    int den = (2 * n) + 1;
    return 1.0 / den;
}


double somaUmSobreImpar(int n) {
    double soma = 0.0;
    
    for (int i = 0; i < n; i++) {  
        soma += umSobreImpar(i);
    }

    return soma;
}

int main() {
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("O n-ésimo termo eh: %.2f\n", umSobreImpar(n));
    printf("A soma dos %d primeiros termos eh: %.5f\n", n, somaUmSobreImpar(n));

    return 0;
}
