#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <ctype.h>

#define MAX_LINHA 1024

typedef struct data{
  int dia;
  int mes;
  int ano;

}DATA;

typedef struct pessoas
{
  int cod;
  char *nome;
  char *cidade;
  DATA dataN;

} PESSOAS;

PESSOAS *ficheiro_para_struct();

int compare(char a[],char b[]);

void paginainicial(PESSOAS *pessoa);

void menu(PESSOAS *pessoa);

void inserir_pessoas(PESSOAS *pessoa);

void eliminar_pessoas(PESSOAS *pessoa);

void pesquisar_por_parte_nome(PESSOAS *pessoa);

void listar_pessoas(PESSOAS *pessoa);

void pesquisar_por_cidade(PESSOAS *pessoa);

void cidadaos_faixa_etaria(PESSOAS *pessoa);

void cidadaos_nascidos_data(PESSOAS *pessoa);

void listar_pessoas_alfabetica_apelido(PESSOAS *pessoa);

void cidade_mais_pessoas(PESSOAS *pessoa);

void nascidos_a_um_domingo(PESSOAS *pessoa);

void media_idades_cidade(PESSOAS *pessoa);

void mes_mais_nascimentos(PESSOAS *pessoa);

void aniversario_quaresma(PESSOAS *pessoa);

void remover_linhas_vazias(const char *filename);

void guardar_cod_dataN_cidade(PESSOAS *pessoa);

void guardar_cod_nome(PESSOAS *pessoa);

void guardar_struct_ficheiro(PESSOAS *pessoa);

void creditos_finais();







int compare(char a[],char b[])  {  
    int flag=0,i=0;  

    while(a[i]!='\0' &&b[i]!='\0'){

       if(a[i]!=b[i]){

           flag=1;
           break;

    } 

       i++;  
  } 

  if(flag==0){

      return 0; 

  }else{
  return 1; 

  } 
}  

void nascidos_a_um_domingo(PESSOAS *pessoa){
  
  int i, d, m, y, ano, mes, dia, iterador = 0;
  system("clear");
  printf("Lista das pessoas nascidas a um domingo:\n");
  
  while(pessoa->cod != 0){

      y = pessoa->dataN.ano;
      m = pessoa->dataN.mes;
      d = pessoa->dataN.dia; 

      ano = y - 1900;
      ano = ano / 4;
      ano = ano + y - 1900;
    
        switch(m){
            case 1:
            case 10:
                mes = 1;
                break;
            case 2:
            case 3:
            case 11:
                mes = 4;
                break;
            case 7:
            case 4:
                mes = 0;
              break;
            case 5:
                mes = 2;
                break;
            case 6:
                mes = 5;
                break;
            case 8:
                mes = 3;
                break;
            case 9:
            case 12:
                mes = 6;
                break;
        }
  
        ano = ano + mes;
        ano = ano + d;
  
      if(( y > 1900 ) && ( y % 4 == 0 ) && ( m < 2 ) ){
        ano--;
      }

        dia = ano % 7;
    
        if(dia == 1){

          printf("\n Cod: %d \t Nome: %s \n",pessoa->cod , pessoa->nome);
      }                
      pessoa++;
      iterador++;
  
  }
  
  printf("\n");
  
  pessoa -= iterador;  

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);
}

void listar_pessoas_alfabetica_apelido(PESSOAS *pessoa){
 
  
  int i, j, iterador = 0;
  char *aux;
  printf("Lista, por ordem alfabetica do apelido (ultima palavra do nome completo):\n");

  while(pessoa->cod != 0){

    iterador++;
    pessoa++;

  }

  pessoa -= iterador;

  for(i = 0; i < iterador - 1; i++){

    for(j = i + 1; j < iterador; j++){

      char *nome1 = strrchr(pessoa[i].nome, ' ');
      char *nome2 = strrchr(pessoa[j].nome, ' ');

      if(nome1 == NULL){
        nome1 = pessoa[i].nome;
      } 
      
      if(nome2 == NULL){
        nome2 = pessoa[j].nome;  
      }
      if(strcmp(nome1, nome2) > 0){

        aux = pessoa[i].nome;
        pessoa[i].nome = pessoa[j].nome;
        pessoa[j].nome = aux;

      }
    }
  }

  for(i = 0; i < iterador; i++){

    printf("\n Cod: %d \t Nome: %s \n",pessoa[i].cod , pessoa[i].nome);

  }
  
  printf("\n");

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);
}

