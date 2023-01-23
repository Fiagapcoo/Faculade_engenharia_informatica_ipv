#include <stdio.h>
int main()
{
    int num, i;
    printf("Introduza um número: ");
    scanf("%d", &num);
    for (i = 1; i < 100; i++)
    {
        if (i % num == 0)
        {
            printf("%d é múltiplo de %d e é inferior a 100 \n", i, num);
        }
    }
}