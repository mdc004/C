#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct squadra{
    char nome[20];
    int subite;
    int segnate;
};

typedef struct squadra squadra;
void inserimento(int *q, squadra lista[40]);
void stampa(int q, squadra lista[40]);
int differenza_reti(int q, squadra lista[40]);
void reti_maggiore(int q, squadra lista[40]);
void elimina(int q, squadra lista[40]);
void ordina_differenza_reti(int q, squadra lista[40]);
void stampa_alfabetico(int q, squadra lista[40]);

    int main()
{
    int choose, q, y=0;
    squadra lista[40];

    //menù testuale
    do{
        printf("Seleziona:\n");
        printf("\t0. Per uscire dal programma.\n");
        printf("\t1. Per inserire le squadre.\n");
        printf("\t2. Per stampare le squadre inserite.\n");
        printf("\t3. Per calcolare il numero di squadre con una differenza reti positiva.\n");
        printf("\t4. Per trovare la squadra che ha segnato piu' reti.\n");
        printf("\t5. Per eliminare una squadra dalla lista.\n");
        printf("\t6. Per ordinare le squadre in base alla differenza reti.\n");
        printf("\t7. Per stampare le squadre in ordine alfabetico.\n");
        printf("Scelta: ");
        scanf("%d", &choose);
        fflush(stdin);

        switch(choose){
            case 0:
                printf("\n********Programma Terminato********\n");
                break;
            case 1:
                inserimento(&q,lista);
                break;
            case 2:
                stampa(q,lista);
                break;
            case 3:
                y=differenza_reti(q,lista);
                printf("Le squadre che hanno una differenza reti positiva sono: %d",y);
                break;
            case 4:
                reti_maggiore(q, lista);
                break;
            case 5:
                elimina(q, lista);
                q--;
                break;
            case 6:
                ordina_differenza_reti(q, lista);
                break;
            case 7:
                stampa_alfabetico(q, lista);
                break;
        }
        printf("\n");
        fflush(stdin);
        system("PAUSE");
        system("CLS");
    }
    while(choose!=0);
    return 0;
}

void inserimento(int *q, squadra lista[40]){
    int i;
    printf("Inserisci la quantita' di squadre da memorizzare: ");
    scanf("%d", &(*q));
    fflush(stdin);
    for ( i = 0; i < (*q); i++)
    {
        printf("\nSquadra %d\n",i+1);
        printf("\n\tInserisci il nome della squadra: ");
        gets(lista[i].nome);
        fflush(stdin);
        printf("\n\tInserisci il numero di reti segnate dalla squadra: ");
        scanf("%d", &lista[i].segnate);
        fflush(stdin);
        printf("\n\tInserisci il numero di reti subite dalla squadra: ");
        scanf("%d", &lista[i].subite);
        fflush(stdin);
    }
}

void stampa(int q, squadra lista[40]){
    int i;
    for ( i = 0; i < q; i++)
    {
        printf("\nSquadra %d",i+1);
        printf("\n\tNome: %s",lista[i].nome);
        printf("\n\tReti segnate: %d", lista[i].segnate);
        printf("\n\tReti subite: %d", lista[i].subite);
    }
}

int differenza_reti(int q, squadra lista[40]){
    int i, cont=0;
    for ( i = 0; i < q; i++)
    {
        if(lista[i].segnate>lista[i].subite)cont++;
    }
    return cont;
}

void reti_maggiore(int q, squadra lista[40]){
    int i, pos=0;
    for (i = 1; i < q; i++)
    {
        if (lista[i].segnate > lista[pos].segnate)
            pos=i;
    }
    printf("\nLa squadra che ha segnato di piu' e' %s",lista[pos].nome);
}

void elimina(int q, squadra lista[40]){
    int i,j,ver=0;
    char name[20];
    printf("\nInserire il nome della squadra da eliminare: ");
    gets(name);
    fflush(stdin);
    for ( i = 0; i < q; i++){
        if(strcmp(name,lista[i].nome)==0){
            ver=1;
            for ( j = i; j < q-1; j++)
            {
                lista[i]=lista[i+1];
            }
        }
    }
    if(ver==0)printf("\nNon e' presente nessuna squadra con il nome indicato\n");
}

void ordina_differenza_reti(int q, squadra lista[40])
{
    int i, j,min, t, a[q];
    squadra temp;
    for ( i = 0; i < q; i++)
        a[i] = lista[i].segnate - lista[i].subite;

    for (i = 0; i < q-1; i++)
    {
        min = i;
        for (j = i + 1; j < q; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;
        temp = lista[min];
        lista[min] = lista[i];
        lista[i] = temp;
    }
}

void stampa_alfabetico(int q, squadra lista[40])
{
    int i, j, min;
    squadra temp[q], t;

    for (i = 0; i < q; i++)
        temp[i]=lista[i];

    for (i = 0; i < q-1; i++)
    {
        min = i;
        for (j = i + 1; j < q; j++)
        {
            if (temp[j].nome < temp[min].nome)
                min = j;
        }
        t = temp[min];
        temp[min] = temp[i];
        temp[i] = t;
    }
    for ( i = 0; i < q; i++)
    {
        printf("\nSquadra %d",i+1);
        printf("\n\tNome: %s",lista[i].nome);
        printf("\n\tReti segnate: %d", lista[i].segnate);
        printf("\n\tReti subite: %d", lista[i].subite);
    }
}
