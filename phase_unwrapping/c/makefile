CC = gcc
CFLAGS = -Wall -O3 -lm
LDFLAGS = -I/usr/local/Cellar/libtiff/4.0.6/include -L/usr/local/Cellar/libtiff/4.0.6/lib -ltiff
PROG=main
EXT=c


all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(PROG).$(EXT) -o $(PROG)