//
// Created by filipe on 29-03-2023.
//
#ifndef TRABALHOPRATICO_HEADER_H
#define TRABALHOPRATICO_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_MAX 2147483647
#define MAX_LINHA 2048

typedef struct funcionario {
    char codigo[6];
    char *nome;
} FUNCIONARIO;

typedef struct clientes {
    char codigo[6];
    char *nome;
} CLIENTES;

typedef struct produtos {
    char codigo[6];
    char *nome;
    float preco; //preco do produto
    float TCompra;//tempo q o consumidor leva na procura do produto em segundos
    float TCaixa; //tempo de passar o produto na caixa em segundos
} PRODUTOS;

typedef struct node {
    void *info;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
    int N_elements;
} LISTA, FILA;




typedef struct{
    LISTA *lista_produtos;
    LISTA  *lista_clientes;
    LISTA *lista_funcionarios;
}SUPERMERCADO;

typedef struct compra {
    CLIENTES *cliente;
    LISTA *produtos;
} COMPRA;


typedef struct caixa {
    char codigo[6];
    LISTA *funcionarios;
    FILA *clientes;
    int aberta; //0 - fechada, 1 - aberta
} CAIXA;


void menu(SUPERMERCADO *supermercado);

LISTA *carregarProdutos();
FUNCIONARIO *carregarFuncionarios();
CLIENTES *carregarClientes();

int aleatorio(int min, int max);

LISTA *criar_Lista();

void adicionar_Lista(LISTA *lista, void *info);

int obter_linhas_ficheiro(char *nome_ficheiro);

NODE *get_Lista(LISTA *lista, int posicao);

void print_caixa_info(CAIXA *caixa);

void simulacao(SUPERMERCADO *supermercado);

void estatisticas(SUPERMERCADO *supermercado);

void mudarCaixa(SUPERMERCADO *supermercado);

void inserirCaixas(SUPERMERCADO *supermercado);

void pesquisarPessoaCaixa(CAIXA *caixa);

void gravar_dados(SUPERMERCADO *supermercado);



#endif //TRABALHOPRATICO_HEADER_Hx\