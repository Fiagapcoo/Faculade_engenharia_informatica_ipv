#include <stdio.h>

int main(){
    int num1, num2, num3, aux;
    printf("primeiro numero: ");
    scanf("%d", &num1);
    printf("segundo numero: ");
    scanf("%d", &num2);
    printf("terceiro numero: ");
    scanf("%d", &num3);
    aux = num1;
    if (aux < num2){
        aux = num2;
    }if (aux < num3){
        aux = num3;
    }
    printf("O maior numero é o %d ", aux);
    
}