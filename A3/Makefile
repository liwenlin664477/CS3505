CC = g++
CFLAGS = -Wall -std=c++11
FFLAGS = -fsanitize=undefined -fsanitize=address

TrieTest: Trie.h
	$(CC) $(CFLAGS) $(FFLAGS) -o TrieTest Trie.h

Trie.o: Trie.cpp  Trie.h 
	$(CC) $(CFLAGS) $(FFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h 
	$(CC) $(CFLAGS) $(FFLAGS) -c Node.cpp

TrieTest.o: Trie.cpp 
	$(CC) $(CFLAGS) $(FFLAGS) -c Trie.cpp

clean:
	rm -f TrieTest *.o