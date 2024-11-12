#include<stdio.h>
#include<stdlib.h>
int main()
{
    float media,n,x,num,somma;
    printf("Inserire la quantita' di numeri da inserire: ");
    scanf("%f", &n);
    x=n;
    while(x>0)
       {
        x--;
        printf("Inserire il numero: ");
        scanf("%f", &num);
        somma+=num;
       }
    media=somma/n;
    printf("La media e' %.2f \nLa somma e' %.2f\n", media, somma);
    system("pause");
}
