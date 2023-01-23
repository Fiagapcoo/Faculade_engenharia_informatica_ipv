#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutos, horas, minutos_restantes;
    printf("    Digite o numero de minutos:    ");
    scanf(" %d", &minutos);
    horas = minutos/60;
    minutos_restantes = minutos%60;
    printf("    %d:%d", horas, minutos_restantes);
    return 0;
}