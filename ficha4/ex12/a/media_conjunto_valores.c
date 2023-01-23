#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i;
    float resultado, valor , media = 0;
    
    printf("Qual o numero de parcelas da sequencia? ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        printf("qual o numero da parcela %d? ", i+1);
        scanf("%f", &valor);
        resultado = resultado + valor;
    }
    media = resultado/n;
    printf("A media e: %f", resultado);

}