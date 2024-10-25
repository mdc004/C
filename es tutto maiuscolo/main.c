#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capslock(char parola[30]);
int main(){
    char parola[30];
    printf("Inserire la parola o la frase: ");
    gets(parola);
    capslock(parola);
    printf("La parola o la frase in maiuscolo sara': %s", parola);
    return 0;
}
void capslock(char parola[30]){
    int i;
    for(i=0;i<strlen(parola);i++)parola[i]=toupper(parola[i]);
}
