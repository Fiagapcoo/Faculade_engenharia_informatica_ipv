#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
int x[MAX], y[MAX], z[2*MAX], i, j, n;
printf("Introduza o numero de elementos dos vectores: ");
scanf("%d", &n);
printf("Introduza os elementos do vector x: ");
for(i=0; i<n; i++)
scanf("%d", &x[i]);
printf("Introduza os elementos do vector y: ");
for(i=0; i<n; i++)
scanf("%d", &y[i]);
for(i=0, j=0; i<n; i++, j+=2)
{
z[j] = x[i];
z[j+1] = y[n-i-1];
}
printf("Vector final: ");
for(i=0; i<2*n; i++)
printf("%d ", z[i]);
return 0;
}