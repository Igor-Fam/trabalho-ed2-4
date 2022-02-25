#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED

class HuffmanNode
{
  	public:
		friend class HuffmanTree;
		HuffmanNode();

		HuffmanNode(char c, int f);

		HuffmanNode(HuffmanNode* a, HuffmanNode* b);

		~HuffmanNode();

		HuffmanNode* getLeft();

		char getChar();

		int getFreq();

		HuffmanNode* getRight();

	private:

		HuffmanNode* left;

		char character;

		int freq;

		HuffmanNode* right;
};

#endif
