CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Board.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=runfile

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
