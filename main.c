#include <stdio.h>
#include <stdlib.h>
void inserisci(int ar[1000], int numero_elementi);


void stampa(int ar[1000], int numero_elementi);

float media(int ar[1000], int numero_elementi);
int main()
{ int a[1000];
int N=0;
int scelta;
float y;
do
{



    printf("menu. \n");
  printf("1. per inseire nell'array \n");
    printf("2. per stampare nell'array \n");
      printf("3. per calcolare la media nell'array \n");
      printf("0. per uscire dal programma \n");

    printf("scelta:");
    scanf("%d",&scelta);
    switch (scelta)



    {case 1: inserisci(a,&N);
           break;
     case 2:stampa(a,N);
           break;
     case 3: y=media(a,N);
    printf("la media degli elementi dell'array e' %f\n",y);
           break;


           default:  if (scelta!=0)printf(" \n scelta non valida");

    }
    } while(scelta!=0);
    printf("**programma terminato***");
    return 0;
}
void inserisci(int a[1000], int numero_elementi)
{ int i;

  printf("quanti elementi vuoi inserire nell'array");
  scanf("%d",&(numero_elementi));

  for (i=0;i<*numero_elementi;i++)
  {
      printf("inserisci l'elementodi posto di indice %d: ",i);
      scanf("%d",&a[i]);
  }
}

void stampa(int ar[1000], int numero_elementi)
{ int i;
  printf("elementi dell'array:\n");
  for (i=0;i<numero_elementi;i++)
    printf("%d\t",ar[i]);
}

float media(int ar[1000], int numero_elementi)
{   int somma=0;
    float m;
    int i;

    for (i=0;i<numero_elementi;i++)
        somma+=ar[i];

    m=((float)(somma))/numero_elementi;

    return m;
}
