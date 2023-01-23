
#include <stdio.h>

int main()
{
    float c, f;
    printf("Digite a temperatura em ºC: ");
    scanf("%f", &c);
    f = (c*9/5)+32;
    printf("\n%.2f = %.2f",c, f);
    printf("Digite a temperatura em ºF: ");
    scanf("%f", &f);
    c = (f-32)*5/9;
    printf("\n%.2f = %.2f",f, c);
}