#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MATRICULA 9
#define MAX_NOME      31
#define MAX_MARCA     16
#define MAX_COR       16


typedef struct
{
    char Matricula[MAX_MATRICULA];
    char Proprietario[MAX_NOME];
    char Marca[MAX_MARCA];
    char Cor[MAX_COR];
    time_t Tempo_de_entrada;
    time_t Tempo_de_saida;
    int Tempo_de_espera;
}Viatura;

typedef struct NO
{
    Viatura   *Info;
    struct NO *Prox;
}NO;

typedef struct
{
    NO *Inicio;
    NO *Fim;
    int NEL;
}FILA;

FILA *CriarFILA()
{
   
   FILA *F = (FILA *)malloc(sizeof(FILA));
   F->Inicio = NULL;
   F->Fim = NULL;
   F->NEL = 0;
   return F;
}

void mostrarDadaViatura(FILA *F){
    if(F->Inicio == NULL)
    {
        printf("Nao existem viaturas na fila");
        return;
    }
    printf("Qual a matricula da viatura que pretende ver? ");
    char matricula[MAX_MATRICULA];
    scanf("%s", matricula);
    NO *Aux;
    Aux = F->Inicio;
    while(Aux != NULL)
    {
        if(strcmp(Aux->Info->Matricula, matricula) == 0){
            printf("Matricula: %s   Proprietario: %s   Marca: %s   Cor: %s   Tempo de espera: %d    Tempo de entrada: %d    Tempo de saida: %d  Tempo de espera: %d", Aux->Info->Matricula, Aux->Info->Proprietario, Aux->Info->Marca, Aux->Info->Cor, Aux->Info->Tempo_de_entrada, Aux->Info->Tempo_de_saida, Aux->Info->Tempo_de_espera);
        }
        Aux = Aux->Prox;
    }
    
}

void LerViatura(Viatura *V)
{
    printf("Matricula: ");
    scanf("%s", V->Matricula);
    printf("Proprietario: ");
    scanf("%s", V->Proprietario);
    printf("Marca: ");
    scanf("%s", V->Marca);
    printf("Cor: ");
    scanf("%s", V->Cor);
    V->Tempo_de_entrada = time(NULL);
    V->Tempo_de_entrada = 0;
}

Viatura *criar_Viatura(){
    Viatura V;
    printf("Matricula: ");
    scanf("%s", V.Matricula);
    printf("Proprietario: ");
    scanf("%s", V.Proprietario);
    printf("Marca: ");
    scanf("%s", V.Marca);
    printf("Cor: ");
    scanf("%s", V.Cor);
    V.Tempo_de_entrada = time(NULL);
    V.Tempo_de_entrada = 0;
    return &V;
}

void inserirCarros(FILA *F)
{
    Viatura *V = criar_Viatura();
    NO *Aux;
    Aux = (NO *)malloc(sizeof(NO));
    Aux->Info = V;
    Aux->Prox = NULL;
    if(F->Inicio == NULL)
    {
        F->Inicio = Aux;
        F->Fim = Aux;
    }
    else
    {
        F->Fim->Prox = Aux;
        F->Fim = Aux;
    }
    F->NEL++;
}

void ListarTodasViaturas(FILA *F)
{
    NO *Aux;
    Aux = F->Inicio;
    while(Aux != NULL)
    {
        printf("Matricula: %s   Proprietario: %s   Marca: %s   Cor: %s   Tempo de espera: %d    Tempo de entrada: %d    Tempo de saida: %d  Tempo de espera: %d", Aux->Info->Matricula, Aux->Info->Proprietario, Aux->Info->Marca, Aux->Info->Cor, Aux->Info->Tempo_de_entrada, Aux->Info->Tempo_de_saida, Aux->Info->Tempo_de_espera);
    }
}

void Lavagem(FILA *F, char *matricula){
    NO *Aux;
    Aux = F->Inicio;
    while(Aux != NULL)
    {
        if(strcmp(Aux->Info->Matricula, matricula) == 0){
            Aux->Info->Tempo_de_saida = 0;
            Aux->Info->Tempo_de_espera = Aux->Info->Tempo_de_saida - Aux->Info->Tempo_de_entrada;
            printf("%d", Aux->Info->Tempo_de_espera);
        }
        Aux = Aux->Prox;
    }
}

void Viaturas_na_fila(FILA *f){
    NO *Aux;
    Aux = f->Inicio;
    int iterator =  0;
    while(Aux != NULL)
    {
        iterator++;
    }
    printf("Existem %d viaturas na fila", iterator);

}

void gravarViatura(FILA *F)
{
    FILE *fp;
    fp = fopen("fila.dat", "wb");
    NO *Aux;
    Aux = F->Inicio;
    while(Aux != NULL)
    {
        fprintf(fp, "Matricula: %s   Proprietario: %s   Marca: %s   Cor: %s   Tempo de espera: %d    Tempo de entrada: %d    Tempo de saida: %d  Tempo de espera: %d", Aux->Info->Matricula, Aux->Info->Proprietario, Aux->Info->Marca, Aux->Info->Cor, Aux->Info->Tempo_de_entrada, Aux->Info->Tempo_de_saida, Aux->Info->Tempo_de_espera);
    }
}

FILA *ler_ficheiro(FILA *F){
    FILE *fp;
    fp = fopen("fila.dat", "rb");
    NO *Aux;
    Aux = (NO *)malloc(sizeof(NO));
    Aux->Info = (Viatura *)malloc(sizeof(Viatura));
    Aux->Prox = NULL;
    if(F->Inicio == NULL)
    {
        F->Inicio = Aux;
        F->Fim = Aux;
    }
    else
    {
        F->Fim->Prox = Aux;
        F->Fim = Aux;
    }
    F->NEL++;
    return F;
}

void limpar_Fila (FILA *F){
    if(F->Inicio == NULL){
        return;
    }

   F->Inicio = NULL;
   F->Fim = NULL;
   F->NEL = 0;


}
int main(){

}

