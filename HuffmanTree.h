#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include "HuffmanNode.h"
#include <memory>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <string>

namespace SHNMBA004{
	class Compare{
		public:
			bool operator()(HuffmanNode a,HuffmanNode b){
				if(a.getFreq()>= b.getFreq()){
					return true;
				}
				else{
					return false;
				}
			}
	};
	
	class HuffmanTree{
		private:
			std::shared_ptr<HuffmanNode> rt;
			std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> priorityQ;
			std::unordered_map<char,std::string>codeTable;
			
		public:
			HuffmanTree();
			~HuffmanTree();
			void CreateTree(std::unordered_map<char,int> & map);
			void Display(HuffmanNode * current, int indent);
			void traverse(HuffmanNode * current, std::string bitString);
			void compression(std::string inputFile,std::string outputFile);
			static std::unordered_map<char, int> getCharMap(std::string inputFileName, std::vector<std::string> *inputStrings);
	};
}

#endif /*HUFFMANTREE_H_ */
