#include <stdio.h>
int main()
{
    char c;
    printf("Introduza um caracter: ");
    scanf("%c", &c);
    if (c >= 'A' && c <= 'Z')
        printf("O caracter %c e uma letra maiuscula \n", c);
    else if (c >= 'a' && c <= 'z')
        printf("O caracter %c e uma letra minuscula \n", c);
    else if (c >= '0' && c <= '9')
        printf("O caracter %c e um numero \n", c);
    else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '[' || c == ']' || c == '{' || c == '}' || c == ';' || c == ':' || c == '\'' || c == '"' || c == ',' || c == '.' || c == '<' || c == '>' || c == '/' || c == '?' || c == '`' || c == '~')
        printf("O caracter %c e um caracter de pontuacao \n", c);
    else
        printf("O caracter %c e um caracter especial \n", c);
    return 0;
}