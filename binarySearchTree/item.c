#include "item.h"
/* funzione che crea una nuova variabile di tipo item contenente la chiave k e
   nessun dato satellite*/
item new_item(key k){	
	item it;
	copy_key(&it.chiave, k);
	return it;
}


/* funzione per restituire la chiave di una variabile di tipo item */
key get_key(item it){
	return it.chiave;
}

/* funzione per leggere da standard input i dati da inserire in un item, 
    chiave inclusa */
void leggi_item(item *it){
	if(it){
		leggi_key(&it->chiave);
	}else printf("\t leggi_item: input it non valido\n");
}	

/* funzione per stampare il contenuto di una variabile di tipo item */
void print_item(item it){
	printf("\t#*****  *****#\n");
	print_key(it.chiave);
}

/* copia il contenuto di un item (source) nell'altro*/

void copy_item(item* target, item source){
			copy_key(&target->chiave, source.chiave);
}

int cmp_item(item target, item source){
			return cmp_key(target.chiave, source.chiave);
}


