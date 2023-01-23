#include <stdio.h>
int main()
{
    int i, j, n;
    printf("Introduza um numero inteiro positivo: ");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
        for (j=1;j<=i;j++){
            printf("%d", j);
        }
        for (j=i-1;j>=1;j--){
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
