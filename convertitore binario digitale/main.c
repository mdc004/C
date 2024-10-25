#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void indigitale();
void inbinario();
int main()
{
    int choose;
    do{
        printf("1. per convertire da digitale a binario\n");
        printf("2. per convertire da binario a digitale\n");
        printf("\nscelta: ");
        scanf("%d", &choose);
        switch (choose){
        case 1:
            indigitale();
            break;
        case 2:
            inbinario();
            break;
        }
    }
    while(choose==-1325);
    return 0;
}

void indigitale(){
    int binario[1000],i=0, n, j;
    printf("\nInserire il numero da convertire: ");
    scanf("%d", &n);
    do{
        binario[i]=n%2;
        n/=2;
        i++;
    }
    while(n==0);
    for(j=i;j>=0;j--){
        printf("%d", binario[i]);
    }
}

void inbinario(){
    int numero[1000], i=0,j,n;
    printf("Inserire il numero da convertire: ");
    numero[0]=0;
    while(numero[i]!=2){
        printf("Inserire il numero da convertire: ");
        scanf("%d", &n);
        numero[i]=n;
        i++;
    }
    i--;
    n=0;
    for(j=i;j>=0;j--){
        n+=numero[i]*pow(2, i);
    }
    printf("%d", n);
}
