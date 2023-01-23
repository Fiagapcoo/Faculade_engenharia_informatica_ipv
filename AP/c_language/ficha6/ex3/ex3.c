#include <stdio.h>
#include <string.h>

void concatena(char *str1, char *str2){
    int i = 0;
    while(str1[i] != '\0'){
        i++;
    }
    int j = 0;
    while(str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main(){
    char str1[100];
    char str2[100];
    printf("Digite a primeira string: ");
    scanf("%s",str1);
    printf("Digite a segunda string: ");
    scanf("%s",str2);
    concatena(str1,str2);
    printf("A string resultante e: %s",str1);
    return 0;
}