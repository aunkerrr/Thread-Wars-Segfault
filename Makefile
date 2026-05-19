all: arena

arena: main.o fire.o robot.o
	gcc main.o fire.o robot.o -o arena -pthread -lncurses

main.o: main.c
	gcc -c main.c

fire.o: fire.c
	gcc -c fire.c

robot.o: robot.c
	gcc -c robot.c

clean:
	rm -f *.o arena