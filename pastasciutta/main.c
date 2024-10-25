#include <stdio.h>
#include <stdlib.h>


void unisci_e_ordina(int ar1[1000], int ar2[1000]);
int main()
{
    int i, ar1[1000], ar2[1000];
    printf("Inserire i valori del primo vettore");
    for(i=0;i<10;i++){
        printf("\nInserire un numero: ");
        scanf("%d", &ar1[i]);
    }
    printf("Inserire i valori del secondo vettore");
    for(i=0;i<10;i++){
        printf("\nInserire un numero: ");
        scanf("%d", &ar2[i]);
    }
    unisci_e_ordina(ar1,ar2);
    for(i=0;i<20;i++){
        printf("\n%d",ar1[1]);
    }
    return 0;
}
void unisci_e_ordina(int ar1[1000], int ar2[1000]){
    int i, k, j, min, posizione, time;

    for(i=0;i<20;i++){
        printf("\n%d",ar1[1]);
    }
    for (k=0;k<20;k++)
        {
        min=ar1[k];
        posizione=k;
        for (j=i;j<10;j++){
        if (ar1[j]<min){
                min=ar1[j];
                posizione=j;
        }
        }
        time=ar1[posizione];
        ar1[posizione]=ar1[k];
        ar1[k]=time;
        }

}

