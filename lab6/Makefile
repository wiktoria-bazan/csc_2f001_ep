.SUFFIXES:
.SECONDARY:
.PHONY: all clean 

CFLAGS= -Wall -Werror

all: main

main: main.cpp treemap.h
	g++ -std=c++20 $(CFLAGS) main.cpp -o main 

clean: 
	rm -f main