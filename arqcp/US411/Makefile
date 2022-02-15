# A simple Makefile
us411: main.o
	gcc main.o -o us411
main.o: main.c
	gcc -g -Wall -c main.c -o main.o
clean:
	rm -f *.o us411
run: us411
	./us411
