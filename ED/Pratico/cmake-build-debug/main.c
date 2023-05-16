#include "header.h"
int main() {
    PRODUTOS *produtos = carregarProdutos();
    FUNCIONARIO *funcionarios = carregarFuncionarios();
    CLIENTES *clientes = carregarClientes();

    LISTA *lista_produtos = criar_Lista();
    LISTA *lista_funcionarios = criar_Lista();
    LISTA *lista_clientes = criar_Lista();

    char *nome_produtos = "produtos.txt";
    char *nome_funcionarios = "funcionarios.txt";
    char *nome_clientes = "clientes.txt";

    int n_produtos = obter_linhas_ficheiro(nome_produtos);
    int n_funcionarios = obter_linhas_ficheiro(nome_funcionarios);
    int n_clientes = obter_linhas_ficheiro(nome_clientes);

    for (int i = 0; i < n_produtos; i++) {
        adicionar_Lista(lista_produtos, &produtos[i]);
    }
    for (int i = 0; i < n_funcionarios; i++) {
        adicionar_Lista(lista_funcionarios, &funcionarios[i]);
    }
    for (int i = 0; i < n_clientes; i++) {
        adicionar_Lista(lista_clientes, &produtos[i]);
    }


   menu(lista_produtos, lista_clientes, lista_funcionarios);
    return 0;
}
