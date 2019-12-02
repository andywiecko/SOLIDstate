##
# @file Makefile
# @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
# @brief Makefile for SOLIDstate C++ library
# @version 0.100.0
# @date 2019-10-23
# 
# @copyright Copyright (c) 2019
## 

########## config ##########
CC=g++
CFLAGS= -O3 -std=c++17
LIBS= -larmadillo
VERSION_FULL=1.0
VERSION=1
SONAME=solid

##########  dirs  ##########
INCLUDE_PATH=/usr/include
LINKS_PATH=/usr/lib

src=$(wildcard Modules/*/*/*/*.cpp\
	  wildcard Modules/*/*/*.cpp\
	  wildcard Modules/*/*.cpp\
      wildcard Modules/*.cpp\
	  )

obj=$(src:.cpp=.o)

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< -std=c++17 -fPIC

%-imp.o: %-imp.cpp %.hpp %.cpp
	$(CC) -o $@ -c $< -std=c++17 -fPIC

all: $(obj)
	$(CC) -shared  -Wl,-soname,lib$(SONAME).so.$(VERSION) -o lib$(SONAME).so.$(VERSION_FULL) $(obj)

main.exe: main.cpp $(obj)
	$(CC) -o main.exe $^ $(LIBS) $(CFLAGS)

main-with-so: lib$(SONAME).so.$(VERSION_FULL)
	$(CC) main.cpp -o main.exe -l$(SONAME) $(LIBS) $(CFLAGS)

install:
	@echo "Copying Includes into ${INCLUDE_PATH}"
	cp Modules/SOLIDstate.hpp ${INCLUDE_PATH}/.
	cp Modules/SOLIDstate ${INCLUDE_PATH}/.
	rsync -rav --exclude="*.cpp" --exclude="*.o"  Modules/SOLIDstate_bits ${INCLUDE_PATH}/.
	
	@echo "Setting Links in $(LINKS_PATH)"
	cp lib$(SONAME).so.$(VERSION_FULL) $(LINKS_PATH)
	ln -sf $(LINKS_PATH)/lib$(SONAME).so.$(VERSION_FULL) $(LINKS_PATH)/lib$(SONAME).so.$(VERSION)
	ln -sf $(LINKS_PATH)/lib$(SONAME).so.$(VERSION_FULL) $(LINKS_PATH)/lib$(SONAME).so

doxy:
	doxygen Doxyfile
	firefox Doxy/html/index.html &

	# TODO make solution to this
	@echo "########################################"
	@echo "[!] REMEMBER modify INPUT in Doxyfile"
	@echo "########################################"

.PHONY : clean

clean:
	@echo "cleaning..."
	@rm -f $(obj) main.exe
	@echo "done!"

help:
	@echo "These make targets are avaliable:"
	@echo "― all (default, creates *.o, *.so files)"
	@echo "― doxy (it creates doxygen documentation)"
	@echo "― install (installing the lib)"
	@echo "― clean (cleaning *.o, *.so, *.a, *.exe files)"
	@echo
	@echo "To install SOLIDstate:"
	@echo " * first: 'make'"
	@echo " * second: 'sudo make install'"