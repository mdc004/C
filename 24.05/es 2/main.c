#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void procedura();
int main(){procedura();}
void procedura()
{
    char riga[300],nome[20],nome2[20];
    FILE *pt, *pt2;
    printf("Inserire il nome del file da copiare: ");
    scanf("%s", nome);
    printf("\nInserire il nome del file in cui copiare: ");
    scanf("%s", nome2);
    pt=fopen(nome,"r");
    pt2=fopen(nome2,"w");
    if((pt==NULL)||(pt2==NULL))printf("\nNon e' stato possible aprire il file\n");
    while(!feof(pt)){
        fgets(riga,300,pt);
        int n=strlen(riga);
        if(riga[n]==',')fprintf(pt2,"\n%s",riga);
    }
    fclose(pt);
    fclose(pt2);
}
