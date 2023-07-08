//
// Created by filipe on 29-03-2023.
//

#include "header.h"

int numClientes = 0;
int numProdutosVendidos = 0;
int numFuncionarios = 0;
float tempoMedioEspera = 0;

//alocar memoria para o produto
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

//alocar memoria para o cliente
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

//alocar memoria para o funcionario
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

//carregar todos os produtos do ficheiro para a lista
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

//carregar todos os funcionarios do ficheiro para a lista
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

//carregar todos os clientes do ficheiro para a lista
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

//criar uma lista generica
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

//adicionar um elemento a fila
void adicionar_Fila(FILA *fila, void *info) {
    if (!fila || !info) {
        gravar_historico("Erro ao adicionar à lista");
        return;
    }

    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (!node) {
        gravar_historico("Erro ao alocar memória para o nó");
        return;
    }

    node->info = info;
    node->next = NULL;

    if (!fila->head) {
        fila->head = node;
        fila->tail = node;
    } else {
        fila->tail->next = node;
        fila->tail = node;
    }

    fila->N_elements++;
}

//adicionar um elemento a lista
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

//gerar um numero aleatorio
int aleatorio(int min, int max) {
    gravar_historico("Foi gerado um numero aleatorio");
    return rand() % (max - min + 1) + min;
}

//obter um elemento da lista
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

