#include <stdio.h>
#include <stdlib.h>

int maior(int len,int mark[]){
    //see the highest mark
    int i, highest;
    highest = mark[0];
    for(i=1; i<len; i++){
        if(mark[i]>highest){
            highest = mark[i];
        }
    }
    return highest;
}

int escreve_vetor(int len,int mark[]){
    int i;
    for(i=0; i<len; i++){
        printf("\n%d", mark[i]);
    }
    return 0;
}

int main(){
    int mark[5] = {19, 10, 8, 17, 9};
    int len = sizeof(mark) / sizeof(mark[0]);
    printf("\nLEN = %d", len);
    int maior_nota;
    escreve_vetor(len, mark);
    maior_nota = maior(len, mark);
    printf("\no maior numero e %d", maior_nota);

}