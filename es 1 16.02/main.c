#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contenuta(char s1[1000], char s2[1000]);
int main()
{
    char prima[1000], seconda[1000];
    int y;
    printf("Inserisci la prima stringa: ");
    fflush(stdin);
    gets(prima);
    printf("Inserisci la parola da cercare: ");
    fflush(stdin);
    gets(seconda);
    y=contenuta(prima,seconda);
    if(y==1)printf("\nLa parola e' contenuta nella stringa\n");
    else printf("\nLa parola non e' contenuta nella stringa\n");
    return 0;
}

int contenuta(char s1[1000], char s2[1000]){
    int i,j,cont=0;
    for(i=0;i<strlen(s2);i++){
        for(j=0;j<strlen(s1);j++){
            if(s2[i]==s1[j]){
                cont++;
                j=strlen(s1);
            }
        }
    }
    if(cont==strlen(s2))return 1;
    else return 0;
}
