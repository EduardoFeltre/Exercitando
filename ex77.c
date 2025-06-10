#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    int idade;
    char sexo;       
    char cpf[15];     
    Data dataNascimento;
    int codigoSetor; 
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    Funcionario f;

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", f.nome);

    printf("Digite a idade: ");
    scanf("%d", &f.idade);

    do {
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &f.sexo);
        f.sexo = toupper(f.sexo);
    } while (f.sexo != 'M' && f.sexo != 'F');

    printf("Digite o CPF (somente números, ex: 00000000000): ");
    scanf(" %14s", f.cpf); 

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &f.dataNascimento.dia, &f.dataNascimento.mes, &f.dataNascimento.ano);

    do {
        printf("Digite o codigo do setor (0 a 99): ");
        scanf("%d", &f.codigoSetor);
    } while (f.codigoSetor < 0 || f.codigoSetor > 99);

    printf("Digite o cargo: ");
    scanf(" %[^\n]", f.cargo);

    printf("Digite o salario: ");
    scanf("%f", &f.salario);

    
    printf("\n--- Dados do Funcionário ---\n");
    printf("Nome: %s\n", f.nome);
    printf("Idade: %d\n", f.idade);
    printf("Sexo: %c\n", f.sexo);
    printf("CPF: %s\n", f.cpf);
    printf("Data de nascimento: %02d/%02d/%04d\n",
           f.dataNascimento.dia, f.dataNascimento.mes, f.dataNascimento.ano);
    printf("Código do setor: %d\n", f.codigoSetor);
    printf("Cargo: %s\n", f.cargo);
    printf("Salário: R$ %.2f\n", f.salario);

    return 0;
}
