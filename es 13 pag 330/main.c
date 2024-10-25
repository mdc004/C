#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cambia_space(char s[81], char x);
int main()
{
    char frase[81], p;
    printf("Inserire la frase: ");
    gets(frase);
    printf("Inserire il carattere da mettere al posto dello spazio: ");
    scanf("%c", &p);
    cambia_space(frase,p);
    printf("Ecco la frase finale: %s", frase);
    return 0;
}

void cambia_space(char s[81], char x){
    int i;
    for(i=0;i<strlen(s);i++)if(s[i]==' ')s[i]=x;
}
