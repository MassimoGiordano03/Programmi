
CC=gcc
COPTS=-Wall -I./

OBJS = main.o

BIN = main.elf

.PHONY: clean all

all: $(BIN)

main.elf: main.o
	$(CC) $(COPTS) $< -o $@

%.o: %.c
	$(CC) $(COPTS) $< -c -o $@

clean:
	rm -rf *.o $(BIN)


