#include <stdio.h>
#include <stdlib.h>

int isdigit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}
int isalpha(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
        return 1;
    }
    else{
        return 0;
    }
}
int isalnum(char c)
{
    if(isdigit(c) || isalpha(c)){
        return 1;
    }
    else{
        return 0;
    }
}
char tolower(char c){
    if(c>='a' && c<='z'){
        c = c + 32;
        return c;
    }
    else{
        return 0;
    }
}
char touooer(char c){
    if(c>='A' && c<='Z'){
        c = c - 32;
        return c;
    }
    else{
        return c;
    }
}

int main(){



}