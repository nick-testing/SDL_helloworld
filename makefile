CC= g++
CPPFLAGS= -pedantic
SDLFLAGS= -lSDL2
SRC= ./src/
OBJ= $(SRC)main.o $(SRC)HelloWorld.o

all: helloworld.out

helloworld.out: $(OBJ)
	$(CC) $(OBJ) -o helloworld.out $(SDLFLAGS)

 %.o: $(SRC)%.cpp
	$(CC) $<  $(CPPFLAGS) -o $(OBJ)

clean:
	rm -f *.out $(SRC)*.o