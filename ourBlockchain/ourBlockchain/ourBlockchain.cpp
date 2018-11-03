//ourBlockchain.cpp
//#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <string>
using namespace std;

//Some Data
struct SomeData {
	double amount;
	string data;
};

//Block class
class Block {
	private:
		int index;
		size_t blockHash;
		size_t lastHash;
		size_t generateHash();

	public:
		//Constructor
		Block(int idx, SomeData d, size_t lHash);

		size_t getHash();
		size_t LastHash();
		SomeData data;
		bool isHashValid();
};

Block::Block(int idx, SomeData d, size_t lHash) {
	index = idx;
	data = d;
	lastHash = lHash;
	blockHash = generateHash();
}
size_t Block::generateHash() {
	hash<string> hash1;
	hash<size_t> hash2;
	hash<double> hash3;
	hash<size_t> finalHash;
	return finalHash(hash1(data.data) + hash2(lastHash) + hash3(data.amount));
};
//public functions
size_t Block::getHash() {
	return blockHash;
}
size_t Block::LastHash() {
	return lastHash;
}
bool Block::isHashValid() {
	return generateHash() == blockHash;
}

//Blockchain
class Blockchain {
	private:
		Block createGenesisBlock();
	
	public:
		vector<Block> chain;

		//Conctructor
		Blockchain();

		void addBlock(SomeData data);
		bool isChainVaild();
};
//Blockchain Class Members
Blockchain::Blockchain() {
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);
}
Block Blockchain::createGenesisBlock() {
	SomeData d;
	d.amount = 0;	
	hash<int> hash1;
	Block gen(0, d, hash1(0));
	return gen;
}
void Blockchain::addBlock(SomeData data) {
	int index = (int)chain.size() - 1;
	vector<Block>::iterator it;
	it = chain.end();
	Block prevBlock = *(it - 1);
	Block newBlock(index, data, prevBlock.getHash() /*BYAAAAAAAT*/);
}
bool Blockchain::isChainVaild() {
	vector<Block>::iterator it;
	int chainLen = (int)chain.size();
	
	for(it = chain.begin(); it != chain.end(); it++) {
		Block curBlock = *it;
		if(!curBlock.isHashValid()) {
			return false;
		}
		if(chainLen > 1) {
			Block prevBlock = *(it - 1);
			if(curBlock.LastHash() != prevBlock.getHash()) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	//starting Blockchain
	Blockchain velcoin;
	//data
	SomeData data1;
	data1.amount = 1;
	data1.data = "Putin wwedi vojska";
	velcoin.addBlock(data1);
	cout << velcoin.isChainVaild();
	SomeData data2;
	data2.amount = 2;
	data2.data = "Putin dai deneh";
	velcoin.addBlock(data2);
	cout << velcoin.isChainVaild();
	return 0;
}