//simular o supermercado
void simulacao(SUPERMERCADO *supermercado, int iterator) {
    if(!supermercado) {
        gravar_historico("Erro ao iniciar a simulacao");
        return;
    }
    printf("Simulacao iniciada!\n");
    gravar_historico("Simulacao iniciada");

    LISTA *listaProdutos = supermercado->lista_produtos;
    LISTA *listaClientes = supermercado->lista_clientes;
    LISTA *listaFuncionarios = supermercado->lista_funcionarios;



    int num_funcionarios = listaFuncionarios->N_elements;

    int num_caixas_abertas;

    if(iterator == 0)
        num_caixas_abertas = aleatorio(1, 10);
    else
        num_caixas_abertas = 0;



    printf("Numero de caixas abertas: %d\n", num_caixas_abertas);

    int num_clientes = aleatorio(1, 30);
    numClientes += num_clientes;

    printf("Numero de clientes: %d\n", num_clientes);
if(iterator == 0) {
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
    if (num_clientes < NUM_CLIENTES_SUB) {
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
}

    for (int i = 1; i <= num_caixas_abertas; i++) {
        CAIXA *caixa = (CAIXA *) malloc(sizeof(CAIXA));
        sprintf(caixa->codigo, "CX_%d", i);
        caixa->clientes = criar_Lista();
        caixa->funcionarios = (FUNCIONARIO *) criar_Lista();
        caixa->aberta = 1;

        int index = aleatorio(0, num_funcionarios - 1);
        numFuncionarios += index;
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
        //usleep(aleatorio(1000, 3000));
        strncpy(nome_cli, cliente->nome, strlen(cliente->nome) - 1);
        sprintf(str_historico, "Cliente: %s entrou no supermercado", nome_cli);
        gravar_historico(str_historico);

        //int num_produtos = aleatorio(1, listaProdutos->N_elements);
        int num_produtos = 2;//aleatorio(0, listaProdutos->N_elements-1);
        numProdutosVendidos += num_produtos;

        int tempoEspera = 0;

        LISTA *produtos_a_comprar = criar_Lista();

        int index;

        for (int j = 0; j < num_produtos; j++){
            index = aleatorio(0, listaProdutos->N_elements-1);
            NODE *produto_node= (NODE *) get_Lista(listaProdutos, index);
            PRODUTOS *produto = produto_node->info;
            adicionar_Lista(produtos_a_comprar, produto);

            tempoEspera += produto->TCaixa;
        }
        cliente->lista_compras = produtos_a_comprar;
        tempoMedioEspera = (tempoMedioEspera / (num_produtos - index));
        tempoMedioEspera += tempoMedioEspera/iterator+1;






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


    }
    printf("\n");



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

//calcula o lucro total do supermercado
float calcular_lucro(SUPERMERCADO *supermercado) {
    if(supermercado == NULL){
        printf("Supermercado não encontrado");
        return 0;
    }
    float lucroTotal = 0.0;
    LISTA *listaCaixas = supermercado->lista_caixas;
    NODE *nodeCaixa = listaCaixas->head;

    while (nodeCaixa != NULL) {
        CAIXA *caixa = nodeCaixa->info;
        FILA *FilaClientes = caixa->clientes;
        NODE *noClientesCaixa = FilaClientes->head;

        while (noClientesCaixa != NULL) {
            CLIENTES *cliente = noClientesCaixa->info;
            LISTA *listaCompras = cliente->lista_compras;
            NODE *noListaCompras = listaCompras->head;

            while (noListaCompras != NULL) {
                PRODUTOS *produto = noListaCompras->info;
                lucroTotal += produto->preco;
                noListaCompras = noListaCompras->next;
            }

            noClientesCaixa = noClientesCaixa->next;
        }

        nodeCaixa = nodeCaixa->next;
    }

    return lucroTotal;
}

//reset das caixas
void reset_caixas(SUPERMERCADO *supermercado) {
    if(supermercado == NULL){
        printf("Supermercado não encontrado");
        return;
    }

    LISTA *listaCaixas = supermercado->lista_caixas;
    NODE *nodeCaixa = listaCaixas->head;

    while (nodeCaixa != NULL) {
        CAIXA *caixa = nodeCaixa->info;
        FILA *FilaClientes = caixa->clientes;
        FilaClientes->head = NULL;
        FilaClientes->tail = NULL;
        FilaClientes->N_elements = 0;
        nodeCaixa = nodeCaixa->next;
    }
}

//remover cliente da lista de clientes
void remover_cliente(CLIENTES *cliente, LISTA *lista_clientes) {
    if(cliente == NULL || lista_clientes == NULL){
        printf("Cliente não encontrado");
        return;
    }
    NODE *current = lista_clientes->head;
    NODE *previous = NULL;

    while (current != NULL) {
        if (current->info == cliente) {
            if (previous == NULL) {
                lista_clientes->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == lista_clientes->tail) {
                lista_clientes->tail = previous;
            }

            free(current);
            lista_clientes->N_elements--;
            break;
        }

        previous = current;
        current = current->next;

    }
}

//continuar a simulação
void continuar_simulacao(SUPERMERCADO *supermercado) {
    if(supermercado == NULL){
        printf("Supermercado não encontrado");
        return;
    }
    char historico_string[100];

    printf("Continuação da simulação\n");
    int lucroSupermercado = calcular_lucro(supermercado);
    LISTA *listaCaixas = supermercado->lista_caixas;
    NODE *nodeCaixa = listaCaixas->head;

    while (nodeCaixa != NULL) {
        CAIXA *caixa = nodeCaixa->info;
        FILA *FilaClientes = caixa->clientes;
        NODE *noClientesCaixa = FilaClientes->head;

        while (noClientesCaixa != NULL) {
            NODE *nextNode = noClientesCaixa->next;

            CLIENTES *cliente = noClientesCaixa->info;
            LISTA *listaCompras = cliente->lista_compras;
            NODE *noListaCompras = listaCompras->head;

            while (noListaCompras != NULL) {
                PRODUTOS *produto = noListaCompras->info;
                clock_t start = clock();

                clock_t end = clock();

                double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
                double waiting_time = produto->TCaixa - elapsed_time;

                if (waiting_time > 0) {

                    clock_t remaining_ticks = (clock_t)(waiting_time * CLOCKS_PER_SEC);
                    clock_t wait_start = clock();
                    while ((clock() - wait_start) < remaining_ticks);
                }

                noListaCompras = noListaCompras->next;
            }


            remover_cliente(cliente, supermercado->lista_clientes);
            printf("Cliente %s saiu do supermercado\n", cliente->nome);

            sprintf(historico_string, "Cliente %s saiu do supermercado\n", cliente->nome);
            gravar_historico(historico_string);

            noClientesCaixa = nextNode;
        }

        nodeCaixa = nodeCaixa->next;
    }
    reset_caixas(supermercado);
    printf("Lucro do supermercado: %d\n", lucroSupermercado);
    sprintf(historico_string, "Lucro do supermercado: %d\n", lucroSupermercado);
    gravar_historico(historico_string);
}

//criar no
NODE * create_node(void *info) {
    if(info == NULL){
        printf("Informação não encontrada");
        return NULL;
    }
    NODE *node = (NODE *) malloc(sizeof(NODE));
    node->info = info;
    node->next = NULL;
    return node;
}

// enfileirar um elemento an fila
void enfileirar(FILA *fila, void *info) {
    if(fila == NULL || info == NULL){
        printf("Fila ou informação não encontrada");
        return;
    }
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

// desenfileirar um elemento da fila
void *desenfileirar(FILA *fila) {
    if(fila == NULL){
        printf("Fila não encontrada");
        return NULL;
    }
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

//pesquisar pessoa em todas as caixas
void pesquisarPessoaCaixa(LISTA *lista_caixas){
    if(lista_caixas->N_elements == 0 || lista_caixas == NULL){
        printf("Nao existem caixas abertas\n");
        return;
    }
    if(lista_caixas->N_elements == 0 || lista_caixas == NULL){
        printf("Nao existem caixas abertas\n");
        return;
    }
    char codCliente[7];
    printf("Insira o codigo do cliente, ex(569306): ");
    scanf("%6s", codCliente);

    NODE *node = lista_caixas->head;

    while(node != NULL){
        CAIXA *caixa = (CAIXA *) node->info;
        NODE *node_cli = caixa->clientes->head;
        while(node_cli != NULL){
            CLIENTES *cliente = (CLIENTES *) node_cli->info;
            if(strcmp(cliente->codigo, codCliente) == 0){
                printf("Cliente %s esta na caixa %s\n", cliente->nome, caixa->codigo);
                return;
            }
            node_cli = node_cli->next;
        }
        node = node->next;
    }
    printf("Cliente nao encontrado\n");
    return;
}

//remover no de lista
void remove_node(LISTA *lista, NODE *node) {
    if(lista == NULL || node == NULL){
        printf("Lista ou nó não encontrados");
        return;
    }
    if (lista->head == NULL) {
        // Empty list
        return;
    }

    NODE *current = lista->head;
    NODE *previous = NULL;

    while (current != NULL) {
        if (current == node) {
            if (previous == NULL) {
                // Node to be removed is the head of the list
                lista->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (lista->tail == current) {
                // Node to be removed is the tail of the list
                lista->tail = previous;
            }

            free(current);
            lista->N_elements--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

//fechar uma caixa
void fecharCaixa(LISTA *lista_caixas) {
    if(lista_caixas == NULL || lista_caixas->N_elements == 0){
        printf("Nao existem caixas abertas\n");
        return;
    }
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

    node = lista_caixas->head;
    NODE *next_node = NULL;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        next_node = node->next;
        if (caixa->aberta == 0) {
            remove_node(lista_caixas, node);
        }
        node = next_node;
    }

}

//total de clientes em todas as caixas
int totalCLientes(LISTA *lista_caixas){

    if(!lista_caixas){
        return 0;
    }
    int total = 0;
    NODE *node = lista_caixas->head;
    while(node != NULL){
        CAIXA *caixa = (CAIXA *) node->info;
        total += caixa->clientes->N_elements;
        node = node->next;
    }
    return total;
}


int compareCaixas(const void* a, const void* b) {
    if(!a || !b){
        return 0;
    }
    const CAIXA* caixaA = *(const CAIXA**)a;
    const CAIXA* caixaB = *(const CAIXA**)b;
    return caixaA->clientes->N_elements - caixaB->clientes->N_elements;
}

//ordena as caixas por numero de clientes
void ordenarCaixas(SUPERMERCADO* supermercado) {
    if (!supermercado || !supermercado->lista_caixas) {
        return;
    }


    int numCaixas = supermercado->lista_caixas->N_elements;
    CAIXA** caixasArray = (CAIXA**)malloc(numCaixas * sizeof(CAIXA*));


    int index = 0;
    CAIXA* caixa = supermercado->lista_caixas->head->info;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {

        caixa = caixaNode->info;
        caixasArray[index++] = caixa;

    }


    qsort(caixasArray, numCaixas, sizeof(CAIXA*), compareCaixas);


    int avgClientes = 0;
    for (int i = 0; i < numCaixas; i++) {
        avgClientes += caixasArray[i]->clientes->N_elements;
    }
    avgClientes /= numCaixas;


    int excessClientes = 0;
    for (int i = 0; i < numCaixas; i++) {
        int diffClientes = caixasArray[i]->clientes->N_elements - avgClientes;
        if (diffClientes > 0) {
            excessClientes += diffClientes;
        }
    }


    for (int i = 0; i < numCaixas; i++) {
        caixa = caixasArray[i];


        int targetClientes = avgClientes;
        if (excessClientes > 0) {
            targetClientes++;
            excessClientes--;
        }


        int diffClientes = targetClientes - caixa->clientes->N_elements;


        if (diffClientes > 0) {
            for (int j = i + 1; j < numCaixas && diffClientes > 0; j++) {
                CAIXA* sourceCaixa = caixasArray[j];
                while (diffClientes > 0 && sourceCaixa->clientes->N_elements > 0) {
                    CLIENTES* cliente = (CLIENTES*)sourceCaixa->clientes->head->info;


                    NODE* clienteNode = sourceCaixa->clientes->head;
                    sourceCaixa->clientes->head = clienteNode->next;
                    free(clienteNode);
                    sourceCaixa->clientes->N_elements--;


                    NODE* newClienteNode = (NODE*)malloc(sizeof(NODE));
                    newClienteNode->info = cliente;
                    newClienteNode->next = caixa->clientes->head;
                    caixa->clientes->head = newClienteNode;
                    caixa->clientes->N_elements++;

                    diffClientes--;
                }
            }
        }
    }


    free(caixasArray);
}

//adiciona caixa na lista das caixas
void inserirCaixa(LISTA *lista_caixas, LISTA *lista_funcionarios){
    if(!lista_caixas || !lista_funcionarios){
        return;
    }
    CAIXA *caixa_a_inserir = (CAIXA *) malloc(sizeof(CAIXA));
    printf("Qual o codigo da caixa? (ex: CX_1): ");
    scanf("%4s", caixa_a_inserir->codigo);
    NODE *node = lista_caixas->head;
    while (node != NULL){
        CAIXA *caixa = (CAIXA *) node->info;
        if(strcmp(caixa->codigo, caixa_a_inserir->codigo) == 0){
            printf("Ja existe uma caixa com esse codigo.\n");
            return;
        }
        node = node->next;
    }
    caixa_a_inserir->aberta = 1;
    caixa_a_inserir->clientes = criar_Lista();
    int index = aleatorio(0, lista_funcionarios->N_elements - 1);
    NODE *funcionario_node = (NODE *) get_Lista(lista_funcionarios, index);
    FUNCIONARIO *funcionario = funcionario_node->info;
    caixa_a_inserir->funcionarios = funcionario;
    adicionar_Lista(lista_caixas, caixa_a_inserir);

    int num_clientes = totalCLientes(lista_caixas);
    int num_caixas = lista_caixas->N_elements;
    int num_clientes_por_caixa = num_clientes / num_caixas;
    int clientes_restantes = num_clientes % num_caixas;

    node = lista_caixas->head;
    while (node != NULL) {
        CAIXA *caixa = (CAIXA *) node->info;
        int num_elemntos_mover = caixa->clientes->N_elements - num_clientes_por_caixa;
        if (caixa->aberta && caixa != caixa_a_inserir) {
            FILA *fila_caixa = caixa->clientes;
            for (int i = 0; i < num_elemntos_mover; i++) {
                CLIENTES *cliente = (CLIENTES *) desenfileirar(caixa->clientes);
                enfileirar(caixa_a_inserir->clientes, cliente);
            }
            if (clientes_restantes > 0) {
                CLIENTES *cliente = (CLIENTES *) desenfileirar(caixa->clientes);
                enfileirar(caixa_a_inserir->clientes, cliente);
                clientes_restantes--;
            }
        }
        node = node->next;
    }
}


//gravar historico como se fossem logs
void gravar_historico(char *data){
    if(!data){
        return;
    }



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

//procurar cliente na lista de caixas
CLIENTES* searchClienteInCaixas(SUPERMERCADO* supermercado, const char* clienteCode) {
    if(!clienteCode){
        return NULL;
    }
    if (!supermercado || !supermercado->lista_caixas) {
        return NULL;
    }

    CAIXA* caixa = supermercado->lista_caixas->head->info;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        caixa = caixaNode->info;

        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            CLIENTES* cliente = clienteNode->info;
            if (strcmp(cliente->codigo, clienteCode) == 0) {
                return cliente; // Found the cliente with the specified code
            }
            clienteNode = clienteNode->next;
        }
    }

    return NULL;
}

//mudar cliente de caixa
void mudarCaixa(SUPERMERCADO* supermercado) {
    if (supermercado->lista_caixas->N_elements == 0 || supermercado->lista_caixas == NULL) {
        printf("Nao existem caixas.\n");
        return;
    }

    char clienteCode[7], caixaCode[5];
    printf("Qual o codigo do cliente? (ex: 609140): ");
    scanf("%6s", clienteCode);
    printf("Qual a caixa para a qual quer mudar o cliente? (ex: CX_1): ");
    scanf("%4s", caixaCode);


    CLIENTES* cliente = searchClienteInCaixas(supermercado, clienteCode);
    if (cliente == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }


    CAIXA* sourceCaixa = NULL;
    NODE* sourceCaixaNode = NULL;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            CLIENTES* currentCliente = (CLIENTES*)clienteNode->info;
            if (currentCliente == cliente) {
                sourceCaixa = caixa;
                sourceCaixaNode = caixaNode;
                break;
            }
            clienteNode = clienteNode->next;
        }
        if (sourceCaixa != NULL) {
            break;
        }
    }

    if (sourceCaixa == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Find the target caixa for the cliente
    CAIXA* targetCaixa = NULL;
    NODE* targetCaixaNode = NULL;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        if (strcmp(caixa->codigo, caixaCode) == 0) {
            targetCaixa = caixa;
            targetCaixaNode = caixaNode;
            break;
        }
    }

    if (targetCaixa == NULL) {
        printf("Caixa nao encontrada.\n");
        return;
    }

    // Move the cliente from the source caixa to the target caixa
    NODE* clienteNode = NULL;
    NODE* prevClienteNode = NULL;
    FILA* sourceClientes = sourceCaixa->clientes;
    clienteNode = sourceClientes->head;

    while (clienteNode != NULL) {
        CLIENTES* currentCliente = (CLIENTES*)clienteNode->info;
        if (currentCliente == cliente) {
            if (prevClienteNode == NULL) {
                sourceClientes->head = clienteNode->next;
            } else {
                prevClienteNode->next = clienteNode->next;
            }
            sourceClientes->N_elements--;
            break;
        }
        prevClienteNode = clienteNode;
        clienteNode = clienteNode->next;
    }

    if (clienteNode == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    NODE* newClienteNode = (NODE*)malloc(sizeof(NODE));
    newClienteNode->info = cliente;
    newClienteNode->next = targetCaixa->clientes->head;
    targetCaixa->clientes->head = newClienteNode;
    targetCaixa->clientes->N_elements++;

    printf("Cliente movido com sucesso para a caixa %s.\n", targetCaixa->codigo);
}

//gravar dados da simulacao
void gravarDadosSimulacao(){
    FILE *fp = fopen("DadosSimulacao.txt", "w");
    if (fp == NULL){
        printf("Erro ao abrir o ficheiro");
        return;
    }

    fprintf(fp, "Numero de clientes que entraram no supermercado: %d\n", numClientes);
    fprintf(fp, "Numero de produtos vendidos: %d\n", numProdutosVendidos);
    fprintf(fp, "Numero de funcionarios que trabalharam: %d\n", numFuncionarios);
    fprintf(fp, "Tempo medio de espera: %f\n", tempoMedioEspera);
    fclose(fp);

}

//numero de clientes
int num_clientes(SUPERMERCADO *supermercado){
    if(!supermercado || !supermercado->lista_caixas){
        return 0;
    }
    int num_clientes = 0;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            num_clientes++;
            clienteNode = clienteNode->next;
        }
    }
    return num_clientes;
}

//numero de produtos vendidos
int produtosVendidos(SUPERMERCADO *supermercado){
    if(!supermercado || !supermercado->lista_caixas){
        return 0;
    }
    int produtos_vendidos = 0;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            CLIENTES* cliente = clienteNode->info;
            produtos_vendidos += cliente->lista_compras->N_elements;
            clienteNode = clienteNode->next;
        }
    }
    return produtos_vendidos;
}

//preco total dos produtos vendidos
float precoTotalProdutosVendidos(SUPERMERCADO *supermercado){
    if(!supermercado || !supermercado->lista_caixas){
        return 0;
    }
    float preco_total = 0;
    for (NODE* caixaNode = supermercado->lista_caixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            CLIENTES* cliente = clienteNode->info;
            for (NODE* produtoNode = cliente->lista_compras->head; produtoNode != NULL; produtoNode = produtoNode->next) {
                PRODUTOS* produto = produtoNode->info;
                preco_total += produto->preco;
            }
            clienteNode = clienteNode->next;
        }
    }
    return preco_total;
}

