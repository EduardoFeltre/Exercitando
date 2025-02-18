#include <stdio.h>
#include <math.h>

    int main(){

        int raio, temp;
        float perimetro, area;

            printf("Digite o valor do raio:\n");
            scanf("%d", &raio);

                temp = raio * raio;
                perimetro = 2 * 3.14 * raio;
                area = temp * 3.14;

                    printf("O perimetro eh:%.2f\n", perimetro);
                    printf("A area eh:%.2f\n", area);




        return 0;

    }