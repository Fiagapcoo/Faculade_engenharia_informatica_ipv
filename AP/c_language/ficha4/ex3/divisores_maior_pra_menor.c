#include <stdio.h>
#include <stdio.h>
int main(){
    int numero, i;
    printf("Introduza um numero inteiro positivo: ");
    scanf("%d", &numero);
    for (i=numero;i>=1;i--){
        if (numero%i==0){
            printf("\n%d ", i);
        }
    }
    return 0;
}
