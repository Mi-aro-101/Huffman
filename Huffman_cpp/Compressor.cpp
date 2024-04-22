#include "Helper.h"

int Compressor::getProperByteSize(std::string binString)
{
	int result = 0;/*
	int byteSize = 8;
	for (int i = 8; i < binString.length(); i+=byteSize) {
		result = i;
	}
	result += 8;
	return result / 8;*/
	return (binString.length() / 8) + 1;
}

void Compressor::compress(std::string fileName, int byteSize, std::string binString)
{
	this->setIsAbondant(false);
	Helper helper;
	std::string groupn = "";
	int i = 0;
	// Define your file
	std::ofstream bin_file(fileName);
	if (!bin_file) {
		std::cout << "Cannot open the file boys" << std::endl;
		return;
	}

	/*const char* file = fileName.c_str();
	FILE* bin_file;
	errno_t error = fopen_s(&bin_file, file, "a");*/

	for (i = 0; i < byteSize-1; i++) {
		groupn = binString.substr(i*8, 8);
		this->writeToFile(bin_file, groupn);
	}
	groupn = binString.substr(i * 8, 8);
	// If the length of the last bit is less than 8 then add additional byte to store the index of the end of temporary 0
	if (groupn.length() < 8) {
		this->setIsAbondant(true);
		std::string groupnLast = helper.fillWithZero(std::string(groupn.c_str()));
		this->writeToFile(bin_file, groupnLast);
		uint8_t reste = 8 - groupn.length();
		std::bitset<8> bitReste(static_cast<uint8_t>(reste));
		this->writeToFile(bin_file, bitReste.to_string());
	}
	else this->writeToFile(bin_file, groupn);


	//fclose(bin_file);
	bin_file.close();
}

void Compressor::writeToFile(std::ofstream& file, std::string binSeq) {
	std::bitset<8> bits(binSeq);
	uint_least8_t word = static_cast<uint_least8_t>(bits.to_ulong());
	/*int result = fputc(word, file);
	if (result == EOF) {
		std::cerr << "Error writing to file!" << std::endl;
	}*/
	file << static_cast<int>(word) << std::endl;
}

std::string Compressor::readBinFile(std::string fileName)
{
	std::string result;
	std::string line;
	std::ifstream bin_file(fileName);
	int i = 0;
	if (!bin_file) {
		return "Cannot open the file boys";
	}
	while (std::getline(bin_file, line)) {
		int byteValue = std::stoi(line);
		std::bitset<8> myBits(static_cast<uint_least8_t>(byteValue));
		std::string bitString = myBits.to_string();
		result += bitString;
	}
	return result;
}

std::string Compressor::formatToCodedSeq(std::string fullFileContent)
{
	std::string result;
	result = fullFileContent;
	if (this->getIsAbondant()) {
		std::string resteBin = fullFileContent.substr(fullFileContent.length() - 8, 8);
		std::bitset<8> myBits(resteBin);
		int_least8_t reste = static_cast<int_least8_t>(myBits.to_ulong());
		result = fullFileContent.substr(0, fullFileContent.length() - 8);
		result = result.substr(0, result.length()-reste);
	}
	return result;
}

std::string Compressor::decompress(std::string fileName)
{
	Helper helper;
	std::string result;

	std::string fullFileContent = this->readBinFile(fileName);
	result = this->formatToCodedSeq(fullFileContent);

	return result;
}

bool Compressor::getIsAbondant() {
	return this->isAbondant;
}

void Compressor::setIsAbondant(bool isAbondant) {
	this->isAbondant = isAbondant;
}
