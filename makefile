.SUFFIXES:
.SUFFIXES: .cpp .o
CC=g++
CCFLAGS=-std=c++11
LIBS=-lm
SOURCES=HuffmanNode.cpp HuffmanTree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TEST_SOURCES=HuffmanNode.cpp HuffmanTree.cpp UnitTesting.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)

huffencode: HuffmanTree.o HuffmanNode.o driver.o
		$(CC) $(CCFLAGS) HuffmanTree.o HuffmanNode.o driver.o -o huffencode $(LIBS)
		
HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
				$(CC) $(CCFLAGS) HuffmanTree.cpp -c

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
				$(CC) $(CCFLAGS) HuffmanNode.cpp -c

				
driver.o: driver.cpp
		$(CC) $(CCFLAGS) driver.cpp -c

		
clean: 
		@rm -f *.o
		@rm -f huffencode
		
install: 
		@mv huffencode -/bin

tests: $(OBJECTS)
	$(CC) $(TEST_SOURCES) -o Test/test $(FLAGS)

run-tests: tests
	cd ./build/Tests && ./test
