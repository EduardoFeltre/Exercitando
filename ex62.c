#include <stdio.h>
#include <string.h>


int contar_caractere_recursivo(char *str, char caractere) {
    
    if (*str == '\0') {
        return 0;
    }

    
    int contagem_atual = 0;
    if (*str == caractere) {
        contagem_atual = 1;
    }

    
    return contagem_atual + contar_caractere_recursivo(str + 1, caractere);
}

int main() {
    char string_usuario[201]; 
    char caractere_busca;

   
    printf("Digite uma string (até 200 caracteres): ");
    fgets(string_usuario, sizeof(string_usuario), stdin);

    

string_usuario[strcspn(string_usuario, "\n")] = 0;


printf("Digite o caractere a ser buscado: ");
    scanf(" %c", &caractere_busca); 

    
    int ocorrencias = contar_caractere_recursivo(string_usuario, caractere_busca);

   
    printf("O caractere '%c' aparece %d vezes na string.\n", caractere_busca, ocorrencias);

    return 0;
}
