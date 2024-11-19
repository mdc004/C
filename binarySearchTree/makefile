CFLAGS = -Wall -ansi -pedantic
OBJS = menu_BST.o BST.o item.o key.o
EXEC = menu_BST

$(EXEC): $(OBJS) 
	gcc $(CFLAGS) -o $(EXEC) $(OBJS)
menu_BST.o: menu_BST.c 
	gcc $(CFLAGS) -c menu_BST.c     
BST.o: BST.c item.h 
	gcc $(CFLAGS) -c BST.c	
item.o: item.c 
	gcc $(CFLAGS) -c item.c
key.o: key.c 
	gcc $(CFLAGS) -c key.c	
clean:
	rm -f $(EXEC) $(OBJS)	
