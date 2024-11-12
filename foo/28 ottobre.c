#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,x,conta;
    printf("Inserire l'intervallo superiore: ");
    scanf("%d", &x);

    do {
        printf("Inserire il numero: ");
        scanf("%d", &n);
        if(n<x)
        {
            conta++;
            printf("%d\n", n);
        }
    }while(n!=0);
        conta--;
        printf("sono stati inseriti %d numeri minori di %d", conta, x);
        system("pause");
}
