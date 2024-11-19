#include"key.h"

struct item{
	key priorita;
};

typedef struct item item;

item new_item(key);

key get_key(item);
void set_key(item* , key );

void leggi_item(item*);
void print_item(item);

void copy_item(item*, item);

int cmp_item(item, item);

