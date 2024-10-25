#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void procedura();
int main(){procedura();}
void procedura()
{
    char riga[300],nome_file[20],parola[20];
    FILE *pt, *pt2;
    printf("Inserire il nome della parola da ricercare: ");
    scanf("%s", parola);
    printf("\nInserire il nome del file in cui cercare: ");
    scanf("%s", nome_file);
    pt=fopen(".txt","r");
    pt2=fopen("fine.txt","w");
    if((pt==NULL)||(pt2==NULL))printf("\nNon e' stato possible aprire il file\n");
    while(!feof(pt)){
        fgets(riga,300,pt);
        int n=strlen(riga);
        if(riga[n]==',')fprintf(pt2,"\n%s",riga);
    }
    fclose(pt);
    fclose(pt2);
}
