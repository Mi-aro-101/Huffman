#pragma once

#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <iostream>

class Node
{
	private:
		std::string value;
		float probability;
		Node* rightNode;
		Node* leftNode;
		std::string code;
	public:
		Node(std::string value, float probability);
		std::string getValue();
		float getProbability();
		Node* getRightNode();
		Node* getLeftNode();
		std::string getCode();
		void setValue(std::string value);
		void setProbability(float probability);
		void setRightNode(Node* rightNode);
		void setLeftNode(Node* leftNode);
		void setCode(std::string code);
};

class Helper
{
public:
	/// <summary>
	/// Get the minimal (obj.value) element of the vector, erase it from it and then return it
	/// </summary>
	/// <param name="nodes">Adress reference given because we are going to modify it here</param>
	/// <returns>Node* (minimal value)</returns>
	Node* popmin(std::vector<Node*>& nodes);

	/// <summary>
	/// Check if the character given is a Node present in the vector
	/// </summary>
	/// <param name="character"></param>
	/// <param name="nodes"></param>
	/// <returns>"true" if present else "false"</returns>
	bool isInNode(std::string character, std::vector<Node*> nodes);

	/// <summary>
	/// Give a character in parameter, check if a node having this char is present in the vector of nodes
	/// </summary>
	/// <param name=""></param>
	/// <param name="nodes"></param>
	/// <returns>Node* having as value the chat</returns>
	Node* getNodeByChar(std::string character, std::vector<Node*> nodes);

	std::string fillWithZero(std::string group);

	std::string readEnglishFile(std::string fileName);

};

class Compressor
{
	private:
		bool isAbondant;

	public:
		int getProperByteSize(std::string binString);
		void compress(std::string fileName, int byteSize, std::string binString);
		void writeToFile(std::ofstream& fileName, std::string binSeq);
		std::string readFile(std::string fileName);
		std::string formatToCodedSeq(std::string fullFileContent);
		std::string decompress(std::string fileName);

		bool getIsAbondant();
		void setIsAbondant(bool isAbondant);
};
