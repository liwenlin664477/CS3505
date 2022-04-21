# Author: Michael Sizemore and Kevin Macknight, CS3505, University of Utah 2022
# A4: Refactoring and Testing
# Description: This make file takes each program and compiles them into .o files which are then used to create an executable

CC = g++
CFLAGS = -Wall -fsanitize=undefined -fsanitize=address 
GOOGLETEST ?= ./googletest

TrieTests: TrieTests.o
	 $(CC) $(CFLAGS) -o TrieTests TrieTests.o -L$(GOOGLETEST)/lib -lgtest -lgtest_main -lpthread

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -g -c Trie.cpp
	
TrieTests.o: TrieTests.cpp
	$(CC) $(CFLAGS) -g -c TrieTests.cpp -I$(GOOGLETEST)/googletest/include

test:
	./TrieTests

clean:
	rm -f TrieTests *.o