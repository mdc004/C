CFLAGS = -Wall -ansi -pedantic
OBJS = ProvaBFS.o BFS.o graph.o intlist.o intqueue.o item.o key.o
EXEC = provaBFS
$(EXEC): $(OBJS) 
	gcc $(CFLAGS) -o $(EXEC) $(OBJS) 
$(EXEC).o: $(EXEC).c 
	gcc $(CFLAGS) -c $(EXEC).c     
BFS.o: BFS.c 
	gcc $(CFLAGS) -c BFS.c	
graph.o: ../graph.c
	gcc $(CFLAGS) -c ../graph.c	
intlist.o: ../intlist/intlist.c 
	gcc $(CFLAGS) -c ../intlist/intlist.c	
intqueue.o: ../intqueue/intqueue.c 
	gcc $(CFLAGS) -c ../intqueue/intqueue.c
item.o: ../intqueue/intqueue.c 
	gcc $(CFLAGS) -c ../intlist/item.c
key.o: ../intqueue/intqueue.c 
	gcc $(CFLAGS) -c ../intlist/key.c		
clean:
	rm -f *.o $(EXEC) $(OBJS)	
