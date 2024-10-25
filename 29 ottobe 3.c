#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,conta,somma;
    printf("per terminare inserire 0\n");
    somma=0;
    do {
    printf("Inserire un numero: ");
    scanf("%d", &n);
    if (n%3==0){
        if(n!=0){
            conta++;
            printf("%d e' un multiplo di 3\n");
            somma+=n;
            }
        }
    }

    while(n!=0);
    printf("Sono stati inseriti %d multipi di 3\n", conta);
    printf("La loro somma e' pari a %d\n", somma);
    system("pause");
}
