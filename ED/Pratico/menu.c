//
// Created by filipe on 30-03-2023.
//
#include "header.h"

void menu(SUPERMERCADO *supermercado){

    simulacao(supermercado);
    int opc;
    do{

        printf("1 - Contiuar simulacao\n");
        printf("2 - Ver estatisticas\n");
        printf("3 - Mudar de caixa\n");
        printf("4 - inserir caixas\n");
        printf("5 - Pesquisar pessoa\n");

        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);



        switch (opc){
            case 1:
                simulacao(supermercado);
                break;
            case 2:
                estatisticas(supermercado);
                break;
            case 3:
                mudarCaixa(supermercado);
                break;
            case 4:
                inserirCaixas(supermercado);
                break;
            case 5:
                pesquisarPessoaCaixa(supermercado);
                break;
            case 0:
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }



} while (opc != 0);
    gravar_dados(supermercado);
    printf("A");

    exit(0);
}