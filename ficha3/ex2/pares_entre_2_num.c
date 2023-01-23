#include <stdio.h>
int main()
{
    int ni, nf, i;
    printf("Introduza um número inicial: ");
    scanf("%d", &ni);
    printf("Introduza um número final: ");
    scanf("%d", &nf);
    for (i = ni; i <= nf; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d é par \n", i);
        }
    }
}