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
		/// <summary>
		/// Having a word, evaluate the frequency (repetition) of each letter and put them as corresponding Node object
		/// </summary>
		/// <param name="word"></param>
		/// <param name="helper"></param>
		/// <returns>std::vector<Node*></returns>
		std::vector<Node*> evaluateFreq(std::string word, Helper helper);

		/// <summary>
		/// Make the Huffman tree based on a vector of nodes
		/// </summary>
		/// <param name="nodes"></param>
		/// <param name="helper"></param>
		/// <returns>Node* root of the tree</returns>
		Node* makeTree(std::vector<Node*> nodes, Helper helper);

		/// <summary>
		/// Encode as binary based on Huffman coding all the leaf value of the root tree
		/// </summary>
		/// <param name="root"></param>
		/// <param name="code"></param>
		void encode(Node*root, std::string code);

		/// <summary>
		/// Rally all the above function to just have one that encode, makeTree and evaluate the word
		/// </summary>
		/// <param name="sentence"></param>
		/// <returns></returns>
		HuffmanResult* huffmanEncode(std::string sentence);

		/// <summary>
		/// Transform a text to a binary string based of Huffman coding
		/// </summary>
		/// <param name="text"></param>
		/// <returns></returns>
		std::string textToHuffmanCode(std::string text);

		/// <summary>
		/// Decode the bin string based on the huffman tree and bring back its initial text
		/// </summary>
		/// <param name="root"></param>
		/// <param name="binString"></param>
		/// <returns></returns>
		std::string decode(Node* root, std::string binString);
};


