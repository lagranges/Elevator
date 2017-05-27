CC=g++

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

EXEC=elevator

all: $(EXEC)
	
$(EXEC):$(OBJ)
	$(CC) -o $@ $(OBJ)

.cpp.o:
	$(CC) -c -Wall $< -o $@

clear:
	$(RM) *.o $(EXEC) 
