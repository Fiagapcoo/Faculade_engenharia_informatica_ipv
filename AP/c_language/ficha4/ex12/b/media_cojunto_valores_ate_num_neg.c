#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero, i;
    float media;
    media = 0;
    printf("escreva um numero ");
    scanf("%d", &numero);
    if(numero < 0){
        return 0;
    }
    for (i=0;;i++){
        media = media + numero;
        printf("escreva um numero ");
        scanf("%d", &numero);
        if (numero < 0){
            break;
        }
        media = media / i;
        printf("media: %f", media);
    }
}