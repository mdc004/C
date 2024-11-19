
#include<stdlib.h>
#include"intqueue.h"

int main(){

	int scelta, res=0;
	int exec = 1;
	item it;
	intqueue *Q = NULL;
	while(exec){		
		printf("\nChe operazione eseguire:\n--------------------------------------------\n --- 0: esci \n --- 1: crea coda vuota \n --- 2: Equeue \n --- 3: Head \n --- 4: Dequeue \n --- 5: Tail \n --- 6: Size \n --- 7: Stampa contenuto coda\n --- 8: Destroy coda--------------------------------------------\n"); 
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 0:
				exec = 0;
			break;				
			case 1:
				Q = createqueue();
			break;
			case 2:
				if(Q)	enqueue(Q);
				else printf("Devi prima creare la coda\n");	
			break;
			case 3:
				if(Q){
					if(!Empty(Q)){
						res=Head(Q, &it);
						if(res){ 
							printf("elemento in testa\n");
							print_item(it);
							res = 0;				
						}else printf("\tOperazione non riuscita\n");	
					}else	 printf("Coda vuota  \n");
				}
				else printf("Devi prima creare la coda\n"); 

			break;
			case 4:
				if(Q){
					if(!Empty(Q)){ 
						res = dequeue(Q, &it);
						if(res){
							printf("\t elemento estratto: \n");
							print_item(it);
							res=0;
						}else printf("\tOperazione non riuscita\n");	
					}else	 printf("Coda vuota\n");
				}else printf("Devi prima creare la coda\n");		
			break;
			case 5:
				if(Q){
					if(!Empty(Q)){
						res = Tail(Q, &it);
						if(res){
							printf("\telemento in coda: \n");
							print_item(it);
							res = 0;
						}else printf("\tOperazione non riuscita\n");	 
					}else	 printf("Coda vuota  \n");
				}else printf("Devi prima creare la coda\n"); 				
			break;
			case 6:
				if(Q){	
					if(!Empty(Q)){
						printf("\nNella lista ci sono %d elementi\n", size(Q));
					}else	 printf("Coda vuota  \n");	
				}else printf("Devi prima creare la coda\n");		
			break;			
			case 7:
				if(Q)
					if(!Empty(Q)) print_list(Q->head);				
			break;
			case 8:
				if(Q){
					destroyqueue(Q);
					Q = NULL;
				}					
			break;
			default: printf("\nScelta non valida\n");	
		}
	
	}
	return 0;
}
