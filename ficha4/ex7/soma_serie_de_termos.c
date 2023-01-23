#include <stdio.h>
#include <stdlib.h>
int main(){
    int numero, aux, i;
    float resultado;
    resultado = 0;
    aux = 2;

    printf("escolha o numero maximo da sequencia: ");
    scanf("%d", &numero);
    for (i=0;i<=numero;i++){
        resultado = resultado + (1.0/aux);
        aux = aux + 2;
    }
    resultado = 1.0 - resultado;
    printf("resultado: %f", resultado);
return 0;
}