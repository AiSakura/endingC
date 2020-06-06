all:	build clean run

build:	lab7.o
	gcc lab7.o -o YEP

lab7.o:	lab7.c
	gcc  -c lab7.c -lm -std=c89

run:	build
	./YEP.exe

clean:	build
	del lab7.o
