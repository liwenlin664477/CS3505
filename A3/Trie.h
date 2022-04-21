/**
 * @Author - Ian Gerrits
 * @Version - 2/12/2022
 */
#ifndef TRIE_H
#define TRIE_H

#include "Node.h"
#include <vector>
#include <string>


class Trie {
    public:
    Node* root;
    std::vector<std::string>* allwords;
    Trie();
    Trie(const Trie& copyTrie);
    Trie& operator=(Trie copyTrie);
    ~Trie();
    void addAWord(std::string inputString);
    bool isAWord(std::string inputString);
    std::vector<std::string> allWordsStartingWithPrefix(std::string inputString);
};

#endif