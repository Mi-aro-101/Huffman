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

	/**
	* Get the node with the minimum freq, drop it from the vector then return it especially
	* @param nodes[]
	* @return Node* with minimal freq
	*/
	Node* popmin(std::vector<Node*>& nodes);

	/**
	* Check if a char sequence is in the nodes[]
	* @param character
	* @param nodes array of nodes[]
	* @return bool true if it is in or else false
	*/
	bool isInNode(std::string character, std::vector<Node*> nodes);

	/**
	* Give a char sequence and return the node that corresponds it
	* @param character
	* @param nodes[]
	* @return Node* corresponding
	*/
	Node* getNodeByChar(std::string character, std::vector<Node*> nodes);

	/**
	* If the char seq length is less than 8, force it to have 8 length by filling it with '0'
	* @param group the char seq
	* @return the filled char seq (with '0')
	*/
	std::string fillWithZero(std::string group);

	/**
	* Read the txt file that contains the english text
	* @param fileName
	* @return string contained in the file
	*/
	std::string readEnglishFile(std::string fileName);

};

class Compressor
{
	private:
		bool isAbondant;

	public:
		/**
		* Get Byte size require for compressing the coded text
		* @param binString the codedSeq
		* @return int the byte numbre required
		*/
		int getProperByteSize(std::string binString);

		/**
		* Compress the coded text in a file (store the int values)
		* @param fileName
		* @param byteSize required for comopressing
		* @param binString coded text
		* @return
		*/
		void compress(std::string fileName, int byteSize, std::string binString);

		/**
		* Get binString group (of 8) transform it to an int and write the int in the file
		* @param file to write in
		* @param binSeq
		* @return
		*/
		void writeToFile(std::ofstream& file, std::string binSeq);

		/**
		* Read the file that contains the compressed text (a lot of int)
		* @param fileName
		* @return string the coded txt (biin seq) representation (not the 'a lot of int')
		*/
		std::string readBinFile(std::string fileName);

		/**
		* Format the binSeq from the compressed datas file
		* As the last byte should or not be the index value where we should not take the 0 seq remaining
		* @param fullFileContent
		* @return string the proper coded text (Without the remaining 0 and the last byte  [if it does represent the index])
		*/
		std::string formatToCodedSeq(std::string fullFileContent);

		/**
		* Use the function 'readBinFile' and 'formatToCodedSeq' to decompress the compressed content of the file
		* @param fileName
		* @return string representing the bin sequence true encoded
		*/
		std::string decompress(std::string fileName);

		bool getIsAbondant();
		void setIsAbondant(bool isAbondant);
};
