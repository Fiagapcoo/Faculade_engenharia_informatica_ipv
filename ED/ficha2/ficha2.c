#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXPALAVRA 51

#define MAXLINHA 1000

typedef struct
{
    char TEXTO[MAXPALAVRA];
} PALAVRA;

typedef struct NO
{
    PALAVRA *Info;
    struct NO *Prox;
} NO, ELEMENTO;

typedef struct
{
    char LINGUA[3];
    int NEL;
    NO *Inicio;
} LISTA;

LISTA *criar_lista(char *lingua);
ELEMENTO criar_elemento();
int validar_String(char *str);
int validar_elemento(ELEMENTO *E);
void ler_elemento(ELEMENTO E);
void inserir_elemento_inicio(LISTA L, ELEMENTO E);
void inserir_elemento_fim(LISTA L, ELEMENTO E);
int comparar_elementos(ELEMENTO A, ELEMENTO B);
int elementos_iguais(ELEMENTO A, ELEMENTO B);
void inserir_elemento_ordenado(LISTA L, ELEMENTO element);
ELEMENTO pesquisar_iterativo(LISTA L, ELEMENTO elemento);
ELEMENTO pesquisar_recursivo(LISTA L, ELEMENTO elemento);
int elementos_repetidos(LISTA L);
int libertar_elemento(LISTA L, ELEMENTO elemento);
ELEMENTO remover_elemento(LISTA L, ELEMENTO elemento);
ELEMENTO remover_primeiro(LISTA L);
ELEMENTO remover_ultimo(LISTA L);
void mostrar_elemento(ELEMENTO E);
void mostrar_lista(LISTA L);
void mostrar_lista_inversa_v1(LISTA L);
void mostrar_lista_inversa_v2(LISTA L);
void eliminar_todos_elementos(LISTA L);
void exportar_ficheiro(LISTA L, char *nome_ficheiro);
void importar_ficheiro(LISTA L, char *nome_ficheiro);
void ordenar_lista_v1_bublesort(LISTA L);
void ordenar_lista_v2_fast_buuble_sort(LISTA L);
char menu_princial(LISTA L, ELEMENTO E);
char menu_remover(LISTA L, ELEMENTO E);
char menu_funcs_adic(LISTA L, ELEMENTO E);





LISTA *criar_lista(char *lingua)

