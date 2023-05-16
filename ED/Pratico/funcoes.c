#include "header.h"

PRODUTOS *criarProduto(){
    PRODUTOS *produto = (PRODUTOS *) malloc(sizeof(PRODUTOS));
    if (produto == NULL) {
        printf("Erro ao alocar memoria.");
        gravar_historico("Erro ao criar produto");
        return NULL;
    }
    gravar_historico("Criar produto");
    return produto;
}

CLIENTES *criarCliente(){
    CLIENTES *cliente = (CLIENTES *) malloc(sizeof(CLIENTES));
    if (cliente == NULL) {
        gravar_historico("Erro ao criar cliente");
        printf("Erro ao alocar memoria.");
        return NULL;
    }
    gravar_historico("Criar cliente");
    return cliente;
}

FUNCIONARIO *criarFuncionarios(){
    FUNCIONARIO *funcionario = (FUNCIONARIO *) malloc(sizeof(FUNCIONARIO));
    if (funcionario == NULL) {
        gravar_historico("Erro ao criar funcionario");
        printf("Erro ao alocar memoria.");
        return NULL;
    }
    gravar_historico("Criar funcionario");
    return funcionario;
}


LISTA *carregarProdutos() {
    LISTA *lista_produtos = criar_Lista();

    if(lista_produtos == NULL){
        gravar_historico("Erro ao criar lista de produtos.");
        return NULL;
    }

    FILE *fProdutos = fopen("produtos.txt", "r");
    if (fProdutos == NULL) {
        gravar_historico("Erro ao abrir o ficheiro produtos.");
        printf("Erro ao abrir o ficheiro produtos.");
        exit(1);
    }

    char linha[MAX_LINHA];

    while (fgets(linha, MAX_LINHA, fProdutos) != NULL) {
        PRODUTOS *produto = criarProduto();
        // printf("Linha: %s", linha);
        if (produto == NULL) {
            gravar_historico("Erro ao criar produto.");
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            gravar_historico("Erro ao ler o codigo do produto.");
            printf("Erro ao ler o codigo do produto.");
            exit(1);
        }
        strcpy(produto->codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            gravar_historico("Erro ao ler o nome do produto.");
            printf("Erro ao ler o nome do produto.");
            exit(1);
        }
        produto->nome = malloc(strlen(token) + 1);
        if (produto->nome == NULL) {
            gravar_historico("Erro ao alocar memoria para o nome do produto.");
            printf("Erro ao alocar memoria para o nome do produto.");
            exit(1);


        }
        strcpy(produto->nome, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            gravar_historico("Erro ao ler o preco do produto.");
            printf("Erro ao ler o preco do produto.");
            exit(1);
        }
        produto->preco = atof(token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            gravar_historico("Erro ao ler o tempo de compra do produto.");
            printf("Erro ao ler o tempo de compra do produto.");
            exit(1);
        }
        produto->TCompra = atof(token);

        token = strtok(NULL, "\n");
        if (token == NULL) {
            gravar_historico("Erro ao ler o tempo de caixa do produto.");
            printf("Erro ao ler o tempo de caixa do produto.");
            exit(1);
        }
        produto->TCaixa = atof(token);

        adicionar_Lista(lista_produtos, produto);

    }
    fclose(fProdutos);

    printf("Produtos carregados com sucesso.\n");
    gravar_historico("Produtos carregados para a lista");
    return lista_produtos;

}

LISTA *carregarFuncionarios(){

    LISTA *lista_funcionarios = criar_Lista();

    if(lista_funcionarios == NULL)
        return NULL;

    FILE *fFuncionario = fopen("funcionarios.txt", "r");

    if (fFuncionario == NULL){
        printf("Erro ao abrir o ficheiro");
        exit(1);
    }

    char linha[MAX_LINHA];

    while (fgets(linha, MAX_LINHA, fFuncionario)){
        FUNCIONARIO *funcionario = criarFuncionarios();
        //  printf("Linha: %s", linha);
        if (funcionario == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            printf("Erro ao ler o codigo do funcionario.");
            exit(1);
        }
        strcpy(funcionario->codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o nome do funcionario.");
            exit(1);
        }

        funcionario->nome = malloc(strlen(token) + 1);
        if (funcionario->nome == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }
        strcpy(funcionario->nome, token);
        adicionar_Lista(lista_funcionarios, funcionario);
    }
    fclose(fFuncionario);
    printf("Funcionarios carregados com sucesso!\n");
    gravar_historico("Funcionarios carregados para a lista");
    return lista_funcionarios;
}

