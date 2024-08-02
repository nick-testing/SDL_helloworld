CC = g++
CPPFLAGS = -c -pedantic
SDLFLAGS = -lSDL2
SRC = ./src/
OBJ = $(SRC)createwindow.o

all: helloworld.out

helloworld.out: $(OBJ)
	$(CC) $(OBJ) -o createwindow.out $(SDLFLAGS)

 %.o: $(SRC)%.cpp
	$(CC) $<  $(CPPFLAGS) -o $(OBJ) $(SDLFLAGS)

clean:
	rm -f *.out $(SRC)*.o