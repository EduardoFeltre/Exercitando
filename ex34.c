#include <stdio.h>

int main() {
    int num;
    printf("Digite n: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) { 
        printf("%d, ", 3 * i);  
    }

    return 0;
}
