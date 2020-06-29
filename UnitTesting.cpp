#include "HuffmanTree.h"
#include "HuffmanNode.h"
#define CATCH_CONFIG_MAIN
#include <unordered_map>
#include <vector>
#include <string>
#include "catch.hpp"

std::string inString("test.txt");
HuffmanTree huffmanTree(inString);

TEST_CASE("CharMap is made correctly", "[char, map]"){
	REQUIRE(huffmanTree.getInStrings().size()==2);
	REQUIRE(huffmanTree.getUnorderedMap().size() == 9);
	REQUIRE(huffmanTree.getUnorderedMap().size() == 3);
}

TEST_CASE("NodeQueue correct", "[node, queue]"){
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> orderedNodes = huffman.getOrderedNodes();
	REQUIRE(!orderedNodes.empty());
	REQUIRE(orderedNodes.size() == 9);
	HuffmanNode * A = orderedNodes.top();
	REQUIRE(A->freq == 1);
}

TEST_CASE("Node structure correct", "[tree]"){
	REQUIRE(huffmanTree.root->freq == 12);
	REQUIRE(huffmanTree.root->letter == '$');
}

TEST_CASE("Code Table correct", "[tree, codeTable]"){
	std::unordered_map<char, std::string> codeTable = huffmanTree.getCodeTable();
	REQUIRE(!codeTable.empty());
    REQUIRE(codeTable.size() == 9);
    REQUIRE(codeTable['H'] == "001");
    REQUIRE(codeTable['e'] == "1100");
    REQUIRE(codeTable['l'] == "01");
    REQUIRE(codeTable['o'] == "111");
	REQUIRE(codeTable['W'] == "1101");
	REQUIRE(codeTable['r'] == "1010");
	REQUIRE(codeTable['d'] == "100");
	REQUIRE(codeTable[' '] == "1011");
	REQUIRE(codeTable['.'] == "000");
}
