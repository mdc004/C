#include "codap.h"
#include <limits.h>


/* funzione Minheapify per elementi di tipo item*/
void MinHeapifyItem(item *, int, int);
/* Funzioni per rappresentazione heap con vettore*/
/* indice del figlio sinistro del nodo di indice i */
int left(int i){
	return 2*i+1;
}

/* indice del figlio destro del nodo di indice i */
int right(int i){
	return 2*i+2;
}

/* indice del padre del nodo di indice i. Non serve applicate la funzione floor, 
   viene automaticamente applicato il cast a intero */
int parent(int i){
	return (i-1)/2;
}

/* funzioni per la gestione di una coda di min-priorita' */

/* Crea una coda di tipo coda p il cui campo Q viene inizializzato a n elementi di tipo item. Restutuisce il puntatore alla coda */
codap *createCodap(int n)
{
	codap *qu = malloc(sizeof(codap));
	if(!qu) {
		fprintf(stdout,"createCodap: Errore di allocazione nodo coda\n");
		exit(-1);
	}
	qu->Q = malloc(n*sizeof(item));
	if(!qu->Q){
		fprintf(stdout,"createCodap: Errore di allocazione dello spazio coda\n");
		exit(-2);
	}
	qu->hs = 0;
	qu->vetsize = n;
	return qu;
}

/* Restituisce l'elemento di priorità minima, facendolo puntare da out. 
    Se non ci sono elementi, restituisce 0.*/ 
int Minimum(codap * C, item *out)
{
	int res = 0;
	if (C && C->hs > 0){
		copy_item(out, C->Q[0]);	
		res = 1;
   }
   return res;
}

/* funzione per scambiare due elementi di una rray a di tipo item nelle posizioni "i" e "j"*/
void swapItem(item *a, int i, int j)
{
	item k = a[i];
	a[i] = a[j];
	a[j] = k;
}

/* funzione Minheapify per elementi di tipo item. hs è l'heapsize, i l'indice che non rispetta 
    l'la proprietà dell'heap*/
void MinHeapifyItem(item *Q, int hs, int i){
  int l = 2 * i + 1;
  int r = l + 1;
  int smallest = (l<hs && cmp_item(Q[l], Q[i]) < 0) ? l:i;
  if(r < hs && cmp_item(Q[r], Q[smallest]) < 0)
      smallest = r;
  if(smallest != i) {
     swapItem(Q, i, smallest);
     MinHeapifyItem(Q, hs, smallest);
  }
}


/*  Restituisce in "out" e cancella l'elemento di priorità minima. 
    Se non ci sono elementi restituisce 0*/
int ExtractMin(codap *C, item * out) 
{
		int res = 0;
		if (C && C->hs > 0){
			copy_item(out, C->Q[0]);
			copy_item(&C->Q[0], C->Q[C->hs-1]);
			C->hs--;
			MinHeapifyItem(C->Q, C->hs, 0);
			res = 1; 
		}else
		{
			printf("ExtractMin:\tcoda vuota o  non creata\n");
			
		}
		return res;
} 

/* Decrementa a key il campo priorita del nodo di indice x della coda C->Q*/ 
void DecreaseKey(codap *C, int x, key key)
{	
	if (C && C->hs > 0) {
		if (x >= C->hs) {
			printf("DecreaseKey:\t indice x non valido\n");
			exit(-1);
		}
		if (cmp_key(key, get_key(C->Q[x])) > 0) {
			printf("DecreaseKey:\tnuova priorità maggiore della precedente\n");
		}else{		
			set_key(&C->Q[x], key);
			while ( x>0 && cmp_item(C->Q[x], C->Q[parent(x)])<0) {
				swapItem(C->Q, x, parent(x));
				x = parent(x);
			}
		}
	}else{
		printf("DecreaseKey:\tCoda vuota o non creata\n");
	}
	  
}

/* inserisce nella coda C un nuovo elemento e. Assumiamo è sia già stato inizializzato, inlcusa la sua priorità. Restituisce 1 se inserimento avviene con successo, 0 latimenti */
int Insert(codap *C, item e)
{
	if (C && C->hs >= C->vetsize) {
		printf("Insert:\tcoda non creata o taglia vettore esaurita\n");
		return 0;
	}
	copy_item(&C->Q[C->hs], e); 
	set_key(&C->Q[C->hs], new_key(INT_MAX));
	C->hs++;
	DecreaseKey(C, C->hs-1, get_key(e));
	return 1;
}

