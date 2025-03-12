#include <stdio.h>

<<<<<<< HEAD
int main(){









    return 0;
} 
=======
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
>>>>>>> cb38c2d86d8873219e8c9b3f6ed46369b58831c0
