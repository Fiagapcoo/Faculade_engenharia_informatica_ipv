#include <stdio.h>
#include <stdio.h>
int main(){
    int numero,i;
    printf("Introduza o numero do qual deseja a tabuada: ");
    scanf("%d", &numero);
    for (i=1;i<=10;i++){
        printf("\n%d x %d = %d ", numero, i, numero*i);
    }
   return 0;
}