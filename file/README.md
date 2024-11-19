# Gestione dei File in C

## Introduzione
La gestione dei file è un aspetto cruciale nella programmazione C, specialmente quando si tratta di leggere o scrivere dati persistenti. Il linguaggio C offre una serie di funzioni per interagire con i file, che consentono di aprire, leggere, scrivere, chiudere e gestire gli errori associati alle operazioni sui file.

### Stream
Si dice stream qualsiasi sorgente di dati in ingresso e qualsiasi destinazione per i risultati in uscita
- tastiera
- video
- file su disco, CD, DVD, memorie flash
- dispositivi di comunicazione (porte di rete, stampanti, ecc. . . ) La libreria stdio.h tratta tutti gli stream allo stesso modo (per quanto possibile)
- rappresentandoli con puntatori a file (FILE *) su cui operano funzioni simili o identiche

### Stream Standard

Esistono tre stream standard, che non occorre definire, aprire e chiudere
- lo standard input (stdin), ovvero la tastiera
- lo standard output (stdout), ovvero il video
- lo standard error (stderr), ovvero il video

Quando si chiama un programma, il sistema operativo può reindirizzare gli stream standard, cioè modificarne il
significato:
- programma < nomefile indica che si ricevono i dati dal file nomefile anziché da tastiera (stdin punta il del nomefile)
- programma > nomefile indica che si stampano i risultati sul file nomefile anziché a video (stdout punta il file nomefile)
- programma 2> nomefile indica che si stampano i messaggi di errore sul file nomefile anziché a video (stderr punta il file nomefile)

### File di testo e binari

Vi sono due tipi di file
- file di testo, costituiti da sequenze di caratteri: sono accessibili all'utente con un editor di testo
- file binari, costituiti da sequenze di byte: occupano meno spazio per rappresentare numeri

