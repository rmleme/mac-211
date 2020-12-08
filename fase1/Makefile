INC= -I/usr/X11R6/include
LIB= -L/usr/X11R6/lib
CFLAGS=-Wall -g ${INC} ${LIB}
CC=gcc

objetos.o: xwc.h xwc.c objetos.h objetos.c
	$(CC) $(CFLAGS) -c $*.c

grafic.o: xwc.h xwc.c objetos.h objetos.c grafic.h grafic.c
	$(CC) $(CFLAGS) -c $*.c

teste.o: xwc.h xwc.c objetos.h objetos.c grafic.h grafic.c teste.c
	$(CC) $(CFLAGS) -c $*.c

teste : teste.o xwc.o objetos.o grafic.o
	${CC} ${CFLAGS} -o teste teste.o xwc.o objetos.o grafic.o -lm -lX11 -lXpm

xwc.o : xwc.c

clean: 
	rm -f *.o objetos grafic teste *~