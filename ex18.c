#include <stdio.h>

int main(){

    int N, num = 1;
        printf("Digite N:");
        scanf("%d", &N);

        printf("Os %d primeiros num impares: ", N);
    
        while(N > 0){
            printf("%d", num);
            num += 2;
            N--;

        }
    return 0;
}