#include <stdio.h>
int main()
{
    int num;
    printf("Introduza um número entre 0 e 9: ");
    scanf("%d", &num);
    while (num < 0 || num > 9){
    printf("Introduza um numero valido: ");
    scanf("%d", &num);
    }
    printf("O numero introduzido foi %d \n", num);
}