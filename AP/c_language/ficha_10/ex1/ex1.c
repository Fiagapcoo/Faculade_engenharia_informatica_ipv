#include <stdio.h>

int somatorio(int n){
    if (n == 0) {
        return 0;
    } else {
        return n + somatorio(n - 1);
    }
}

int main(){
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("O somatório de %d é %d", n, somatorio(n));
}