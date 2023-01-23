#include <stdio.h>
#include <stdio.h>
int tabuada(int numero){
    int i;
    for (i=1;i<=10;i++){
        printf("\n%d x %d = %d ", numero, i, numero*i);
    }
    return 0;
}
int main(){
    for(int i = 2; i<=10; i++){
        tabuada(i);
        printf("\n\n");
    }
}