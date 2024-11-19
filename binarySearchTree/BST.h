#include "item.h"

struct BST {
	item info;
	struct BST *left, *right, *parent;
}; 

typedef struct BST BST;

BST *createBST(void);

void BSTinorderVisit(BST *, void op(item ));


BST *BSTsearch(BST *p, key k);

BST *BSTmax(BST *p); 
BST *BSTmin(BST *p); 

BST *BSTpred(BST *q); /* si assume q != NULL */

BST *BSTinsert(BST *, item );

BST * BSTdelete(BST *p, BST *q); /* si assume q != NULL */

void destroyBST(BST *p); /* si assume p != NULL */


