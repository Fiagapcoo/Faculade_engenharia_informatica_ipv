//
// Created by filipe on 30-03-2023.
//
#include "header.h"

void menu(SUPERMERCADO *supermercado){


    int opc;
    do{

        printf("1 - Contiuar simulacao\n");
        printf("2 - Ver estatisticas\n");
        printf("3 - Mudar de caixa\n");
        printf("4 - inserir caixas\n");
        printf("5 - Pesquisar pessoa\n");
        printf("6 - Fechar determinada caixa\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);


        switch (opc){
            case 1:
                continuar_simulacao(supermercado);
                break;
            case 2:
                estatisticas(supermercado->estatisticas);
                break;
            case 3:
                mudarCaixa(supermercado);
                break;
            case 4:
                inserirCaixa(supermercado->lista_caixas, supermercado->lista_funcionarios);
                ordenarCaixas(supermercado);
                break;
            case 5:
                pesquisarPessoaCaixa(supermercado->lista_caixas);
                break;
            case 6:
                fecharCaixa(supermercado->lista_caixas);
                break;
            case 0:
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

        NODE *node = supermercado->lista_caixas->head;
        while (node != NULL){
            CAIXA *caixa = (CAIXA *) node->info;
            printf("Caixa %s | Numero de Clientes %d\n", caixa->codigo, caixa->clientes->N_elements);
            node = node->next;
        }



    } while (opc != 0);
    gravarDadosSimulacao();

    exit(0);
}