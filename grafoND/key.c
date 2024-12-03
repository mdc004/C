#include "key.h"

/* funzione che crea una nuova variabile di tipo key e ne inizializza il campo 
   codice con l'intero d 
   Restituisce la struttura*/
key new_key(int d){	
	key k;
	k.codice = d;	
	return k;
}
/* Funzione per leggere da standard input i deti per inizializzare la chiave 
    puntata da k*/
void leggi_key(key *k){
	if(k){
		printf("Inserisci codice intero\n");
		scanf("%d", &k->codice);
	}else printf("\t leggi_key: input k non è valido\n");
}
/* function to set the base field of the key k to val*/
void set_val(key *k, int val){
	k->codice = val;
}

/* funzione che copia la chiave k2 nella chiave puntata da k1. */
void copy_key(key * k1, key k2){
	if(k1) 
		k1->codice = k2.codice;
	else 
		printf("copy_key: prima chiave non allocata\n");	
}

/* funzione per stampare il contenuto di una chiave */
void print_key(key k){
	printf("\t--- Chiave %d\n", k.codice);
}

/* Funzione per confrontare due chiavi. Restituisce un valore 
   < 0 se la prima chiave e' minore della seconda, 
     0 se sono uguali, 
   > 0  se la prima chiave è maggiore della seconda. */
int cmp_key(key k1, key k2){
	return k1.codice - k2.codice;
}



