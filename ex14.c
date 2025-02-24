#include <stdio.h>

int main(){

    float a, b, c;

    printf("Digite 3 numeros a seguir\n");
    scanf("%f %f %f", &a, &b, &c);

    if(a + b > c && a + c > b && b + c > a)
        printf("Os numeros %.2f %.2f %.2f podem formar um triangulo", a, b, c);
    else
        printf("Os numeros nao formam um triangulo");

    return 0;
}