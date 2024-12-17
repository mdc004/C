#include <stdio.h>
#include <stdlib.h>

#include "../graph.h"

void BFS(graph *, int, int* , int* , int* );

int main(int ac, char **av)
{
	int *color, *p, *d;
	int nv;	
	struct graph *G = NULL;
	FILE *fp;

	if(ac != 3) {
		fprintf(stderr,"Uso: %s <Numero nodi> <file>\n",av[0]);
		exit(-1);
	};
	if(!(fp = fopen(av[2], "r"))) {
	fprintf(stderr,"File %s non trovato\n", av[2]);
		exit(-2);
	};	
	nv = atoi(av[1]);
	G = creategraph(nv);
	readgraph(G, fp);
	printf ("Numero archi nel grafo: %d\n", G->E);
	
/*#####################################
######### ALLOCAZIONE ARRAY #############
######################################*/	
	color = malloc(sizeof(int)*G->V);
	if(!color){
		fprintf(stderr,"Errore di Allocazione color\n");
		exit(-1);
	}
	p = malloc(sizeof(int)*G->V);
	if(!p){
		fprintf(stderr,"Errore di Allocazione p\n");
		exit(-2);
	}
	d = malloc(sizeof(int)*G->V);
	if(!d){
		fprintf(stderr,"Errore di Allocazione d\n");
		exit(-3);
	}	
/*#####################################
######### FINE ALLOCAZIONE ARRAY #############
######################################*/	
	BFS(G, 0, d, p, color);
	putchar('\n');
	for(nv = 0; nv < G->V; nv++)
		printf("Albero BFS: padre nodo %d : %d\n", nv, p[nv]);
	putchar('\n');
	for(nv = 0; nv< G->V; nv++)
		printf("Distanza minima:  nodo %d : %d\n", nv, d[nv]);	
	free(p);free(color);free(d);
	destroygraph(G);	
	return 0;
}
