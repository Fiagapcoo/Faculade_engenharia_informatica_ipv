#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

float area_retangulo(Ponto p1, Ponto p2){
    float area;
    area = (p2.x - p1.x) * (p2.y - p1.y);
    return area;
}

float diagonal(Ponto p1, Ponto p2){
    float diagonal;
    diagonal = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return diagonal;
}

int main(){
    Ponto p1, p2;
    printf("Insira as coordenadas do ponto 1: ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Insira as coordenadas do ponto 2: ");
    scanf("%f %f", &p2.x, &p2.y);
    printf("A area do retangulo é: %.2f e a diagonal é: %.2f", area_retangulo(p1, p2), diagonal(p1, p2));
    return 0;
}

