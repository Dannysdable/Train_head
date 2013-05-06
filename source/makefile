train: main.o
	gcc -o $@ $? -I ../include/

main.o: main.c 
	gcc -c main.c -I ../include/

.PHONY: clean
clean:
	-rm -rf train *.o
