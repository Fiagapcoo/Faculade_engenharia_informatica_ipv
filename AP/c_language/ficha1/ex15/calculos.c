#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Digite um numero: ");
    scanf("%d", &x);
    printf("Digite outro numero: ");
    scanf("%d", &y);
    printf("\n%d + %d = %d    ", x, y, x+y);
    printf("\n%d * %d = %d    ", x, y, x*y);
    printf("\n%d / %d = %d    ", x, y, x/y);
    printf("\n%d %% %d = %d    ", x, y, x%y);
    return 0;
}
