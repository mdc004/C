#include "intqueue.h"
/*#include<stdio.h>
#include<stdlib.h>*/


/* Funzione aggiuntiva per il tipo intlist per inserire in fondo alla lista usando il 
    puntatore aggiuntivo tail. 
    Tail è il puntatore all'ultimo nodo della lista. 
    In questa implementazione, la chiave e i dati satellite del nuovo 
    vengono letti dalla tastiera mediante la funzione leggi_item. 
    Restituisce il puntatore tail aggiornato*/
intlist* list_insertatend(intlist *tail){
	intlist *q=NULL;
	q = malloc(sizeof(intlist));
	if(!q) {
		fprintf(stderr,"list_insertatend: errore nell’allocazione del nuovo elemento\n");
		exit(-1);
	}
	leggi_item(&q->dati);
	q->next = NULL;
	if(tail)	tail->next = q; /* controllo sia prima nodo*/	
	return q;
} 

/* Funzione alternativa per cancellare il nodo di testa della lista. */
intlist *list_deletehead(intlist *head)
{	
	intlist *r=head;
	if (head) {
		head = head->next;
		free(r);
	}
	return head;
}

intqueue *createqueue(void)
{
	intqueue *q = malloc(sizeof(intqueue));
	if(!q) {
		fprintf(stderr,"createQueue: errore di allocazione nella creazione della coda\n");
		exit(-1);
	}
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

int size(intqueue * Q){
	return Q->size;
}

int Empty(intqueue * Q)
{
	return !size(Q);	
}

/* Anche l'enqueue, in questa versione, legge l'item da inserire da tastiera.
   Infatti si serve della funzione list_insertatend su intlist che abbiamo aggiunto*/
void enqueue(intqueue *Q)
{
	intlist * r=NULL;
	r=list_insertatend(Q->tail);
	if(r){
		Q->size++;
		Q->tail = r;
		if(Q->size == 1) Q->head = r; /* primo elemento inserito in coda*/
	}	
}

/* Funzione per restituire il l'item contenuto nel nodo di testa.
   La funzione dovrebbe restituire il puntatore head, ma per non esporre all'esterno puntatori, 
   restituimo un intero che dà l'esito dell'operazione (1 se successo, 0 latrimenti), e prendiamo il riferimento all'item in cui scrivere come input.  */
int Head(intqueue * Q, item* it){
   int res=0;
	if(!Empty(Q)){
		copy_item(it, Q->head->dati);
		res =1;
	}
	
	return res;	
}

/* Funzione per restituire il l'item contenuto nel nodo di coda.
   La funzione dovrebbe restituire il puntatore tail, ma per non esporre all'esterno puntatori, 
   restituimo un intero che dà l'esito dell'operazione (1 se successo, 0 latrimenti), e prendiamo il riferimento all'item in cui scrivere come input. */
int Tail(intqueue * Q, item * it){
	int  res=0;
	if(!Empty(Q)){
		copy_item(it, Q->tail->dati);
		res = 1;
	}
	return res; 	
}

/* Funzione per restituire il l'item contenuto nel nodo di testa, che poi verrà rimosso.
   La funzione dovrebbe restituire il puntatore head, ma per non esporre all'esterno puntatori, 
   restituimo un intero che dà l'esito dell'operazione (1 se successo, 0 latrimenti), e prendiamo il riferimento all'item in cui scrivere come input.  */
int dequeue(intqueue * Q, item * it)
{		
		int res=0;
		if(!Empty(Q)){ 
			copy_item(it, Q->head->dati); 
			Q->head = list_deletehead(Q->head); 
			Q->size--;
			if(Empty(Q)) Q->tail = Q->head;
			res = 1;
		}else
			printf("\ndequeue: coda vuota\n");
		return res;	
}

void destroyqueue(intqueue *Q){
	list_destroy(Q->head);
	free(Q);
}


