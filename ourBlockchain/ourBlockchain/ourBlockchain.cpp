//ourBlockchain.cpp

#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>


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
		int blockHash;
		int lastHash;
		int generateHash();

	public:
		//Constructor
		Block(int idx, SomeData d, int lHash);

		int getHash();
		int LastHash();
		SomeData Data;
		bool isHashValid();
};

//Blockchain
class Blockchain {
	private:
		Block createGenesisBlock();
	
	public:
		vector<Block> chain;

		//Conctructor
		Blockchain();

		void addBlock(SomeData data);
		void isChainVaild();




};
	
int main() {
	return 0;
}



