#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
void deletex(int array[1000], int n, int x);
int main()
{   int q=0, vettore[1000],x;
    iniziallizzazione(&q,vettore);
    printf("\nInserire l'elemento da cancellare: ");
    scanf("%d", &x);
    deletex(vettore,q,x);
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
void deletex(int array[1000], int n, int x){
    int i,verifica=0;
    for(i=0; i<n; i++){
        if(array[i]==x){
            array[i]=0;
            verifica=1;
        }
    }
    if(verifica=0)printf("\nIl numero da cancellare non si trova all'interno dell'array");
    else printf("\nElemento cancellato con successo");
}
