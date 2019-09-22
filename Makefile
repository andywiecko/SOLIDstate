
CC=g++
CFLAGS= -O3 -std=c++11
LIBS= -larmadillo

OBJ=Ensemble.o Canonical.o GrandCanonical.o\
    ParityGrandCanonical.o Hamiltonian.o Info.o\
	Factory.o SOLIDstate.o main.o

test.exe: $(OBJ)
	$(CC) $(OBJ) -o test.exe $(LIBS) $(CFLAGS)

main.o: main.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Ensemble.o: Modules/Ensemble/Ensemble.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Canonical.o: Modules/Ensemble/Canonical.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

GrandCanonical.o: Modules/Ensemble/GrandCanonical.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

ParityGrandCanonical.o: Modules/Ensemble/ParityGrandCanonical.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Hamiltonian.o: Modules/Hamiltonian/Hamiltonian.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Info.o: Modules/Info/Info.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Factory.o: Modules/Factory/Factory.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

SOLIDstate.o: Modules/SOLIDstate.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

.PHONY : clean
clean:
	rm *.o
	rm test.exe