
CC=g++
CFLAGS= -O3 -std=c++11
LIBS = -larmadillo

all: Ensemble.o Canonical.o GrandCanonical.o ParityGrandCanonical.o Hamiltonian.o Info.o Factory.o SOLIDstate.o
	$(CC) main.cpp SOLIDstate.o -o test.exe $(LIBS) $(CFLAGS)

# ENSEMBLE
Ensemble.o:
	$(CC) -c Modules/Ensemble/Ensemble.cpp $(LIBS) $(CFLAGS)

Canonical.o:
	$(CC) -c Modules/Ensemble/Canonical.cpp $(LIBS) $(CFLAGS)

GrandCanonical.o:
	$(CC) -c Modules/Ensemble/GrandCanonical.cpp $(LIBS) $(CFLAGS)

ParityGrandCanonical.o:
	$(CC) -c Modules/Ensemble/ParityGrandCanonical.cpp $(LIBS) $(CFLAGS)

# HAMILTONIAN
Hamiltonian.o:
	$(CC) -c Modules/Hamiltonian/Hamiltonian.cpp $(LIBS) $(CFLAGS)

# INFO
Info.o:
	$(CC) -c Modules/Info/Info.cpp $(LIBS) $(CFLAGS)

# FACTORY
Factory.o:
	$(CC) -c Modules/Factory/Factory.cpp $(LIBS) $(CFLAGS)

# LIB
SOLIDstate.o: 
	$(CC) -c Modules/SOLIDstate.cpp $(LIBS) $(CFLAGS)

clean:
	rm *.o
	rm test.exe
