OBJS	= ShellSort.o main.o fileManager.o HuffmanNode.o HuffmanTree.o HuffmanCompression.o BalancedStructures.o BNode.o BTree.o VPNode.o VPTree.o
SOURCE	= ShellSort.cpp main.cpp fileManager.cpp HuffmanNode.cpp HuffmanTree.cpp HuffmanCompression.cpp BalancedStructures.cpp BNode.cpp BTree.cpp VPNode.cpp VPTree.cpp
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

HuffmanCompression.o: HuffmanCompression.cpp
	$(CC) $(FLAGS) HuffmanCompression.cpp -std=c++14

BalancedStructures.o: BalancedStructures.cpp
	$(CC) $(FLAGS) BalancedStructures.cpp -std=c++14

BNode.o: BNode.cpp
	$(CC) $(FLAGS) BNode.cpp -std=c++14

BTree.o: BTree.cpp
	$(CC) $(FLAGS) BTree.cpp -std=c++14

VPNode.o: VPNode.cpp
	$(CC) $(FLAGS) VPNode.cpp -std=c++14

VPTree.o: VPTree.cpp
	$(CC) $(FLAGS) VPTree.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)