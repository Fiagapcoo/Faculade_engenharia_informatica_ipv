#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1024

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct
{
    int cod;
    char nome[50];
    char utilizador[20];
    char password[20];
    float joia;
    DATA data_registo;
    char email[30];
    char pagina_web_pessoal[50];
    int telemovel;
    int numero_acessos;
    DATA data_ultimo_acesso;
} REGISTO_UTILIZADORES;

typedef struct
{
    char nome[50];
    int count;
} NomeContagem;

typedef struct node
{
    NomeContagem data;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    int count_list;
    Node *tail;
} List;



REGISTO_UTILIZADORES *lerFicheirobin(char *namefile);
void OrdenarDados(REGISTO_UTILIZADORES *registos, int num_registos);
void LibertarMemoria(REGISTO_UTILIZADORES *registos);
int num_reg(REGISTO_UTILIZADORES *registos);
void ListarUtilizadores(REGISTO_UTILIZADORES *registos, int num_registos);
void ContarPessoasAcessosAno(REGISTO_UTILIZADORES *registos, int num_registos);
void GerarFicheiro_So_Para_Testes(char *nficheiro);
void PesquisarCod(REGISTO_UTILIZADORES *registos, int num_registos);
int GravarXML(REGISTO_UTILIZADORES *registos, int num_registos);

void GerarFicheiro_So_Para_Testes(char *nficheiro)
{
    int N = 6;
    FILE *F = fopen(nficheiro, "wb");
    if (!F)
        return;
    for (int i = 0; i < N; i++)
    {
        REGISTO_UTILIZADORES X;
        sprintf(X.nome, "Joao-%d", i);
        //  X.numero_acessos = Aleatorio(10, 50);
        sprintf(X.email, "jony_%d@gmail.com", i);
        // X.joia = Aleatorio(10, 16) * 1.5f;

        fwrite(&X, sizeof(REGISTO_UTILIZADORES), 1, F);
    }
    fclose(F);
}

REGISTO_UTILIZADORES *lerFicheirobin(char *namefile)
{

    FILE *file = fopen(namefile, "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o ficheiro");
        return NULL;
    }
    long file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    int num_registos = file_size / sizeof(REGISTO_UTILIZADORES);

    // create 3 users

    REGISTO_UTILIZADORES *registos = (REGISTO_UTILIZADORES *)malloc(num_registos * sizeof(REGISTO_UTILIZADORES));

    fread(registos, sizeof(REGISTO_UTILIZADORES), num_registos, file);
    fclose(file);

    return registos;
}

void OrdenarDados_bubble(REGISTO_UTILIZADORES *registos, int num_registos)
{

    for (int i = 0; i < num_registos; i++)
    {
        for (int j = 0; j < num_registos - 1; j++)
        {
            if (registos[j].cod > registos[j + 1].cod)
            {
                REGISTO_UTILIZADORES temp = registos[j];
                registos[j] = registos[j + 1];
                registos[j + 1] = temp;
            }
        }
    }
}

void OrdenarDados_quick(REGISTO_UTILIZADORES *registos, int num_registos)
{
    int i, j;
    REGISTO_UTILIZADORES x, y;
    i = 0;
    j = num_registos - 1;
    x = registos[(i + j) / 2];
    do
    {
        while ((registos[i].numero_acessos < x.numero_acessos) && (i < num_registos))
            i++;
        while ((x.numero_acessos < registos[j].numero_acessos) && (j > 0))
            j--;
        if (i <= j)
        {
            y = registos[i];
            registos[i] = registos[j];
            registos[j] = y;
            i++;
            j--;
        }
    } while (i <= j);
    if (0 < j)
        OrdenarDados_quick(registos, j + 1);
    if (i < num_registos)
        OrdenarDados_quick(registos + i, num_registos - i);
}

