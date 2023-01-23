#include <stdio.h>
#include <malloc.h>
typedef struct tipo_dados{
    int numero;
    float valor;   
}TIPO_DADOS;

TIPO_DADOS *aloca_matriz(int linhas, int colunas){
    TIPO_DADOS *matriz;
    matriz = (TIPO_DADOS *) malloc(linhas * colunas * sizeof(TIPO_DADOS));
    if(matriz  == NULL){
        printf("Erro na alocacao da matriz");
        exit(1);
    }
    return matriz;
}

void ler_matriz(int linhas, int colunas, TIPO_DADOS *matriz){
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("Digite o numero da linha %d e coluna %d: ", i, j);
            scanf("%d", &matriz[i * colunas + j].numero);
            //scanf("%d", matriz->numero);
            //matriz++;
        }
    }
}

void mostra_matriz(int linhas, int colunas, TIPO_DADOS *matriz){
    int i, j;
    for(i = 0; i < linhas; i++){
        printf("\n");
        for(j = 0; j < colunas; j++){
            printf("\t %d ", matriz[i * colunas + j].numero);
        }
}}

void simetria(int linhas,int colunas, TIPO_DADOS *matriz){
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(matriz[i * colunas + j].numero != matriz[j * linhas + i].numero){
                printf("A matriz nao e simetrica");
            }
        }
    }
    printf("A matriz e simetrica");
}

void calculo_traco(int linhas, int colunas, TIPO_DADOS *matriz){
    int i, j;
    float traco = 0;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(i == j){
                traco += matriz[i * colunas + j].numero;
            }
        }
    }
    printf("O traco da matriz e: %f", traco);
}

void calculo_determinante(int linhas, int colunas, TIPO_DADOS *matriz){
    int i, j;
    float determinante = 0;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(i == j){
                determinante += matriz[i * colunas + j].numero;
            }
        }
    }
    printf("O determinante da matriz e:  %f", determinante);

}


int main(){
    //fazer opc para real ou inteiro 

    int linhas, colunas;
    char opc;
    
    

    printf("Introduza o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Introduza o numero de colunas: ");
    scanf("%d", &colunas);

    TIPO_DADOS *matiz = aloca_matriz(linhas, colunas);
    ler_matriz(linhas, colunas, matiz);
    
    
   
}
