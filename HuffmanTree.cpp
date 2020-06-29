//Student Name: Mbaliyethemba Shangase
//Student Number: SHNMBA004
//Due Date: 02/04/2019
//Assignment 3

#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <iomanip>
#include <fstream>

namespace SHNMBA004{
	HuffmanTree::HuffmanTree(){
		std::shared_ptr<HuffmanNode> rt = nullptr;
	}
	
	HuffmanTree::~HuffmanTree(){
		rt = nullptr;
	}
	
	void HuffmanTree::CreateTree(std::unordered_map<char,int> & map){
		using namespace std;
		for(auto iterator : map){
			HuffmanNode node;
			shared_ptr<HuffmanNode> nodePtr = make_shared<HuffmanNode>(node);
			node.setChar(iterator.first);
			node.setFreq(iterator.second);
			priorityQ.push(node);
		}
		
		while(priorityQ.size() > 1){
			HuffmanNode A = priorityQ.top();
			priorityQ.pop();
			HuffmanNode B = priorityQ.top();
			priorityQ.pop();
			HuffmanNode tot;
			tot.setChar(0);
			tot.setFreq(A.getFreq() + B.getFreq());
			tot.setLeftChild(A);
			tot.setRightChild(B);
			priorityQ.push(tot);
		}
		
		rt = make_shared<HuffmanNode>(priorityQ.top());
		traverse(rt.get(),"");
	}
	
	void HuffmanTree::traverse(HuffmanNode * current,std::string bitString){
		using namespace std;
		if(current){
			traverse(current->getLeftChild(),bitString+"0");
			if(current->getChar() !=0){
				cout<< current -> getChar() << " the bitstream is " << bitString << endl;
				codeTable[current->getChar()] = bitString;
			}
			traverse(current->getRightChild(),bitString+"1");
		}
	}
	
	void HuffmanTree::compression(std::string inputFile,std::string outputFile){
		using namespace std;
		int numChars;
		int numOneZero;
		ofstream output;
		output.open(outputFile + ".txt");
		ifstream input(inputFile);
		char c;
		
		while(input.get(c)){
			numChars++;
			string bit = codeTable[c].c_str();
			output << bit;
			numOneZero += bit.length();
			cout << bit << ": " << bit.length() << endl;
		}
		input.close();
		output.open(outputFile + ".hdr");
		output << "Size: " << codeTable.size() << endl;
		for(auto iterator : codeTable){
			output << iterator.first << ": " << iterator.second << endl;
		}
		output.close();
		double compression = numOneZero/(numChars*8);
		cout << "Compression ratio: " << compression << endl;
	}
	
	void HuffmanTree::Display(HuffmanNode * current,int indent){
		using namespace std;
		if(current != nullptr){
			Display(current->getRightChild(), indent + 4);
			if(indent > 0){
				cout<<setw(indent)<<" ";
			}
			cout << current->getFreq() << "," << current->getChar() << endl;
			Display(current->getLeftChild(), indent + 4);
		}
	}
	
	// Generate and return a map of all the characters in the input file
std::unordered_map<char, int> HuffmanTree::getCharMap(std::string inputFileName, std::vector<std::string> *inputStrings) {
    std::unordered_map<char, int> charMap;
    std::ifstream inFile(inputFileName);
    std::string line;

    // Read in and count the frequency of each character
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            inputStrings->push_back(line);
            for (char character: line) {
                if (charMap.find(character) != charMap.end()) {
                    charMap.at(character) += 1;
                } else {
                    charMap.insert({character, 1});
                }
            }
        }
        inFile.close();
    } else {
        std::cout << "Can't open file." << std::endl;
    }
    return charMap;
}
}
