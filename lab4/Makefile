.SUFFIXES:
.SECONDARY:
.PHONY: all clean

LDFLAGS=
LIBS=
CFLAGS= -Wall -Werror -g 
BIN=bilbao

all: $(BIN) #do if is there is no all (which is true from phony and then do BIN if it's not up to date)

#instruction how to create bilbao
bilbao: main.o location.o shortest_path.o
	g++ -std=c++20 $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp location.h shortest_path.h
	g++ -std=c++20 $(CFLAGS) -o $@  -c $<

clean:
	rm -f $(BIN) *.o *~ 