#pragma once

#include <iostream>
#include <string.h>

class Node
{
	private:
		std::string value;
		float probability;
		Node* rightNode;
		Node* leftNode;
		std::string code;
	public:
		Node();
		Node(float value, float probability);
		std::string getValue();
		float getProbability();
		Node getRightNode();
		Node getLeftNode();
		std::string getCode();

		void setValue(std::string value);
		void setProbability(float probability);
		void setRightNode(Node* rightNode);
		void setLeftNode(Node* leftNode);
		void setCode(std::string code);
};

