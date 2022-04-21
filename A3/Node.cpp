/**
 * @Author - Ian Gerrits
 * @Version - 2/12/2022
 */
#include "Node.h"
#include <vector>
#include <iostream>
#include <string>

using std::cout;

/**
 * Node constructor that creates a node with 26 node pointers and a boolean saying if the node is the end of a word
 */
Node::Node() {
    Node* connectedNodes[26];
    bool isWord = false;
    std::string word;

    for(int currIndex = 0; currIndex < 26; currIndex++) {
        connectedNodes[currIndex] = nullptr;
    }
}

/**
 * Copy constructor for Node
 * 
 * @param - A node to copy the original node to
 */
Node::Node(const Node& copyNode) {
    for(int currIndex = 0; currIndex < 26; currIndex++) {
        connectedNodes[currIndex] = copyNode.connectedNodes[currIndex];
    }

    isWord = copyNode.isWord;
    word = copyNode.word;
}

/**
 * An operational copy constructor for Node
 * 
 * @param - A node to copy the original node to
 */
Node& Node::operator=(Node copyNode) {
    std::swap(connectedNodes, copyNode.connectedNodes);
    std::swap(isWord, copyNode.isWord);
    std::swap(word, copyNode.word);
    return *this;
}

/**
 * A node destructor
 */
Node::~Node() {
}

/**
 * Returns the next node contained at the given index of the previous node's array
 * 
 * @param - The current node
 * @param - The index of the next node down the trie
 */
Node Node::getNextNode(Node currNode, int nodeIndex) {
        return *currNode.connectedNodes[nodeIndex];
}

/**
 * Adds a new node to the trie
 * 
 * @param - The current node
 * @param - The index of the next node to be added to the trie
 */
void Node::addNode(Node currNode, int nodeIndex) {
    Node* newNode = nullptr;
    *newNode = *currNode.connectedNodes[nodeIndex];
}

/**
 * Prints a text representation of the trie (for testing purposes)
 * 
 * @param - The number of spaces depending on where in the trie the current node is
 * @param - The current node
 */
void Node::printTrie(std::string spaces, Node* currNode) {
    for(Node* currChar : currNode -> connectedNodes) {
        if(currChar) {
            cout << currChar;
            currChar -> printTrie(spaces + " ", currChar);
        }
    }
}

/**
 * Searches the trie and returns a vector of words used for the allWordsStartingWith method
 * 
 * @param - The current node
 * @param - A vector of strings that are to be returned
 */
void Node::searchArray(Node* currNode, std::vector<std::string> &returnStrings) {
    for(Node* currChar : currNode -> connectedNodes) {
        if(currChar) {
            if(currChar -> isWord) {
                returnStrings.push_back(currChar->word);
            }
            currChar -> searchArray(currChar, returnStrings);
        }
    }
}