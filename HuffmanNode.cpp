//Student Name: Mbaliyethemba Shangase
//Student Number: SHNMBA004
//Due Date: 02/04/2019
//Assignment 3

#include "HuffmanNode.h"
#include <memory>

namespace SHNMBA004{
	//Node Constructor
	HuffmanNode::HuffmanNode(){
		character = 0;
		freq = 0;
		std::shared_ptr<HuffmanNode> left = nullptr;
		std::shared_ptr<HuffmanNode> right = nullptr;
	}
	
	//Destructor
	HuffmanNode::~HuffmanNode(){
		left = nullptr;
		right = nullptr;
		freq = -1;
	}
	
	void HuffmanNode::setChar(char c){
		character = c;
	}
	
	void HuffmanNode::setFreq(int f){
		freq = f;
	}
	
	void HuffmanNode::setLeftChild(HuffmanNode leftChild){
		left = std::make_shared<HuffmanNode>(leftChild);
	}
	
	void HuffmanNode::setRightChild(HuffmanNode rightChild){
		right = std::make_shared<HuffmanNode>(rightChild);
	}
	
	char HuffmanNode::getChar(){
		return character;
	}
	
	int HuffmanNode::getFreq(){
		return freq;
	}
	
	HuffmanNode * HuffmanNode::getLeftChild(){
		return left.get();
	}
	
	HuffmanNode * HuffmanNode::getRightChild(){
		return right.get();
	}
	
	HuffmanNode::HuffmanNode (const HuffmanNode & rhs){
		character = rhs.character;
		freq = rhs.freq;
		left = rhs.left;
		right = rhs.right;
	}
	
	HuffmanNode::HuffmanNode (HuffmanNode && rhs){
		character = rhs.character;
		this->freq = rhs.freq;
		left = rhs.left;
		right = rhs.right;
		rhs.left = nullptr;
		rhs.right = nullptr;
		rhs.freq = -1;
	}
	
	HuffmanNode & HuffmanNode::operator = (const HuffmanNode & rhs){
		if(this != &rhs){
			character = rhs.character;
			freq = rhs.freq;
			left = rhs.left;
			right = rhs.right;
		}
		return * this;
	}
	
	HuffmanNode & HuffmanNode::operator = (HuffmanNode && rhs){
		if(this != &rhs){
			character = std::move(rhs.character);
			freq = rhs.freq;
			left = rhs.left;
			right = rhs.right;
			rhs.left = nullptr;
			rhs.right = nullptr;
			rhs.freq = -1;
		}
		return * this;
	}
}
