/**
 * @Author - Ian Gerrits
 * @Version - 2/12/2022
 */
#include "Trie.h"
#include <iostream>
#include <vector>
#include <string>

/**
 * Trie constructor that creates a trie with a root node and a vector of all words contained within
 */
Trie::Trie() {
    Node* root = new Node;
    std::vector<std::string> allwords;
}

/**
 * Copy constructor for Trie
 * 
 * @param - A trie to copy the original trie to
 */
Trie::Trie(const Trie& copyTrie) {
    root = nullptr;
    root = new Node(*(copyTrie.root));
    allwords = new std::vector<std::string>(*(copyTrie.allwords));
}

/**
 * An operational copy constructor for Trie
 * 
 * @param - A trie to copy the original trie to
 */
Trie& Trie::operator=(Trie copyTrie) {
    std::swap(root, copyTrie.root);
    std::swap(allwords, copyTrie.allwords);
    return *this;
}

/**
 * Destructor for the Trie class
 */
Trie::~Trie() {
    delete root;
}

/**
 * Adds a word to the trie
 * 
 * @param - The input string to be added
 */
void Trie::addAWord(std::string inputWord) {

    Node* currNode = nullptr;
    currNode = root;

    for(char currChar : inputWord) {
        int currIndex = currChar - 'a';
        currNode -> addNode(*currNode, currIndex);
        currNode -> getNextNode(*currNode, currIndex);
    }

    allwords->push_back(inputWord);
    currNode -> isWord = true;
}

/**
 * Searches the trie and returns if the given input is a word
 * 
 * @param - The input string being tested
 */
bool Trie::isAWord(std::string inputWord) {

    Node* currNode = nullptr;
    currNode = root;
    
    for(char currChar : inputWord) {
        int currIndex = currChar - 'a';
        currNode -> getNextNode(*currNode, currIndex);
    }
    return currNode -> isWord;
}

/**
 * Searches the trie and returns a vector of words that start with the given string
 * 
 * @param - The input string used for finding longer words
 */
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string inputString) {
    if(inputString.length() == 0) {
        return *allwords;
    }

    Node* currNode = nullptr;
    currNode = root;
    std::vector<std::string> returnStrings;

    for(char currChar : inputString) {
        int currIndex = currChar - 'a';
        currNode -> getNextNode(*currNode, currIndex);
    }
    currNode->searchArray(currNode, returnStrings);
}
