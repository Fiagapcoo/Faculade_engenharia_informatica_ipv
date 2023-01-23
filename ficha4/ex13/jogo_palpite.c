#include <stdio.h>
#include <stdlib.h>
int gess(int numero,int i){
    int gess;
    while (i >-5)
    {
    
    printf("\nescreva a sua tentativa ");
    scanf("%d", &gess);
    if(gess == numero){
        printf("\nacertou");
        return 0;
    }
    else if (gess > numero){
        printf("\no numero e menor");
        i++;
    }
    else if (gess < numero){
        printf("\no numero e maior");
        i++;
    }      
}
}

int main(){
    int numero, i=0;
    printf("escreva um numero ");
    scanf("%d", &numero);
    if(numero>0 && numero<100){
        gess(numero,i);
    }
    else{
        printf("numero invalido\n");
        return 0;
    }
    
}