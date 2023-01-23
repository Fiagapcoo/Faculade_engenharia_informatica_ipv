 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>


int tamanho_ficheiro(char *nome){

     nome[strlen(nome)-1] = '\0';
     FILE *f = fopen(nome, "r");
     if (f == NULL){
         printf("Erro na abertura do ficheiro!\n");
         exit(1);
     }
     fseek(f, 0, SEEK_END);
     int tamanho = ftell(f);
    fclose(f);
    return tamanho;
}

int main(){

     char *nome = malloc(sizeof(char)*100);
     printf("Digite o nome do ficheiro: ");
     fgets(nome, 100, stdin);
     int tamanho = tamanho_ficheiro(nome); 
     printf("O ficheiro tem %d bytes.\n", tamanho);    
     free(nome);
     
 }
