#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, Y;

    printf("Digite os valores de a, b e c respectivamente:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    Y = a + (b / (c + a)) + 2 * (a - b) + log2(64);

    printf("O valor de Y eh:%.2lf\n", Y);

    return 0;
}