OBJS	= ShellSort.o main.o fileManager.o HuffmanNode.o HuffmanTree.o
SOURCE	= ShellSort.cpp main.cpp fileManager.cpp HuffmanNode.cpp HuffmanTree.cpp
HEADER	= main.h HuffmanNode.h HuffmanTree.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

ShellSort.o: ShellSort.cpp
	$(CC) $(FLAGS) ShellSort.cpp -std=c++14
	
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

fileManager.o: fileManager.cpp
	$(CC) $(FLAGS) fileManager.cpp -std=c++14

HuffmanNode.o: HuffmanNode.cpp
	$(CC) $(FLAGS) HuffmanNode.cpp -std=c++14

HuffmanTree.o: HuffmanTree.cpp
	$(CC) $(FLAGS) HuffmanTree.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)