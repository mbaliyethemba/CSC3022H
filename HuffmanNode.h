#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_

#include <memory>

namespace SHNMBA004{
	class HuffmanNode{
		private:
			char character; //stored in node
			int freq; //frequency of occurence
			std::shared_ptr<HuffmanNode> left; //left node
			std::shared_ptr<HuffmanNode> right; //right node
			
		public:
			HuffmanNode(); //constructor
			~HuffmanNode(); //destructor
			void setChar(char c);
			void setFreq(int f);
			void setLeftChild(HuffmanNode leftChild);
			void setRightChild(HuffmanNode rightChild);
			char getChar();
			int getFreq();
			HuffmanNode * getLeftChild();
			HuffmanNode * getRightChild();
			HuffmanNode ( const HuffmanNode & rhs); //copy constructor
			HuffmanNode (HuffmanNode && rhs); //move constructor
			HuffmanNode & operator = (const HuffmanNode & rhs); //copy assignment operator
			HuffmanNode & operator = (HuffmanNode && rhs); //Move assignment operator
	};
}
#endif /* HUFFMANNODE_H_ */
