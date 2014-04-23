CC = gcc
CFLAGS = -g -Wall 
LIBS = -lglib-2.0  
DEPS = 
OBJ = glibhash.o

mem_errors: mem_errors.c 
	gcc $(CFLAGS) -o mem_errors mem_errors.c

list_errors: list_errors.c 
	gcc $(CFLAGS) -o list_errors list_errors.c

valgrind:
	G_SLICE=always-malloc G_DEBUG=gc-friendly valgrind --tool=memcheck --leak-check=full --leak-resolution=high --num-callers=20 --log-file=vgdump --show-reachable=yes ./mem_errors

