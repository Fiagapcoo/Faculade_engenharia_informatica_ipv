#include <stdio.h>
#define MAX 100


int ler(v[MAX], n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Introduza o elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}

int mostrar(v[MAX], n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int mostrar_inversa(v[MAX], n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", v[i]);
    }
}

int max_vetor(v[MAX], n)
{
    int i, max = v[0];
    for (i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    printf("O maior elemento do vector é %d", max);
}

int min_vetor(v[MAX], n)
{
    int i, min = v[0];
    for (i = 1; i < n; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    printf("O menor elemento do vector é %d", min);
}

int soma(v[MAX], n)
{
    int i, soma = 0;
    for (i = 0; i < n; i++)
    {
        soma += v[i];
    }
    printf("A soma dos elementos do vector é %d", soma);
}

int media_elementos(v[MAX], n)
{
    int i, soma = 0;
    for (i = 0; i < n; i++)
    {
        soma += v[i];
    }
    printf("A média dos elementos do vector é %d", soma / n);
}

int inf_sup_med(v[MAX], n)
{
    int i, soma = 0, inf = 0, sup = 0;
    for (i = 0; i < n; i++)
    {
        soma += v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] < soma / n)
        {
            inf++;
        }
        else if (v[i] > soma / n)
        {
            sup++;
        }
    }
    printf("Existem %d elementos inferiores à média e %d elementos superiores à média", inf, sup);
}

int duplica(v[MAX], n)
{   
    int vetor[MAX];
    int i;
    for (i = 0; i < n; i++)
    {
        vetor[i] = v[i]*2;
    }
}

int intercalar(v[MAX], n)
{
    int vetor[MAX];
    int vetor2[MAX];
    int i, j;
    for (i = 0, j = 0; i < n; i++, j+=2)
    {
        vetor[j] = v[i];
        vetor[j+1] = v[n-i-1];
    }
}