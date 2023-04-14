#include "header.h"
int main() {

    FUNCIONARIO *funcionarios = carregarFuncionarios();
    CLIENTES *clientes = carregarClientes();

    LISTA *lista_produtos = carregarProdutos();
    LISTA *lista_funcionarios = criar_Lista();
    LISTA *lista_clientes = criar_Lista();

    char *nome_produtos = "produtos.txt";
    char *nome_funcionarios = "funcionarios.txt";
    char *nome_clientes = "clientes.txt";

    int n_funcionarios = obter_linhas_ficheiro(nome_funcionarios);
    int n_clientes = obter_linhas_ficheiro(nome_clientes);


    for (int i = 0; i < n_funcionarios; i++) {
        adicionar_Lista(lista_funcionarios, &funcionarios[i]);
    }
    for (int i = 0; i < n_clientes; i++) {
        adicionar_Lista(lista_clientes, &clientes[i]);
    }

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
