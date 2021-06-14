CC = g++
CFLAGS = -w 
LINKER = -lSDL2

all: password_class.h main.cpp
	$(CC) main.cpp $(CFLAGS) $(LINKER) -o password

clean:
	rm -f $(wildcard *.o) password

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -s ./password
