/**
 * @file Trie.h
 * @author Michael Sizemore and Kevin Macknight
 * @brief A4: Refactoring and Testing
 * @version 2.0
 * @date 2022-02-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Trie
{
private:
    const static int ALPHABET_SIZE = 26; // data member or instance variable
    bool formsAWord;
    map<char, Trie> AlphabetTrieMap;
    char integerToCharacter(int givenInt); // private helper methods 
    Trie traverseToString(string givenString);
    void getAllWords(vector<string> &allWords, string givenString);

public:
    Trie();
    void addAWord(string givenString);
    bool isAWord(string givenString);
    vector<string> allWordsStartingWithPrefix(string givenPrefix);
};

#endif // include guard for TRIE_H