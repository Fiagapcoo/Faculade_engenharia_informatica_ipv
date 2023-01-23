#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

void operacao(Fracao f1, Fracao f2, Fracao *f3, char op){
    switch (op){
        case '+':
            f3->numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
            f3->denominador = f1.denominador * f2.denominador;
            break;
        case '-':
            f3->numerador = (f1.numerador * f2.denominador) - (f2.numerador * f1.denominador);
            f3->denominador = f1.denominador * f2.denominador;
            break;
        case '*':
            f3->numerador = f1.numerador * f2.numerador;
            f3->denominador = f1.denominador * f2.denominador;
            break;
        case '/':
            f3->numerador = f1.numerador * f2.denominador;
            f3->denominador = f1.denominador * f2.numerador;
            break;
}
}

int main(){
    Fracao f1, f2, f3;
    char operacaooo;
    printf("Insira a primeira fracao: ");
    scanf("%d/%d", &f1.numerador, &f1.denominador);
    printf("Insira a segunda fracao: ");
    scanf("%d/%d", &f2.numerador, &f2.denominador);
    printf("Insira a operacao: ");
    scanf(" %c", &operacaooo);
    operacao(f1, f2, &f3, operacaooo);
    printf("Resultado: %d/%d", f3.numerador, f3.denominador);
    return 0;
    }

