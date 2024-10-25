#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,num,prodotto,i;
    printf("Inserire il numero: ");
    scanf("%d", &n);



    for (i=n; i>0; i--)
        {
         prodotto=prodotto*i;

        }
printf("%d", prodotto);

}
