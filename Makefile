CC=g++
CFLAGS= -O3 -std=c++11
LIBS= -larmadillo

src=$(wildcard Modules/*/*.cpp\
      wildcard Modules/*.cpp\
	  main.cpp)
obj=$(src:.cpp=.o)

myprog.exe: $(obj)
	$(CC) -o $@ $^ $(LIBS) $(CFLAGS)


.PHONY : clean
clean:
	rm -f $(obj) 