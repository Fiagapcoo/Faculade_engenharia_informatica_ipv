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
//estruturas
typedef struct funcionario {
    char codigo[6];
    char *nome;
} FUNCIONARIO;


typedef struct clientes {
    char codigo[7];
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


//acaba aqui as estruturas


//funcoes


PRODUTOS *criarProduto();


CLIENTES *criarCliente();


FUNCIONARIO *criarFuncionarios();


LISTA *carregarProdutos();


LISTA *carregarFuncionarios();


LISTA *carregarClientes();


LISTA *criar_Lista();


void adicionar_Fila(FILA *fila, void *info);


void adicionar_Lista(LISTA *lista, void *info);


int aleatorio(int min, int max);


NODE *get_Lista(LISTA *lista, int posicao);


void simulacao(SUPERMERCADO *supermercado);


void continuar_simulacao(SUPERMERCADO *supermercado);


void estatisticas(SUPERMERCADO *supermercado);


NODE * create_node(void *info);


void enfileirar(FILA *fila, void *info);


void *desenfileirar(FILA *fila);


void pesquisarPessoaCaixa(LISTA *lista_caixas);


void fecharCaixa(LISTA *lista_caixas);


int totalCLientes(LISTA *lista_caixas);


int compareCaixas(const void* a, const void* b);


void ordenarCaixas(SUPERMERCADO* supermercado);


void inserirCaixa(LISTA *lista_caixas, LISTA *lista_funcionarios);


void gravar_dados(SUPERMERCADO *supermercado);


void gravar_historico(char *data);


CLIENTES* searchClienteInCaixas(SUPERMERCADO* supermercado, const char* clienteCode);


void mudarCaixa(SUPERMERCADO* supermercado);


void menu(SUPERMERCADO *supermercado);


void gravarDadosSimulacao();
//acaba aqui as funcoes
#endif //TRABALHOPRATICO_HEADER_Hx\
