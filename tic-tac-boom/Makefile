CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -g

.PHONY: clean all

all: computer main

computer: computer.o
	$(CC) $(CFLAGS) -o computer computer.o

computer.o: computer.c computer.h
	$(CC) $(CFLAGS) -c computer.c

main: main.o 
	$(CC) $(CFLAGS) -o tic-tac-boom main.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

# acrophobe: player.o acrophobe.o common.o  
# 	$(CC) $(CFLAGS) -o acrophobe player.o acrophobe.o common.o 

# acrophobe.o: acrophobe.c player.h 2310express.h enums.h
# 	$(CC) $(CFLAGS) -c acrophobe.c

clean:
	rm -f *.o *~