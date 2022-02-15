INCLUDES = is_refrigerated.h energy.h
SOURCES = is_refrigerated.s energy.c main.c
OBJFILES = is_refrigerated.o energy.o main.o
EXEC = US410

.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

.s.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES} : ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}
