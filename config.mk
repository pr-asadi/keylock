PREFIX = ~/.local
PROGNAME = keylock

# OpenBSD
X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib


INCS = -I${X11INC}
LIBS = -L${X11LIB} -l X11
CFLAGS = -Wall -Wno-deprecated-declarations ${INCS}

