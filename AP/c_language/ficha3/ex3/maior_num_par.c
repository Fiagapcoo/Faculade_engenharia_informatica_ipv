#include <stdio.h>
int main()
{
    int num, i, soma = 0;
    printf("Introduza um número: ");
    scanf("%d", &num);
    for (i = 1; i < num; i++)
    {
        if (i % 2 == 0)
        {
            soma += i;
            if (soma >= num)
            {
                printf("O maior número par é %d \n", i - 2);
                break;
            }
        }
    }
}