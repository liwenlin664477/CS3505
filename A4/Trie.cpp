/**
 * @file Trie.cpp
 * @author Michael Sizemore and Kevin Macknight
 * @brief A4: Refactoring and Testing
 * @version 2.0
 * @date 2022-02-22
 *
 * @copyright Copyright (c) 2022
 */

#include "Trie.h"
using namespace std;

/**
 * @brief Sets formsAWord to false by default.
 */
Trie::Trie() : formsAWord(false) { ; }

/**
 * @brief This method takes a given word and adds it into the Trie and sets the last node to true to signify that it
 *        forms a word. This method uses recursion and the given string to navigate through the Trie.
 *
 * @param givenString The given string which will be added into the Trie by setting formsAWord to True
 */
void Trie::addAWord(string givenString)
{
    if (givenString.length() == 0) // Base case for the recursive calls which sets the last node to true
    {
        formsAWord = true;
    }
    else
    {
        // Uses AlphabetTrieMap[char] to look for a branch as it will make a default Node if it does not exist
        AlphabetTrieMap[givenString.at(0)].addAWord(givenString.substr(1));
    }
}

/**
 * @brief This method takes a given word and uses recursion to check and see if it is in the Trie and returns
 *        the variable "formsAWord". If the word can not be found or is empty in the Trie it returns false.
 *
 * @param givenString The given string which will be used to check and see if it is a word
 * @return true Returns true if the item is found in the Trie and has "formsAWord" is set to true
 * @return false Returns false if "formsAWord" is set to false or if the string length is 0
 */
bool Trie::isAWord(string givenString)
{
    if (givenString.length() == 0) // Ensures that empty strings always returns false
    {
        return false;
    }
    else
    {
        return traverseToString(givenString).formsAWord;
    }
}

/**
 * @brief This method takes a given prefix and uses it to find the location of the prefix in the Trie and to
 *        then put every word starting with the prefix into a vector which will be returned to the user.
 *
 * @param givenPrefix The given prefix which will be used for getting all the words
 * @return vector<string> Returns a vector<string> containing all of the words starting with the given prefix.
 *         If the Trie does not contain the prefix it will return an empty vector.
 */
vector<string> Trie::allWordsStartingWithPrefix(string givenPrefix)
{
    vector<string> validWordVector;
    traverseToString(givenPrefix).getAllWords(validWordVector, givenPrefix);
    return validWordVector;
}

/**
 * @brief This private helper method is used to take the given string and to navigate to that location in the
 *        Trie using recursion. If the string leads to a location that does not exist it returns a default Trie. This
 *        is only used to traverse the Trie and does not add in or modify any nodes.
 *
 * @param givenString The given string which will be used to navigate to the location in the Trie
 * @return Trie Returns the location that is navigated to by the givenString. If the givenString leads to 
 *              location that does not exist it returns a default Trie with no branches set to false
 */
Trie Trie::traverseToString(string givenString)
{
    if (givenString.length() == 0) // Base Case for when the last letter has been navigated to
    {
        return *this;
    }
    else if (AlphabetTrieMap.count(givenString.at(0)) == 1)
    {
        // Uses AlphabetTrieMap[char] since we know char exists to make the next recursive call with a truncated string
        return AlphabetTrieMap[givenString.at(0)].traverseToString(givenString.substr(1));
    }
    else
    {
        return Trie();
    }
}

/**
 * @brief This private helper method uses recursion to get all valid words that can be found from the current point at which
 *        this method is called. Valid words are added to the vector which will then later be returned to the user.
 *
 * @param allWords The reference to the vector which will have the valid words added to
 * @param givenString The given string that will be checked to see if it forms a word
 *                    and will be added to and passed in to the next recursive call.
 */
void Trie::getAllWords(vector<string> &allWords, string givenString)
{
    if (formsAWord)
    {
        allWords.push_back(givenString);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (AlphabetTrieMap.count(integerToCharacter(i)) == 1)
        {
            // Recursively searches for additional words using the newly found prefix.
            AlphabetTrieMap[integerToCharacter(i)].getAllWords(allWords, givenString + integerToCharacter(i));
        }
    }
}

/**
 * @brief This private helper method is used to take a given integer and converts it into
 *        the returned character which correlates to the given values ascii code.
 *
 * @param givenInt The given integer which will be converted into a character
 * @return char Returns a character which is equivalent to the ascii code of the given integer
 */
char Trie::integerToCharacter(int givenInt)
{
    return char(givenInt + int('a'));
}