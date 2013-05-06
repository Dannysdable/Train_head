train: main.o
	gcc -o train main.o

@echo Being compiled

main.o: main.c main.h
	gcc -c main.c -I ../include/

.PHONY: clean
clean:
	-rm -rf train *.o
