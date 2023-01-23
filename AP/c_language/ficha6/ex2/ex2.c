#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    printf("Digite uma string: ");
    scanf("%s",str);
    printf("Os dois primeiros caracteres sao: %c%c",str[0],str[1]);
    return 0;
}