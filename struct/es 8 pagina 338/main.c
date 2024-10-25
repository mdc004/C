#include <stdio.h>
#include <stdlib.h>

struct persona{
    char nome[30];
    char cognome[30];
    char telefono[15];
    char email[40];
    int giorno;
    char mese[10];
    int anno;
};
typedef persona persona;
void inserimento(persona p[300], int *q);
void stampa(persona p[300], int q);
void ordina(persona p[300], int q);
void cerca(persona p[300], int q);
int main()
{
    int choose, q;
    persona p[300];
    do{
    printf("Scegli cosa vuoi fare\n");
    printf("0. per terminare il programma\n");
    printf("1. per inserire i dati\n");
    printf("2. per stampare i dati\n");
    printf("3. per ordinare i dati\n");
    printf("4. per cercare un dato\n");
    printf("Scelta: ");
    scanf("%d", &choose);
    fflush(stdin);
    switch(choose){
        case 0:
            printf("**********Programma terminato**********");
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
    printf("\n");
    system("pause");
    system(CLS);
    }
    while(choose!=0);
    return 0;
}

void inserimento(persona p[300], int *q){
    int i;
    printf("\nQuande persone si desidera inserire: ");
    scanf("%d", &(*q));
    fflush(stdin);
    for(i=0;i<(*q);i++){
        printf("\nInserire i dati della persona %d", i+1);
        printf("\n\tCognome: ");
        gets(p[i].cognome);
        fflush(stdin);
        printf("\n\tNome: ");
        gets(p[i].nome);
        fflush(stdin);
        printf("\n\tTelefono: ");
        gets(p[i].telefono);
        fflush(stdin);
        printf("\n\temail: ");
        gets(p[i].email);
        fflush(stdin);
        printf("\nData di nascita");
        printf("\n\tGiorno: ");
        scanf("%d",&p[i].giorno);
        fflush(stdin);
        printf("\n\tMese: ");
        gets(p[i].mese);
        fflush(stdin);
        printf("\n\tAnno: ");
        scanf("%d",&p[i].anno);
        fflush(stdin);
    }
}

void stampa(persona p[300], int q){
    int i;
        int i;
    for (i = 0; i < q; i++){
        printf("\nPersona %d\n", i + 1);
        printf("\tCognome: %s\n\tNome: %s\n\ttelefono: %s\n\temail: %s\nData di nascita\n\tGiorno: %d\n\tMese: %s\n\tAnno: %d", p[i].cognome, p[i].nome, p[i].materia, p[i].voto, p[i].giorno, p[i].mese, p[i].anno);
    }
}

