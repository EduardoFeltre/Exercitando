#include <stdio.h>
#include <string.h>
#include <ctype.h>


int contar_vogais_recursivo(char *str) {
    
    if (*str == '\0') {
        return 0;
    }

    
    char caractere_atual_lower = tolower(*str);
    int contagem_atual = 0;

    
    if (caractere_atual_lower == 'a' || caractere_atual_lower == 'e' || 
        caractere_atual_lower == 'i' || caractere_atual_lower == 'o' || 
        caractere_atual_lower == 'u') {
        contagem_atual = 1;
    }

    
    return contagem_atual + contar_vogais_recursivo(str + 1);
}

int main() {
    char string_usuario[101]; 

    
    printf("Digite uma string (até 100 caracteres): ");
    fgets(string_usuario, sizeof(string_usuario), stdin);

    
    string_usuario[strcspn(string_usuario, "\n")] = 0;

    
    int numero_vogais = contar_vogais_recursivo(string_usuario);

   
    printf("A string contém %d vogais.\n", numero_vogais);

    return 0;
}