LISTA *carregarClientes(){
    LISTA *lista_clientes = criar_Lista();

    if(lista_clientes == NULL){
        gravar_historico("Erro ao criar a lista de clientes");
        return NULL;
    }

    FILE *fClientes = fopen("clientes.txt", "r");

    if (fClientes == NULL){
        printf("Erro ao abrir o ficheiro");
        exit(1);
    }

    char linha[MAX_LINHA];
    int i = 0;

    while (fgets(linha, MAX_LINHA, fClientes)){
        CLIENTES *clientes = criarCliente();
        //printf("Linha: %s", linha);
        if (clientes == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }

        char *token = strtok(linha, "\t");
        if (token == NULL) {
            printf("Erro ao ler o codigo do cliente.");
            exit(1);
        }
        strcpy(clientes->codigo, token);

        token = strtok(NULL, "\t");
        if (token == NULL) {
            printf("Erro ao ler o nome do cliente.");
            exit(1);
        }


        clientes->nome = malloc(strlen(token) + 1);
        if (clientes->nome == NULL) {
            printf("Erro ao alocar memoria.");
            exit(1);
        }
        strcpy(clientes->nome, token);
        adicionar_Lista(lista_clientes, clientes);
    }
    fclose(fClientes);
    printf("Clientes carregados com sucesso!\n");
    gravar_historico("Clientes carregados para a lista");
    return lista_clientes;
}

