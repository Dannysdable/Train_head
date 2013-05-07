train: main.o
	gcc -g -Wall -o $@ $? -I ../include/

main.o: main.c 
	gcc -g -Wall -c main.c -I ../include/

.PHONY: clean
clean:
	-rm -rf train *.o
