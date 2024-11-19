EXEC = menuCoda
CFLAGS = -Wall -ansi -pedantic
OBJS = menu_coda.o intlist.o intqueue.o item.o key.o

$(EXEC): $(OBJS)
	gcc -o $(EXEC) $(OBJS) $(CFLAGS)
menu_coda.o: menu_coda.c  
	gcc -c menu_coda.c $(CFLAGS)
intqueue.o: intqueue.c
	gcc -c intqueue.c $(CFLAGS)
intlist.o: ../intlist/intlist.c
	gcc -c ../intlist/intlist.c $(CFLAGS)
item.o: ../intlist/item.c 
	gcc $(CFLAGS) -c ../intlist/item.c
key.o: ../intlist/key.c 
	gcc $(CFLAGS) -c ../intlist/key.c	
clean:
	rm -f $(EXEC) $(OBJS)	
