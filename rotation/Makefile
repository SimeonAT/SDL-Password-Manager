# Helpful Links:
# - https://stackoverflow.com/questions/10488775/
#   sdl-h-no-such-file-or-directory-found-when-compiling
# - https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php

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
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all ./$(EXECBIN)

format:
	clang-format -i $(FILE)
