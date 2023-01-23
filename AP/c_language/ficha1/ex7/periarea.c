#include <stdio.h>
#include <stdlib.h>

void main(){
    int opc;
    double base,altura,raio,perimetro,area;
    printf("1- Retangulo \n 2- Circulo\n 3- Quadrado\n");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        printf("qual o valor da base? ");
        scanf("%lf",&base);
        printf("qual o valor da altura? ");
        scanf("%lf",&altura);
        perimetro = 2*base+2*altura;
        area = base*altura;
        printf("o valor do perimetro é %lf e o valor da area é %lf",perimetro,area);       
        break;
    case 2:
        printf("qual o valor do raio? ");
        scanf("%lf",&raio);
        perimetro = 2*3.14*raio;
        area = 3.14*raio*raio;
        printf("o valor do perimetro é %lf e o valor da area é %lf",perimetro,area);       
        break;
    case 3:
        printf("qual o valor da base? ");
        scanf("%lf",&base);
        perimetro = 4*base;
        area = base*base;
        printf("o valor do perimetro é %lf e o valor da area é %lf",perimetro,area);       
        break;
    default:
        break;
    }
}