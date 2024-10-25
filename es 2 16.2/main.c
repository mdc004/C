#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserisci_vocale(char s[80], char finale[80]);
int main()
{
    char stringa[80],fin[80]={};
    printf("Inserire la stringa: ");
    fflush(stdin);
    gets(stringa);
    inserisci_vocale(stringa,fin);
    printf("La stringa finale: %s", fin);
    return 0;
}

void inserisci_vocale(char s[80], char finale[80]){
    int i,j,cont=0,ver;
    char vocali[5]={'a','e','i','o','u'};
    for(i=0;i<strlen(s);i++){
        ver=0;
        for(j=0;j<5;j++){
            if(s[i]==vocali[j]){
                finale[cont]='*';
                cont++;
                finale[cont]=vocali[j];
                cont++;
                ver=1;
            }
        }
        if(ver==0){
            finale[cont]=s[i];
            cont++;
        }
    }
}





