

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mes, dias, hoje, falta;
    printf("Digite o mes: ");
    scanf("%d", &mes);
    printf("Digite o dia de hoje: ");
    scanf("%d", &hoje);
    switch(mes)
    {
        case 1:
            dias = 31;
            break;
        case 2:
            dias = 28;
            break;
        case 3:
            dias = 31;
            break;
        case 4:
            dias = 30;
            break;
        case 5:
            dias = 31;
            break;
        case 6:
            dias = 30;
            break;
        case 7:
            dias = 31;
            break;
        case 8:
            dias = 31;
            break;
        case 9:
            dias = 30;
            break;
        case 10:
            dias = 31;
            break;
        case 11:
            dias = 30;
            break;
        case 12:
            dias = 31;
            break;
    }
    falta = dias - hoje;
    printf("Faltam %d dias ate o fim do mes", falta);
    return 0;
}