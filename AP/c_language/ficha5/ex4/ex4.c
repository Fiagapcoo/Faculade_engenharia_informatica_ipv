#include <stdio.h>
#include <stdlib.h>
int pede_numero(){
    int n;
    printf("escreva um numero ");
    scanf("%d", &n);
    return n;
}

int calcular_cubo(int n){
    int cubo;
    cubo = n*n*n;
    printf("o Cubo de %d e %d", n, cubo);
    return cubo;
}
int main(){
    int n;
    n = pede_numero();
    calcular_cubo(n);
}