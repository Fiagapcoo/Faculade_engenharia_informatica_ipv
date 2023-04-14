#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N_LINHAS 3
#define N_COLUNAS 3

int Esparsa(int *Matriz, int M, int N, float percentagem){
    int i, j, count = 0;
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            if(*(Matriz + i*N + j) == 0){
                count++;
            }
        }
    }
    if((float)count/(M*N) > percentagem){
        printf("Matriz esparsa");
        return 1; // Matriz esparsa
    }
    printf("Matriz nao esparsa");
    return 0;
}

int main(){
    int *Matriz = (int *)malloc(N_LINHAS*N_COLUNAS*sizeof(int));
    Matriz[0] = 1;
    Matriz[1] = 0;
    Matriz[2] = 3;
    Matriz[3] = 0;
    Matriz[4] = 0;
    Matriz[5] = 0;
    Matriz[6] = 0;
    Matriz[7] = 4;
    Matriz[8] = 0;

    printf("%d  ", Esparsa(Matriz, N_LINHAS, N_COLUNAS, 0.5));  
}