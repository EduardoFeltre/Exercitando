#include <stdio.h>

int main() {
    int n, i = 0, num = 1;
    
    printf("Digite a quantidade de termos da sequencia: ");
    scanf("%d", &n);
    
    printf("Sequencia: ");
    
    while (i < n) {
        if ((num % 3 == 0 && num % 5 == 0) || (num % 7 == 0)) {
            printf("%d ", num);
            i++; 
        }
        num += 2; 
    }
    
    printf("\n");
    return 0;
}
