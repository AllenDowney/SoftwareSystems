CC = gcc
CFLAGS = -Wall
WRAPPERS = wraplib.o wrapstdio.c wrapsock.o wrapunix.o error.o \
writen.c readline.c
FILES = error.c     str_cli08.c   tcpserv01.c  wrapsock.c   writen.c \
Makefile    str_echo08.c  unp.h        wrapstdio.c \
readline.c  tcpcli01.c    wraplib.c    wrapunix.c


tcpcli01:	tcpcli01.o str_cli08.o ${WRAPPERS}
		${CC} ${CFLAGS} -o $@ tcpcli01.o str_cli08.o ${WRAPPERS}

tcpserv01:	tcpserv01.o str_echo08.o 
		${CC} ${CFLAGS} -o $@ tcpserv01.o str_echo08.o ${WRAPPERS}

distrib:
	rm -rf roman
	mkdir roman
	cp ${FILES} roman
	tar -czf ../roman.tgz roman
	rm -rf roman

clean:
	rm *.o *~ tcpcli01 tcpserv01