void guardar_cod_nome(PESSOAS *pessoa){
FILE *ficheiro_cod_nome;

ficheiro_cod_nome = fopen("cod_nome.txt", "w");

while(pessoa->cod != 0){
    if(pessoa->cod == 4785392){

      pessoa++;

    }else{

    fprintf(ficheiro_cod_nome, "%d\t%s\n", pessoa->cod, pessoa->nome);
    pessoa++;

  }
 }

  fclose(ficheiro_cod_nome);

}

void remover_linhas_vazias(const char *filename) {
  FILE *fp_in = fopen(filename, "r");
  
  if (fp_in == NULL) {

    fprintf(stderr, "Erro a abrir o ficheiro %s \n", filename);
    exit(1);
  }


  FILE *fp_out = fopen("temp.txt", "w");

  if (fp_out == NULL) {

    fprintf(stderr, "Erro a abrir o ficheiro temporario\n");
    exit(1);
  
  }

  char line[1024];
  
  while (fgets(line, sizeof(line), fp_in)) {

    if (strcmp(line, "\n") != 0) {

      fputs(line, fp_out);

    }
  }

  fclose(fp_in);
  fclose(fp_out);

  rename("temp.txt", filename);
}

void guardar_cod_dataN_cidade(PESSOAS *pessoa){
FILE *ficheiro_cod_dataN_cidade;

ficheiro_cod_dataN_cidade = fopen("cod_dataN_cidade.txt", "w");

  while(pessoa->cod != 0){
    if(pessoa->cod == 4785392){

       pessoa++;

    }else{
    
    char *string = (char*) malloc(100*sizeof(char));
    sprintf(string, "%d\t%d-%d-%d\t%s\n",pessoa->cod, pessoa->dataN.dia, pessoa->dataN.mes, pessoa->dataN.ano, pessoa->cidade);
    
    size_t count = fwrite(string, sizeof(char), strlen(string), ficheiro_cod_dataN_cidade);

    printf("%s  \n", string);

    pessoa++;
  
  }
 }
  
    fclose(ficheiro_cod_dataN_cidade);
}

void guardar_struct_ficheiro(PESSOAS *pessoa){

  guardar_cod_nome(pessoa);

  guardar_cod_dataN_cidade(pessoa);

  remover_linhas_vazias("cod_nome.txt");
  remover_linhas_vazias("cod_dataN_cidade.txt");

  printf("Ficheiro guardado com sucesso!\n");

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  menu(pessoa);

}

void cidade_mais_pessoas(PESSOAS *pessoa){
  int num_pessoas = 0;
  while (pessoa->cod != 0)
  {
      num_pessoas++;
      pessoa++;
  }
  pessoa -= num_pessoas;
    int contador_cidade[num_pessoas];
  for (int i = 0; i < num_pessoas; i++) {
    contador_cidade[i] = 0;
  }

  for (int i = 0; i < num_pessoas; i++) {
    int index_cidade = -1;
    for (int j = 0; j < i; j++) {
      if (strcmp((pessoa + i)->cidade, (pessoa + j)->cidade) == 0) {
        index_cidade = j;
        break;
      }
    }
    if (index_cidade == -1) {
      index_cidade = i;
    }
    contador_cidade[index_cidade]++;
  }

  int cidade_mais_comum = 0;
  for (int i = 1; i < num_pessoas; i++) {
    if (contador_cidade[i] > contador_cidade[cidade_mais_comum]) {
      cidade_mais_comum = i;
    }
  }

  printf("\n\nA cidade com mais pessoas é %s com %d pessoas\n\n", (pessoa + cidade_mais_comum)->cidade, contador_cidade[cidade_mais_comum]);

}

