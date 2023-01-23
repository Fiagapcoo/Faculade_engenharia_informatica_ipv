#include <stdio.h>

int main(){
    int ano, a, b, c, d, e, f, g, h, i, k, l, m, p, dia, mes;
    printf("escreva o ano ");
    scanf("%d", &ano);
    if(ano>=1900 && ano<=2099){
        a = ano%19;
        b = ano/100;
        c = ano%100;
        d = b/4;
        e = b%4;
        f = (b+8)/25;
        g = (b-f+1)/3;
        h = (19*a+b-d-g+15)%30;
        i = c/4;
        k = c%4;
        l = (32+2*e+2*i-h-k)%7;
        m = (a+11*h+22*l)/451;
        p = (h+l-7*m+114)%31;
        dia = p+1;
        mes = (h+l-7*m+114)/31;
        printf("a pascoa e no dia %d do mes %d", dia, mes);
    }
    else{
        printf("ano invalido");
    }
}