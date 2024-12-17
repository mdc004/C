#include<stdio.h>
#include "../graph.h"
/*#include "../intqueue/intqueue.h"
#include "../intlist/intlist.h"
#include "../intlist/item.h"
#include "../intlist/key.h"*/
#include <limits.h>
#include <stdlib.h>
/* Funzione per eseguire la visita BFS sul grafo non orientato G 
del tipo graph visto a lezione
INPUT 
G,  	oggetto di tipo graph, grafo non orientato di input
s,  	intero,  indice del nodo da cui parte la 
      visita (indici partono da 0).
d,  	puntatore a int,  vettore contente le 
      distanze minimime da s. d[i] distanza nodo i
        (indice i) da s. Si ricordi che i  nodi nodi
        sono numerati da 0 a G->V-1.
p,  	puntatore a int,  vettore rappresentante 
       l'albero BFS. Al temine della visita, p[i]
         conterrà il padre del nodo i nell'albero,
        cioe' il nodo da cui e' stato scoperto. 
color,  puntatore a int,  vettore dei colori. 
        color[i] = 0 (bianco) oppure 
        1 (grigio) oppure 2 (nero), colore del 
        nodo i.           
*/

void BFS(graph *G, int s, int* d, int* p, int* color){
	intlist *adj;
	int v, u, res;
	item it;
	key k;
	intqueue *Q = createqueue();
	if(!(s >= 0 && s< G->V)) {
		printf("s non valido:%d\n", s);
		exit(-1);
	}
	for(v = 0; v < G->V; v++){
		color[v] = 0;
		d[v] = INT_MAX;
		p[v] = -1;
	}	
	color[s] = 1; /* primo nodo scoperto e' s*/
	d[s] = 0;
	k = new_key(s);	
	set_key(&it, k);
	enqueue2(Q, it);
	while(!Empty(Q)){
		res = dequeue(Q, &it);
		k = get_key(it);		
		u = get_val(k);
		printf("\t Estratto dalla coda nodo %d:\n",u);
		adj = getAdj(G, u); 
		if(adj){
			/*scorre la lista id u*/
			while(adj != NULL){					
				k = get_key(adj->dati);
				v = get_val(k);
				printf("\t\tvisita adiacenza di %d: trovato %d\n\t color[%d]:%d\n", u, v, v, color[v]);
				if(color[v] == 0){ 
					color[v] = 1;
					p[v] = u;
					d[v] = d[u] + 1;	
					k = new_key(v);
					set_key(&it, k);
					enqueue2(Q, it);
					printf("\t\t %d inserito in coda \n", v);
				}
				adj = adj->next;	
			}
		}else printf("\t lista di adiacenza nodo %d vuota\n",u); 
		color[u] = 2;	
		printf("Fine visita nodo %d\n", u); 
	}			
}





