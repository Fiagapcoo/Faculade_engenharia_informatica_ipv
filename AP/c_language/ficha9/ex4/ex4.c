#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct livro
{
	char titulo[30];
	char autor[30];
	char area[20];
	int ano;
	int ocupado;
}LIVRO;

void iniciarLivro(LIVRO *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		(*p).ocupado = 0;//p->ocupado=0;
		p++;
	}
}

void removerLivro(LIVRO *p, int n)
{
	int i;
	do
	{
		printf("\nQual o indice a remover? ");
		scanf("%d", &i);
	} while ((i < 0) || (i >= n));

	(p + i)->ocupado = 0;
}

void inserirLivro(LIVRO *p, int n)
{

	int i;
	i = 0;
	while ((p->ocupado != 0) && (i < n))
	{
		p++; i++;
	}
	if (i < n)
	{
		p->ocupado = 1;
		fseek(stdin, 0, 2);
		printf("\nT?tulo: ");
		gets(p->titulo);
		printf("\nAutor: ");
		gets(p->autor);
		printf("\nArea: ");
		gets(p->area);
		printf("\nAno: ");
		scanf("%d", &(p->ano));
	}
	else
		printf("\nVetor cheio!!\n");
}

void listarLivros(LIVRO *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (p->ocupado != 0)
		{
			printf("\nTitulo: %s", p->titulo);
			printf("\nAutor: %s", p->autor);
			printf("\nArea: %s", p->area);
			printf("\nAno: %d\n\n", p->ano);
		}
		p++;
	}
}

void le_ficheiro(LIVRO *biblio, int n) {
	// Ponteiro para o ficheiro
	FILE *file = fopen("livros.bin", "rb");
	
	if (file == NULL) {
		printf("ERRO: Impossivel abrir ficheiro livros.bin");
		exit(1);
	}
	
	fread(biblio, sizeof(LIVRO), n, file);
	fclose(file);
}

void escreve_ficheiro(LIVRO *biblio, int n) {
	// Ponteiro para o ficheiro
	FILE *file = fopen("livros.bin", "wb");
	
	if (file == NULL) {
		printf("ERRO: Impossivel abrir ficheiro livros.bin");
		exit(1);
	}
	int i;
	for(i = 0; i < n; i++)
		if(biblio->ocupado != 0){
	fwrite(biblio, sizeof(LIVRO), n, file);
	fclose(file);
	}
}

int main(int argc, char *argv[])
{
	int op;
	LIVRO *biblio = (LIVRO *) malloc(sizeof(LIVRO) * MAX);
	
	iniciarLivro(biblio, MAX);
	
	do
	{
		printf("\n\n\tMENU****\n");
		printf("1 - Inserir novo livro\n");
		printf("2 - Remover livro\n");
		printf("3 - Listar livros\n");
		printf("4 - Ler Ficheiro\n");
		printf("5 - Escrever ficheiro\n");
		printf("6 - Sair\n");
		printf("\nDigite opcao: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:inserirLivro(biblio, MAX); break;
		case 2:removerLivro(biblio, MAX); break;
		case 3:listarLivros(biblio, MAX); break;
		case 4:le_ficheiro(biblio, MAX); break;
		case 5:escreve_ficheiro(biblio, MAX); break;
		case 6:printf("\nAdeus\n"); break;
		default:printf("\nOpcao invalida!\n\n"); break;
		}
		system("pause");
	} while (op != 6);

	free(biblio);
}