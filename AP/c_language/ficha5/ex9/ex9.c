#include <stdio.h>
#include <stdlib.h>
int ler_matriz(int array[][]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Introduza o valor da linha %d e coluna %d: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    return 0;
}


int mostrar_matriz(int array[][]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}
int minimo_matriz(int array[][]){
    int i, j, minimo;
    minimo = array[0][0];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(array[i][j] < minimo){
                minimo = array[i][j];
            }
        }
    }
    return minimo;
}
int simetrica(int array[]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(array[i][j] != array[j][i]){
                return 0;
            }
        }
    }
}
int transposta(int array[]){
    int i, j, transposta[3][3];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            transposta[i][j] = array[j][i];
        }
    }
    return transposta;
}
int soma_matrizes(){
    int i, j, matriz1[3][3], matriz2[3][3], soma[3][3];
    ler_matriz(matriz1);
    ler_matriz(matriz2);
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return soma;

}
int main(){
    int array[10][10];
}