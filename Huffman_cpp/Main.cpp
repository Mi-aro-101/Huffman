#include <iostream>
#include "Huffman.h"

int main() {
	Helper helper;
	Huffman huffman;
	HuffmanResult* result;
	Compressor compressor;

	//const char* sentence = helper.readEnglishFile("English.txt").c_str();
	// Read the file text
	std::string sentence = helper.readEnglishFile("English.txt");
	// [ TEST ]
	printf("Your text : \n%s\n", sentence.c_str());

	//Encode each char of the file following Huffman
	result = huffman.huffmanEncode(sentence);
	// [ TEST ]
	//printf("%s\n", result->getNodes()[0]->getCode().c_str());

	// Encode the full text
	std::string encodedText = huffman.textToHuffmanCode(sentence);
	// [ TEST ]
	printf("Encoded from TEXT : %s\n as %i\n", encodedText.c_str(), encodedText.length());

	 //Compress the sentence in a file
	///*
	size_t byteRequiredSize = compressor.getProperByteSize(encodedText);
	compressor.compress("Compressed.txt", byteRequiredSize, encodedText);
	//*/

	// Decompress from file to original text

	///*
	std::string decompressed = compressor.decompress("Compressed.txt");
	// [ TEST ]
	printf("Encoded from FILEBIN : %s\n as %i\n", decompressed.c_str(), decompressed.length());
	//*/

	///*
	std::string decodedBinString = huffman.decode(result->getRoot(), decompressed);
	// [ TEST ]
	printf("Decompressed decoded datas : %s\n", decodedBinString.c_str());
	//*/

	return 0;
}