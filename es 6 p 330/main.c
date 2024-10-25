#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funzione che restituisce quante volte la lettera c compare nella stringa s
int contavocale(char s[80],char c);
//funzione che restiutisce nell'array du 5 interi l'indice della posizione dove c'e' l'elemento massimo
int massimo(int a[5]);
//funzione che restiutisce nell'array du 5 interi l'indice della posizione dove c'e' l'elemento minimo
int minimo(int a[5]);


int main()
{  char parola[81];
   int vocali[5];
   int pos_min;
   int i;
   int pos_max;
   char voc[6]={'a','e','i','o','u'};


    printf("inserisci la frase: ");
    gets(parola);

    //conto le vocali nella frase e inserisco le occorrenza nell'array di interi
    vocali[0]=contavocale(parola,'a');
    vocali[1]=contavocale(parola,'e');
    vocali[2]=contavocale(parola,'i');
    vocali[3]=contavocale(parola,'o');
    vocali[4]=contavocale(parola,'u');

    pos_max=massimo(vocali);
    pos_min=minimo(vocali);

    //completare: devo stampare quante volte compare ogni singola vocale e quali sono le vocali che compaiono il maggior numero di volte
    //e il minor numero di volte


    for(i=0;i<5;i++){printf("\nLa vocale %c compare %d volte", voc[i], vocali[i]);}
    printf("\nLa vocale che compare piu' volte e' la %c", voc[pos_max]);
    printf("\nLa vocale che compare meno volte e' la %c", voc[pos_min]);


     return 0;
}

int contavocale(char s[80],char c)
{  int i,cont=0;
   for (i=0;i<strlen(s);i++)
        if (s[i]==c) cont++;

   return cont;
}

int massimo(int a[5])
{int ind_max,i;
 int max;
    ind_max=0;
    max=a[0];
    for (i=0;i<5;i++)
        if (a[i]>max)
        { max=a[i];
          ind_max=i;
        }

    return ind_max;
}

int minimo(int a[5])
{int ind_min,i;
 int min;
 ind_min=0;
 min=a[0];
    for (i=0;i<5;i++)
        if (a[i]<min)
        { min=a[i];
          ind_min=i;
        }

    return ind_min;
}
