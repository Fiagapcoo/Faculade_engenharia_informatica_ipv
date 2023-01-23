#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("    Digite o primeiro numero:    ");
    scanf(" %f", &a);
    printf("    Digite o segundo numero:    ");
    scanf(" %f", &b);
    printf("    Digite o terceiro numero:    ");
    scanf(" %f", &c);
    if(a>b && a>c)
    {
        printf("\n    O maior numero e:  %f    ", a);
    }
    else if(b>a && b>c)
    {
        printf("\n    O maior numero e:  %f    ", b);
    }
    else
    {
        printf("\n    O maior numero e:  %f    ", c);
    }
    return 0;
}