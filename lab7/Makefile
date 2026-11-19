.SUFFIXES:
.SECONDARY:
.PHONY: all clean 

CFLAGS= -Wall -Werror

all: monster

monster: monster.cpp 
	g++ -std=c++20 $(CFLAGS) monster.cpp -o monster 

clean: 
	rm -f monster