I file di testo sono organizzati in righe, separate da appositi caratteri, che sono specifici di ogni sistema operativo
- il C gestisce la differenza automaticamente (e sempre ‘\n')
Nel seguito considereremo solo i file di testo

In generale per gestire i file è necessario includere l'apposita libreria `stdio`

```C
    #include<stdio.h>
```

### Apertura file

Per usare un file occorre aprirlo specificando FILE *fopen(char *nomele, char *modo)
- il nome del file da aprire e la posizione su disco (path)
- il modo in cui usarlo
- "r": in lettura, ponendosi al principio del file
- "w": in scrittura, ponendosi al principio del file
- "a": in accodamento, ponendosi alla fine del file
Per i file binari si usano "rb", "wb" e "ab"
Il path può essere assoluto o relativo (al file eseguibile o al progetto)

La funzione fopen restituisce un puntatore al file per poterlo usare, se il file non esiste
- in lettura, restituisce NULL
- in scrittura e accodamento, ne crea uno vuoto
se il file non può essere aperto o creato
- restituisce NULL

Aperto un file, la posizione accessibile è
- il principio del file se si è aperto il file in lettura o scrittura
- la fine del file se si è aperto il file in accodamento

```C
    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen(output.txt", "w");
```

### Chiusura di un file

Dopo l'uso, il file va chiuso con l'istruzione int fclose(FILE *stream) che restituisce
• 0 se la chiusura ha successo
• la costante simbolica EOF altrimenti
Si possono usare puntatori diversi per lo stesso file al fine di scorrerlo in maniera differenziata (non ha senso farlo in scrittura)
La funzione void rewind(FILE* stream)  riporta la posizione corrente al principio del file

```C
    fclose(fr);
```

### Parsing di stream

Tutti gli stream di ingresso sono gestiti allo stesso modo int fscanf(FILE *stream, char *formato, ...)
• interpreta il contenuto dello stream
• in base alla stringa di formato
• assegna gli oggetti riconosciuti ai puntatori che seguono
• restituisce il numero di oggetti assegnati

```c
FILE *fp;
int giorno, mese, anno;
fp = fopen("prova.txt","r");
fscanf(fp,"%d/%d/%d", &giorno, &mese, &anno);
```

### Terminazione di un file

Se si arriva al termine di un file
• la funzione fscanf restituisce il numero di oggetti assegnati
• se non ne ha assegnati, restituisce la costante simbolica EOF int fscanf(FILE *stream, char *formato, ...) N.B.: fscanf restituisce EOF se si trova esattamente al termine, non se il file termina durante il parsing

Dopo il fallimento di un'operazione di lettura
• la funzione feof restituisce vero, cioè un valore intero non Nullo int feof(FILE *stream)

### Lettura di righe

char *fgets(char *s, int n, FILE *stream)
• legge una riga di testo dallo stream cioè tutto il testo fino al primo ‘\n' incluso
• si ferma dopo al massimo n caratteri (meno se compare ‘\n')
• assegna quanto letto alla stringa s
• se fallisce restituisce NULL, altrimenti la stringa s char *gets(char *s)
• opera sullo stream stdin
• non specifica la lunghezza n (possibile overflow sul buffer s (meglio usare fgets()))
• legge ‘\n', ma non lo include in s

### Scrittura su file

int fprintf(FILE *stream, char *formato, ...) funziona esattamente come printf e sprintf:
• scrive sullo stream
• nel formato specificato dalla relativa stringa
• il valore degli oggetti che seguono int *fputs(char *s, FILE *stream) scrive la stringa s sullo stream di uscita senza aggiungere ‘\n‘ int *puts(char *s) scrive la stringa s sullo stdout con un ‘\n' aggiuntivo
Restituiscono EOF se falliscono, un valore non negativo altrimenti

### Buffering

L'accesso ai file non viene eseguito ad ogni operazione (è troppo lento)
• si leggono i dati da file un blocco per volta e si conserva il blocco in un'area di memoria dedicata (buffer di lettura)
• si accodano i risultati in un'area di memoria dedicata (buffer di scrittura) e si salvano su file quando essa è piena Il meccanismo di buffering è automatico La funzione int fflush (FILE* stream) svuota completamente il buffer associato al file stream Se stream vale NULL, svuota i buffer associati a tutti i file Nota: non funziona con stdin; il comportamento dipende dal sistema operativo e dal compilatore, ma lo standard non ne /specifica il comportamento per gli stream di input.

### fflush

Non deve essere per forza fatto sempre esistono delle situazioni in cui è triggerato automaticamente
fpritnf(stdout, "Testo di esempio\n"); Il "\n") triggera un flush automatico fclose() o un exit dal programma anche

### Lettura e scrittura di caratteri singoli

int getc(FILE *pf) Restituisce il successivo carattere del file pf, che deve essere aperto in lettura, come intero (ossia il suo codice ASCII del carattere), oppure l’intero EOF se incontra la fine del file o riscontra un errore.
A differenza della lettura da stdin, la lettura da file non è mai bloccante. 

int putc(int c, FILE *pf) Scrive il carattere c, codificato come int, sul file pf, che deve essere aperto in scrittura. Restituisce il carattere scritto oppure EOF se incorre in un errore.




## Tipi di File
In C, i file possono essere gestiti in due modalità principali:

1. **File di Testo**: Gestiscono dati in formato leggibile dall'uomo, come caratteri, numeri, ecc. Le righe sono terminate da un carattere di nuova linea (`\n`).
2. **File Binari**: Gestiscono dati in formato binario, quindi byte grezzi. Sono utili quando è necessario leggere o scrivere file non di testo, come immagini o file eseguibili.

## Flussi di File
In C, un file è rappresentato da un puntatore al tipo `FILE`. Questo puntatore, chiamato anche "stream" (flusso), rappresenta una connessione tra il programma e il file nel sistema operativo.

```c
FILE *filePointer;
```

## Apertura di un File
Prima di poter leggere o scrivere un file, bisogna aprirlo. Per farlo, si utilizza la funzione `fopen`.

### Sintassi
```c
FILE *fopen(const char *filename, const char *mode);
```

### Modalità di Apertura
- "r" : Apre il file in lettura. Il file deve esistere.
- "w" : Apre il file in scrittura. Se il file esiste, viene troncato a lunghezza zero; se non esiste, viene creato.
- "a" : Apre il file in modalità append. Se il file non esiste, viene creato.
- "r+" : Apre il file in lettura e scrittura. Il file deve esistere.
- "w+" : Apre il file in lettura e scrittura. Se il file esiste, viene troncato a lunghezza zero; se non esiste, viene creato.
- "a+" : Apre il file in lettura e scrittura. I dati scritti vengono aggiunti alla fine del file.

#### Esempio
```c
FILE *filePointer;
filePointer = fopen("example.txt", "r");

if (filePointer == NULL) {
    printf("Errore nell'apertura del file.\n");
    return 1;
}
```

## Lettura da un File
Ci sono diverse funzioni per leggere da un file:

### `fgetc`
Legge un singolo carattere dal file.

```c
int c = fgetc(filePointer);
```c

### `fgets`
Legge una linea dal file e la memorizza in una stringa.

```c
char buffer[100];
fgets(buffer, 100, filePointer);
```

### `fscanf`
Legge dati formattati dal file, simile a `scanf`.

```c
int number;
fscanf(filePointer, "%d", &number);
```

## Scrittura su un File
Analogamente alla lettura, ci sono diverse funzioni per scrivere su un file:

### `fputc`
Scrive un singolo carattere nel file.

```c
fputc('A', filePointer);
```

`fputs`
Scrive una stringa nel file.

```c
fputs("Hello, World!", filePointer);
```

`fprintf`
Scrive dati formattati nel file, simile a `printf`.

```c
fprintf(filePointer, "%d", 123);
```

## Chiusura di un File
Dopo aver finito di lavorare con un file, è buona norma chiuderlo usando fclose.

### Sintassi
```c
int fclose(FILE *filePointer);
```

### Esempio
```c
fclose(filePointer);
```

## Gestione degli Errori
È importante controllare se le operazioni sui file riescono o falliscono, per evitare comportamenti inaspettati.

### `ferror`
Verifica la presenza di errori durante un'operazione sul file.

```c
if (ferror(filePointer)) {
    printf("Errore durante l'operazione sul file.\n");
}
```

### `feof`
Verifica se è stata raggiunta la fine del file.

```c
if (feof(filePointer)) {
    printf("Fine del file raggiunta.\n");
}
```

## File Binari
La gestione dei file binari differisce leggermente rispetto a quella dei file di testo.

### Apertura di File Binari
Si utilizzano le stesse modalità di apertura, aggiungendo una b al modo.

```c
FILE *filePointer;
filePointer = fopen("example.bin", "rb");
```

### Lettura e Scrittura di File Binari
Si utilizzano le funzioni fread e fwrite.

#### `fread`
```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

Legge nmemb elementi di dimensione size dal file e li memorizza in ptr.

#### `fwrite`
```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

Scrive nmemb elementi di dimensione size nel file da ptr.

### Esempio di Lettura/Scrittura Binaria
```c
int numbers[5] = {1, 2, 3, 4, 5};
fwrite(numbers, sizeof(int), 5, filePointer);

int readNumbers[5];
fread(readNumbers, sizeof(int), 5, filePointer);
```
