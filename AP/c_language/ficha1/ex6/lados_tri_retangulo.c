#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(){
    int opc;
    double cat,cat2,hip,solution;
    printf("1- Cateto e hipotenusa \n 2- Cateto e Cateto\n");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        printf("qual o valor do cateto? ");
        scanf("%lf",&cat);
        printf("qual o valor da hipotenusa ");
        scanf("%lf",&hip);
        solution = sqrt(hip*hip-cat*cat);
        printf("o valor do cateto é %lf",solution);       

        break;
    case 2:
        printf("qual o valor do cateto? ");
        scanf("%lf",&cat);
        printf("qual o valor do 2 cateto? ");
        scanf("%lf",&cat2);
        solution = sqrt(cat*cat+cat2*cat2);
        printf("\n o valor da hipotenusa é %lf",solution);
        
        break;
    
    default:
        break;
    }
}