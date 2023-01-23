 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define MAX 100

 int main(){
     FILE *f = fopen("ficheiro.txt", "r");
     if (f == NULL){
         printf("Erro na abertura do ficheiro!\n");
         exit(1);
     }    
     char *string = malloc(sizeof(char)*MAX);
     while (fgets(string, MAX, f) != NULL){
         printf("%s", string);
     }
     fclose(f);
    free(string);
 }
