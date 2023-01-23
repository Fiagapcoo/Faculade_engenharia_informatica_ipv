#include <stdio.h>
int main()
{
    int i, b;
    float a, resultado = 1;
    printf("Introduza um numero real: ");
    scanf("%f", &a);
    printf("Introduza um numero inteiro: ");
    scanf("%d", &b);
    for (i=1;i<=b;i++){
        resultado = resultado * a;
    }
    printf("O resultado é: %f", resultado);
    return 0;
}