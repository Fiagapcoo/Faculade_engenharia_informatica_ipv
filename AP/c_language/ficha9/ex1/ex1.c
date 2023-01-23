#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 100

int main(){


FILE *f = fopen("ficheiro.txt", "w");
if (f == NULL){
    printf("Erro na abertura do ficheiro!\n");
    exit(1);    
}

while (1==1)
{
    printf("Digite uma String");
    char *string = malloc(sizeof(char)*MAX);
    fgets(string, MAX, stdin);
    if (string[0] == '.'){
        break;
    }else{
    fprintf(f, "%s ", string);


    }
    
   // fgets(string, MAX, stdin);

}



}