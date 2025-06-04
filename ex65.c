#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vetor_original[20];
    int *ptr_original = vetor_original; 
    int *vetor_multiplos3 = NULL;
    int *ptr_multiplos;
    int contador_multiplos = 0;
    int i;

    
    srand(time(NULL));

    
    printf("Vetor Original (20 elementos entre 1 e 100):\n");
    for (i = 0; i < 20; i++) {
        *(ptr_original + i) = (rand() % 100) + 1;
        printf("%d ", *(ptr_original + i));
        
        if (*(ptr_original + i) % 3 == 0) {
            contador_multiplos++;
        }
    }
    printf("\n");

    
    if (contador_multiplos > 0) {
        vetor_multiplos3 = (int *)malloc(contador_multiplos * sizeof(int));
        if (vetor_multiplos3 == NULL) {
            printf("Erro ao alocar memória para o vetor de múltiplos de 3.\n");
            return 1;
        }
    } else {
        printf("\nNenhum múltiplo de 3 encontrado no vetor original.\n");
        return 0; 
    }

    
    ptr_multiplos = vetor_multiplos3; 
    for (i = 0; i < 20; i++) {
        if (*(ptr_original + i) % 3 == 0) {
            *ptr_multiplos = *(ptr_original + i);
            ptr_multiplos++; 
        }
    }

    
    printf("\nVetor de Múltiplos de 3 (%d elementos):\n", contador_multiplos);
    ptr_multiplos = vetor_multiplos3; 
    for (i = 0; i < contador_multiplos; i++) {
        printf("%d ", *(ptr_multiplos + i));
    }
    printf("\n");

    
    free(vetor_multiplos3);

    return 0;
}