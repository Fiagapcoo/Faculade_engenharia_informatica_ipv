
#include <stdio.h>
#include <stdio.h>
int main(){
    int i, soma = 0, n;
    printf("Introduza um numero inteiro positivo: ");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
        soma = soma + i;
        printf("Soma = %d ", soma);
    }
    return 0;
}
