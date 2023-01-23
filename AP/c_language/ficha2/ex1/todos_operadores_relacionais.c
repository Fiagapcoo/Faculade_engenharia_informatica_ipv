#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("    Digite o primeiro numero:    ");
    scanf(" %d", &a);
    printf("    Digite o segundo numero:    ");
    scanf(" %d", &b);
    printf("\n    O resultado da igualdade e:  %d    ", a==b);
    printf("\n    O resultado da diferenca e:  %d    ", a!=b);
    printf("\n    O resultado da maior que e:  %d    ", a>b);
    printf("\n    O resultado da menor que e:  %d    ", a<b);
    printf("\n    O resultado da maior ou igual e:  %d    ", a>=b);
    printf("\n    O resultado da menor ou igual e:  %d    ", a<=b);
    return 0;
}