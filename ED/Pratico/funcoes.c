#include "header.h"

PRODUTOS *criarProduto(){
    PRODUTOS *produto = (PRODUTOS *) malloc(sizeof(PRODUTOS));
    if (produto == NULL) {
        printf("Erro ao alocar memoria.");
        return NULL;
    }
    return produto;
}
LISTA *carregarProdutos() {
    LISTA *lista_produtos = criar_Lista();

    if(lista_produtos == NULL)
        return NULL;
    FILE *fProdutos = fopen("produtos.txt", "r");
    if (fProdutos == NULL) {
        printf("Erro ao abrir o ficheiro produtos.");
        exit(1);
    }

    char linha[MAX_LINHA];
    int i = 0;

    while (fgets(linha, MAX_LINHA, fProdutos) != NULL) {
        PRODUTOS *produto = criarProduto();
       // printf("Linha: %s", linha);
        if (produto == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            printf("Erro ao ler o codigo do produto.");
            exit(1);
        }
        strcpy(produto->codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o nome do produto.");
            exit(1);
        }
        produto->nome = malloc(strlen(token) + 1);
        if (produto->nome == NULL) {
            printf("Erro ao alocar memoria para o nome do produto.");
            exit(1);
        }
        strcpy(produto->nome, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o preco do produto.");
            exit(1);
        }
        produto->preco = atof(token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o tempo de compra do produto.");
            exit(1);
        }
        produto->TCompra = atof(token);

        token = strtok(NULL, "\n");
        if (token == NULL) {
            printf("Erro ao ler o tempo de caixa do produto.");
            exit(1);
        }
        produto->TCaixa = atof(token);

        adicionar_Lista(lista_produtos, produto);
    }
    fclose(fProdutos);

    printf("Produtos carregados com sucesso.\n");
    return lista_produtos;

}

FUNCIONARIO *carregarFuncionarios(){
    FILE *fFuncionario = fopen("funcionarios.txt", "r");

    if (fFuncionario == NULL){
        printf("Erro ao abrir o ficheiro");
        exit(1);
    }

    char linha[MAX_LINHA];
    int i = 0;
    FUNCIONARIO *funcionario = NULL;

    while (fgets(linha, MAX_LINHA, fFuncionario)){
      //  printf("Linha: %s", linha);
        funcionario = realloc(funcionario, sizeof(FUNCIONARIO) * (i + 1));
        if (funcionario == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            printf("Erro ao ler o codigo do funcionario.");
            exit(1);
        }
        strcpy(funcionario[i].codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o nome do funcionario.");
            exit(1);
        }

        funcionario[i].nome = malloc(strlen(token) + 1);
        if (funcionario[i].nome == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }
        strcpy(funcionario[i].nome, token);
        i++;
    }
    fclose(fFuncionario);
    printf("Funcionarios carregados com sucesso!\n");
    return funcionario;
}

CLIENTES *carregarClientes(){
FILE *fClientes = fopen("clientes.txt", "r");

    if (fClientes == NULL){
        printf("Erro ao abrir o ficheiro");
        exit(1);
    }

    char linha[MAX_LINHA];
    int i = 0;
    CLIENTES *clientes = NULL;

    while (fgets(linha, MAX_LINHA, fClientes)){
        //printf("Linha: %s", linha);
        clientes = realloc(clientes, sizeof(CLIENTES) * (i + 1));
        if (clientes == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            printf("Erro ao ler o codigo do cliente.");
            exit(1);
        }
        strcpy(clientes[i].codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o nome do cliente.");
            exit(1);
        }


        clientes[i].nome = malloc(strlen(token) + 1);
        if (clientes[i].nome == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }
        strcpy(clientes[i].nome, token);
        i++;
    }
    fclose(fClientes);
    printf("Clientes carregados com sucesso!\n");
    return clientes;
}

