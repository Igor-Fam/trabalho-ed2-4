#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED

class HuffmanNode
{
  	public:
		friend class HuffmanTree;
		HuffmanNode(){}

		HuffmanNode(char c, int f){
			character = c;
			freq = f;
			left = NULL;
			right = NULL;
		}

		HuffmanNode(HuffmanNode* a, HuffmanNode* b){
			freq = a->freq + b->freq;
			character = '\0';
			if(a->freq <= b->freq){
				left = a;
				right = b;
			} else {
				left = b;
				right = a;
			}
		}

		~HuffmanNode(){}

		HuffmanNode* getLeft(){ return left; }

		char getChar(){ return character; }

		int getFreq(){ return freq; }

		HuffmanNode* getRight(){ return right; }

	private:

		HuffmanNode* left;

		char character;

		int freq;

		HuffmanNode* right;
};

#endif
