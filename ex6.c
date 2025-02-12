#include <stdio.h>
#include <math.h>

int main(){

    int base, altura, perimetro, area, temp;
    float diagonal;
    
    printf("Digite o valor da base:\n");
    scanf("%d", &base);
    printf("Digite o valor da altura:\n");
    scanf("%d", &altura);

    perimetro = 2 * (base + altura);
    area = base * altura;
    temp = (base * base) + (altura * altura);
    diagonal = sqrt(temp);

    printf("O perimetro eh:%d\n", perimetro);
    printf("A area eh:%d\n", area);
    printf("A diagonal eh:%.2f\n", diagonal);


    return 0;
}