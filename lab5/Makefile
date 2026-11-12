.SUFFIXES:
.SECONDARY:
.PHONY: all clean 

LDFLAGS= 
LIBS=
CFLAGS= -Wall -Werror -g
BIN=lisp

all: $(BIN)

lisp: lisp.o structures.o
	g++ -std=c++20 $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp structures.h
	g++ -std=c++20 $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) *.o *~

