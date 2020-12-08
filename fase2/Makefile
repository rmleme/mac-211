INC= -I/usr/X11R6/include
LIB= -L/usr/X11R6/lib
CFLAGS=-Wall -g ${INC} ${LIB}
CC=gcc

objetos.o: xwc.h xwc.c objetos.h objetos.c
	$(CC) $(CFLAGS) -c $*.c

grafic.o: xwc.h xwc.c objetos.h objetos.c grafic.h grafic.c
	$(CC) $(CFLAGS) -c $*.c

pilhas.o: pilhas.h pilhas.c
	$(CC) $(CFLAGS) -c $*.c

instruc.o: pilhas.h pilhas.c instruc.h instruc.c
	$(CC) $(CFLAGS) -c $*.c

interp.o: objetos.h objetos.c grafic.h grafic.c pilhas.h pilhas.c instruc.h instruc.c interp.h interp.c
	$(CC) $(CFLAGS) -c $*.c

teste.o: xwc.h xwc.c objetos.h objetos.c grafic.h grafic.c pilhas.h pilhas.c instruc.h instruc.c interp.h interp.c teste.c
	$(CC) $(CFLAGS) -c $*.c

teste : teste.o xwc.o objetos.o grafic.o pilhas.o instruc.o interp.o
	${CC} ${CFLAGS} -o teste teste.o xwc.o objetos.o grafic.o pilhas.o instruc.o interp.o -lm -lX11 -lXpm

xwc.o : xwc.c

clean: 
	rm -f *.o objetos grafic pilhas instruc interp teste *~