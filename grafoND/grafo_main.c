#include "graph.h"

int main(int argc, char **argv)
{
	int nv, i, j, scelta, exec=1;
	graph *g=NULL;
	FILE *fp;

	if(argc != 3) {
		fprintf(stderr, "Uso: %s <Numero nodi> <file>\n",argv[0]);
		exit(-1);
	};
	if(!(fp = fopen(argv[2],"r"))) {
	   fprintf(stderr, "File %s non trovato\n",argv[2]);
		exit(-2);
	};	
	nv = atoi(argv[1]);
	g = creategraph(nv);
	readgraph(g, fp);

	while(exec){		
		printf("\nChe operazione eseguire:\n\
		    --------------------------------------------\n\
		    --- 0: esci \n\
		    --- 1: stampa lista di adiacenza di un nodo \n\
		    --- 2: Aggiungi un arco \n\
		    --- 3: rimuovi un arco \n\
		    --- 4: numero archi \n\
		    --- 5: numero vertici \n\
		    --- 6: distruggi il grafo \n\
		    --------------------------------------------\n"); 
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 0:
				exec = 0;
			break;				
			case 1:
				if(!g) printf("Grafo già' distrutto\n");	
				else{
					printf("inserisci il nodo\n");
					scanf("%d",&i);
					if(i >=0 && i < g->V)
						stampalista(g, i);
					else 
						printf("nodo inesistente\n");
				}			
			break;
			case 2:
				if(!g) printf("Grafo già' distrutto\n");	
				else{
					printf("inserisci i due nodi dell'arco\n");
					scanf("%d %d",&i, &j);
					if((i >=0 && i <= g->V) && (j >=0 && j <= g->V))
					add_edge(g, i, j);
					else
						printf("Uno o entrambi i nodi non esistono\n");
				}		
			break;
			case 3:
				if(!g) printf("Grafo già' distrutto\n");	
				else{
					printf("inserisci i due nodi dell'arco da cancellare\n");
					scanf("%d %d",&i, &j);
					if((i >=0 && i <= g->V) && (j >=0 && j <= g->V))
						remove_edge(g, i, j);
					else
						printf("Uno o entrambi i nodi non esistono\n");
				}				
			break;
			case 4:
				if(g)	printf("Numero archi nel grafo: %d\n", g->E);
				else printf("Grafo già' distrutto\n");				
			break;
			case 5:
				if(g)	printf("Numero vertici nel grafo: %d\n", g->V);
				else printf("Grafo già' distrutto\n");				
		
			break;
			case 6:
				if(g){ 
					destroygraph(g);
					g = NULL;
				}		
			break;			
			default: printf("\nScelta non valida\n");	
		}
	
	}

	return 0;
}