void OrdenarDadosShell(REGISTO_UTILIZADORES *registos, int num_registos)
{
    int i, j, h = 1;
    REGISTO_UTILIZADORES x;
    do
    {
        h = 3 * h + 1;
    } while (h < num_registos);
    do
    {
        h /= 3;
        for (i = h; i < num_registos; i++)
        {
            x = registos[i];
            j = i;
            while (registos[j - h].numero_acessos > x.numero_acessos)
            {
                registos[j] = registos[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            registos[j] = x;
        }
    } while (h != 1);
}

void OrdenarDadosShakerSort(REGISTO_UTILIZADORES *registos, int num_registos)
{
    int i, j, k;
    REGISTO_UTILIZADORES x;
    i = 0;
    j = num_registos - 1;
    k = 0;
    do
    {
        for (i = k; i < j; i++)
        {
            if (registos[i].numero_acessos > registos[i + 1].numero_acessos)
            {
                x = registos[i];
                registos[i] = registos[i + 1];
                registos[i + 1] = x;
                k = i;
            }
        }
        j--;
        for (i = j; i > k; i--)
        {
            if (registos[i - 1].numero_acessos > registos[i].numero_acessos)
            {
                x = registos[i];
                registos[i] = registos[i - 1];
                registos[i - 1] = x;
                k = i;
            }
        }
    } while (k != 0);
}

void LibertarMemoria(REGISTO_UTILIZADORES *registos)
{
    if (registos)
        free(registos);
}

int num_reg(REGISTO_UTILIZADORES *registos)
{
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o ficheiro");
        return 1;
    }
    long file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    int num_registos = file_size / sizeof(REGISTO_UTILIZADORES);

    return num_registos;
}

void ListarUtilizadores(REGISTO_UTILIZADORES *registos, int num_registos)
{

    for (int i = 0; i < num_registos; i++)
    {
        printf("ID: %d  Nome: %s    Utilizador: %s    Password: %s    Joia: %f    Data Registo: %d/%d/%d    Email: %s    Pagina Web: %s    Telemovel: %d    Numero de Acessos: %d    Data Ultimo Acesso: %d/%d/%d   \n", registos[i].cod, registos[i].nome, registos[i].utilizador, registos[i].password, registos[i].joia, registos[i].data_registo.dia, registos[i].data_registo.mes, registos[i].data_registo.ano, registos[i].email, registos[i].pagina_web_pessoal, registos[i].telemovel, registos[i].numero_acessos, registos[i].data_ultimo_acesso.dia, registos[i].data_ultimo_acesso.mes, registos[i].data_ultimo_acesso.ano);
    }
}

void PesquisarCod(REGISTO_UTILIZADORES *registos, int num_registos)
{ // nao ha codigo

    int cod;
    printf("Digite o codigo que quer procurar: ");
    scanf("%d", &cod);

    int i = 0;

    for (i = 0; i < num_registos; i++)
    {
        if (registos->cod == cod)
        {
            printf("A pessoa com o codigo %d existe \n", cod);
            printf("ID: %d \n Nome: %s  \n  Utilizador: %s  \n  Password: %s  \n  Joia: %f  \n  Data Registo: %d/%d/%d  \n  Email: %s  \n  Pagina Web: %s  \n  Telemovel: %d  \n  Numero de Acessos: %d \n   Data Ultimo Acesso: %d/%d/%d   \n", registos->cod, registos->nome, registos->utilizador, registos->password, registos->joia, registos->data_registo.dia, registos->data_registo.mes, registos->data_registo.ano, registos->email, registos->pagina_web_pessoal, registos->telemovel, registos->numero_acessos, registos->data_ultimo_acesso.dia, registos->data_ultimo_acesso.mes, registos->data_ultimo_acesso.ano);
        }
        registos++;
    }
}

void PesquisarNome(REGISTO_UTILIZADORES *registos, int num_registos)
{
    char nome[3];
    char aux[5];
    printf("Digite o nome que quer procurar: ");
    scanf("%s", nome);

    int i;
    for (i = 0; i < num_registos; i++)
    {
        if (strcmp(registos->nome, nome) == 0)
        {
            printf("A pessoa com o nome %s existe \n", nome);
            printf("ID: %d \n Nome: %s  \n  Utilizador: %s  \n  Password: %s  \n  Joia: %f  \n  Data Registo: %d/%d/%d  \n  Email: %s  \n  Pagina Web: %s  \n  Telemovel: %d  \n  Numero de Acessos: %d \n   Data Ultimo Acesso: %d/%d/%d   \n", registos->cod, registos->nome, registos->utilizador, registos->password, registos->joia, registos->data_registo.dia, registos->data_registo.mes, registos->data_registo.ano, registos->email, registos->pagina_web_pessoal, registos->telemovel, registos->numero_acessos, registos->data_ultimo_acesso.dia, registos->data_ultimo_acesso.mes, registos->data_ultimo_acesso.ano);
            break;
        }
        registos++;
    }
}

void PessoaMais_Acessos(REGISTO_UTILIZADORES *registos, int num_registos)
{
    int max = 0;
    int index = 0;
    for (int i = 0; i < num_registos; i++)
    {
        if (registos[i].numero_acessos > max)
        {
            max = registos[i].numero_acessos;
            index = i;
        }
    }
    printf("A pessoa com mais acessos é %s com %d acessos \n", registos[index].nome, max);
}

void TotalJoias(REGISTO_UTILIZADORES *registos, int num_registos)
{
    float total = 0;
    for (int i = 0; i < num_registos; i++)
    {
        total += registos[i].joia;
    }
    printf("O total de joias é %f \n", total);
}

void MesMaisRegistos(REGISTO_UTILIZADORES *registos, int num_registos)
{
    int count[12] = {0};
    for (int i = 0; i < num_registos; i++)
    {
        count[registos[i].data_registo.mes - 1]++;
    }
    int max = 0;
    int index = 0;
    for (int i = 0; i < 12; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            index = i;
        }
    }
    printf("O mes com mais registos é %d com %d registos \n", index + 1, max);
}

