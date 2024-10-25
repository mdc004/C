#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
int cercax(int array[1000], int n, int x);
int main()
{   int q=0, vettore[1000],x;
    iniziallizzazione(&q,vettore);
    printf("\nInserire l'elemento da ricercare: ");
    scanf("%d", &x);
    x=cercax(vettore,q,x);
    printf("\nL'elemento si trova in posizione %d",x);
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
int cercax(int array[1000], int n, int x){
    int i, pos=-1;
    for(i=0; i<n; i++){
        if(array[i]==x)pos=i;
    }
    return pos;
}
