#include <stdio.h>
#include <stdlib.h>
struct key{
	int codice;
};
typedef struct key key;

key new_key(int);

void leggi_key(key *);
void set_val(key *, int);
void copy_key(key *, key);

void destroy_key(key*);

int cmp_key(key, key);

void print_key(key);
