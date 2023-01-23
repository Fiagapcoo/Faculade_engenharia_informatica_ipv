//soma dos N primeiros numeros interios positivos, escrevendo em cada iteracao o total acumulado
#include <stdio.h>
int main(void)
{
    int n, i, soma = 0;
    printf("\nIntroduza um numero inteiro positivo: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        soma += i;
        printf("\nSoma = %d + %d = %d \t i = %d \t n = %d \t soma = %d \t \n", soma - i, i, soma, i, n, soma);
    }
    printf("\nSoma dos %d primeiros numeros = %d \t \n", n, soma);
    return 0;
}