CC = clang++ 
CFLAGS = -Wall -Werror -Wextra -Wpedantic -I/usr/include/SDL2
LINKER = -lSDL2 -lSDL2_image 
EXECBIN = rotation
FILE = $(EXECBIN).cpp 

all: $(FILE)
	$(CC) $(FILE) $(CFLAGS) $(LINKER) -o $(EXECBIN)

clean:
	rm -f $(EXECBIN) $(wildcard *.o)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(EXECBIN)
