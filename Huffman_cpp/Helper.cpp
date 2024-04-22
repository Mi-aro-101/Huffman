#include "Helper.h"

Node* Helper::popmin(std::vector<Node*>& nodes) {
	int minIndex = 0;
	Node* minNode = nodes[0];
	for (int i = 1; i < nodes.size(); i++) {
		if (minNode->getProbability() > nodes[i]->getProbability()) {
			minNode = nodes[i];
			minIndex = i;
		}
	}
	nodes.erase( nodes.begin()+minIndex );
	return minNode;
}

bool Helper::isInNode(std::string character, std::vector<Node*> nodes) {
	bool result = false;
	for (Node* node : nodes) {
		if (node->getValue() == character){
			result = true;
			break;
		}
	}
	return result;
}

Node* Helper::getNodeByChar(std::string character, std::vector<Node*> nodes) {
	Node* result = new Node("0", 0);
	for (Node* node : nodes) {
		if (node->getValue() == character) {
			result = node;
			break;
		}
	}
	return result;
}

std::string Helper::fillWithZero(std::string group)
{
	size_t reste = 8 - group.length();
	for (int i = 0; i < reste; i++) {
		group += "0";
	}
	return group;
}

// *** The string temp gets destroyed and we cannot get the proper value of the return ***
std::string Helper::readEnglishFile(std::string fileName)
{
	std::string temp;
	const char error[] = "Unable to open file";
	std::ifstream inputFile(fileName);
	std::string line;
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			temp += line;
		}
		inputFile.close();
	}
	else {
		return error;
	}
	return temp;
}
