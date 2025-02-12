#include <stdio.h>

int main(){

    float celsius, fahrenheit;

    printf("Qual eh a temp em fahrenheit:");
    scanf("%f", &fahrenheit);

    celsius =  ((float) 5 / 9) * (fahrenheit - 32);

    printf("A temp em celsius eh %.2f\n",celsius);


    return 0;
}