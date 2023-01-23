#include <stdio.h>
int main(){

    int index;
    char names [5][50];
    for(index=0; index<5; index++){
        printf("nome da %D pessoa: ", index+1);
        scanf("%s",names[index]);
     }
    for(index=0; index<5; index++){
        printf("%s \n",names[index]);
    }
}
