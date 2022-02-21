OBJS	= main.o
SOURCE	= main.cpp
HEADER	= main.h HuffmanTree.h HuffmanNode.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)