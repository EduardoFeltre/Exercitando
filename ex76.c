#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

int main() {
    Aluno alunos[5];
    int i;
    float media[5];
    int idxMaiorNota1 = 0, idxMaiorMedia = 0, idxMenorMedia = 0;

    
    for (i = 0; i < 5; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);

       
        media[i] = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0f;
    }

    
    for (i = 1; i < 5; i++) {
        if (alunos[i].nota1 > alunos[idxMaiorNota1].nota1) {
            idxMaiorNota1 = i;
        }
    }

    
    for (i = 1; i < 5; i++) {
        if (media[i] > media[idxMaiorMedia]) {
            idxMaiorMedia = i;
        }
    }

    
    for (i = 1; i < 5; i++) {
        if (media[i] < media[idxMenorMedia]) {
            idxMenorMedia = i;
        }
    }

    
    printf("\nAluno com maior nota na prova 1:\n");
    printf("Matricula: %d, Nome: %s, Nota1: %.2f\n",
           alunos[idxMaiorNota1].matricula,
           alunos[idxMaiorNota1].nome,
           alunos[idxMaiorNota1].nota1);

    printf("\nAluno com maior media geral:\n");
    printf("Matricula: %d, Nome: %s, Media: %.2f\n",
           alunos[idxMaiorMedia].matricula,
           alunos[idxMaiorMedia].nome,
           media[idxMaiorMedia]);

    printf("\nAluno com menor media geral:\n");
    printf("Matricula: %d, Nome: %s, Media: %.2f\n",
           alunos[idxMenorMedia].matricula,
           alunos[idxMenorMedia].nome,
           media[idxMenorMedia]);

    
    printf("\nSituação dos alunos:\n");
    for (i = 0; i < 5; i++) {
        printf("Aluno: %s, Media: %.2f - %s\n",
               alunos[i].nome,
               media[i],
               (media[i] >= 6.0) ? "Aprovado" : "Reprovado");
    }

    return 0;
}
