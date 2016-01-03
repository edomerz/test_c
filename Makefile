CC=gcc
CFLAGS=-g -std=c89 -ansi -Wall -Werror -D_DEBUG -I .
DEPS = test_c.h
OBJ = test_c.o test_c_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_c_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
