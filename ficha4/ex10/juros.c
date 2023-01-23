#include<stdio.h>
#include<locale.h>

int main() {

	int anos, i;
	float capital_inicial, taxa, acum;
	do{
	
	printf("Qual é o capital inicial?: ");
	scanf("%f", &capital_inicial);
	} while(capital_inicial<=0);
	do{
	printf("Qual é a taxa?: ");
	scanf("%f", &taxa);
	} while(taxa<0||taxa>1);
	do{
	printf("Qual é a duração em anos?: ");
	scanf("%d", &anos);
	} while(anos<1);
	
	acum=1;
	for(i=1; i<=anos; i++){
		acum=acum*(1+taxa);
		
	}
	printf("%f", acum);
		
}
	
