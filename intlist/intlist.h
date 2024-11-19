#include "item.h"

struct intlist{
	item dati;
	struct intlist* next;
};
typedef struct intlist intlist;

void leggi_nodo(intlist*);

item get_item(intlist);
intlist* list_insert(intlist*);


intlist* list_search(intlist*, key);

int list_search2(intlist*, key, item*);

intlist* list_delete(intlist*, key);
void print_list(intlist*);

void list_destroy(intlist*);
