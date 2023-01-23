#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
int main(){
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("O factorial de %d é %d", n, factorial(n));
}