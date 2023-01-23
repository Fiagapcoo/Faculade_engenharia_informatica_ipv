/*Elabore um programa que determine os n primeiros múltiplos de um número inteiro m.*/
#include <stdio.h>
int main()
{
    int n, m, i;
    printf("Introduza um número: ");
    scanf("%d", &m);
    printf("Introduza um número: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%d x %d = %d \n", m, i, m * i);
    }
}