void media_idades_cidade(PESSOAS *pessoa){
  char* cidade;
  cidade = (char*)malloc(sizeof(char) * MAX_LINHA);

  printf("\nInsiria a cidade cuja quer saber a idade media:\t");
  scanf("%s", cidade);

  int iterador = 0;
  int soma = 0;
  int contador = 0;

  float media = 0;

  while (pessoa->cod != 0)
  {
      if (compare(pessoa->cidade, cidade) == 0)
      {
          soma += (2023 - (pessoa->dataN.ano));
          contador++;
      }

      pessoa++;
      iterador++;
  }

  pessoa -= iterador;
  media = soma / contador;

  printf("\n\nA media de idades das pessoas de  %s é de %f\n", cidade, media);

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);

}

void mes_mais_nascimentos(PESSOAS *pessoa){

int iterador = 0;
int janeiro = 0, fevereiro = 0, marco = 0, abril = 0;
int maio = 0, junho = 0, julho = 0, agosto = 0;
int setembro = 0, outubro = 0, novembro = 0, dezembro = 0;
int mes1 = pessoa->dataN.mes;

  while (pessoa->cod != 0){
    
    switch (mes1)
    {
    case 1:
        janeiro++;
        break;
    case 2:
        fevereiro++;
        break;
    case 3:
        marco++;
        break;
    case 4:
        abril++;
        break;
    case 5:
        maio++;
        break;
    case 6:
        junho++;
        break;
    case 7:
        julho++;
        break;
    case 8:
        agosto++;
        break;
    case 9:
        setembro++;
        break;
    case 10:
        outubro++;
        break;
    case 11:
        novembro++;
        break;
    case 12:
        dezembro++;
        break;
    default:
      printf("mes invalido");
      break;
    }

    pessoa++;
    iterador++;
    mes1 = pessoa->dataN.mes;
  }

    int maior = janeiro;
    int mes_maior = 1;

    if (fevereiro > maior)
    {
        maior = fevereiro;
        mes_maior = 2;
    }
    if (marco > maior)
    {
        maior = marco;
        mes_maior = 3;
    }
    if (abril > maior)
    {
        maior = abril;
        mes_maior = 4;
    }
    if (maio > maior)
    {
        maior = maio;
        mes_maior = 5;
    }
    if (junho > maior)
    {
        maior = junho;
        mes_maior = 6;
    }
    if (julho > maior)
    {
        maior = julho;
        mes_maior = 7;
    }
    if (agosto > maior)
    {
        maior = agosto;
        mes_maior = 8;
    }
    if (setembro > maior)
    {
        maior = setembro;
        mes_maior = 9;
    }
    if (outubro > maior)
    {
        maior = outubro;
        mes_maior = 10;
    }
    if (novembro > maior)
    {
        maior = novembro;
        mes_maior = 11;
    }
    if (dezembro > maior)
    {
        maior = dezembro;
        mes_maior = 12;
    }

    printf("O mes com mais nascimentos é %d\n", mes_maior);

    pessoa -= iterador;
  
  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);


}

int calcular_mes_pascoa(int ano){
  int a = ano % 19;
  int b = ano / 100;
  int c = ano % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * l) / 451;
  int mes = (h + l - 7 * m + 114) / 31;

  return mes;
}

int calcular_dia_pascoa(int ano){
  int a = ano % 19;
  int b = ano / 100;
  int c = ano % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * l) / 451;
  int dia = ((h + l - 7 * m + 114) % 31) + 1;

  return dia;
}

