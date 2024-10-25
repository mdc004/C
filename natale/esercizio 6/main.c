#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
int decrescente(int array[1000], int n);
void stampa(int array[1000], int n);
int main()
{   int q=0, vettore[1000];
    iniziallizzazione(&q,vettore);
    vettore[1000]=decrescente(vettore,q);
    stampa(vettore,q);
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
int decrescente(int array[1000], int n){
    int j, i, mag, pos,tempo;
    for (i=0;i<n;i++){
        mag=array[i];
        pos=i;
        for (j=i;j<n;j++){
            if (array[j]>mag){
                mag=array[j];
                pos=j;
            }
        }
        tempo=array[pos];
        array[pos]=array[i];
        array[i]=tempo;
    }
    return array[1000];
}
void stampa(int array[1000], int n){
    int j;
    printf("Gli elementi dell'array sono:\n");
    for (j=0;j<n;j++)printf("%d\n",array[j]);
}