void ContarPessoasAcessosAno(REGISTO_UTILIZADORES *registos, int num_registos)
{
    printf("Digite o ano: ");
    int ano;
    scanf("%d", &ano);

    int count = 0;

    for (int i = 0; i < num_registos; i++)
    {
        if (registos[i].data_ultimo_acesso.ano == ano)
        {
            count++;
        }
    }

    printf("Existem %d pessoas que fizeram acesso no ano %d \n", count, ano);
}

int GravarXML(REGISTO_UTILIZADORES *registos, int num_registos)
{

    printf("Qual o nome do ficheiro que quer gravar? Tem de acabar em .xml \n ");
    char nome[50];
    scanf("%s", nome);

    FILE *fp = fopen(nome, "w");

    if (fp == NULL)
    {
        printf("Erro ao abrir o ficheiro \n");
        return 0;
    }

    fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(fp, "<registos>\n");
    int i = 0;
    for (i = 0; i < num_registos; i++)
    {
        fprintf(fp, "\t<user%d>\n", i);
        fprintf(fp, "\t\t<cod>%d</cod>\n", registos->cod);
        fprintf(fp, "\t\t<nome>%s</nome>\n", registos->nome);
        fprintf(fp, "\t\t<utilizador>%s</utilizador>\n", registos->utilizador);
        fprintf(fp, "\t\t<password>%s</password>\n", registos->password);
        fprintf(fp, "\t\t<joia>%f</joia>\n", registos->joia);
        fprintf(fp, "\t\t<data_registo>%d/%d/%d</data_registo>\n", registos->data_registo.dia, registos->data_registo.mes, registos->data_registo.ano);
        fprintf(fp, "\t\t<email>%s</email>\n", registos->email);
        fprintf(fp, "\t\t<pagina_web_pessoal>%s</pagina_web_pessoal>\n", registos->pagina_web_pessoal);
        fprintf(fp, "\t\t<telemovel>%d</telemovel>\n", registos->telemovel);
        fprintf(fp, "\t\t<numero_acessos>%d</numero_acessos>\n", registos->numero_acessos);
        fprintf(fp, "\t\t<data_ultimo_acesso>%d/%d/%d</data_ultimo_acesso>\n", registos->data_ultimo_acesso.dia, registos->data_ultimo_acesso.mes, registos->data_ultimo_acesso.ano);
        fprintf(fp, "\t</user%d>\n", i);
        registos++;
    }
    fprintf(fp, "</registos>\n");

    fclose(fp);
}

void ToLetrasGrandes(REGISTO_UTILIZADORES *V, int num_registos)
{
    int i, j;
    for (i = 0; i < num_registos; i++)
    {
        for (j = 0; V[i].nome[j] != '\0'; j++)
        {
            if (V[i].nome[j] >= 'a' && V[i].nome[j] <= 'z')
            {
                V[i].nome[j] = V[i].nome[j] - 32;
            }
        }
    }
}

int ListarUsersContain(REGISTO_UTILIZADORES *V, int N, char *subnome)
{
    int i, j, k, count = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; V[i].nome[j] != '\0'; j++)
        {
            if (V[i].nome[j] == subnome[0])
            {
                for (k = 1; subnome[k] != '\0'; k++)
                {
                    if (V[i].nome[j + k] != subnome[k])
                    {
                        break;
                    }
                }
                if (subnome[k] == '\0')
                {
                    printf("%s\n", V[i].nome);
                    count++;
                }
            }
        }
    }

    return count;
}