int mes_carnaval(int ano){
  int mes_pascoa = calcular_mes_pascoa(ano);
  int dia_pascoa = calcular_dia_pascoa(ano);

  if (mes_pascoa == 3 && dia_pascoa > 21)
  {
    return 2;
  }
  else
  {
    return 3;
  }
  
}

int dia_carnaval(int ano){
  int mes_pascoa = calcular_mes_pascoa(ano);
  int dia_pascoa = calcular_dia_pascoa(ano);

  if (mes_pascoa == 3 && dia_pascoa > 21)
  {
    return dia_pascoa - 47;
  }
  else
  {
    return dia_pascoa - 46;
  }
  
}

void aniversario_quaresma(PESSOAS *pessoa){
  
  printf("digite o ano que quer saber os aniversariantes da quaresma:\t");
  int ano;
  scanf("%d", &ano);

  int iterador = 0;

  int mes_carnaval1 = mes_carnaval(ano);
  int mes_pascoa = calcular_mes_pascoa(ano);
  int dia_pascoa = calcular_dia_pascoa(ano);
	
  int carnaval_dia = dia_pascoa - 47;

  if (carnaval_dia < 1){

    mes_carnaval1--;

    if (mes_carnaval1 < 1){

      mes_carnaval1 = 12;
    }
    if (mes_carnaval1 == 2){

      carnaval_dia += 28;
    }
    else if (mes_carnaval1 == 4 || mes_carnaval1 == 6 || mes_carnaval1 == 9 || mes_carnaval1 == 11){

      carnaval_dia += 30;
    }
    else{

      carnaval_dia += 31;
    
    }
  
  }

	while(pessoa->cod != 0){
 		
 		if(pessoa->dataN.mes >= mes_carnaval1 && pessoa->dataN.mes <= mes_pascoa){

 			if(pessoa->dataN.dia <= dia_pascoa|| pessoa->dataN.dia >= carnaval_dia){

 					printf("\n Cod: %d",pessoa->cod);
					printf("\n\tName: %s", pessoa->nome);					
			 }
		 }		
		
    pessoa++;
    iterador++;

	}

  pessoa -= iterador;
	char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);


}

void cidadaos_nascidos_data(PESSOAS *pessoa){

  int dia, mes, ano, iterador = 0;

  printf("Insira o dia que pretende pesquisar: ");
  scanf("%d", &dia);

  printf("Insira o mes que pretende pesquisar: ");
  scanf("%d", &mes);

  printf("Insira o ano que pretende pesquisar: ");
  scanf("%d", &ano);

  while (pessoa->cod != 0){

    if (pessoa->dataN.dia == dia ){

      if (pessoa->dataN.mes == mes){

        if (pessoa->dataN.ano == ano){

          printf("Codigo: %d \n", pessoa->cod);
          printf("Nome: %s \n", pessoa->nome);

          pessoa++;
          iterador++;

        }else{

          pessoa++;
          iterador++;

        }

      }

      pessoa++;
      iterador++;

    }else{

      pessoa++;
      iterador++;

    }

  }

  pessoa -= iterador;
  
  char ch;
  fflush(stdin);
  printf("\n\n");
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);


  
}

void cidadaos_faixa_etaria(PESSOAS *pessoa){

  int ano_inicio_faixa_etaria, ano_fim_faixa_etaria;

  int iterador = 0;

  printf("Insira a idade de inicio da faixa etaria : ");
  scanf("%d", &ano_inicio_faixa_etaria);

  printf("Insira a idade de fim da faixa etaria : ");
  scanf("%d", &ano_fim_faixa_etaria);

  while (pessoa->cod != 0){

  int aux = 2023 - pessoa->dataN.ano;

  if (aux >= ano_inicio_faixa_etaria){

    if (aux <= ano_fim_faixa_etaria){

      printf("Codigo: %d \n", pessoa->cod);
      printf("Nome: %s \n", pessoa->nome);

      pessoa++;
      iterador++;

    }else{

      pessoa++;
      iterador++;

    }
  
  }
  pessoa++;
  iterador++;
  }

  pessoa -= iterador;

  printf("\n\n");

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);

}

