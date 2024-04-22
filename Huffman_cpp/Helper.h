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

	Node* popmin(std::vector<Node*>& nodes);

	bool isInNode(std::string character, std::vector<Node*> nodes);

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
		void writeToFile(std::ofstream& file, std::string binSeq);
		std::string readBinFile(std::string fileName);
		std::string formatToCodedSeq(std::string fullFileContent);
		std::string decompress(std::string fileName);

		bool getIsAbondant();
		void setIsAbondant(bool isAbondant);
};
