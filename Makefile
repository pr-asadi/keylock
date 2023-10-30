include config.mk

SRC = keylock.c
OBJ = ${SRC:.c=.o}

all: keylock

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

keylock: ${OBJ}
	${CC} -o $@ ${LIBS} ${OBJ}

install: all
	mkdir -p ${PREFIX}
	install -m 0755 ${PROGNAME} ${PREFIX}/bin
uninstall: 
	rm ${PREFIX}/bin/${PROGNAME}

clean:
	rm *.o ${PROGNAME}

.PHONY: all install uninstall clean
