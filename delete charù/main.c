#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_char(char stringa[30], char carattere);
int main()
{
    char parola[30];
    char x;
    printf("Inserire la parola: ");
    scanf("%s", parola);
    fflush(stdin);
    printf("Inserire il carattere da cancellare: ");
    scanf("%c", &x);
    delete_char(parola, x);
    printf("\n La stringa senza il carattere e': %s",parola);
    return 0;
}

void delete_char(char stringa[30], char carattere){
    int i,j;
    for(i=0;i<strlen(stringa);i++){
        if(stringa[i]==(carattere)){
            for(j=i;j<strlen(stringa);j++){
                stringa[j]=stringa[j+1];
            }
        }
    }
}
