CC = g++ -std=c++2a
COMPILER_FLAGS = -Wall
OBJ_NAME = bit.cpp
OBJ = bit

all:$(OBJ_NAME)
	$(CC) $(COMPILER_FLAGS) $(OBJ_NAME) -o $(OBJ)

.phony: clean
clean:
	rm -f $(OBJ) *.o
