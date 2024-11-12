#include <stdio.h>
#include <stdlib.h>

struct persona{
    char nome[20];
    char cognome[20];
    char materia[20];
    int voto;
};
typedef struct persona persona;
void inserimento(struct persona n[100], int *q);
void stampa(struct persona n[100], int q);
int main()
{
    int q=0, n[100];
    inserimento(n[100],&q);
    stampa(n[100],q);
    printf("Hello world!\n");
    return 0;
}

void inserimento(struct persona n[100], int *q){

    int i;
    printf("Inserire il numero di persone da registrare: ");
    scanf("%d",&(*q));
    fflush(stdin);
    for(i=0;i<(*q);i++){
        printf("\nPersona %d\n",i+1);
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
        scanf("%d",&n[i].voto);
        fflush(stdin);
    }
}

void stampa(struct persona n[100], int q){
    int i;
    for(i=0;i<q;i++){
        printf("\nPersona %d\n",i+1);
        printf("Cognome: %s\nNome: %s\nMateria: %s\nVoto: %d",n[i].cognome,n[i].nome,n[i].materia,n[i].voto);
    }
}
