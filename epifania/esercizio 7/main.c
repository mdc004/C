#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
int cercax(int array[1000], int n, int x);
void stampa(int ar[1000], int numero_elementi);
void deletex(int array[1000], int n, int x);
void spostaposi(int array[1000], int n, int *position);
void spostapos(int array[1000], int n);

int main()
{   int q=0, vettore[1000], i, x, pos,choose;
    float m;
    do{
    printf("\nPremi\n");
    printf("0. per uscire dal programma\n");
    printf("1. per inserire gli elementi\n");
    printf("2. per stampare gli elementi\n");
    printf("3. per ricercare un valore\n");
    printf("4. per cancellare un elemento\n");
    printf("5. per inserire un elemento in prima posizione\n");
    printf("6. per inserire un elemento in qualsiasi pozione\n");
    scanf("%d",&choose);

    switch (choose){
    case 1: iniziallizzazione(&q,vettore);
            break;
    case 2: stampa(vettore,q);
            break;
    case 3: printf("\nInserire l'elemento da ricercare: ");
            scanf("%d", &x);
            x=cercax(vettore,q,x);
            printf("\nL'elemento si trova in posizione %d",x);
            break;
    case 4: printf("\nInserire l'elemento da cancellare: ");
            scanf("%d", &x);
            deletex(vettore,q,x);
            break;
    case 5: q++;
            spostapos(vettore,q);
            q--;
            break;
    case 6: q++;
            printf("In che posizione vuoi inserire il nuovo elemento? ");
            scanf("%d",&pos);
            spostaposi(vettore,q, &pos);
            q--;
            break;

     default:
            if (choose!=0) printf("scelta non valida\n");
            break;
    }
    }
    while (choose!=0);
    printf("\nProgramma terminato");
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
void stampa(int array[1000], int n){
    int j;
    printf("Gli elementi dell'array sono:\n");
    for (j=0;j<n;j++)printf("%d\n",array[j]);
}
int cercax(int array[1000], int n, int x){
    int i, pos=-1;
    for(i=0; i<n; i++){
        if(array[i]==x)pos=i;
    }
    return pos;
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
void spostaposi(int array[1000], int n, int *position){
    int i,sost,tempo;
    printf("Inserire il valore dell'elemento da mettere in posizione %d: ",(*position));
    scanf("%d",&sost);
    for (i=*position;i<n;i++){
        tempo=array[i];
        array[i]=sost;
        sost=tempo;
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
