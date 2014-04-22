CC = gcc
CFLAGS = -g -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBS = -lglib-2.0  
DEPS = 
OBJ = glibhash.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

glibhash: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

valgrind:
	G_SLICE=always-malloc G_DEBUG=gc-friendly valgrind --tool=memcheck --leak-check=full --leak-resolution=high --num-callers=20 --log-file=vgdump --show-reachable=yes ./glibhash

tar:
	rm -rf hw20_soln
	mkdir hw20_soln
	cp glibhash.c Makefile emma.txt hw20_soln
	tar -czf hw20_soln.tgz hw20_soln