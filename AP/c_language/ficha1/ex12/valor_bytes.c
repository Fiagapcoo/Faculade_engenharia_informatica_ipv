
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
int main()
{
    printf("\nchar nomral %ld.O numero minimo de bytes de um char de %d e maximo é  %d", sizeof(char),CHAR_MIN, CHAR_MAX);
    printf("\nint normal %ld.O numero minimo de bytes de um int de %d e maximo é  %d", sizeof(int),INT_MIN, INT_MAX);
    printf("\nfloat normal %ld.O numero minimo de bytes de um float de %d e maximo é  %d", sizeof(float),FLT_MIN, FLT_MAX);
    printf("\ndouble normal %ld.O numero minimo de bytes de um double de %ls e maximo é  %d", sizeof(double),DBL_MIN, DBL_MAX);
}