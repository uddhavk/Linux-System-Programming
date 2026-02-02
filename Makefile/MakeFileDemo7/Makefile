CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = Main.o Helper.o
Target = app

$(Target): $(OBJ)
	$(CC) $(OBJ) -o $(Target)

Main.o: Main.c Helper.h 
	$(CC) $(CFLAGS) -c $< -o $@

Helper.o: Helper.c Helper.h 
	$(CC) $(CFLAGS) -c $< -o $@

run: app
	./app

clean:
	rm -f $(OBJ) $(Target)

.PHONY: clean

