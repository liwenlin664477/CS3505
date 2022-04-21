/**
 * @Author - Ian Gerrits
 * @Version - 2/12/2022
 */
#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

/**
 * Driver method for creating and testing a Trie using two input files
 */
int main() {
    ifstream firstInputFile;
    ifstream secondInputFile;
    string firstFile;
    string secondFie;
    string line;
    Trie::Trie testTrie;

    // Read in the first file and add it to the trie
    cin >> firstFile;
    firstInputFile.open(firstFile);
    if(firstInputFile.is_open()) {
        while (getline (firstInputFile,line) ) {
            testTrie.addAWord(line);
        }
        firstInputFile.close();
    }

    else {
        cout << "Unable to open first file";
    }

    // Read in the second file and check if the input words are contained in the trie
    cin >> secondFie;
    secondInputFile.open(secondFie);
    if(secondInputFile.is_open()) {
        while ( getline (secondInputFile,line) ) {
            if(testTrie.isAWord(line)) {
                cout << (line + " is found");
            }

            else {
                cout << (line + " is not found, did you mean:\n");
                std::vector<std::string> returnStrings;
                returnStrings = testTrie.allWordsStartingWithPrefix(line);
                if(returnStrings.size() != 0) {
                    for(std::string currString : returnStrings) {
                        cout << ("   " + currString) << endl;
                    }
                }
                else {
                    cout << "   no alternatives found";
                }
            }
        }
        secondInputFile.close();
    }

    else {
        cout << "Unable to open second file";
    }


    // Test for the copy constructor
    Trie::Trie copyTrie1;
    Trie::Trie copyTrie2;

    copyTrie1.addAWord("hello");
    copyTrie1.addAWord("world");
    copyTrie2 = copyTrie1;
    copyTrie2.addAWord("foo");
    copyTrie1.root -> printTrie("", copyTrie1.root);
    copyTrie2.root -> printTrie("", copyTrie2.root);
}