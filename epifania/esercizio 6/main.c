#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
void spostapos(int array[1000], int n, int *position);
int main(){
    int q=0, vettore[1000],pos;
    iniziallizzazione(&q,vettore);
    q=q+1;
    printf("In che posizione vuoi inserire il nuovo elemento? ");
    scanf("%d",&pos);
    spostapos(vettore,q, &pos);
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
void spostapos(int array[1000], int n, int *position){
    int i,sost,tempo;
    printf("Inserire il valore dell'elemento da mettere in posizione %d: ",(*position));
    scanf("%d",&sost);
    for (i=*position;i<n;i++){
        tempo=array[i];
        array[i]=sost;
        sost=tempo;
    }
}
