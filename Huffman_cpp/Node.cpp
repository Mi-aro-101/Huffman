#include "Helper.h"

Node::Node(std::string value, float probability) {
	this->setValue(value);
	this->setProbability(probability);
	this->setLeftNode(nullptr);
	this->setRightNode(nullptr);
	this->setCode("");
}

std::string Node::getValue() {
	return this->value;
}

void Node::setValue(std::string value) {
	this->value = value;
}

float Node::getProbability(){
	return this->probability;
}

void Node::setProbability(float probability) {
	this->probability = probability;
}

std::string Node::getCode(){
	return this->code;
}

void Node::setCode(std::string code) {
	this->code = code;
}

Node* Node::getLeftNode() {
	return this->leftNode;
}

void Node::setLeftNode(Node *leftNode) {
	this->leftNode = leftNode;
}

Node* Node::getRightNode() {
	return this->rightNode;
}

void Node::setRightNode(Node* rightNode) {
	this->rightNode = rightNode;
}
