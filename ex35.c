#include <stdio.h>
int main(){

    int x, y, cont = 0;
    printf("Digite o X e o Y: ");
    scanf("%d %d", &x, &y);
    for(int i = x;i <= y; i++){
        if(i % 2 == 1){
            printf("%d", i);
            cont++;
        }
    }
    if(cont == 0){
        printf("Nao existe num impar");
    }

    return 0;
}