LISTA *criar_Lista(){
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if(lista == NULL){
        return NULL;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->N_elements = 0;
    return lista;
}


void adicionar_Fila(FILA *fila, void *info){
    if(!fila || !info) return;
    NODE *node = (NODE*) malloc(sizeof(NODE));

    node->info = info;

    node->next = NULL;

    if(!fila->head) {
        fila->head = fila->tail = node;
        fila->N_elements++;
        return;
    }
        fila->tail->next = node;
        fila->tail = node;
        fila->N_elements++;

}

void adicionar_Lista(LISTA *lista, void *info){
    if(!lista || !info) return;
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->next = lista->head;
    node->info = info;
    lista->head = node;
    lista->N_elements++;
}

int aleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int obter_linhas_ficheiro(char *nome_ficheiro) {
    FILE *f = fopen(nome_ficheiro, "r");
    if (f == NULL) {
        printf("Erro ao abrir o ficheiro %s", nome_ficheiro);
        exit(1);
    }

    int linhas = 0;
    char linha[MAX_LINHA];
    while (fgets(linha, MAX_LINHA, f) != NULL) {
        linhas++;
    }
    fclose(f);

    return linhas;
}

NODE *get_Lista(LISTA *lista, int posicao) {
    if (lista == NULL || lista->head == NULL || posicao < 0 || posicao >= lista->N_elements) {
        return NULL;
    }
    NODE *node = lista->head;
    for (int i = 0; i < posicao; i++) {
        node = node->next;
    }
    return node;
}

void remover_da_Fila(FILA *fila){
    

}
void remover_da_Lista(LISTA *lista){

}
void mudar_de_caixa(CAIXA *caixa, CAIXA *nova_caixa){


}

void simulacao(SUPERMERCADO *supermercado) {
    printf("Simulacao iniciada!\n");

    LISTA *listaProdutos = supermercado->lista_produtos;
    LISTA *listaClientes = supermercado->lista_clientes;
    LISTA *listaFuncionarios = supermercado->lista_funcionarios;

    float total_price = 0;

    int num_funcionarios = listaFuncionarios->N_elements;

    //int num_caixas_abertas = aleatorio(1, 10);
    int num_caixas_abertas = 3;
    printf("Numero de caixas abertas: %d\n", num_caixas_abertas);

    LISTA *listaCaixas = criar_Lista();

    for (int i = 0; i < num_caixas_abertas; i++) {
        CAIXA *caixa = (CAIXA *) malloc(sizeof(CAIXA));
        sprintf(caixa->codigo, "CX_%d", i);
        caixa->clientes = criar_Lista();
        caixa->funcionarios = criar_Lista();
        caixa->aberta = 1;

        int index = aleatorio(0, num_funcionarios - 1);
        NODE *funcionario_node = (NODE *) get_Lista(listaFuncionarios, index);
        FUNCIONARIO *funcionario = funcionario_node->info;
        adicionar_Lista(caixa->funcionarios, funcionario);

        adicionar_Lista(listaCaixas, caixa);

    }
    //int num_clientes = aleatorio(1, 100);
    int num_clientes = 4;
    printf("Numero de clientes: %d\n", num_clientes);

    for (int i = 0; i < num_clientes; i++) {
        NODE *cliente_node = (NODE *) get_Lista(listaClientes, i);
        if(cliente_node == NULL){
            printf("Cliente não encontrado %d", i+1);
        }
        CLIENTES *cliente = cliente_node->info;

      //  int num_produtos = aleatorio(1, listaProdutos->N_elements);
        int num_produtos = 4;



        LISTA *produtos_a_comprar = criar_Lista();

        for (int j = 0; j < num_produtos; j++) {
            //int index = aleatorio(0, listaProdutos->N_elements - 1);
            int index = 3;
            NODE *produto_node= (NODE *) get_Lista(listaProdutos, index);
            PRODUTOS *produto = produto_node->info;
            adicionar_Lista(produtos_a_comprar, produto);
            total_price += produto->preco;
        }


        int min_customers = INT_MAX;
        CAIXA *selected_caixa = NULL;
        NODE *node = listaCaixas->head;
        while (node != NULL) {
            CAIXA *caixa = (CAIXA *) node->info;
            if (caixa->clientes->N_elements < min_customers) {
                min_customers = caixa->clientes->N_elements;
                selected_caixa = caixa;
            }
            node = node->next;
        }

        adicionar_Fila(selected_caixa->clientes, cliente);


        printf("Caixa %s | Cliente %s | Produtos:", selected_caixa->codigo, cliente->nome);
        NODE *node_produto = produtos_a_comprar->head;
        while (node_produto != NULL) {
            PRODUTOS *produto = (PRODUTOS *) node_produto->info;
            printf(" Nome: %s | preco: (%.2f€) | TCompra: %f, | TCaixa: %f", produto->nome, produto->preco, produto->TCompra, produto->TCaixa);
            node_produto = node_produto->next;
        }

    }
    printf("\n");
    printf("Preco Total: %.2f\n", total_price);


    printf("Lista de Caixas:\n");
    NODE *node = listaCaixas->head;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        printf("Codigo: %s  | Numero de Clientes: %d\n", caixa->codigo, caixa->clientes->N_elements);
        node = node->next;
    }

}


void estatisticas(SUPERMERCADO *supermercado){

}

void mudarCaixa(SUPERMERCADO *supermercado){


}

void inserirCaixas(SUPERMERCADO *supermercado){

}

void pesquisarPessoaCaixa(CAIXA *caixa){
    char *codigo;
    printf("Insira o codigo do cliente que pretende pesquisar: ");
    scanf("%s", codigo);

    NODE *node = caixa->clientes->head;
while (node->next != NULL) {
        CLIENTES *cliente = (CLIENTES *) node->info;
        if(strcmp(cliente->codigo, codigo) == 0){
            printf("Cliente %s encontrado na caixa %s", cliente->nome, caixa->codigo);
            return;
        }
        node = node->next;
    }
    printf("Cliente nao encontrado na caixa %s", caixa->codigo);





}

void gravar_dados(SUPERMERCADO *supermercado) {

}