void pesquisar_por_parte_nome(PESSOAS *pessoa){


  int iterador = 0;

  char *nome = (char *)malloc (sizeof(char) * 100);

  printf("Insira a parte do nome que pretende pesquisar: ");
  scanf("%s", nome);

  while (pessoa->cod != 0){

    if (strstr(pessoa->nome, nome) != NULL)
    {
      printf("\n Codigo: %d    Nome: %s   \n", pessoa->cod, pessoa->nome);
    }

    pessoa++;
    iterador++;

  }

  pessoa -= iterador;

  char ch;
  printf("\n\n");
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  menu(pessoa);
}

void inserir_pessoas(PESSOAS *pessoa) {

   int cod = 0;
   int dia = 0;
   int mes = 0;
   int ano = 0;
	 char aux[5];

	 char *nome = (char *)malloc(sizeof(char) * MAX_LINHA);
	 char *cidade = (char *)malloc(sizeof(char) * MAX_LINHA);
  

	 system("clear");
	
	 printf("Introduza o codigo: ");
	 scanf("%d", &cod);

   if(cod == 4785392){
      printf("Este codigo ja está reservado para outros fins");
      inserir_pessoas(pessoa);
   }

	 printf("\n Introduza o nome: ");
	 scanf("%c",&aux);
	 fgets(nome, MAX_LINHA, stdin);
	

	 while(dia < 1 || dia > 31 || mes < 1 || mes > 12){
    
      printf("\n Dia de nascimento formato (dd-mm-yyyy): ");
		  scanf("%d-%d-%d", &dia, &mes, &ano);

  }
	
	printf("\n Cidade: ");
	scanf("%c",&aux[1]);
	fgets(cidade, MAX_LINHA, stdin);
	

	pessoa->cod = cod;
  pessoa->nome = nome;
  pessoa->dataN.dia = dia;
  pessoa->dataN.mes = mes;
  pessoa->dataN.ano = ano;
  pessoa->cidade = cidade;

	
	printf("Pessoa adicionada com sucesso.\n");


    char ch;
    fflush(stdin);
    printf(" digite qualquer tecla para voltar ao menu");
    scanf("%c", &ch);
    getchar();
    system("clear");
    menu(pessoa);

}

void eliminar_pessoas(PESSOAS *pessoa){
  int cod;
  
  printf("Insira o codigo da pessoa que pretende eliminar: ");
  scanf("%d", &cod);
  int iterador = 0;
  while (pessoa->cod != 0)
  {
    if (pessoa->cod == cod)
    {
      pessoa->cod =  4785392;
      pessoa->nome = NULL;
      pessoa->dataN.dia=0;
      pessoa->dataN.mes=0;
      pessoa->dataN.ano=0;
      pessoa->cidade = NULL;
    }
    
    pessoa++;
    iterador++;
  
  }

  pessoa -= iterador;

  printf("Pessoa eliminada com sucesso");

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  system("clear");
  menu(pessoa);

}

