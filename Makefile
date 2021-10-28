build: main.o functions.o
	gcc main.o functions.o -o tenis
	./tenis cerinte.in date.in rezultate.out

main.o: main.c
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c

clean:
	rm *.o tenis