CC := gcc
#CFLAGS := 
DEST := ./build/

all: recursion_atoi.c
	mkdir -p build
	$(CC) recursion_atoi.c -lcs50 -o $(DEST)/recursion_atoi 