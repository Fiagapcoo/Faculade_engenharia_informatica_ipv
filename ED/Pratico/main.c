#include "header.h"
int main() {



    LISTA *lista_produtos = carregarProdutos();
    LISTA *lista_funcionarios = carregarFuncionarios();
    LISTA *lista_clientes = carregarClientes();








    SUPERMERCADO *supermercado = (SUPERMERCADO *) malloc(sizeof(SUPERMERCADO));
    if (supermercado == NULL) {
        printf("Erro ao alocar memoria.");
        exit(1);
    }

    supermercado->lista_produtos = lista_produtos;
    supermercado->lista_clientes = lista_clientes;
    supermercado->lista_funcionarios = lista_funcionarios;


    menu(supermercado);
    return 0;
}
