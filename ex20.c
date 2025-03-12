#include <stdio.h>

int main() {
    int n, i = 0, num = 1;
    
    
    printf("Digite a quantidade de termos da sequencia: ");
    scanf("%d", &n);
    
    printf("Sequencia: ");
    
    while (i < n) {
        printf("%d ", num);
        num += 2; 
        i++;
    }
    
    printf("\n");
    return 0;
}
