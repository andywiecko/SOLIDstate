
CC=g++
CFLAGS= -O3 -std=c++17
LIBS= -larmadillo

src=$(wildcard Modules/*/*/*/*.cpp\
	  wildcard Modules/*/*/*.cpp\
	  wildcard Modules/*/*.cpp\
      wildcard Modules/*.cpp\
	  )
obj=$(src:.cpp=.o)

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< -std=c++17 -fPIC

# template initialization files pattern
%-imp.o: %-imp.cpp %.hpp %.cpp
	$(CC) -o $@ -c $< -std=c++17 -fPIC

main.exe: main.cpp $(obj)
	$(CC) -o main.exe $^ $(LIBS) $(CFLAGS)

solid: $(obj)
	ar rcs SOLIDstate.a $(obj)

solid.exe: main.cpp SOLIDstate.a 
	$(CC) -o solid.exe main.cpp SOLIDstate.a $(LIBS) $(CFLAGS)

####### Shared... #######
# export LD_LIBRARY_PATH=.
shared: $(obj)
	$(CC) -shared  -Wl,-soname,libsolid.so -o libsolid.so $(obj)

main-with-shared: libsolid.so
	$(CC) main.cpp -o main.exe -L. -lsolid $(LIBS) $(CFLAGS)

#########################

doxy:
	doxygen Doxyfile
	firefox Doxy/html/index.html &

	# TODO make solution to this
	@echo "########################################"
	@echo "[!] REMEMBER modify INPUT in Doxyfile"
	@echo "########################################"

install:
	@echo "Copying into /usr/include


.PHONY : clean
clean:
	@echo "cleaning..."
	rm -f $(obj) main.exe


help:
	@echo "These make targets are avaliable:"
	@echo "― all (default)"
	@echo "― doxy (it creates doxygen documentation)"