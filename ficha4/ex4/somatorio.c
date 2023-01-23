#include <stdio.h>
#include <stdio.h>
int main(){
    int i, soma = 0;
    for (i=1;i<=5;i++){
        if (i!=5){
            soma = soma + i;
        }
    }
    printf("Soma = %d", soma);
    return 0;
}