void pesquisar_por_cidade(PESSOAS *pessoa){
  
  char *cidade = (char *)malloc(sizeof(char) *100);

  printf("Insira a cidade que pretende pesquisar: ");
  scanf("%s", cidade );

  printf("Pessoas que nasceram na cidade %s: \n\n", cidade);

  int iterador = 0;

  while (pessoa->cod != 0)
  {
    if (compare(pessoa->cidade, cidade) == 0)
    {

      printf("  Codigo: %d    Nome: %s\n", pessoa->cod, pessoa->nome);

    }

    pessoa++;
    iterador++;

  }

  pessoa -= iterador;

  printf("\n\n");

  char ch;
  fflush(stdin);
  printf("digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  menu(pessoa);

}

void listar_pessoas(PESSOAS *pessoa){

  int iterador = 0;
  while (pessoa->cod != 0)
  {
    iterador++;
    printf("\n Codigo: %d  Nome: %s \n", pessoa->cod, pessoa->nome);
    printf("\t Data de nascimento: %d-%d-%d  Cidade: %s  \n", pessoa->dataN.dia, pessoa->dataN.mes, pessoa->dataN.ano, pessoa->cidade);
    pessoa++;
  
  }
  
  pessoa-=iterador;

  char ch;
  fflush(stdin);
  printf(" digite qualquer tecla para voltar ao menu");
  scanf("%c", &ch);
  getchar();
  menu(pessoa);
  
}

PESSOAS *ficheiro_para_struct(){

  FILE *File_cod_nome = fopen("cod_nome.txt", "r");

  if (File_cod_nome == NULL)
  {
    perror("Erro na abertura do ficheiro");
    exit(1);
  }
  FILE *File_cod_data_cidade = fopen("cod_dataN_cidade.txt", "r");

  if (File_cod_data_cidade == NULL)
  {
    perror("Erro na abertura do ficheiro");
    exit(1);
  }

  int num_linhas = 0;
  int i;
  char *linha = (char *)malloc(sizeof(char) * MAX_LINHA);
  while (fgets(linha, MAX_LINHA, File_cod_nome) != NULL)
  {
    num_linhas++;
  }

  PESSOAS *pessoa;
  pessoa = (PESSOAS *)malloc(sizeof(PESSOAS) * num_linhas);

  fseek(File_cod_nome, 0, SEEK_SET);
  while (fgets(linha, MAX_LINHA, File_cod_nome) != NULL)
  {
    pessoa->cod = atoi((char *)strtok(linha, "\t"));

    pessoa->nome = (char *)malloc(sizeof(char) * 100);
    strcpy(pessoa->nome, (char *)strtok(NULL, "\n"));

    while (fgets(linha, MAX_LINHA, File_cod_data_cidade) != NULL)
    {
      int cod = atoi((char *)strtok(linha, "\t"));
      if (pessoa->cod == cod)
      {
        pessoa->dataN.dia = atoi((char *) strtok(NULL, "-"));
				pessoa->dataN.mes = atoi((char *) strtok(NULL, "-"));
				pessoa->dataN.ano = atoi((char *) strtok(NULL, "\t"));

        pessoa->cidade = (char *)malloc(sizeof(char) * 100);
        strcpy(pessoa->cidade, (char *)strtok(NULL, "\n"));

        break;
      }
    }
    pessoa++;
  }

  fclose(File_cod_data_cidade);
  fclose(File_cod_nome);

  for (i = 0; i < num_linhas; i++)
  {
    pessoa--;
  }

  return pessoa;
}

void paginainicial(PESSOAS *pessoa){
	system("clear");
	int option;
            printf("\n");                                                                                                        
    FILE *fptr;
      // Open file
      fptr = fopen("estgv.txt", "r");
      if (fptr == NULL)
      {
          printf("Não é possivel abrir o ficheiro \n");
          exit(0);
      }
    
      // Read contents from file
      int c;
      c = fgetc(fptr);
      while (c != EOF)
      {
          printf ("%c", c);
          c = fgetc(fptr);
      }
      printf("\n");
      fclose(fptr);
            printf("\n");
            printf("         ----------------------------------------------------------------------------\n");
            printf("         |                                                                          |\n");
            printf("         |      BEM VINDO AO PROJETO VERSÃO B  CLICA NA TECLA 1 PARA COMEÇAR        |\n");
            printf("         |      PARA SAIR DO PROGRAMA CLICAR NA TECLA 0                             |\n");
            printf("         ----------------------------------------------------------------------------\n");
            printf("\n Option:\t");
            scanf(" %d", &option);
            system("clear");
    
    switch (option){

  case 0:
      creditos_finais();
      break;
  case 1:
      menu(pessoa);
      break;
  default:
      printf("Opção inválida\n");
      paginainicial(pessoa);
      break;
        }
    
}

void creditos_finais(){
	
	system("clear");
    printf("\n");printf("\n");
    printf("   -------------------------------------------------\n");
    printf("  |     		Programa:	            |\n");
    printf("  |               Registo de Nascimentos            |\n");
    printf("  |     	É seguro fechar a janela            |\n");
    printf("  |              <  Grupo 12 | Tema B  >            |\n");
    printf("   -------------------------------------------------\n");
    printf("\n");printf("\n");printf("\n");
    exit(0);
}

void menu(PESSOAS *pessoa)
{
  system("clear");
  fflush(stdin);


  int op;
          printf("\n");
          printf("   -----------------------------------------------------------------------------------------------------------------------------------------------------\n");
          printf("  |                                                                    Menu Principal                                                                   |\n");
          printf("  |                                                                  Selecione uma opção:                                                               |\n");
          printf("  |                                                                                                                                                     |\n");
          printf("  |  1 - Inserir pessoa                                                        | 2 - Eliminar pessoa                                                    |\n");
          printf("  |  3 - Pesquisar por parte de nome                                           | 4 - Listar todos os cidadãos                                           |\n");
          printf("  |  5 - Listar cidadão que nasceu numa determinada cidade                     | 6 - Listar cidadãos que nasceram numa determinada faixa etaria         |\n");
          printf("  |  7 - Listar cidadãos que nasceram numa determinada data                    | 8 - Listar cidadãos por ordem alfabética do apelido                    |\n");
          printf("  |  9 - Determinar a cidade onde nasceram mais pessoas                        | 10 - Determinar a média de idades das pessoas que nasceram numa cidade |\n");
          printf("  |  11 - Determinar o mês em que ocorreram mais nascimentos                   | 12 - Listar cidadãos que nasceram num Domingo                          |\n"); 
          printf("  |  13 - Listar Cidadãos cujo aniversário, num determinado ano, é na quaresma | 14 - Salvar alterações                                                 |\n");
          printf("  |  0 - Sair da aplicação                                                                                                                              |\n");
          printf("   -----------------------------------------------------------------------------------------------------------------------------------------------------\n");
          printf("\n Opção:\t");
          scanf(" %d", &op);
      system("clear");
      fflush(stdin);
  switch (op){

  case 0:
      creditos_finais();
      break;
  case 1:
      inserir_pessoas(pessoa);
      break;
  case 2:
      eliminar_pessoas(pessoa);
      break;
  case 3:
      pesquisar_por_parte_nome(pessoa);
      break;
  case 4:
      listar_pessoas(pessoa);
      break;
  case 5:
      pesquisar_por_cidade(pessoa);
      break;
  case 6:
      cidadaos_faixa_etaria(pessoa);
      break;
  case 7:
      cidadaos_nascidos_data(pessoa);
      break;
  case 8:
      listar_pessoas_alfabetica_apelido(pessoa);
      break;  
  case 9:
      cidade_mais_pessoas(pessoa);
      break;
  case 10:
      media_idades_cidade(pessoa);
      break;
  case 11:
      mes_mais_nascimentos(pessoa);
      break;
  case 12:
      nascidos_a_um_domingo(pessoa);
      break;
  case 13:
      aniversario_quaresma(pessoa);
      break;
  case 14:
      guardar_struct_ficheiro(pessoa);
      break;
  default:
      printf("Opção inválida\n");
      getchar();
      menu(pessoa);
      break;

  }

  
}

int main()
{
  //por causa dos acentos
  setlocale(LC_ALL, "Portuguese"); 


  PESSOAS *pointer = ficheiro_para_struct();
  paginainicial(pointer);
  return 0;

}

