#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct musica
{
    char *titulo;
    char *interprete;
    int ano;
    int sigle; // 0 - sim, 1 - nao
    int numDownloads;
}MUSICA;

MUSICA *vetor_musicas(){
    printf("Quantas musicas pretende guardar");
    int nMusicas;
    scanf("%d", &nMusicas);

    MUSICA *vetorMusica = (MUSICA*)malloc(sizeof(MUSICA)*nMusicas);

    return nMusicas;
}


void musicasDownload(MUSICA *lista, int n, int numDownloads){
/*Implemente uma função que escreva no ecrã, as características das músicas com mais do que
um determinado número de downloads*/
    int i;
    for(i = 0; i < n; i++){
        if(lista[i].numDownloads > numDownloads){
            printf("Titulo: %s  Interprete: %s  Ano: %d  Sigle: %d  NumDownloads: %d", lista[i].titulo, lista[i].interprete, lista[i].ano, lista[i].sigle, lista[i].numDownloads);
        }

}
}

int listagemMusica(MUSICA *lista, char *interprete){

    int countMusicas;

    while (lista->ano != 0)
    {
        if(strcmp(lista->interprete, interprete)==0){
            countMusicas++;
        }
    }

    return countMusicas;
    

}

float gravaFichMusicas (MUSICA *lista, int n, int ano, char *nFich, char tpMeio){

    int i;
    float mediaDownloads = 0;
    int countMusicas = 0;
    FILE *ficheiro = fopen(nFich, "wb");

    if(ficheiro == NULL){
        printf("Erro ao abrir o ficheiro");
        return -1;
    }

    

    for(i = 0; i < n; i++){
       if(lista[i].ano < ano) continue;

       if(tpMeio == 's' && lista[i].sigle != 1)continue;

       if(tpMeio == 'n' && lista[i].sigle != 0)continue;

       MUSICA music = lista[i];
       fwrite(&music, sizeof(MUSICA), 1, ficheiro);

       mediaDownloads += music.numDownloads;
       countMusicas++;

       fclose(ficheiro);




       
    }

    fclose(ficheiro);

    return mediaDownloads/countMusicas;


}

MUSICA *CarregaListaMusicas(char *nomeFicheiro){
    FILE *ficheiro = fopen(nomeFicheiro, "rb");

    if(ficheiro == NULL){
        printf("Erro ao abrir o ficheiro");
        return -1;
    }
    fseek(ficheiro, 0, SEEK_END);

    long tamanhoFicheiro = ftell(ficheiro);

    long nMusicas = tamanhoFicheiro/sizeof(MUSICA);

    
}