us315: occupied.o main.o
	gcc -g -Wall occupied.o main.o -o us315
	
occupied.o: occupied.s
	gcc -g -Wall -c occupied.s -o occupied.o

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

clean:
	rm -f *.o us315

run: us315
	./us315
