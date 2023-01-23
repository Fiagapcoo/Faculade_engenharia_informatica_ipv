#include <stdio.h>
int opcao;
float valor;
int main(){
    
    printf("1- cm para pol \n 2- kg para lbs \n 3- L para gal\n 4- ºC para ºF\n opção: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            printf("qual o valor em cm? ");
            scanf("%f",&valor);
            printf("\nvalor em pol: %f",valor/2.54);

            break;
        case 2:
            printf("qual o valor em kg? ");
            scanf("%f",&valor);
            printf("\nvalor em lbs: %f",valor/2.54);
            break;
        case 3:
            printf("qual o valor em L? ");
            scanf("%f",&valor);
            printf("\n valor em gal: %f",valor/ 3.785);
            break;
        case 4:
            printf("qual o valor em ºC? ");
            scanf("%f",&valor);
            printf("\n Valor em ºF: %f", 1.8*valor + 32);
            break;
        default:
            printf("\n opção inválida");
    }
}
