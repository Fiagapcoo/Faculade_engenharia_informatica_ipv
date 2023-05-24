#include "header.h"

int numClientes = 0;
int numProdutosVendidos = 0;
int numFuncionarios = 0;
float tempoMedioEspera = 0;

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
    numClientes += num_clientes;

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
        usleep(aleatorio(1000, 3000));
        strncpy(nome_cli, cliente->nome, strlen(cliente->nome) - 1);
        sprintf(str_historico, "Cliente: %s entrou no supermercado", nome_cli);
        gravar_historico(str_historico);

        //  int num_produtos = aleatorio(1, listaProdutos->N_elements);
        int num_produtos = 4;
        numProdutosVendidos += num_produtos;



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
        tempoMedioEspera += tempo_medio_espera;






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


void continuar_simulacao(SUPERMERCADO *supermercado){
    printf("Continuação da simulação");
    LISTA *listaClientes = supermercado->lista_clientes;
    LISTA *listaCaixas = supermercado->lista_caixas;
    LISTA *listaProdutos = supermercado->lista_produtos;
    LISTA *listaFuncionarios = supermercado->lista_funcionarios;

    NODE *nodeCaixa = listaCaixas->head;

    while(nodeCaixa != NULL){
        CAIXA *caixa = nodeCaixa->info;
        FILA *FilaClientes =caixa->clientes;
        NODE *noClientesCaixa = FilaClientes->head;
        while(noClientesCaixa != NULL){

        }
    }
 }


void estatisticas(SUPERMERCADO *supermercado){
    printf("Estatisticas");

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

void remove_node(LISTA *lista, NODE *node) {
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
    const CAIXA* caixaA = *(const CAIXA**)a;
    const CAIXA* caixaB = *(const CAIXA**)b;
    return caixaA->clientes->N_elements - caixaB->clientes->N_elements;
}


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


void inserirCaixa(LISTA *lista_caixas, LISTA *lista_funcionarios){
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


CLIENTES* searchClienteInCaixas(SUPERMERCADO* supermercado, const char* clienteCode) {
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

    return NULL; // Cliente not found
}


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

    // Search for the cliente with the specified code
    CLIENTES* cliente = searchClienteInCaixas(supermercado, clienteCode);
    if (cliente == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Find the source caixa containing the cliente
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

