# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
RUNOPTION = main
CFLAGS = -g -Wall

SRCS = insertionsort.cpp
OBJ = $(patsubst %.cpp,%.o,$(SRCS))

all: $(RUNOPTION)
$(RUNOPTION): $(OBJ) 
	$(CC) -o $@ $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

run:
	./$(RUNOPTION)

clean:
	rm *.o $(RUNOPTION)