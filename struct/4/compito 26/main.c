#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona
{
    char nome[20];
    char cognome[20];
    char materia[20];
    int voto;
    int giorno;
    char mese[10];
    int anno;
};
typedef struct persona persona;
void inserimento(struct persona n[300], int *q);
int cerca_trenta_info(struct persona n[300], int q);
void cerca_anno_mate(struct persona n[300], int q);
void cerca_max_info(struct persona n[300], int q);
void aggiungi_testa(struct persona n[300], int q);
void stampa(struct persona n[300], int q);
int main()
{
    int y, q = 0, choose;
    persona n[300];
    do
    {
        printf("\nScegli cosa fare\n");
        printf("\t0. Termina programma\n\t1. Inserimento\n\t2. Stampa\n\t3. Numero di studenti che hanno preso 30 all'esame di informatica\n\t4. Stampa a video gli studenti che hanno svolto l'esame di matematica nel 2018\n\t5. Stampa a video lo studente che ha preso il voto maggione in informatica\n\t6. Aggiungere una persona in testa\n Scelta: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            printf("\n***********Programma terminato***********\n");
            break;
        case 1:
            inserimento(n, &q);
            break;
        case 2:
            stampa(n, q);
            break;
        case 3:
            y=cerca_trenta_info(n, q);
            if (y == 0)printf("\n******Nessuno studente ha preso 30 in informatica******\n");
            else printf("\n%d studenti hanno preso 30 all'esame di informatica",y);
            break;
        case 4:
            cerca_anno_mate(n, q);
            break;
        case 5:
            cerca_max_info(n, q);
            break;
        case 6:
            aggiungi_testa(n,q);
            q++;
            break;
        }
        printf("\n");
        system("PAUSE");
        system("CLS");
    } while (choose != 0);
    return 0;
}

void inserimento(struct persona n[300], int *q)
{
    int i;
    printf("Inserire il numero di persone da registrare: ");
    scanf("%d", &(*q));
    fflush(stdin);
    for (i = 0; i < (*q); i++)
    {
        printf("\nPersona %d\n", i + 1);
        printf("\n\tCognome: ");
        gets(n[i].cognome);
        fflush(stdin);
        printf("\n\tNome: ");
        gets(n[i].nome);
        fflush(stdin);
        printf("\n\tMateria: ");
        gets(n[i].materia);
        fflush(stdin);
        printf("\n\tVoto: ");
        scanf("%d", &n[i].voto);
        fflush(stdin);
        printf("\n\tData dell'esame:\n");
        printf("\n\tGiorno: ");
        scanf("%d", &n[i].giorno);
        fflush(stdin);
        printf("\n\tMese : ");
        gets(n[i].mese);
        fflush(stdin);
        printf("\n\tAnno: ");
        scanf("%d", &n[i].anno);
        fflush(stdin);
    }
}

void stampa(struct persona n[300], int q)
{
    int i;
    for (i = 0; i < q; i++)
    {
        printf("\nPersona %d\n", i + 1);
        printf("\tCognome: %s\n\tNome: %s\n\tMateria: %s\n\tVoto: %d\n\tGiorno: %d\n\tMese: %s\n\tAnno: %d", n[i].cognome, n[i].nome, n[i].materia, n[i].voto, n[i].giorno, n[i].mese, n[i].anno);
    }
}

int cerca_trenta_info(struct persona n[300], int q)
{
    int i, cont=0;
    for (i = 0; i < q; i++)
    {
        if ((strcmp("Informatica", n[i].materia) == 0)||(strcmp("informatica", n[i].materia) == 0))if (n[i].voto == 30)cont++;
    }

    return cont;
}

void cerca_anno_mate(struct persona n[300], int q)
{
    int i,ver=0;
    printf("\nStudenti che hanno svolto l'esame di matematica nell'anno 2018\n");
    for (i = 0; i < q; i++)
    {
        if ((strcmp("Matematica", n[i].materia) == 0) || (strcmp("matematica", n[i].materia) == 0))
            if (n[i].anno == 2018){
                ver=1;
                printf("\tCognome: %s\n\tNome: %s\n\tMateria: %s\n\tVoto: %d\n\tGiorno: %d\n\tMese: %s\n\tAnno: %d", n[i].cognome, n[i].nome, n[i].materia, n[i].voto, n[i].giorno, n[i].mese, n[i].anno);
            }
    }
    if (ver == 0)printf("\n******Nessuno studente ha svolto l'esame di matematica nell'anno 2018******\n");
}

void cerca_max_info(struct persona n[300], int q)
{
    int i,max=0;
    for (i = 0; i < q; i++)
    {
        if ((strcmp("Informatica", n[i].materia) == 0) || (strcmp("informatica", n[i].materia) == 0))
            if (n[i].voto > n[max].voto)max=i;
    }
    printf("\nLo studente con il voto maggiore in informatica e' %s %s", n[max].cognome, n[max].nome);
}

void aggiungi_testa(struct persona n[300], int q)
{
    int i;
    for (i = q; i >= 0; i--)n[i]=n[i+1];
    printf("\n\tCognome: ");
    gets(n[0].cognome);
    fflush(stdin);
    printf("\n\tNome: ");
    gets(n[0].nome);
    fflush(stdin);
    printf("\n\tMateria: ");
    gets(n[0].materia);
    fflush(stdin);
    printf("\n\tVoto: ");
    scanf("%d", &n[0].voto);
    fflush(stdin);
    printf("\n\tData dell'esame:\n");
    printf("\n\tGiorno: ");
    scanf("%d", &n[0].giorno);
    fflush(stdin);
    printf("\n\tMese : ");
    gets(n[0].mese);
    fflush(stdin);
    printf("\n\tAnno: ");
    scanf("%d", &n[0].anno);
    fflush(stdin);
}
