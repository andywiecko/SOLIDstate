
CC=g++
CFLAGS= -O3 -std=c++11
LIBS = -larmadillo

all: 
	$(CC) main.cpp -o test.exe $(LIBS) $(CFLAGS)
