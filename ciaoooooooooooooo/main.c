#include <stdio.h>
#include <stdlib.h>

void inserisci(int vettore[1000], int quantita);
void stampa(int vettore[1000], int quantita);
float calcmedia(int vettore[1000],int quantita);
int main()
{
    int vettore[1000], quantita;
    float media;

    printf("Inserisci la quantita': ");
    scanf("%d", &quantita);
    inserisci(vettore,quantita);
    stampa(vettore,quantita);
    media=calcmedia(vettore,quantita);
    printf("\nLa media e': %.2f", media);
    return 0;
}

void inserisci(int vettore[1000], int quantita){
    int i;
    for(i=0;i<quantita; i++){
        printf("Inserisci un numero: ");
        scanf("%d", &vettore[i]);
    }
}

void stampa(int vettore[1000], int quantita){
    int i;
    for(i=0;i<quantita; i++){
        printf("\n %d", vettore[i]);
    }
}

float calcmedia(int vettore[1000],int quantita){
    int i, somma,media;
    for(i=0;i<quantita;i++){
        somma+=vettore[i];
    }
    media=somma/quantita;
    return media;
}
