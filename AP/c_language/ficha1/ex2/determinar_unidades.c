#include <stdio.h>
#include <stdlib.h>
float dinheiro;
float preco;
int unidades;
float troco;
void main(){

    printf("Digite o dinheiro: ");
    scanf("%f",&dinheiro);
    printf("Digite o preco: ");
    scanf("%f",&preco);

    unidades = dinheiro / preco;
    troco = dinheiro - (unidades * preco);

    printf("Obtiveram-se %d unidades, e obteve-se de troco %.2f €", unidades, troco);


    
}