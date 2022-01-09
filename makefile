OBJS	= build/catcounter.o build/wordcounter.o
SOURCE	= src/catcounter.cpp src/wordcounter.cpp
HEADER	= src/wordcounter.h
OUT	= catcounter
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

build/catcounter.o: src/catcounter.cpp
	$(CC) $(FLAGS) src/catcounter.cpp -o build/catcounter.o 

build/wordcounter.o: src/wordcounter.cpp
	$(CC) $(FLAGS) src/wordcounter.cpp -o build/wordcounter.o 

clean:
	rm -f $(OBJS) $(OUT)