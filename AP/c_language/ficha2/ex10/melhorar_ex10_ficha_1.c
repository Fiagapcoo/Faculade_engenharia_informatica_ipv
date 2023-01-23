#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mes, dias, hoje, falta;
    printf("Digite o mes: ");
    scanf("%d", &mes);
    if (mes>12 || mes<1){
        printf("Mes invalido!");
    }
    else{
        printf("Digite o dia: ");
        scanf("%d", &hoje);
        if (hoje>31 || hoje<1){
            printf("Dia invalido!");
        }
        else{
            if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                dias = 31;
            }
            else if (mes==4 || mes==6 || mes==9 || mes==11){
                dias = 30;
            }
            else{
                dias = 28;
            }
            falta = dias - hoje;
            printf("Faltam %d dias para o fim do mes!", falta);
        }
    }
    return 0;
}