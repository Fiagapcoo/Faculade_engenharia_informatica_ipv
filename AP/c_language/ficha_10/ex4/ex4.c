#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * potencia(x, n - 1);
    }
}

float somatorio_r_n(int n, int r){
    if (n == 0) {
        return 0;
    } else {
        float numerador = potencia(r,n);
        float denominador = factorial(n);
        return ((numerador/denominador)) + somatorio_r_n(n-1,r);
    }
}

int main(){
    int n, r;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("Insira o valor de r: ");
    scanf("%d", &r);
    printf("O somatório de %d é %d", n, somatorio_r_n(n,r));
}