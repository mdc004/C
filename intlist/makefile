CFLAGS = -Wall -ansi -pedantic
OBJS = menu.o intlist.o item.o key.o
EXEC = menu

$(EXEC): $(OBJS) 
	gcc $(CFLAGS) -o $(EXEC) $(OBJS)
menu.o: menu.c 
	gcc $(CFLAGS) -c menu.c     
intlist.o: intlist.c
	gcc $(CFLAGS) -c intlist.c	
item.o: item.c 
	gcc $(CFLAGS) -c item.c
key.o: key.c 
	gcc $(CFLAGS) -c key.c	
clean:
	rm -f *.o $(EXEC) $(OBJS)	
