/*5 -Faça o algoritmo de um programa que leia números reais até que o utilizador introduza um número
xE[10, 15.5]. Implemente o algoritmo em linguagem C.*/
#include <stdio.h>
int main()
{
    float num;

    printf("Introduza um número: ");
    scanf("%f", &num);
    while (num < 10 || num > 15.5){
    printf("Introduza um numero valido");
    scanf("%f", &num);
    }
}