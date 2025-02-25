#include <stdio.h>

int main(){
    
    float a1, b1, c1, a2, b2, c2;
    float D;

    printf("Digite os coeficientes da equacao (a1, b1 e o termo independente c1):\n");
    scanf("%f %f %f", &a1, &b1, &c1);

    printf("Digite os coeficientes da segunda equacao (a2, b2 e o termo independente c2):\n");
    scanf("%f %f %f", &a2, &b2, &c2);

    D = a1 * b2 - a2 * b1;

    if(D != 0){
        printf("O sistema tem uma solucao unica.\n");
    } else {
        if((a1 * c2 - a2 * c1) == 0 && (b1 * c2 - b2 * c1) == 0){
            printf("O sistema tem infinitas solucoes.\n");
        } else {
            printf("O sistema nao tem solucao.\n");
        }
    }

    return 0;
}