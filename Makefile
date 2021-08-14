all: main clean

main: main.o route-records.o
	clang main.o route-records.o -o main -lm

main.o: main.c route-records.h
	clang -c main.c

route-records.o: route-records.c route-records.h
	clang -c route-records.c 

clean:
	rm -rf *.o
