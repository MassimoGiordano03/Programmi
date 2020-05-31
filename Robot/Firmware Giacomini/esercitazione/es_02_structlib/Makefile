CC=gcc
COPTS=-Wall -I./

OBJS = 	main.o	miastruct.o

DEPS = miastruct.h

BINS = main.elf

.PHONY: clean all

all: $(BINS)

%.o: %.c 
	$(CC) $(COPTS) $< -c -o $@

main.elf: $(OBJS)  
	$(CC) $(COPTS) $^ -o $@

clean:
	rm -rf *.o $(BINS)
