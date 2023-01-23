#include <stdio.h>
#include <stdlib.h>
int resto (int a, int b){
    int r;
    r = a%b;
    return r;
}

int impar (int x){
    if(resto(x,2)==0){
        return 0;
    }
    else{
        return 1;
    }
}

int perfeito (int n){
    int i, soma;
    soma = 0;
    for(i=1; i<n; i++){
        if(resto(n,i)==0){
            soma = soma + i;
        }
    }
    if(soma==n){
        return 1;
    }
    else{
        return 0;
    }
}

int primo (int n){
    int i, soma;
    soma = 0;
    for(i=1; i<=n; i++){
        if(resto(n,i)==0){
            soma = soma + 1;
        }
    }
    if(soma==2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n,b;
    printf("escreva um numero ");
    scanf("%d", &n);
    printf("escreva o segundo numero");
    scanf("%d", &b);
    printf("\no resto e %d", resto(n,b));
    printf("\no numero e impar %d", impar(n));
    printf("\no numero e perfeito %d", perfeito(n));
    printf("\no numero e primo %d", primo(n));

}