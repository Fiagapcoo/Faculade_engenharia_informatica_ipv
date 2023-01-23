#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>



int potencia(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * potencia(x, n - 1);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int x, n;
    printf("Insira o valor de x: ");
    scanf("%d", &x);
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("%d elevado a %d é %d    ", x, n, potencia(x, n));
}