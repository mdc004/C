#include <stdio.h>
#include <stdlib.h>

//procedura che legge i dati dal file di testo e scrive a video il contenuto
//in ingresso viene passato il nome del file di testo con estensione
void leggi_file_txt(char s[30]);

int main()
{
    leggi_file_txt("ciao.txt");

    return 0;
}


void leggi_file_txt(char s[30])
{ //dichiaro le variabili locali
  char cognome[30], nome[30];
  int eta;

  //dichiaro il puntatore al file
  FILE *ptr;

  //dichiaro le variabili locali

  //apro il file in lettura
  ptr=fopen(s,"r");

  //controllo se apertura del file è andata a buon fine
  if (ptr==NULL)
  {
      printf("impossibile aprire il file!!!");
      exit(1);
  }

  //leggo una riga dal file fino a quando il file non è finito
  while (!feof(ptr))
  {
    //leggo una riga del file.Se utilizzo la fscans devo sapere come sono formattati i dati sul file

    fscanf(ptr,"%s\t%s\t%d\n",cognome,nome,&eta);
        fgets(30,)

    //per evitare che venga stampata a video l'ultima riga due volte....devo controllare anche qui dopo la scanf feof()

    //scrivo a video i dati della riga letta dal file
    printf("%s\t%s\t%d\n",cognome,nome,eta);

  }
}
