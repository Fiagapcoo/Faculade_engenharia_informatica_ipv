#include <stdio.h>
int main()
{
int classificacao;
printf("Introduza a classificação do atleta: ");
scanf("%d", &classificacao);
if (classificacao == 1)
{
printf("O atleta ganhou uma medalha de ouro!");
}
else if (classificacao == 2)
{
printf("O atleta ganhou uma medalha de prata!");
}
else if (classificacao == 3)
{
printf("O atleta ganhou uma medalha de bronze!");
}
else
{
printf("O atleta não ganhou medalha!");
}
return 0;
}