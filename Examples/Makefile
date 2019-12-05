CC=g++
CFLAGS= -O3 -std=c++17
LIBS= -lsolid -larmadillo

src=$(wildcard *.cpp)
exe=$(src:.cpp=.exe)

examples: $(src)
	$(CC) -o $(^:.cpp=.exe) $^ $(LIBS) $(CFLAGS) 

.PHONY : clean
clean:
	rm -f $(exe)