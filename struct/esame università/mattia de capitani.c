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
void cerca_studente(struct persona n[300], int q, char name[20], char surname[20]);
void stampa(struct persona n[300], int q);
int main()
{
    int q = 0, choose;
    char name[20], surname[20];
    persona n[300];
    do
    {
        printf("\nScegli cosa fare\n");
        printf("\t0. Termina programma\n\t1. Inserimento\n\t2. Stampa\n\t3. Cerca alunno\n Scelta: ");
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
            fflush(stdin);
            printf("\nInserire identificativo allunno: ");
            printf("\n\tNome: ");
            gets(name);
            fflush(stdin);
            printf("\n\tCognome: ");
            gets(surname);
            fflush(stdin);
            cerca_studente(n, q, name, surname);
            break;
        }
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

void cerca_studente(struct persona n[300], int q, char name[20], char surname[20])
{
    int i;
    for (i = 0; i < q; i++)
    {
        if (strcmp(name, n[i].nome) == 0)
        {
            if (strcmp(surname, n[i].cognome) == 0)
                printf("\n\n\tCognome: %s\n\tNome: %s\n\tMateria: %s\n\tVoto: %d\n\tGiorno: %d\n\tMese: %s\n\tAnno: %d", n[i].cognome, n[i].nome, n[i].materia, n[i].voto, n[i].giorno, n[i].mese, n[i].anno);
            else
                printf("\nNessuno studente corrisponde ai criteri di ricerca\n");
        }
        else
            printf("\n******Nessuno studente corrisponde ai criteri di ricerca******\n");
    }
}
