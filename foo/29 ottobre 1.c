#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,max;
    printf("per terminare inserire 0\n");
    printf("Inserire un numero: ");
    scanf("%d", &n);
    max=n;
    do {
    printf("Inserire un numero: ");
    scanf("%d", &n);
    if(n>max)
        max=n;
    }

    while(n!=0);
    printf("Il maggiore dei numeri inseriti e' %d\n", max);
    system("pause");
}
