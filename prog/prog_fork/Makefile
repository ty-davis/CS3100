# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Targets
all: hw3 minmax readfile gendata

# Compile hw3
hw3: hw3.c
	$(CC) $(CFLAGS) -o hw3 hw3.c

# Compile minmax
minmax: minmax.c
	$(CC) $(CFLAGS) -o minmax minmax.c

readfile: read.c
	$(CC) $(CFLAGS) -o readfile read.c

gendata: write.c
	$(CC) $(CFLAGS) -o gendata write.c

# Clean up build files
clean:
	rm -f hw3 minmax gendata readfile input*.txt *.o
