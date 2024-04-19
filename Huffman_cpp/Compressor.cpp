#include "Helper.h"

int Compressor::getProperByteSize(std::string binString)
{
	int result = 0;
	int byteSize = 8;
	for (int i = 8; i < binString.length(); i+=byteSize) {
		result = i;
	}
	result += 8;
	// Again because the last seq 8 bit is used to store the index where I shall delete the 0
	result += 8;
	return result / 8;
}

void Compressor::compress(std::string fileName, int byteSize, std::string binString)
{
	this->setIsAbondant(false);
	Helper helper;
	std::string groupn = "";
	int i = 0;
	// Define your file
	std::ofstream bin_file(fileName, std::ios::binary);
	if (!bin_file) {
		std::cout << "Cannot open the file boys" << std::endl;
		return;
	}

	for (i = 0; i < byteSize-1; i++) {
		groupn = binString.substr(i*8, 8);
		this->writeToFile(bin_file, groupn);
	}
	groupn = binString.substr(i * 8, 8);
	groupn = helper.fillWithZero(std::string(groupn.c_str()));
	this->writeToFile(bin_file, groupn);
	// If the length of the last bit is less than 8 then add additional byte to store the index of the end of temporary 0
	if (groupn.length() < 8) {
		this->setIsAbondant(true);
		int_least8_t reste = 8 - groupn.length();
		std::bitset<8> resteBit(reste);
		this->writeToFile(bin_file, resteBit.to_string());
	}

	bin_file.close();
}

void Compressor::writeToFile(std::ofstream& file, std::string binSeq) {
	std::bitset<8> bits(std::string(binSeq.c_str()));
	unsigned char word = static_cast<unsigned char>(bits.to_ulong());
	file << word << std::endl;
}

std::string Compressor::readFile(std::string fileName)
{
	std::string result;
	std::string line;
	std::ifstream bin_file(fileName);
	if (!bin_file) {
		return "Cannot open the file boys";
	}
	while (std::getline(bin_file, line)) {
		char byteValue = line[0];
		std::bitset<8> myBits(static_cast<unsigned char>(byteValue));
		std::string bitString = myBits.to_string();
		result += bitString;
	}
	return result;
}

std::string Compressor::formatToCodedSeq(std::string fullFileContent)
{
	std::string result;

	std::string resteBin = fullFileContent.substr(fullFileContent.length() - 8, 8);
	std::bitset<8> myBits(resteBin);
	int_least8_t reste = static_cast<int_least8_t>(myBits.to_ulong());
	result = fullFileContent.substr(0, fullFileContent.length() - 8);
	result = result.substr(0, result.length()-reste);
	return result;
}

std::string Compressor::decompress(std::string fileName)
{
	std::string result;

	std::string fullFileContent = this->readFile(fileName);
	if (this->getIsAbondant()) {
		fullFileContent = this->formatToCodedSeq(fullFileContent);
	}

	return result;
}

bool Compressor::getIsAbondant() {
	return this->isAbondant;
}

void Compressor::setIsAbondant(bool isAbondant) {
	this->isAbondant = isAbondant;
}