{
    LISTA *L = (LISTA *)malloc(sizeof(LISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    strcpy(L->LINGUA, lingua);
    return L;
}

ELEMENTO criar_elemento()
{
    ELEMENTO *E = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    E->Info = (PALAVRA *)malloc(sizeof(PALAVRA));
    E->Prox = NULL;
    return *E;
}

int validar_String(char *str)
{

    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] != ' '&& (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
    }
    return 1;
}

int validar_elemento(ELEMENTO *E)
{
    int i;
    int valido = 1;

    if (validar_String(E->Info->TEXTO) == 0)
    {
        printf("O elemento contém um caractere inválido.\n");
    }else{
        printf("O elemento é válido e foi registado com sucesso =).\n");
    }
}

void ler_elemento(ELEMENTO E)
{

    if (validar_elemento(&E) == 1)
    {
        printf("O elemento contém um caractere inválido.\n");
        return;
    }
    else if (validar_elemento(&E) == -1)
    {
        printf("Algo de errado nao ta certo");
        return;
    }
    else
    {
        printf("O elemento é válido e foi registado com sucesso =).\n");
        return;
    }
}

void inserir_elemento_inicio(LISTA L, ELEMENTO E)
{
    if (L.Inicio == NULL)
    {
        L.Inicio = &E;
        L.NEL++;
    }
    else
    {
        E.Prox = L.Inicio;
        L.Inicio = &E;
        L.NEL++;
    }
}

void inserir_elemento_fim(LISTA L, ELEMENTO E)
{
    if (L.Inicio == NULL)
    {
        L.Inicio = &E;
        L.NEL++;
    }
    else
    {
        ELEMENTO *aux = L.Inicio;
        while (aux->Prox != NULL)
        {
            aux = aux->Prox;
        }
        aux->Prox = &E;
        L.NEL++;
    }
}

int comparar_elementos(ELEMENTO A, ELEMENTO B)
{
    if (strcmp(A.Info->TEXTO, B.Info->TEXTO) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int elementos_iguais(ELEMENTO A, ELEMENTO B)
{
    if (comparar_elementos(A, B) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_elemento_ordenado(LISTA L, ELEMENTO element){
    if(L.Inicio == NULL){
        L.Inicio = &element;
        L.NEL++;
    }else{
        ELEMENTO *aux = L.Inicio;
        while(aux->Prox != NULL && strcmp(aux->Prox->Info->TEXTO, element.Info->TEXTO) < 0){
            aux = aux->Prox;
        }
        element.Prox = aux->Prox;
        aux->Prox = &element;
        L.NEL++;
    }
}

ELEMENTO pesquisar_iterativo(LISTA L, ELEMENTO elemento){

    while(L.Inicio->Prox != NULL){
        if(strcmp(L.Inicio->Info->TEXTO, elemento.Info->TEXTO) == 0){
            return *L.Inicio;
        }
        L.Inicio = L.Inicio->Prox;

    }

}

ELEMENTO pesquisar_recursivo(LISTA L, ELEMENTO elemento){
    if(L.Inicio->Prox == NULL){
        return *L.Inicio;
    }else{
        if(strcmp(L.Inicio->Info->TEXTO, elemento.Info->TEXTO) == 0){
            return *L.Inicio;
        }
        L.Inicio = L.Inicio->Prox;
        pesquisar_recursivo(L, elemento);
    }
}

int elementos_repetidos(LISTA L){
    int repetidos = 0;
    ELEMENTO *aux = L.Inicio;
    while(aux->Prox != NULL){
        if(strcmp(aux->Info->TEXTO, aux->Prox->Info->TEXTO) == 0){
            repetidos++;
        }
        aux = aux->Prox;
    }
    return repetidos;
}

int libertar_elemento(LISTA L, ELEMENTO elemento){
    if(L.Inicio == NULL){
        return 0;
    }else{
        ELEMENTO *aux = L.Inicio;
        while(aux->Prox != NULL){
            if(strcmp(aux->Prox->Info->TEXTO, elemento.Info->TEXTO) == 0){
                aux->Prox = aux->Prox->Prox;
                L.NEL--;
                return 1;
            }
            aux = aux->Prox;
        }
        return 0;
    }
}

ELEMENTO remover_elemento(LISTA L, ELEMENTO elemento){
 
 while(L.Inicio->Prox != NULL){
        if(strcmp(L.Inicio->Info->TEXTO, elemento.Info->TEXTO) == 0){
            ELEMENTO *aux = L.Inicio;
            L.Inicio = L.Inicio->Prox;
            L.NEL--;
            return *aux;
        }
        L.Inicio = L.Inicio->Prox;

    }
}

ELEMENTO remover_primeiro(LISTA L){
    if(L.Inicio == NULL){
        return *L.Inicio;
    }else{
        ELEMENTO *aux = L.Inicio;
        L.Inicio = L.Inicio->Prox;
        L.NEL--;
        return *aux;
    }
}

ELEMENTO remover_ultimo(LISTA L){
    while (L.Inicio->Prox != NULL)
    {
        L.Inicio = L.Inicio->Prox;
    }
    ELEMENTO *aux = L.Inicio;
    L.Inicio = NULL;
    L.NEL--;
    return *aux;

   
}

void mostrar_elemento(ELEMENTO elemento)
{
    printf("Elemento: %s", elemento.Info->TEXTO);
}

void mostrar_lista(LISTA L)
{
    ELEMENTO *aux = L.Inicio;
    while (aux != NULL)
    {
        mostrar_elemento(*aux);
        aux = aux->Prox;
    }
}

void mostrar_lista_inversa_v1(LISTA L)
{
    ELEMENTO *aux = L.Inicio;
    if (aux != NULL)
    {
        mostrar_lista_inversa_v1(L);
        mostrar_elemento(*aux);
    }
}


void mostrar_lista_inversa_v2(LISTA L)
{
    ELEMENTO *aux = L.Inicio;
    while (aux != NULL)
    {
        mostrar_elemento(*aux);
        aux = aux->Prox;
    }
}

void eliminar_todos_elementos(LISTA L){
    if(L.Inicio == NULL){
        return;
    }else{
        L.Inicio = NULL;
        L.NEL = 0;
        L.Inicio->Prox = NULL;
    }
}

void exportar_ficheiro(LISTA L, char *nome_ficheiro){
    FILE *ficheiro = fopen(nome_ficheiro, "w");
    if(ficheiro == NULL){
        printf("Erro ao abrir o ficheiro");
        return;
    }else{
        ELEMENTO *aux = L.Inicio;
        while(aux != NULL){
            fprintf(ficheiro, "%s", aux->Info->TEXTO);
            aux = aux->Prox;
        }
        fclose(ficheiro);
    }
}

void importar_ficheiro(LISTA L, char *nome_ficheiro){
    FILE * ficheiro = fopen(nome_ficheiro, "r");
    if(ficheiro == NULL || strcmp(nome_ficheiro, " ") == 0){
        printf("Erro ao abrir o ficheiro");
        return;
    }else{
        char linha[MAXLINHA];
        int n_linha = 0;
        while(fgets(linha, MAXLINHA, ficheiro) != NULL){
            n_linha++;
        }
        fseek(ficheiro, 0, SEEK_SET);

        ELEMENTO *elemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));

        while (fgets(linha, MAXLINHA, ficheiro) != NULL){
            
            strcpy(elemento->Info->TEXTO, linha);
            inserir_elemento_ordenado(L, *elemento);
        }

}
}

void ordenar_lista_v1_bublesort(LISTA L){
    int i, j;
    for(i = 0; i < L.NEL; i++){
        for(j = 0; j < L.NEL - 1; j++){
            if(strcmp(L.Inicio->Info->TEXTO, L.Inicio->Prox->Info->TEXTO) > 0){
                ELEMENTO *aux = L.Inicio;
                L.Inicio = L.Inicio->Prox;
                aux->Prox = L.Inicio->Prox;
                L.Inicio->Prox = aux;
            }
        }
    }
}

void ordenar_lista_v2_fast_buuble_sort(LISTA L){
    int j;
    bool troca;
    do{
        troca = false;
        for(j=0;j < L.NEL - 1; j++){
            if(strcmp(L.Inicio->Info->TEXTO, L.Inicio->Prox->Info->TEXTO) > 0){
                ELEMENTO *aux = L.Inicio;
                L.Inicio = L.Inicio->Prox;
                aux->Prox = L.Inicio->Prox;
                L.Inicio->Prox = aux;
                troca = true;
            }
            
        }

    }while(troca);
}


char menu_princial(LISTA L, ELEMENTO E){
     
    int opcao;

    do
    {
    system("clear");
    printf("\nMENU:");
    printf("\n1- Inserir novo elemento na lista:");
    printf("\n2- Retirar  elementos da lista (ir para submenu):");
    printf("\n3- Mostrar os elementos pela ordem actual:");
    printf("\n4- Mostrar os elementos pela ordem inversa:");
    printf("\n5- Mostrar o numero de elementos da lista:");
    printf("\n6- Pesquisar por um elemento da lista:");
    printf("\n7- Verificar se existem elementos repetidos na lista:");
    printf("\n8- Exportar elementos para um ficheiro de texto:");
    printf("\n9- Importar elementos de um ficheiro de texto:");
    printf("\n0- SAIR: ");
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            criar_elemento();
            break;
        case 2:
            menu_remover(L, E);
            break;
        case 3:
            mostrar_lista(L);
            break;
        case 4:
           mostrar_lista_inversa_v1(L);
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
        
        case 0:
            exit(0);
            break;
        default:
            printf("Opcao invalida \n");
            break;
        }

    } while(opcao!=0);


}

char menu_remover(LISTA L, ELEMENTO E){

    int opcao;

    do
    {
    system("cls");
    printf("\nMENU:");
    printf("\n1- Retirar o primeiro elemento:");
    printf("\n2- Retirar um elemento especificado pelo utilizador:");
    printf("\n3- Retirar o último elemento:");
    printf("\n4- Destruir a lista de elementos:");
    printf("\n0- VOLTAR ao Menu Principal: ");
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:

            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
           
            break;               
        case 0:
            menu_princial(L,E);
            break;
        default:
            printf("Opcao invalida \n");
            break;
        }

    } while(opcao!=0);

}

char menu_funcs_adic(LISTA L, ELEMENTO E){

    int opcao;

    do
    {
    system("cls");
    printf("\nMENU:");
    printf("\n1- Inserir elemento no início:");
    printf("\n2- Inserir elemento no fim:");
    printf("\n3- Reordenar Lista:");
    printf("\n0- VOLTAR ao Menu Principal: ");
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:

            break;
        case 2:
            
            break;
        case 3:
            
            break;               
        case 0:
            exit(0);
            break;
        default:
            printf("Opcao invalida \n");
            break;
        }

    } while(opcao!=0);

}

int main(){
    LISTA *L = criar_lista("Lista");
    ELEMENTO E = criar_elemento();
    menu_princial(*L, E);
    return 0;
}