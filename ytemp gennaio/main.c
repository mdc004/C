#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float media,somma, min, max, temp[31];
    int i, gmin, gmax;
    srand(time(NULL));
    for (i=0;i<31;i++)
    {
       temp[i]=(rand()%30)-15;
       somma+=temp[i];
       printf("\n%f",temp[i]);
        /*printf("giorno %d: ",i+1);
        scanf("%d",&temp[i]);*/
    }
    media=somma/31;
    min=max=temp[0];
    for (i=0;i<31;i++)
    {
        if(temp[i]<min){
            min=temp[i];
            gmin=i++;
        }
        if(temp[i]>max){
            max=temp[i];
            gmax=i++;
        }
    }
    printf("\nIl giorno con la temperatura minore e' %d con %f °C\n", gmin, min);
    printf("\nIl giorno con la temperatura maggiore e' %d con %f °C\n", gmax, max);
    printf("\nLa media delle temperature e' %f °C\n", media);
    return 0;
}
