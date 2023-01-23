#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b,c;
    printf("    Digite o primeiro numero:    ");
    scanf(" %f", &a);
    printf("    Digite o segundo numero:    ");
    scanf(" %f", &b);
    printf("    Digite o terceiro numero:    ");
    scanf(" %f", &c);
    if(a==0)
    {
        printf("\n    O primeiro numero nao pode ser zero");
    }
    else
    {
        float delta = b*b - 4*a*c;
        if(delta<0)
        {
            printf("\n    Nao existem raizes reais");
        }
        else if(delta==0)
        {
            float x = -b/(2*a);
            printf("\n    A unica raiz e:  %f    ", x);
        }
        else
        {
            float x1 = (-b + sqrt(delta))/(2*a);
            float x2 = (-b - sqrt(delta))/(2*a);
            printf("\n    As raizes sao:  %f    e  %f    ", x1, x2);
        }
    }
    return 0;
}