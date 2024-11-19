#include "BST.h"

/* funzione per creare un BST vuoto*/
BST *createBST(void)
{
	return NULL;
}

/* Funzione che realizza la visita inorder sul BST puntato da p.
  op la funzione chiamata sul membro info (di tipo item) di ciascun nodo*/
void BSTinorderVisit(BST *p, void op(item)){
	if(p){
		BSTinorderVisit(p->left, op);
		print_item(p->info);
		BSTinorderVisit(p->right, op);
	}	
}

/* Funzione per inserire un nuovo nodo con item it in un BST puntato da p */
BST *BSTinsert(BST *p, item it)
{
	BST *x = p;     BST *y = NULL;	
	BST *z = calloc(1, sizeof(BST));
	if(!z) { 
		fprintf(stderr,"Errore di allocazione\n");
        	exit(-1);
	}	
	copy_item(&(z->info) , it); 
/*	z->left = z->right = NULL;*/
	while(x) {
		y = x;
		x = cmp_item(it,  x->info) <= 0 ? x->left : x->right;
	}
	z->parent = y;
	if(!y) return z; /* z e' il primo nodo inserito */
	if(cmp_item(it, y->info) > 0)
      y->right = z;
   else
      y->left = z;     
	return p;
}

/* funzione che cerca un nodo con chiave k nel BST la cui radice è puntata da p.*/
BST * BSTsearch(BST *p, key k)
{
	if(!p || cmp_key(k, get_key(p->info)) == 0)
		return p;
	return BSTsearch(cmp_key(k, get_key(p->info)) <= 0 ? p->left : p->right, k);
}

/* Funzione per ottenere il puntatore al nodo dell'albero radicato in p che contiene 
    la chiave massima */
BST *BSTmax(BST *p)  
{
	if(p)
	   for(; p->right; p = p->right);
	return p;
}

/* Funzione per ottenere il puntatore al nodo dell'albero radicato in p che contiene 
    la chiave minima */
BST *BSTmin(BST *p)  
{
	if(p)
	   for(; p->left; p = p->left);
	return p;
}


/* Funzione per ottenere il puntatore al nodo predecessore del nodo puntato da q */
BST *BSTpred(BST *q) {
	BST *y=NULL, *pred=NULL;
	pred=q;
	if(!q)	   return q;
	if(q->left) return BSTmax(q->left);	
	y = q->parent;	
	if(!y) return q; /* q nodo radice*/
	while(y && q == y->left) {
		q = y;		y = y->parent;		
	}	
	if(y)	return y;
	else return pred; /* caso in cui il predecessore di q non esite (q chiave minima)*/
}


/* Funzione per cancellare la chiave del nodo q dal BST puntato da p*/
BST * BSTdelete(BST *p, BST *q)  /* si assume q != NULL */
{
	BST *r, *s = NULL; 	/* r nodo da cancellare */
	if(!q || !p) return p;
	r = q; /* caso 1 o 2*/
	if(q->left && q->right) /* Caso 3 */ 
		r = BSTpred(q); /* il predecessore non ha figlio destro*/
	/* nel caso 1 o 2 r ha al più un figlio (che metto in s)*/
	/* ma anche nel caso 3  r, che ora è il predecessore di q, ha al più
	   il figlio destro (che metto in s)*/	
	s = r->left ? r->left : r->right;
	if(s) s->parent = r->parent;	/* creo il ponte, r sarà cancellato*/
	if(!r->parent) /*  r e' la radice*/ 
		p = s; /* t nodo restituito come radice */
	else /* imposto il campo figlio del padre */
		if(r == r->parent->left)/* nodo da cancellare figlio sinistro di suo padre */
			r->parent->left = s;
		else
			r->parent->right = s;
	/* Caso 3: nota qui se se ci sono più informazioni nel nodo occorre copiarle*/
	if(r != q)
		copy_item(&(q->info), r->info);
	/* Chiamare la destroy_item su r->info se essa 
	   dovesse contenere memoria allocata dinamicamente*/
	free(r);
	return p != r ? p : NULL;
}


/* Funzione che dealloca tutti i nodi dell'albero p*/
void destroyBST(BST *p) /* si assume p != NULL */
{
	while((p = BSTdelete(p,p)));
}

