#include <stdio.h>
#include <stdlib.h>

void acquisisci();
void crea_file(char nome[200]);
int main()
{
    //char nome[200];
    //printf("Inserisci il nome del file: ");
    //gets(nome);
    //crea_file(nome);
    acquisisci();
}

void crea_file(char nome[200]){
    FILE *ptr,*ptr2;
    ptr=fopen(nome,"r");
    ptr2=fopen("copia.txt","w");
    if((ptr==NULL)||(ptr2==NULL)){
        printf("Non e' stato possibile aprire il file");
        exit(1);
    }
    while(!feof(ptr)){
        char c=fgetc(ptr);
        if(c!='s')fprintf(ptr2,"%c",c);
    }
    fclose(ptr);
    fclose(ptr2);
}
void acquisisci(){
    FILE *ptr,*ptr2;
    char titolo1[20],titolo2[20],riga[300];
    ptr=fopen("citrullo.txt","r");
    ptr2=fopen("mammalucco.txt","w");
    if((ptr==NULL)||(ptr2==NULL)){
        printf("ERRORE PIEDOSO");
        exit(1);
    }
    fscanf(ptr,"%s %s",titolo1,titolo2);
    fprintf(ptr2,"%s %s\n",titolo1,titolo2);
    int ver=0;
    while(!feof(ptr)){
        fgets(riga,300,ptr);
        ver++;
        if(ver%2!=0)fprintf(ptr2,"%s",riga);
    }
    fclose(ptr);
    fclose(ptr2);
}
