#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("    Digite um numero:    ");
    scanf(" %d", &a);
    if(a%2==0)
    {
        printf("\n    O numero e par");
    }
    else
    {
        printf("\n    O numero e impar");
    }
}