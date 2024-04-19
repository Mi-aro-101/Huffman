#include "Huffman.h"

std::vector<Node*> Huffman::evaluateFreq(std::string word, Helper helper) {
	std::vector<Node*> result;
	for (int i = 0; i < word.length(); i++) {
		std::string character = word.substr(i, 1);
		if (!helper.isInNode(character, result)) {
			Node* newNode = new Node(character, 1);
			result.push_back(newNode);
		}
		else if (helper.isInNode(character, result)) {
			Node* node = helper.getNodeByChar(character, result);
			float prob = node->getProbability();
			node->setProbability(prob + 1);
		}
	}
	return result;
}

Node* Huffman::makeTree(std::vector<Node*> nodes, Helper helper) {
	std::vector<Node*> array_copy = nodes;
	while (array_copy.size() > 1) {
		Node* left = helper.popmin(array_copy);
		Node* right = helper.popmin(array_copy);
		Node* newNode = new Node(left->getValue() + right->getValue(), left->getProbability() + right->getProbability());
		newNode->setLeftNode(left);
		newNode->setRightNode(right);
		array_copy.push_back(newNode);
	}
	return array_copy.at(0);
}

void Huffman::encode(Node* root, std::string code) {
	if (root != nullptr) {
		root->setCode(code);
		this->encode(root->getLeftNode(), code + "0");
		this->encode(root->getRightNode(), code + "1");
	}
}

HuffmanResult* Huffman::huffmanEncode(std::string sentence) {
	HuffmanResult* result = new HuffmanResult();
	Helper helper;
	std::vector<Node*> nodes = this->evaluateFreq(sentence, helper);
	Node* root = this->makeTree(nodes, helper);
	this->encode(root, "");

	result->setNodes(nodes);
	result->setRoot(root);

	return result;
}

std::string Huffman::textToHuffmanCode(std::string text)
{
	std::string result = "";
	Helper helper;
	HuffmanResult* huffResult = this->huffmanEncode(text);
	std::vector<Node*> nodes = huffResult->getNodes();
	for (int i = 0; i < text.length(); i++) {
		std::string character = text.substr(i, 1);
		std::string code = helper.getNodeByChar(character, nodes)->getCode();
		result += code;
	}

	return result;
}

std::string Huffman::decode(Node* root, std::string binString)
{
	Node* trueRoot = root;
	std::string result;
	for (int i = 0; i < binString.length(); i++) {
		if (binString[i] == '0') root = root->getLeftNode();
		else if (binString[i] == '1') root = root->getRightNode();
		if (root->getLeftNode() == nullptr && root->getRightNode() == nullptr) {
			result += root->getValue();
			root = trueRoot;
		}
	}

	return result;
}
