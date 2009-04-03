CC=gcc
CPP=g++
CFLAGS=
CXXFLAGS=
LD=gcc
LDFLAGS=-lSDL 

OBJECTS=sdl.o sdlheader.o
TARGET=snake

all: $(TARGET)

clean:   
	rm $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) 
	$(CPP) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

sdlheader.o: sdlheader.cpp
	$(CPP) $(CXXFLAGS) -c sdlheader.cpp

sdl.o: sdl.cpp
	$(CPP) $(CXXFLAGS) -c sdl.cpp 

