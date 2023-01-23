#include <stdio.h>
int base, altura, resposta, area;

int calcular(int base, int altura){
    
    area = (base*altura)/2;
    return area;
}

int main(){

printf("qual a base?  ");
scanf("%d",&base);
printf("qual a altura? ");
scanf("%d",&altura);
resposta = calcular(base,altura);

printf("A area é: %d", resposta);

}