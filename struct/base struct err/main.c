#include <stdlib.h>
#include <stdio.h>

struct nome
{
    char nome_stringa[30];
    int nome_intero;
};
int main()
{
    struct nome nome1;
    printf("inserisci il nome_stringa di nome1: ");
    scanf("%s", nome1.nome_stringa);
    fflush(stdin);
    printf("inserisci il nome_intero di nome1: ");
    scanf("%s", &nome1.nome_intero);

    printf("i dati di nome1 sono: %s\t%d", nome1.nome_stringa, nome1.nome_intero);
}
