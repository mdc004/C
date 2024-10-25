#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
void spostapos(int array[1000], int n);
int main(){
    int q=0, vettore[1000],i;
    iniziallizzazione(&q,vettore);
    q=q+1;
    spostapos(vettore,q);
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
void spostapos(int array[1000], int n){
    int i,sost,tempo;
    printf("Inserire il valore dell'elemento da mettere in prima posizione: ");
    scanf("%d",&sost);
    for (i=0;i<n;i++){
        tempo=array[i];
        array[i]=sost;
        sost=tempo;
    }
}
