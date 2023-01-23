/*Escreva uma função que determine o maior de dois números dados. Teste a função num
pequeno programa.
*/
// Language: c

// Path: ap/c__language/ficha5/ex5/ex5.c



#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int a,b;
    printf("escreva um numero ");
    scanf("%d", &a);
    printf("escreva o segundo numero ");
    scanf("%d", &b);
    printf("o maior numero e %d", maior(a,b));
}