#include "graph.h"

/* Alloca spazio per un grafo non diretto con nv vertici 
    rappresentato mediante liste di adiacenza, e ne restituisce
     il puntatore
 */
graph *creategraph(int nv)
{
	int i;
	graph *g = malloc(sizeof(graph));
	
	if(!g) {
		fprintf(stderr,"Errore di Allocazione\n");
		exit(-1);
	}
	g->E = 0;
	g->V = nv;
	if(!(g->A = calloc(nv, sizeof(intlist *))))  {
		fprintf(stderr,"Errore di Allocazione\n");
		exit(-2);
	}
	/* Inizializzazione liste di adiacenza di tipo intlist per ciascun nodo*/
	for(i = 0;i < nv; i++) 
		g->A[i] = NULL;
	return g;
}

/* Inserisce nel grafo non diretto puntato da g l'arco {v1, v2}.
  */
void add_edge(graph *g, int v1, int v2)
{		
	intlist *p=NULL;
	key k = new_key(v2);
	item it;
	copy_key(&it.chiave, k);
	/* verifica che l'arco non sia già presente */
	if(g->A[v1]) p = list_search(g->A[v1], k);
	if(!p){
		set_key(&it, k);
		g->A[v1] = list_insert2(g->A[v1], it);
		k = new_key(v1);
		set_key(&it, k);
		g->A[v2] = list_insert2(g->A[v2], it);
		g->E++;
		printf("\tOperazione avvenuta con successo!\n");
	}
}

/* Rimuove dal grafo non diretto puntato da g l'arco  {v1, v2}, se esiste. */
void remove_edge(graph *g, int v1, int v2)
{	
	key k = new_key(v2);
	if (list_search(g->A[v1], k)) {	
		g->E--;
		g->A[v1] = list_delete(g->A[v1], k);
		k = new_key(v1);
		g->A[v2] = list_delete(g->A[v2], k);
	}else 
		printf("Arco non presente\n");	
}



/* Legge gli archi di un grafo non diretto dal file fp e li inserisce nel grafo 
    puntato da g. Si assume che il file puntato da fp sia organizzato in righe 
    del tipo <v1 v2>*/
void readgraph(graph *g, FILE *fp)
{
	int v1, v2;
	while (fscanf(fp,"%d %d",&v1, &v2)!=EOF)	{			
		printf("letto %d %d\n", v1, v2);
		add_edge(g, v1, v2);					
	}		
}

/* Funzione che stampa la lista di adiacenza del nodo v */
void stampalista(graph *g, int v)
{
	print_list(g->A[v]);
}

/* Funzione che restituisce il puntatore alla testa della 
    lista di adiacenza del nodo v */
intlist* getAdj(graph *g, int v)
{
	return g->A[v];
}

/* Funzione per deallocare tutta la memoria allocata per il grafo g */
void destroygraph(graph *g) {
	int i;
	for(i = 0; i < g->V; i++)		
		list_destroy(g->A[i]);	
	
	free(g);
}