FILE *AbrirFicheiro()
{
    FILE *fp = fopen("performance.csv", "w");
    if (!fp)
    {
        printf("Erro ao abrir o ficheiro\n");
        exit(1);
    }
    return fp;
}
void EscreverFicheiro(FILE *fp, clock_t tempo_inicio, clock_t tempo_fim, char *nome_funcao)
{
    fprintf(fp, "%s,%f\n", nome_funcao, (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC);
}
void FecharFicheiro(FILE *fp)
{
    fclose(fp);
}

List *create_list(){
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->count_list = 0;
    return list;
}

Node *get_node( List *lista, char *nome){
    if(lista == NULL){
        return NULL;
    }

    if(lista->head == NULL){
        return NULL;
    }

    Node *node = lista->head;
    int i;
    for(i = 0; i < lista->count_list; i++){
        if(strcmp(node->data.nome, nome) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

Node *create_node(NomeContagem *data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = *data;
    node->next = NULL;
    return node;
}

void add_node_on_tail(List *lista,  NomeContagem *data){
    if(lista == NULL){
        return;
    }

    Node *node = create_node(data);

    if(lista->head == NULL){
        lista->head = node;
        lista->tail = node;
    }else{
        lista->tail->next = node;
        lista->tail = node;
    }
    lista->count_list++;
}


List *contar_ocorrencias_nome(REGISTO_UTILIZADORES *registos, int N){    
    
    NomeContagem *pointer = (NomeContagem *)malloc(N * sizeof(NomeContagem));

    List *lista = create_list();




    int i;
    for (i = 0; i < N; i++){
        char *token = strtok(registos->nome, " ");
        while(token != NULL){
            Node *node = get_node(lista, token);
            if(node == NULL){
                NomeContagem *nome = (NomeContagem *)malloc(sizeof(NomeContagem));
                strcpy(nome->nome, token);
                nome->count = 1;
                add_node_on_tail(lista, nome);
            }else{
                node->data.count++;
            }
            token = strtok(NULL, " ");
        }
        registos++;
    }


     
    
    return lista;
}

Node *obter_maior(List *lista){
    
    if (lista == NULL){
        return NULL;
    }
    
    Node *node = lista->head;
    Node *maior = lista->head;
    
    if(node == NULL){
        return NULL;
    }

    int i;
    
    while (node)
    {
        if(node->data.count > maior->data.count){
            maior = node;
        }
        node = node->next;
       
    }
    return maior;
}

char *NomeMaisComum(REGISTO_UTILIZADORES *registos, int N)
{

    List *lista = contar_ocorrencias_nome(registos, N);
    
    
    Node *node = obter_maior(lista);

    printf("Nome mais comum: %s\n", node->data.nome);

    
}

int main()
{
    char *namefile = "users.dat";
    REGISTO_UTILIZADORES *registos = lerFicheirobin(namefile);
    int num_registos = 3;

    int opc;
    do
    {
        printf("\nmenu:");
        printf("\n1- Ordenar dados:");
        printf("\n2-Liberar Memoria:");
        printf("\n3-Listar Utilizadores:");
        printf("\n4-Contar Pessoas acesso:");
        printf("\n5-Pesquisar por codigo:");
        printf("\n6-Pesquisar por nome:");
        printf("\n7-Pessoa com mais acessos:");
        printf("\n8-Total de joias:");
        printf("\n9-Mes com mais registos:");
        printf("\n10-Gravar XML:");
        printf("\n3523-Nome mais comum:");
        printf("\n11-Sair:");

        printf("Digite a opcao que quer: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            // ordenarDados(registos, num_registos);
            break;
        case 2:
            free(registos);
            break;
        case 3:
            ListarUtilizadores(registos, num_registos);
            break;
        case 4:
            ContarPessoasAcessosAno(registos, num_registos);
            break;
        case 5:
            PesquisarCod(registos, num_registos);
            break;
        case 6:
            PesquisarNome(registos, num_registos);
            break;
        case 7:
            PessoaMais_Acessos(registos, num_registos);
            break;
        case 8:
            TotalJoias(registos, num_registos);
            break;
        case 9:
            MesMaisRegistos(registos, num_registos);
            break;
        case 10:
            GravarXML(registos, num_registos);
            break;
        case 3523:
            NomeMaisComum(registos, num_registos);
            break;
        default:
            printf("Opcao invalida \n");
            break;
        }
    } while (opc != 11);

    return 0;
}
