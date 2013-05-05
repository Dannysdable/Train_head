train: main.o
	gcc -o train main.o
main.o: main.c main.h
	gcc -c main.c -I ../include/
clean:
	rm -rf train *.o
