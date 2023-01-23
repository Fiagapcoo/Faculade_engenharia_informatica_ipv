#include <stdio.h>
#include <stdlib.h>

int produto (int a[], int b[], int len){
    int i, prod;
    prod = 0;
    for(i=0; i<len; i++){
        prod = prod + a[i]*b[i];
    }
    return prod;
}

int main(){
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int len = sizeof(a) / sizeof(a[0]);
    int len2 = sizeof(b) / sizeof(b[0]);
    if(len==len2){
    int prod;
    prod = produto(a, b, len);
    printf("\n%d", prod);
    }else{
        printf("os vetores nao tem o mesmo tamanho");
    }
}