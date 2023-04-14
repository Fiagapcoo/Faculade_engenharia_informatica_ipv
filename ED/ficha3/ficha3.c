#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct contentor {

char conteudo[81];
char origem[30];
char destino[16];
char cliente[81];
DATA data_entrada;
float tonelagem;
char referencia[16];

} CONTENTOR;

typedef struct nodo{
    CONTENTOR contentor;
    struct nodo* next;
}NODO;

typedef struct pilha{
    NODO *inicio;
    int num_elementos;
}PILHA;


void inserir (CONTENTOR contentor, PILHA* pilha){
    
    NODO* nodo = (NODO*) malloc(sizeof(NODO));
    nodo->contentor = contentor;
    nodo->next = pilha->inicio;
    pilha->inicio = nodo;
}

void listar (PILHA* pilha){
        if(pilha == NULL){
        printf("Pilha inexistente");
        return;
    }
    if(pilha->inicio == NULL ){
        printf("Pilha vazia");
        return;
    }
    NODO* nodo = pilha->inicio;
    while (nodo != NULL){
        printf("Conteudo: %s    Origem: %s    Destino: %s    Cliente: %s    Data de entrada: %d/%d/%d    Tonelagem: %f    Referencia: %s    \n", nodo->contentor.conteudo, nodo->contentor.origem, nodo->contentor.destino, nodo->contentor.cliente, nodo->contentor.data_entrada.dia, nodo->contentor.data_entrada.mes, nodo->contentor.data_entrada.ano, nodo->contentor.tonelagem, nodo->contentor.referencia);
        nodo = nodo->next;
    }
}

void inserir_pilha(PILHA *pilha){

    CONTENTOR contentor;
    char conteudo[81], origem[30], destino[16], cliente[81], referencia[16];
    float tonelagem;
    //obter data do sistema
    int day, month, year;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    day = tm.tm_mday;
    month = tm.tm_mon + 1;
    year = tm.tm_year + 1900;

    printf("\nIntroduza o conteudo do contentor: ");
    scanf("%s", conteudo);
    printf("\nIntroduza a origem do contentor: ");
    scanf("%s", origem);
    printf("\nIntroduza o destino do contentor: ");
    scanf("%s", destino);
    printf("\nIntroduza o cliente do contentor: ");
    scanf("%s", cliente);
    printf("\nIntroduza a tonelagem do contentor: ");
    scanf("%f", &tonelagem);
    printf("\nIntroduza a referencia do contentor: ");
    scanf("%s", referencia);

    strcpy(contentor.conteudo, conteudo);
    strcpy(contentor.origem, origem);
    strcpy(contentor.destino, destino);
    strcpy(contentor.cliente, cliente);
    contentor.data_entrada.dia = day;
    contentor.data_entrada.mes = month;
    contentor.data_entrada.ano = year;
    contentor.tonelagem = tonelagem;
    strcpy(contentor.referencia, referencia);
    inserir(contentor, pilha);



}


PILHA* criar_pilha(){
    PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
    pilha->inicio = NULL;
    pilha->num_elementos = 0;
    return pilha;
}

void remover_pilha(PILHA* pilha){
        if(pilha == NULL){
        printf("Pilha inexistente");
        return;
    }
    if(pilha->inicio == NULL ){
        printf("Pilha vazia");
        return;
    }


    NODO* nodo = pilha->inicio;
    pilha->inicio = nodo->next;
    free(nodo);
}

int contar_contentores_pilha(PILHA* pilha){
        if(pilha == NULL){
        printf("Pilha inexistente");
        return 1;
    }
    if(pilha->inicio == NULL ){
        printf("Pilha vazia");
        return 2;
    }
    int contador = 0;
    NODO* nodo = pilha->inicio;
    while (nodo != NULL){
        contador++;
        nodo = nodo->next;
    }
    return contador;
}

void print_contentor_fundo(PILHA* pilha){
    if(pilha == NULL){
        printf("Pilha inexistente");
        return;
    }
    if(pilha->inicio == NULL ){
        printf("Pilha vazia");
        return;
    }

    NODO* nodo = pilha->inicio;
    while (nodo->next != NULL){
        nodo = nodo->next;
    }
    printf("Conteudo: %s    Origem: %s    Destino: %s    Cliente: %s    Data de entrada: %d/%d/%d    Tonelagem: %f    Referencia: %s    \n", nodo->contentor.conteudo, nodo->contentor.origem, nodo->contentor.destino, nodo->contentor.cliente, nodo->contentor.data_entrada.dia, nodo->contentor.data_entrada.mes, nodo->contentor.data_entrada.ano, nodo->contentor.tonelagem, nodo->contentor.referencia);
}

void menu(PILHA *pilha){
    int opc;
    do{
        printf("1 - Inserir contentor na pilha \n");
        printf("2 - Remover contentor da pilha \n");
        printf("3 - Listar contentores da pilha \n");
        printf("4 - Contar contentores da pilha \n");
        printf("5 - Mostrar contentor do fundo da pilha \n");
        printf("6 - Sair \n");

        scanf("%d", &opc);

        switch (opc){
            case 1:
                inserir_pilha(pilha);
                break;
            case 2:
                remover_pilha(pilha);
                break;
            case 3:
                listar(pilha);
                break;
            case 4:
                printf("Existem %d contentores na pilha", contar_contentores_pilha(pilha));
                break;
            case 5:
                print_contentor_fundo(pilha);
                break;
            default:
                printf("Opcao invalida");
                break;
        }
    }while (opc != 6);
    
}

int main(){
    PILHA* pilha = criar_pilha();
    menu(pilha);
    
}

