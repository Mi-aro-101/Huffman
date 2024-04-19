#include "Huffman.h"

std::vector<Node*> HuffmanResult::getNodes() {
	return this->nodes;
}

void HuffmanResult::setNodes(std::vector<Node*> nodes) {
	this->nodes = nodes;
}

Node* HuffmanResult::getRoot() {
	return this->root;
}

void HuffmanResult::setRoot(Node* root) {
	this->root = root;
}