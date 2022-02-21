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

		void auxMap(HuffmanNode* current, string code){
			if(current->left == NULL && current->right == NULL){
				charMap[current->character] = code;
			} else {
				auxMap(current->left, code + "0");
				auxMap(current->right, code + "1");
			}

		}

	public:
	    HuffmanTree(){
			root = NULL;
		}

		HuffmanTree(HuffmanTree* a, HuffmanTree* b)
		{
			root = new HuffmanNode(a->root, b->root);
		}

		HuffmanTree(char c, int f){
			root = new HuffmanNode(c, f);
		}

		~HuffmanTree(){}

		int getRootFreq(){
			if(root == NULL){
				cout << "Arvora vazia!" << endl;
				exit(1);
			}
			else {
				return root->getFreq();
			}
		}

		void map(){
			auxMap(root, "");
		}

		void printMap(){
			for(auto k : charMap){
				cout << k.first << " => " << k.second << endl;
			}
		}

		string encode(string text){
			string encodedText;
			for(char c : text){
				encodedText = encodedText + charMap[c];
			}
			return encodedText;
		}

		string decode(string enc_text){
			string decodedtext="";
			HuffmanNode* current = root;
			for(char c : enc_text){
				if(c == '0'){
					current=current->left;
					if(current->left == NULL && current->right == NULL){
						decodedtext = decodedtext + current->character;
						current=root;
					}
				}else{
					current=current->right;
					if(current->left == NULL && current->right == NULL){
						decodedtext = decodedtext + current->character;
						current=root;
					}
				}
			}
			return decodedtext;
		}
};

#endif
