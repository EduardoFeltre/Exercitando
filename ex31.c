#include <stdio.h>

void mostrarParesEmOrdemDecrescente(int n){
    for (int i = n; i > 0; i--) {
        if (i % 2 == 0) { 
            printf("%d ", i);
        }
    }
    printf("\n"); 
}



int par(int n){
    return 2 * n;
}




int main() {
    int n;

    printf("Digite n:\n");
    scanf("%d", &n);

    printf("O n-esimo termo eh: %d \n", par(n));
    printf("Sequencia em ordem decrescente: ");
    mostrarParesEmOrdemDecrescente(n);

    return 0;
}
