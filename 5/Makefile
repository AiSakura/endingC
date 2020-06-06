run: project.exe	
	./project.exe	
build: main.o
	gcc -o project.exe main.o 
	gcc -o project.out main.o
valgrind:
	valgrind --leak-check=full -v --track-origins=yes ./project.out
splint:
	splint main.c
clean:
	rm -rf *.o *.exe *.out
main.o: main.c
	gcc -c -o main.o main.c -std=c89
