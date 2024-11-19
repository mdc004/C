#include"key.h"

struct item{
	key chiave;
};

typedef struct item item;

item new_item(key);

key get_key(item);

void leggi_item(item*);
void print_item(item);

void copy_item(item*, item);

int cmp_item(item, item);

