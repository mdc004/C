#include <stdio.h>
#include <stdlib.h>

void inserisci_studenti();
int main()
{
    printf("Hello world!\n");
    return 0;
}

void inserisci_studenti()
{
    int n;
    FILE *pt;
    pt=fopen("elenco_studenti.txt","w");
    if(pt==NULL){
        printf("\nNon e' stato possibile aprire il file\n");
        exit(1);
    }

    printf("Inserire la quantita' di studenti: ");
    scanf("%d",n);
    for ( i = 0; i < n; i++)
    {
        printf("\n\tNome: ");
        gets(nome);
        printf("\n\tCognome: ");
        gets(nome);

    }
    while(!=feof(pt)){
        fgets(c);
    }
}