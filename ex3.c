#include <stdio.h>

int main(){

    float peso, altura, IMC;

    printf("Digite seu peso e altura respectivamente:");
    scanf("%f %f", &peso, &altura);

    IMC = peso / (altura * altura);

    printf("Seu IMC eh %.2f\n", IMC);

    return 0;
}