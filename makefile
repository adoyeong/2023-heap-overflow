#Makefile

all: test

test: main.c
	gcc -o test main.c

clean:
	rm -f test