LISTA *criar_Lista(){
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if(lista == NULL){
        gravar_historico("Erro ao criar lista");
        return NULL;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->N_elements = 0;
    gravar_historico("Foi criada uma lista generica");
    return lista;
}


void adicionar_Fila(FILA *fila, void *info){
    if(!fila || !info) {
        gravar_historico("Erro ao adicionar a fila");
        return;
    }
    NODE *node = (NODE*) malloc(sizeof(NODE));

    node->info = info;

    node->next = NULL;

    if(!fila->head) {
        fila->head = fila->tail = node;
        fila->N_elements++;
        gravar_historico("Foi adicionado um elemento a fila");
        return;
    }
    fila->tail->next = node;
    fila->tail = node;
    fila->N_elements++;

}

void adicionar_Lista(LISTA *lista, void *info){
    if(!lista || !info) {
        gravar_historico("Erro ao adicionar a lista");
        return;
    }
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->next = lista->head;
    node->info = info;
    lista->head = node;
    lista->N_elements++;
    gravar_historico("Foi adicionado um elemento a lista");
}

int aleatorio(int min, int max) {
    gravar_historico("Foi gerado um numero aleatorio");
    return rand() % (max - min + 1) + min;
}

NODE *get_Lista(LISTA *lista, int posicao) {
    if (lista == NULL || lista->head == NULL || posicao < 0 || posicao >= lista->N_elements) {
        gravar_historico("Erro ao obter a lista");
        return NULL;
    }
    NODE *node = lista->head;
    for (int i = 0; i < posicao; i++) {
        node = node->next;
    }
    gravar_historico("Foi obtido um elemento da lista");
    return node;
}

void remover_da_Fila(FILA *fila){

    if(!fila || !fila->head){
        gravar_historico("Erro ao remover da fila");
        return;
    }
    NODE *node = fila->head;
    fila->head = fila->head->next;
    free(node);
    fila->N_elements--;
    gravar_historico("Foi removido um elemento da fila");



}
void remover_da_Lista(LISTA *lista){

    if(!lista || !lista->head){
        gravar_historico("Erro ao remover da lista");
        return;
    }
    NODE *node = lista->head;
    while(node->next->next != NULL){
        node = node->next;
    }
    node->next = NULL;
    free(node);
    lista->N_elements--;
    gravar_historico("Foi removido um elemento da lista");

}

void eliminar_caixa(CAIXA *caixa){

    if(!caixa) return;
    free(caixa->clientes);
    free(caixa->funcionarios);
    free(caixa);

}


void simulacao(SUPERMERCADO *supermercado) {
    printf("Simulacao iniciada!\n");
    gravar_historico("Simulacao iniciada");

    LISTA *listaProdutos = supermercado->lista_produtos;
    LISTA *listaClientes = supermercado->lista_clientes;
    LISTA *listaFuncionarios = supermercado->lista_funcionarios;
    

    float total_price = 0, tempo_medio_espera = 0;

    int num_funcionarios = listaFuncionarios->N_elements;

    //int num_caixas_abertas = aleatorio(1, 10);
    int num_caixas_abertas = 3;
    printf("Numero de caixas abertas: %d\n", num_caixas_abertas);

    int num_clientes = aleatorio(1, 100);

    printf("Numero de clientes: %d\n", num_clientes);

    if (num_clientes > NUM_CLIENTES_ADD) {
        int resposta;
        printf("Deseja abrir mais 1 caixa? (1 - Sim, 0 - Nao)\n");
        scanf("%d", &resposta);
        while (resposta != 1 && resposta != 0) {
            printf("Opcao invalida. Deseja abrir mais 1 caixa? (1 - Sim, 0 - Nao)\n");
            scanf("%d", &resposta);
        }
        if (resposta == 1) {
            num_caixas_abertas++;
        }
    }
    if (num_clientes < NUM_CLIENTES_SUB){
        int resposta;
        printf("Deseja fechar 1 caixa? (1 - Sim, 0 - Nao)\n");
        scanf("%d", &resposta);
        while (resposta != 1 && resposta != 0) {
            printf("Opcao invalida. Deseja fechar 1 caixa? (1 - Sim, 0 - Nao)\n");
            scanf("%d", &resposta);
        }
        if (resposta == 1) {
            num_caixas_abertas--;
        }
    }


    for (int i = 1; i <= num_caixas_abertas; i++) {
        CAIXA *caixa = (CAIXA *) malloc(sizeof(CAIXA));
        sprintf(caixa->codigo, "CX_%d", i);
        caixa->clientes = criar_Lista();
        caixa->funcionarios = (FUNCIONARIO *) criar_Lista();
        caixa->aberta = 1;

        int index = aleatorio(0, num_funcionarios - 1);
        NODE *funcionario_node = (NODE *) get_Lista(listaFuncionarios, index);
        FUNCIONARIO *funcionario = funcionario_node->info;
        caixa->funcionarios = funcionario;

        adicionar_Lista(supermercado->lista_caixas, caixa);

    }


    for (int i = 0; i < num_clientes; i++) {

        NODE *cliente_node = (NODE *) get_Lista(listaClientes, i);
        if(cliente_node == NULL){
            printf("Cliente não encontrado %d", i+1);
        }
        CLIENTES *cliente = cliente_node->info;
        char *str_historico = (char *) malloc(sizeof(char) * 300);
        char *nome_cli = (char *)malloc(sizeof(char)*100);
        usleep(aleatorio(1000, 3000));
        strncpy(nome_cli, cliente->nome, strlen(cliente->nome) - 1);
        sprintf(str_historico, "Cliente: %s entrou no supermercado", nome_cli);
        gravar_historico(str_historico);

        //  int num_produtos = aleatorio(1, listaProdutos->N_elements);
        int num_produtos = 4;



        LISTA *produtos_a_comprar = criar_Lista();

        //int index = aleatorio(0, listaProdutos->N_elements - 1);
        int index = 3;
        for (int j = 0; j < num_produtos; j++){

            NODE *produto_node= (NODE *) get_Lista(listaProdutos, index);
            PRODUTOS *produto = produto_node->info;
            adicionar_Lista(produtos_a_comprar, produto);
            total_price += produto->preco;
            tempo_medio_espera += produto->TCaixa;
        }
        tempo_medio_espera = (tempo_medio_espera / (num_produtos - index));






        int min_customers = INT_MAX;
        CAIXA *selected_caixa = NULL;
        NODE *node = supermercado->lista_caixas->head;
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
    printf("tempo  medio de espera: %.2f\n", tempo_medio_espera);


    printf("Lista de Caixas:\n");
    NODE *node = supermercado->lista_caixas->head;
    NODE *node_cli = supermercado->lista_clientes->head;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        CLIENTES *cli = (CLIENTES *) node_cli->info;
        printf("Codigo: %s  | Numero de Clientes: %d\n", caixa->codigo, caixa->clientes->N_elements);
        printf("\nCodigo cliente %s \n", cli->codigo);
        node = node->next;
    }

}

void continuar_simulação(SUPERMERCADO *supermercado){
    LISTA *lista_caixas = supermercado->lista_caixas;
    NODE *node = lista_caixas->head;

    while(node != NULL){
        CAIXA *caixa = (CAIXA *) node->info;
        while(caixa->clientes->head->next != NULL){
            CLIENTES *cliente = (CLIENTES *) caixa->clientes->head->info;
            printf("Cliente %s\n", cliente->nome);
            caixa->clientes->head = caixa->clientes->head->next;
        }
        node = node ->next;
    }

}


void estatisticas(SUPERMERCADO *supermercado){

}

NODE * create_node(void *info) {
    NODE *node = (NODE *) malloc(sizeof(NODE));
    node->info = info;
    node->next = NULL;
    return node;
}

void enfileirar(FILA *fila, void *info) {
    NODE *node = create_node(info);
    if (fila->head == NULL) {
        fila->head = node;
        fila->tail = node;
    } else {
        fila->tail->next = node;
        fila->tail = node;
    }
    fila->N_elements++;
}

void *desenfileirar(FILA *fila) {
    if (fila->head == NULL) {
        return NULL; // fila vazia
    }
    NODE *node = fila->head;
    void *info = node->info;
    fila->head = node->next;
    if (fila->head == NULL) {
        fila->tail = NULL; // fila ficou vazia
    }
    fila->N_elements--;
    free(node);
    return info;
}

void pesquisarPessoaCaixa(LISTA *lista_caixas){
    printf("Qual o codigo da Pessoa?");
    char codigo[7];
    scanf("%6f", codigo);

    printf("Qual o codigo do caixa, (exCX_1)?");
    char codigo_caixa[5];
    scanf("%4s", codigo_caixa);

    NODE *node_caixas = lista_caixas->head;
    while (node_caixas != NULL){
        CAIXA *caixa = (CAIXA*) node_caixas->info;
        if(strcmp(caixa->codigo, codigo_caixa) == 0){
            NODE *node_clientes = caixa->clientes->head;
            while(node_clientes != NULL){
                CLIENTES *cliente = (CLIENTES*) node_clientes->info;
                if(strcmp(cliente->codigo, codigo) == 0){
                    printf("Cliente %s encontrado no caixa %s", cliente->nome, caixa->codigo);
                    return;
                }
                node_clientes = node_clientes->next;
            }
        }
    }


}

void fecharCaixa(LISTA *lista_caixas) {
    printf("Digite o codigo da caixa que pretende fechar (CX_1): ");
    char codigo[5];
    scanf("%4s", codigo);

    CAIXA *caixa_fechada = NULL;
    int caixas_abertas = 0;
    NODE *node = lista_caixas->head;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        if (strcmp(caixa->codigo, codigo) == 0) {
            caixa_fechada = caixa;
            caixa->aberta = 0;
            gravar_historico("Caixa fechada");
        }
        else if (caixa->aberta) {
            caixas_abertas++;
        }
        node = node->next;
    }

    if (caixa_fechada == NULL) {
        printf("Nao existe uma caixa com esse codigo.\n");
        return;
    }
    if (caixas_abertas == 0) {
        printf("Nao existem caixas abertas.\n");
        return;
    }

    FILA *fila_clientes = caixa_fechada->clientes;
    int num_clientes = fila_clientes->N_elements;
    int num_clientes_por_caixa = num_clientes / caixas_abertas;
    int clientes_restantes = num_clientes % caixas_abertas;

    node = lista_caixas->head;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        if (caixa->aberta && caixa != caixa_fechada) {
            FILA *fila_caixa = caixa->clientes;
            for (int i = 0; i < num_clientes_por_caixa; i++) {
                CLIENTES *cliente = (CLIENTES *) desenfileirar(fila_clientes);
                enfileirar(fila_caixa, cliente);
            }
            if (clientes_restantes > 0) {
                CLIENTES *cliente = (CLIENTES *) desenfileirar(fila_clientes);
                enfileirar(fila_caixa, cliente);
                clientes_restantes--;
            }
        }
        node = node->next;
    }
}




void gravar_dados(SUPERMERCADO *supermercado) {


}

void gravar_historico(char *data){



    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);

    char date_str[11];
    char time_str[9];

    strftime(date_str, sizeof(date_str), "%d-%m-%Y", tm);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", tm);

    FILE *fp = fopen("historico.csv", "a");
    if (fp == NULL){
        gravar_historico("Erro ao abrir o ficheiro");
        return;
    }

    fprintf(fp, "%s;%s %s\n", data, date_str, time_str);
    fclose(fp);

}