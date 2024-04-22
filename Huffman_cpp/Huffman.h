#pragma once

#include "Helper.h"

class HuffmanResult
{
	private:
		std::vector<Node*> nodes;
		Node* root;
	public:
		std::vector<Node*> getNodes();
		void setNodes(std::vector<Node*> nodes);
		Node* getRoot();
		void setRoot(Node* root);
};

class Huffman
{
	public:
		/**
		* Evaluate each char and calculate their freq (resp prob)
		* @param word your text
		* @param helper
		* @return vector<Node*> that contains all the char and their freq
		*/
		std::vector<Node*> evaluateFreq(std::string word, Helper helper);

		/**
		* Make the Huffman after the freq of each char of the text is evaluated
		* @param node[&] 
		* @param helper
		* @return root node
		*/
		Node* makeTree(std::vector<Node*> nodes, Helper helper);

		/**
		* Assign code to each character based from the root node
		* @param &root
		* @param code [Recursive code require this param as the code]
		* @return
		*/
		void encode(Node*root, std::string code);

		/**
		* Rally evalueateFreq, makeTree and encode function -> assign code to each character
		* @param sentence the text to encode
		* @return HuffmanResult -> root and nodes[]
		*/
		HuffmanResult* huffmanEncode(std::string sentence);

		/**
		* Take your text and encode the totality of it as a code (call huffmanEncode method)
		* @param text
		* @return string your coded text
		*/
		std::string textToHuffmanCode(std::string text);

		/**
		* Decode the coded text and remake it as the original text
		* @param &root node
		* @param binString text to decode
		* @return string the original/decoded text
		*/
		std::string decode(Node* root, std::string binString);
};