//cliente que tem mais produtos
CLIENTES *clienteMaisProutos(LISTA *listaCaixas){
    CLIENTES *clienteMaisProdutos = NULL;
    int maxProdutos = 0;
    for (NODE* caixaNode = listaCaixas->head; caixaNode != NULL; caixaNode = caixaNode->next) {
        CAIXA* caixa = caixaNode->info;
        FILA* clientes = caixa->clientes;
        NODE* clienteNode = clientes->head;
        while (clienteNode != NULL) {
            CLIENTES* cliente = clienteNode->info;
            if (cliente->lista_compras->N_elements > maxProdutos) {
                maxProdutos = cliente->lista_compras->N_elements;
                clienteMaisProdutos = cliente;
            }
            clienteNode = clienteNode->next;
        }
    }
    return clienteMaisProdutos;
}

//grava estatisticas
void gravarEstatisticas(SUPERMERCADO *supermercado){
    if(!supermercado || !supermercado->lista_caixas){
        return;
    }
    ESTATISTICAS *estatisticas = (ESTATISTICAS*)malloc(sizeof(ESTATISTICAS));
    estatisticas->clientes = num_clientes(supermercado);
    estatisticas->produtos_vendidos = produtosVendidos(supermercado);
    estatisticas->preco_totalProdutosVendidos = precoTotalProdutosVendidos(supermercado);
    estatisticas->cliente_mais_compras = clienteMaisProutos(supermercado->lista_caixas);
    supermercado->estatisticas = estatisticas;
}

//mostrar estatisticas
void estatisticas(ESTATISTICAS *estatisticas){
    if(!estatisticas){
        return;
    }
    printf("ESTATISTICAS\n");
    printf("Numero de clientes que entraram no supermercado: %d\n", estatisticas->clientes);
    printf("Numero de produtos vendidos: %d\n", estatisticas->produtos_vendidos);
    printf("Receita total: %f\n", estatisticas->preco_totalProdutosVendidos);
    printf("Cliente com mais produtos: %s\n", estatisticas->cliente_mais_compras->nome);
}