#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("    Digite o primeiro numero:    ");
    scanf(" %d", &a);
    printf("    Digite o segundo numero:    ");
    scanf(" %d", &b);
    if(a%b==0)
    {
        printf("\n    O primeiro numero e multiplo do segundo");
    }
    else if(b%a==0)
    {
        printf("\n    O segundo numero e multiplo do primeiro");
    }
    else
    {
        printf("\n    Nenhum dos numeros e multiplo do outro");
    }
    return 0;
}