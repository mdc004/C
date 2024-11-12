#include<stdio.h>
#include<stdlib.h>
int main()
{
    int somma, smax,n;
    printf("Inserire il valore massimo della somma: ");
    scanf("%d", &smax);

    do{
        printf("Inserire un numero positivo: ");
        scanf("%d", &n);
        somma+=n;
    }
    while (somma>=smax);
    }
