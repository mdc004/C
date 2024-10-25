#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vettore[10], i=0, posizione, maggiore;
    for(i=0;i<10;i++)
    {
      printf("\nInserire un numero:");
      scanf("%d",&vettore[i]);
    }
    for(i=0;i<10;i++)
    {
        if(vettore[i]>maggiore)
        {
           maggiore=vettore[i];
           posizione=i;
        }
    }
    printf("\n%d e' il numero maggiore ed e' di posto %d", vettore[posizione],posizione);

    return 0;
}
