all: clean
	gcc main.c LDED.c -o exec -Wall

clean:
	rm -rf *.o exec

zip:
	zip T2.zip *.c *.h Makefile

run:
	./exec