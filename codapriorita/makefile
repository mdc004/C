EXEC = codap_main

CFLAGS = -Wall -ansi -pedantic
OBJS = coda_priorita_main.o codap.o item.o key.o
$(EXEC): $(OBJS)
	gcc -o $(EXEC) $(OBJS) $(CFLAGS) 
coda_priorita_main.o: coda_priorita_main.c codap.h
	gcc -c coda_priorita_main.c $(CFLAGS)       
codap.o: codap.c  codap.h
	gcc -c codap.c $(CFLAGS)	
item.o: item.c 
	gcc $(CFLAGS) -c item.c
key.o: key.c 
	gcc $(CFLAGS) -c key.c	
clean:
	rm -f $(EXEC) $(OBJS)	
