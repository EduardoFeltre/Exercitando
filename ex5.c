#include <stdio.h>

int main(){

    int dias, anos, semanas, dias_restantes;

    printf("quantidade de dias para converter:");
    scanf("%d", &dias);

    anos = dias / 365;
    dias_restantes = dias % 365;
    semanas = dias_restantes / 7;
    dias_restantes = dias_restantes % 7;


    printf("%d dias equivalem a:\n", dias);
    printf("%d anos, %d semanas e %d dias.\n", anos, semanas, dias_restantes);

    return 0;
}