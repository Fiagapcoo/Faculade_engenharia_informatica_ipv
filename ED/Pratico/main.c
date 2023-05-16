#include "header.h"
int main() {

    /* initialize random seed: */
    srand (time(NULL));


    LISTA *lista_produtos = carregarProdutos();
    LISTA *lista_funcionarios = carregarFuncionarios();
    LISTA *lista_clientes = carregarClientes();
    LISTA *lista_caixas = criar_Lista();








    SUPERMERCADO *supermercado = (SUPERMERCADO *) malloc(sizeof(SUPERMERCADO));
    if (supermercado == NULL) {
        printf("Erro ao alocar memoria.");
        exit(1);
    }

    supermercado->lista_produtos = lista_produtos;
    supermercado->lista_clientes = lista_clientes;
    supermercado->lista_funcionarios = lista_funcionarios;
    supermercado->lista_caixas = lista_caixas;


    menu(supermercado);
    return 0;
}