#include <stdlib.h>
#include <stdio.h>

void crea_file_persone();
int main(){
    crea_file_persone();
    return 0;
}

void crea_file_persone(){
    int i, n, eta;
    char nome[20],cognome[20];

    FILE *ptr;
    ptr=fopen("persone.txt","w");
    if (ptr==NULL){
        printf("\nNon e' stato possibile aprire il file!\n");
        exit(1);
    }

    printf("\nInserire la quantita' di persone: ");
    scanf("%d",&n);
    fflush(stdin);
    for (i=0;i<n;i++){
        printf("\nPersona %d",i);
        printf("\n\tNome: ");
        gets(nome);
        fflush(stdin);
        printf("\n\tCognome: ");
        gets(cognome);
        fflush(stdin);
        printf("\n\tEta': ");
        scanf("%d", &eta);
        fflush(stdin);
        fprintf(ptr,"%s %s %d\n",cognome,nome,eta);
        }
    fclose(ptr);
}
