CFLAGS = -Wall -ansi -pedantic
OBJS = grafo_main.o graph.o intlist.o item.o key.o
EXEC = grafo_main
$(EXEC): $(OBJS) 
	gcc $(CFLAGS) -o $(EXEC) $(OBJS) 
$(EXEC).o: $(EXEC).c 
	gcc $(CFLAGS) -c $(EXEC).c     
graph.o: graph.c 
	gcc $(CFLAGS) -c graph.c	
intlist.o: intlist.c
	gcc $(CFLAGS) -c intlist.c
item.o: item.c 
	gcc $(CFLAGS) -c item.c
key.o: key.c 
	gcc $(CFLAGS) -c key.c	
clean:
	rm -f $(EXEC) $(OBJS)
