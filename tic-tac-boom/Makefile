CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -g

.PHONY: clean all

all: computer game

computer: computer.o game.o
	$(CC) $(CFLAGS) -o computer computer.o game.o

computer.o: computer.c computer.h game.h
	$(CC) $(CFLAGS) -c computer.c

game: game.o
	$(CC) $(CFLAGS) -o tic-tac-boom game.o

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

# debugHelper: debugHelper.o
# 	$(CC) $(CFLAGS) -o debug debugHelper.o

# debugHelper.o: debugHelper.c debugHelper.h
# 	$(CC) $(CFLAGS) -c debugHelper.c


# acrophobe: player.o acrophobe.o common.o  
# 	$(CC) $(CFLAGS) -o acrophobe player.o acrophobe.o common.o 

# acrophobe.o: acrophobe.c player.h 2310express.h enums.h
# 	$(CC) $(CFLAGS) -c acrophobe.c

clean:
	rm -f *.o *~