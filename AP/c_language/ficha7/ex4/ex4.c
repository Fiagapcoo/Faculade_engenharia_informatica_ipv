 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <malloc.h>

 #define MAX 2
 #define MAX_NOME 30
 #define MAX_AREA 20

 typedef struct livro {
     char *titulo;
     char *autor;
     char *area;
     int ano;
 } LIVRO;

 void insere_livro(LIVRO *livro );
 void mostrar_livro(LIVRO *lista_livros, int num_livro);
 void retirar_livro(LIVRO *lista_livros, int num_livro);

 int main() {
     int n, num;
     LIVRO *lista_livros = (LIVRO *) malloc(sizeof(LIVRO)*MAX);
     int i;

     for(i=0; i<MAX; i++) {
         insere_livro(&lista_livros[i]);
     }

     printf("Introduza o numero do livro que pretende ver: ");
     scanf("%d", &num);
     mostrar_livro(lista_livros, num);

     printf("Introduza o numero do livro que pretende retirar: ");
     scanf("%d", &num);
     retirar_livro(lista_livros, num);

     return 0;

 }

 void insere_livro(LIVRO *livro) {

 livro->titulo = (char *) realloc(livro->titulo,sizeof(char)*MAX_NOME );
 livro->autor = (char *) realloc(livro->autor,sizeof(char)*MAX_NOME );
 livro->area = (char *) realloc(livro->area,sizeof(char)*MAX_AREA );

 printf("Introduza o titulo do livro: ");
 scanf("%s", livro->titulo);
 printf("Introduza o autor do livro: ");
 scanf("%s", livro->autor);
 printf("Introduza a area do livro: ");
 scanf("%s", livro->area);
 printf("Introduza o ano do livro: ");
 scanf("%d", &livro->ano);

 }

 void mostrar_livro(LIVRO *lista_livros, int num_livro) {

 int i;
 while(lista_livros != NULL) {
     if(lista_livros->ano == num_livro){
        printf("\nTitulo: %s", lista_livros->titulo);
        printf("\nAutor: %s", lista_livros->autor);
        printf("\nArea: %s", lista_livros->area);
        printf("\nAno: %d", lista_livros->ano);
     }
     lista_livros++;
 }

 }

 void retirar_livro(LIVRO *lista_livros, int num_livro) {

 int i;
 while(lista_livros != NULL) {
     if(lista_livros->ano == num_livro){
        lista_livros->titulo = NULL;
        lista_livros->autor = NULL;
        lista_livros->area = NULL;
        lista_livros->ano = 0;
     }
     lista_livros++;
 }

 }

