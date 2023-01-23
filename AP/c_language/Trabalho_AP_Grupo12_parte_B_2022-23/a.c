#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct str
{
char st[20];
} STRING;


void bubble_sort(STRING *a, int n){
    STRING temp;
    int i,j;
    for(i=0;i<n-1;i++){

        for(j=0; j<n-2;j++){

            if(strcmp(a[j],a[j+1])>0){

                strcpy(temp, a[j]);
                strcpy(a[j+1], a[j]);
                strcpy(a[j+1] , temp);

            }
        }

    }


}