#include <stdio.h>

int main() {
    int n, i = 0, num = 1;
    
    
    printf("Digite a quantidade de termos da sequência: ");
    scanf("%d", &n);
    
    printf("Sequência: ");
    
    while (i < n) {
        printf("%d ", num);
        num += 2; 
        i++;
    }
    
    printf("\n");
    return 0;
}
