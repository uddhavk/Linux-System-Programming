CC = gcc 

CFLAGS = -Wall -Wextra -O2

app: Main.o Helper.o
	$(CC) Main.o Helper.o -o app

Main.o: Main.c Helper.h
	$(CC) $(CFLAGS) -c Main.c 

Helper.o: Helper.c Helper.h
	$(CC) $(CFLAGS) -c Helper.c 

clean:
	rm -f Main.o Helper.o app

.PHONY: clean
