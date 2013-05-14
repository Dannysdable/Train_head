CFLAGS = -g -Wall
CFILE = main.c
CFILE += func.c process.c 
INCLUDE = ../include/

train: $(CFILE)
	gcc $(CFLAGS) -o $@ $? -I $(INCLUDE)


#train: main.o
#	gcc -g -Wall -o $@ $? -I ../include/
#
#main.o: main.c 
#	gcc -g -Wall -c main.c -I ../include/


.PHONY: clean
clean:
	-rm -rf train *.o
