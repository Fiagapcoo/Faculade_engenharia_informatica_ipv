#include <stdio.h>
#include <stdlib.h>
int troca(int array[]){
    int i, aux;
    aux = array[2];
    for(i=2; i>0; i--){
        array[i] = array[i-1];
    }
    array[0] = aux;
    return 0;
}
int permuta(int array[]){
    
int index1,index2, aux1, aux2;
printf ("qual o index que quer permutar? ");
scanf("%d", &index1);
printf ("qual o index que quer permutar com o anterior? ");
scanf("%d", &index2);
aux1 = array[index1];
aux2 = array[index2];

array[index1] = aux2;
array[index2] = aux1;

printf(array);

}
int main(){
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    permuta("%d", array);

}