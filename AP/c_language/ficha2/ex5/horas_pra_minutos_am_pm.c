#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutos, horas, minutos_restantes;
    printf("    Digite o numero de minutos:    ");
    scanf(" %d", &minutos);
    horas = minutos/60;
    minutos_restantes = minutos%60;
    if(horas>12)
    {
        horas = horas - 12;
        printf("    %d:%d p.m.", horas, minutos_restantes);
    }
    else
    {
        printf("    %d:%d a.m.", horas, minutos_restantes);
    }
    return 0;
}