#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2
#define MAX_NOME 30



typedef struct aluno {
    int numero;
    char *nome;
    float nota;
} ALUNO;

void insere_aluno(ALUNO *aluno );
void mostrar_aluno(ALUNO *lista_alunos, int num_aluno);

int main() {
    int n, num;
    ALUNO *lista_alunos = (ALUNO *) malloc(sizeof(ALUNO)*MAX);
    int i;

    for(i=0; i<MAX; i++) {
        insere_aluno(&lista_alunos[i]);
    }

    
        printf("Introduza o numero do aluno que pretende ver: ");
        scanf("%d", &num);
        mostrar_aluno(lista_alunos, num);
    

    return 0;
}

void insere_aluno(ALUNO *aluno) {

aluno->nome = (char *) realloc(aluno->nome,sizeof(char)*MAX_NOME );

printf("Introduza o numero do aluno: ");
scanf("%d", &aluno->numero);
printf("Introduza o nome do aluno: ");
scanf("%s", aluno->nome);
printf("Introduza a nota do aluno: ");
scanf("%f", &aluno->nota);

}

void mostrar_aluno(ALUNO *lista_alunos, int num_aluno) {
   
int i;
while(lista_alunos != NULL) {
    if(lista_alunos->numero == num_aluno){
       printf("\nNumero: %d", lista_alunos->numero);
       printf("\nNome: %s", lista_alunos->nome);
       printf("\nNota: %f", lista_alunos->nota);
        break;
    }
    lista_alunos++;
    }
}
