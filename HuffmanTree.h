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
		
		HuffmanNode* sae(HuffmanNode *p) { return p->getLeft(); };

		HuffmanNode* sad(HuffmanNode *p) { return p->getRight(); };

		void auxPrint(HuffmanNode *r){
			if(r!=NULL){
				cout << r->getFreq() << " ";
				auxPrint(sae(r));
				auxPrint(sad(r));
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

		bool vazia(){
			return root == NULL;
		}

		void print(){
			cout << "Pre-Ordem: ";
			auxPrint(root);
			cout << endl;
		}

		/* void merge(HuffmanTree *a, HuffmanTree *b){
			HuffmanNode *r = new HuffmanNode(a->root, b->root);
			root = r;
		} */

		void printLevel(int k){
			cout << "Nos do nivel " << k << ": ";
			auxPrintLevel(root, 0, k);
			cout << endl;
		}

		void auxPrintLevel(HuffmanNode *p, int atual, int k){
			if(p != NULL){
				if(atual == k)
					cout << p->getFreq() << " ";
				else {
					auxPrintLevel(p->getLeft(), atual+1, k);
					auxPrintLevel(p->getRight(), atual+1, k);
				}
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
