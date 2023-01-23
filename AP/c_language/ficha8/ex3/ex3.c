#include <stdio.h>
typedef struct lista{
    int n_votos;
    int n_lugares;
    int *nome;
}LISTA;

LISTA *aloca_lista(int n_listas){

if(n_listas <=0){
    printf("Numero de listas invalidos");
    exit(1);
}
LISTA *listas = (LISTA *) malloc(sizeof(LISTA)*n_listas);

}

void preenchelista(LISTA *lista){



}
void mostra_lista(LISTA *lista){

}

void maximo (int *quociente, LISTA *listas, int n_listas, int *pos){

}

void conta_eleitos(LISTA *listas, int n_lista, int n_lugares){
    
}



int main(){
    int n_listas, n_lugares;
    

}