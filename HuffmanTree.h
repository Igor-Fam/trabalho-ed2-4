#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include "HuffmanNode.h"

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class HuffmanTree
{
	private:
		HuffmanNode *root;

		unordered_map<char, string> charMap;

		void auxMap(HuffmanNode* current, string code);

	public:
	    HuffmanTree();

		HuffmanTree(HuffmanTree* a, HuffmanTree* b);

		HuffmanTree(char c, int f);

		~HuffmanTree();

		int getRootFreq();

		void map();

		void printMap();

		string encode(string text);

		string decode(string enc_text);
};

#endif
