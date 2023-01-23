#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a,b;
    char op;
    printf("    CALCULADORA\n"); 
    printf("    1. Soma\n");
    printf("    2. Subtracao\n"); 
    printf("    3. Multipliacao\n");
    printf("    4. Divisao\n");
    printf("    5. Potencia\n");
    printf("    6. Raiz \n");
    printf("    7. Seno\n");
    printf("    8. Coseno\n");
    printf("    9. Tangente\n");
    printf("    10. Logaritmo\n");
    printf("    11. Sair\n");
    printf("    Escolha uma opcao:");
    scanf("%hhd", &op);

    switch(op)
    {
        case 1:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    Digite o segundo numero:    ");
            scanf(" %f", &b);
            printf("    O resultado da soma e:  %f    ", a+b);
            break;
        case 2:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    Digite o segundo numero:    ");
            scanf(" %f", &b);
            printf("    O resultado da subtracao e:  %f    ", a-b);
            break;
        case 3:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    Digite o segundo numero:    ");
            scanf(" %f", &b);
            printf("    O resultado da multiplicacao e:  %f    ", a*b);
            break;
        case 4:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    Digite o segundo numero:    ");
            scanf(" %f", &b);
            printf("    O resultado da divisao e:  %f    ", a/b);
            break;
        case 5:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    Digite o segundo numero:    ");
            scanf(" %f", &b);
            printf("    O resultado da potencia e:  %f    ", pow(a,b));
            break;
        case 6:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    O resultado da raiz e:  %f    ", sqrt(a));
            break;
        case 7:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    O resultado do seno e:  %f    ", sin(a));
            break;
        case 8:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    O resultado do coseno e:  %f    ", cos(a));
            break;
        case 9:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a  );
            printf("    O resultado da tangente e:  %f    ", tan(a));
            break;
        case 10:
            printf("    Digite o primeiro numero:    ");
            scanf(" %f", &a);
            printf("    O resultado do logaritmo e:  %f    ", log(a));
            break;
        case 11:
            printf("    A sair   ");
            break;
        default:
            printf("    Opcao invalida    ");
    }
    return 0;
}