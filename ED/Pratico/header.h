//
// Created by filipe on 29-03-2023.
//
#ifndef TRABALHOPRATICO_HEADER_H
#define TRABALHOPRATICO_HEADER_H



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_MAX 2147483647
#define MAX_LINHA 2048
#define NUM_CLIENTES_ADD 10
#define NUM_CLIENTES_SUB 5

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
    LISTA *lista_caixas;
}SUPERMERCADO;

typedef struct compra {
    CLIENTES *cliente;
    LISTA *produtos;
} COMPRA;


typedef struct caixa {
    char codigo[6];
    FUNCIONARIO *funcionarios;
    FILA *clientes;
    int aberta; //0 - fechada, 1 - aberta
} CAIXA;



void gravar_historico(char *);

void menu(SUPERMERCADO *supermercado);

LISTA *carregarProdutos();
LISTA *carregarFuncionarios();
LISTA *carregarClientes();

int aleatorio(int min, int max);

LISTA *criar_Lista();

void adicionar_Lista(LISTA *lista, void *info);


NODE *get_Lista(LISTA *lista, int posicao);

void continuar_simulação(SUPERMERCADO *supermercado);

void simulacao(SUPERMERCADO *supermercado);

void estatisticas(SUPERMERCADO *supermercado);



void inserirCaixas(SUPERMERCADO *supermercado);

void pesquisarPessoaCaixa(LISTA *lista_caixas);

void gravar_dados(SUPERMERCADO *supermercado);

void fecharCaixa(LISTA *lista_caixas);

#endif //TRABALHOPRATICO_HEADER_Hx\
