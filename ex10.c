#include <stdio.h>
#include <math.h>

    int main(){
       
        int lado, perimetro, area, temp;
        float diagonal;

            printf("Digite o valor do lado:\n");
            scanf("%d", &lado);

                temp = lado * 4;
                perimetro = temp;
                area = lado * lado;
                diagonal = lado * sqrt(2);

                    printf("O perimetro eh:%d\n", perimetro);
                    printf("A area eh:%d\n", area);
                    printf("A diagonal eh:%.2f\n", diagonal);


        return 0;


    }