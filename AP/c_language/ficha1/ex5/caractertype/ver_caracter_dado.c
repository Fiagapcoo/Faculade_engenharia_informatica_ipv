#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    printf("Introduza um caracter: ");
    scanf("%c", &c);
    if (isalpha(c))
    {
        if (isupper(c))
        {
            printf("O caracter %c é uma letra maiúscula");
        }
        else
        {
            printf("O caracter %c é uma letra minúscula");
        }  
    }
    else if (isdigit(c))
    {
        printf("O caracter %c é um número  ");
    }
    else if (ispunct(c))
    {
        printf("O caracter %c é um caracter de pontuação  ");
    }
    else
    {
        printf("O caracter %c é um caracter especial  ");
    }
    return 0;
}