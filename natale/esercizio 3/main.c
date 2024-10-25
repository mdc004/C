#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
void contapari(int array[1000], int n);
int main()
{   int q=0, vettore[1000];
    iniziallizzazione(&q,vettore);
    contapari(vettore,q);
    return 0;
}
void iniziallizzazione(int *n, int array[1000]){
    int i;
    printf("Inserire la quantita' di elementi dell'array: ");
    scanf("%d",&(*n));
    for (i=0;i<*n;i++){
        printf("\nInserire un numero: ");
        scanf("%d",&array[i]);
    }
}
void contapari(int array[1000], int n){
    int j, conta=0;
    for (j=0;j<n;j++){
            if(array[j]%2==0)conta++;
    }
    printf("\nI numeri pari sono %d", conta);
}
