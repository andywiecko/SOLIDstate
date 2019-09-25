
CC=g++
CFLAGS= -O3 -std=c++11
LIBS= -larmadillo

OBJ=Ensemble.o Canonical.o GrandCanonical.o\
    ParityGrandCanonical.o Hamiltonian.o KitaevHamiltonian.o\
	Info.o Factory.o SOLIDstate.o Combinadics.o\
	main.o

test.exe: $(OBJ)
	$(CC) $(OBJ) -o test.exe $(LIBS) $(CFLAGS)

main.o: main.cpp
	$(CC) -c $< $(LIBS) $(CFLAGS)

Ensemble.o: Modules/Ensemble/Ensemble.cpp Modules/Ensemble/Ensemble.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

Canonical.o: Modules/Ensemble/Canonical.cpp Modules/Ensemble/Canonical.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

GrandCanonical.o: Modules/Ensemble/GrandCanonical.cpp Modules/Ensemble/GrandCanonical.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

ParityGrandCanonical.o: Modules/Ensemble/ParityGrandCanonical.cpp Modules/Ensemble/ParityGrandCanonical.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

Hamiltonian.o: Modules/Hamiltonian/Hamiltonian.cpp Modules/Hamiltonian/Hamiltonian.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

KitaevHamiltonian.o: Modules/Hamiltonian/KitaevHamiltonian.cpp Modules/Hamiltonian/KitaevHamiltonian.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

Info.o: Modules/Info/Info.cpp Modules/Info/Info.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

Factory.o: Modules/Factory/Factory.cpp Modules/Factory/Factory.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

Combinadics.o: Modules/Combinadics/Combinadics.cpp Modules/Combinadics/Combinadics.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

SOLIDstate.o: Modules/SOLIDstate.cpp Modules/SOLIDstate.h
	$(CC) -c $< $(LIBS) $(CFLAGS)

.PHONY : clean
clean:
	rm *.o
	rm test.exe