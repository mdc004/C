#include "BST.h"

int main()
{
	int scelta, exec=1;
	key k;
	BST *q, *root = createBST();
	item it;
	while(exec){		
		printf("\nChe operazione eseguire:\n--------------------------------------------\n\
		--- 0: esci \n\
		--- 1: Crea BST vuoto \n\
		--- 2: Inserisci una chiave \n\
		--- 3: Rimuovi una chiave \n\
		--- 4: Cerca una chiave \n\
		--- 5: Visita l'albero\n\
		--- 6: Chiave minima\n\
		--- 7: Chiave massima\n\
		--- 8: distruggi l'albero \n--------------------------------------------\n"); 
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 0:
				if(root){
					destroyBST(root);
					root = NULL;
				}
				exec = 0;
			break;				
			case 1:				
				root = createBST();
			break;
			case 2:								 
				leggi_item(&it);					
			   root = BSTinsert(root, it);
			break;
			case 3:
				if (root){	
					printf("inserisci la chiave da cancellare\n");
					leggi_key(&k);	 
					q = BSTsearch(root, k);
					if(q){
						printf("chiave trovata nel nodo seguente:\n");
						print_item(q->info);
						root = BSTdelete(root,q);
					}	
					else				
						printf("Chiave non presente\n");		
				}else printf("\t Prima creare l'albero\n"); 	
			break;
			case 4:
				if (root){				
					printf("inserisci la chiave da cercare\n");
					leggi_key(&k);	 
					q = BSTsearch(root, k);
					if(!q)				
						printf("Chiave non presente\n");
					else{ 
						 printf("Chiave presente nel nodo seguente:\n");
						 print_item(q->info);
					}	 
				}else printf("\t Prima creare l'albero\n"); 	
			break;
			case 5:
				if(root) BSTinorderVisit(root, print_item);
				else printf("Albero vuoto\n");
			break;
			case 7:
				if(root) {
					printf("Chiave massima: \n");
					q = BSTmax(root);
					print_item(q->info);
				}
				else printf("Albero vuoto\n");
			break;
			case 6:
				if(root) {
					printf("Chiave minima: \n");
					q = BSTmin(root);
					print_item(q->info);
				}
				else printf("Albero vuoto\n");
			break;
			case 8:
				if(root){
					destroyBST(root);
					root = NULL;
				}	
			break;			
			default: printf("\nScelta non valida\n");	
		}
	
	}

	return 0;
}
