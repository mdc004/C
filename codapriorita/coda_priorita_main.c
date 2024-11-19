#include "codap.h"
int main(){
	int scelta, res;
	item it;
	int exec = 1;
	codap *queue = NULL;
	
	while(exec){		
		printf("\nChe operazione eseguire:\n\
		--------------------------------------------\n\
		 --- 0: esci \n\
		 --- 1: crea coda vuota \n\
		 --- 2: inserisci elemento \n\
		 --- 3: visualizza elemento di minima priorità'\n\
		 --- 4: Estrai elemento di minima priorità' \n\
		 --- 5: numero elementi in coda \n\
		 --- 6: Stampa la coda \n\
		 --- 7: cancella coda\n\
		 --------------------------------------------\n"); 
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 0:
				if(queue) {
					free(queue->Q);
					free(queue);
					queue = NULL;		
				}					
				exec = 0;
			break;				
			case 1:
				printf("Inserisci dimensione:\n");
				scanf("%d", &res); 
				queue = createCodap(res);
			break;
			case 2:
				if(queue){
					leggi_item(&it);
					res=Insert(queue, it);
					if(res) printf("Inserimento avvenuto con successo\n");	
					res = 0;
				}else printf("Prima creare la coda\n");				
			break;
			case 3:
				if(queue){					
					res = Minimum(queue, &it);
					if(res){
						printf("Elemento con priorità' minima :\n");
						print_item(it);
					} 
					res = 0;
				}else printf("Prima creare la coda\n");
			break;
			case 4:
				if(queue){			
					res =  ExtractMin(queue, &it);
					if(res){
						printf("Elemento con priorità' minima rimosso:\n");
						print_item(it);
					}
					res = 0;
				}else printf("Prima creare la coda\n");
			break;
			case 5:								
				if(!queue)
				   printf("Prima creare la coda\n");
				else
				   printf("elementi in coda: %d \n", queue->hs);    
			break;
			case 6:								
				if(!queue)
				   printf("Prima creare la coda\n");
				else
				   for (res=0;res<queue->hs; res++){
						print_item(queue->Q[res]);					
					}   
			break;
			case 7:
				if(queue) {
					free(queue->Q);
					free(queue);
					queue = NULL;		
				}					
			break;			
				
			default: printf("\nScelta non valida\n");	
		}
	
	}
	return 1;
}

