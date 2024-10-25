#include <stdio.h>
#include <stdlib.h>

void iniziallizzazione(int *n, int array[1000]);
void stampa(int ar[1000], int numero_elementi);
void contapari(int array[1000], int n);
void contatre(int array[1000], int n);
int max(int array[1000], int n);
float calcmedia(int array[1000], int n);
int decrescente(int array[1000], int n);


int main()
{   int q=0, vettore[1000], mag,choose;
    float m;
    do{
    printf("\nPremi\n");
    printf("0. per uscire dal programma\n");
    printf("1. per inserire gli elementi\n");
    printf("2. per stampare gli elementi\n");
    printf("3. per stampare la media degli elementi\n");
    printf("4. per trovare il maggiore degli elementi\n");
    printf("5. per contare gli elementi pari\n");
    printf("6. per stampare gli elementi multipli di 3\n");
    printf("7. per ordinare in modo decrescente gli elementi\n");

    scanf("%d",&choose);

    switch (choose){
    case 1: iniziallizzazione(&q,vettore);
            break;
    case 2: stampa(vettore,q);
            break;
    case 3: m=calcmedia(vettore,q);
            printf("\nLa media degli elementi dell'array e' pari a: %.2f", m);
            break;
    case 4: mag=max(vettore,q);
            printf("L'elemento maggiore dell'array e' %d", mag);
            break;
    case 5: contapari(vettore,q);
            break;
    case 6: contatre(vettore,q);
            break;
    case 7: vettore[1000]=decrescente(vettore,q);
            break;

     default:
            if (choose!=0) printf("scelta non valida\n");
            break;
    }
    }
    while (choose!=0);
    printf("\nprogramma terminato");
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
int max(int array[1000], int n){
    int i, maggiore;
    maggiore=array[0];
        for (i=0;i<n;i++){
            if (array[i]>maggiore)maggiore=array[i];
        }
    return maggiore;
}
void contapari(int array[1000], int n){
    int j, conta=0;
    for (j=0;j<n;j++){
            if(array[j]%2==0)conta++;
    }
    printf("\nI numeri pari sono %d", conta);
}
float calcmedia(int array[1000], int n){
    int j;
    float media, somma=0;
    for (j=0;j<n;j++){
            somma+=array[j];
    }
    media=somma/n;
    return media;
}
void contatre(int array[1000], int n){
    int j;
    for (j=0;j<n;j++){
            if(array[j]%3==0)printf("\n%d e' un multiplo di 3", array[j]);
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


