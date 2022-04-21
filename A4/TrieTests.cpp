/**
 * @file TrieTests.cpp
 * @author Michael Sizemore and Kevin Macknight
 * @brief A4: Refactoring and Testing
 * @version 2.0
 * @date 2022-02-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Trie.cpp"
#include <gtest/gtest.h>

using namespace std;

// isAWord Tests

/**
 * Showcases how "" will always display as not a word,
 * even if an attempt is made to explicitly add it to the trie.
 */
TEST(TrieTests, EmptyWordAlwaysFalse)
{
  Trie dictionaryRoot;
  EXPECT_EQ(false, dictionaryRoot.isAWord(""));
  dictionaryRoot.addAWord("");
  EXPECT_EQ(false, dictionaryRoot.isAWord(""));
}

/**
 * Showcases that words won't be present in the Trie
 * if they aren't added into it.
 */
TEST(TrieTests, BasicWordNotPresent)
{
  Trie dictionaryRoot;
  for (int i = 0; i < 26; i++)
  {
    string givenString(3, char(i + int('a')));
    EXPECT_EQ(false, dictionaryRoot.isAWord(givenString));
  }
}

/**
 * Adds in a word and shows that the isAWord recognizes that
 * specific word as being there, and slight variations as not being present.
 */
TEST(TrieTests, AddBasicWord)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("aaaa");
  EXPECT_EQ(false, dictionaryRoot.isAWord("aaa"));
  EXPECT_EQ(true, dictionaryRoot.isAWord("aaaa"));
  EXPECT_EQ(false, dictionaryRoot.isAWord("aaaaa"));
}

// addAWord Tests

/**
 * Showcases that large words can be processed
 */
TEST(TrieTests, BasicLongWordPresent)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("thisisalongword");
  EXPECT_EQ(true, dictionaryRoot.isAWord("thisisalongword"));
}

/**
 * Showcases that the same word can be added in
 * multiple times without anything adverse happening
 */
TEST(TrieTests, AddDuplicateWord)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("aaaa");
  dictionaryRoot.addAWord("aaaa");
  dictionaryRoot.addAWord("aaaa");
  EXPECT_EQ(false, dictionaryRoot.isAWord("aaa"));
  EXPECT_EQ(true, dictionaryRoot.isAWord("aaaa"));
  EXPECT_EQ(false, dictionaryRoot.isAWord("aaaaa"));
}

/**
 * Edge cases to show that 'a' and 'z' are present in the Trie,
 * thus showing that it contains a-z letters.
 */
TEST(TrieTests, AandZWordsWork)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("aza");
  dictionaryRoot.addAWord("zaz");
  EXPECT_EQ(true, dictionaryRoot.isAWord("aza"));
  EXPECT_EQ(true, dictionaryRoot.isAWord("zaz"));
}

// allWordsStartingWithPrefix Tests

/**
 * Shows that the prefix methods returns all
 * words starting with 'a', and doesn't return the
 * one word that doesn't.
 */
TEST(TrieTests, PrefixPresentUsingA)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("an");
  dictionaryRoot.addAWord("and");
  dictionaryRoot.addAWord("zed");
  // Due to how vectors work, they must be pushed back
  // in a reverse order for comparison to the method vector.
  vector<string> comparisonVector;
  comparisonVector.push_back("and");
  comparisonVector.push_back("an");
  vector<string> testVector = dictionaryRoot.allWordsStartingWithPrefix("a");
  long unsigned int expectedSize = 2;
  EXPECT_EQ(expectedSize, testVector.size());
  // Checks to make sure the prefix words present match
  // up with what they should be, and that the method didn't just
  // coincidentally get the correct number of expected words.
  for (string word : testVector)
  {
    EXPECT_EQ(comparisonVector.back(), word);
    comparisonVector.pop_back();
  }
}

// /**
//  * Showcases that adding in multiple of the same word
//  * still just adds it once, and it still only appears
//  * in the vector once.
//  */
TEST(TrieTests, PrefixPresentOnce)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("an");
  dictionaryRoot.addAWord("an");
  dictionaryRoot.addAWord("zed");
  vector<string> comparisonVector;
  comparisonVector.push_back("an");
  vector<string> testVector = dictionaryRoot.allWordsStartingWithPrefix("a");
  long unsigned int expectedSize = 1;
  EXPECT_EQ(expectedSize, testVector.size());
  // Checks to make sure the prefix words present match
  // up with what they should be, and that the method didn't just
  // coincidentally get the correct number of expected words.
  for (string word : testVector)
  {
    EXPECT_EQ(comparisonVector.back(), word);
    comparisonVector.pop_back();
  }
}

// /**
//  * Shows that when you put "" as the word to find all words that
//  * contain it as a prefix, it simply returns all words present in the Trie.
//  */
TEST(TrieTests, PrefixPresentAllWords)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("an");
  dictionaryRoot.addAWord("and");
  dictionaryRoot.addAWord("soul");
  dictionaryRoot.addAWord("water");
  dictionaryRoot.addAWord("zed");
  // Due to how vectors work, they must be pushed back
  // in a reverse order for comparison to the method vector.
  vector<string> comparisonVector;
  comparisonVector.push_back("zed");
  comparisonVector.push_back("water");
  comparisonVector.push_back("soul");
  comparisonVector.push_back("and");
  comparisonVector.push_back("an");
  vector<string> testVectorAllWords = dictionaryRoot.allWordsStartingWithPrefix("");
  long unsigned int expectedSize = 5;
  EXPECT_EQ(expectedSize, testVectorAllWords.size());
  // Checks to make sure the prefix words present match
  // up with what they should be, and that the method didn't just
  // coincidentally get the correct number of expected words.
  for (string word : testVectorAllWords)
  {
    EXPECT_EQ(comparisonVector.back(), word);
    comparisonVector.pop_back();
  }
}

// /**
//  * Showcases that searching for all words
//  * that contain a prefix with a prefix that cannot be
//  * found returns nothing, as no words can have it as a
//  * prefix in those circumstances.
//  */
TEST(TrieTests, PrefixWordNotInTrie)
{
  Trie dictionaryRoot;
  dictionaryRoot.addAWord("an");
  dictionaryRoot.addAWord("alr");
  dictionaryRoot.addAWord("alrigh");
  vector<string> testVectorAllWords = dictionaryRoot.allWordsStartingWithPrefix("alright");
  long unsigned int expectedSize = 0;
  EXPECT_EQ(expectedSize, testVectorAllWords.size());
}

// Assignment Tests

/**
 * Showcases rule-of-three by swapping the words
 * contained in two different Trie's.
 */
TEST(TrieTests, SimpleAssignmentTest)
{
  Trie sampleTrie;
  Trie assignmentTest;
  assignmentTest.addAWord("cat");
  assignmentTest = sampleTrie;
  EXPECT_FALSE(assignmentTest.isAWord("cat"));
  EXPECT_FALSE(sampleTrie.isAWord("cat"));
}

/**
 * Showcases that the assignment operator
 * covers all the values in a transfer.
 */
TEST(TrieTests, ComplexAssignmentTest)
{
  Trie sampleTrie;
  Trie assignmentTest;
  // Adds 26 strings to sampleTrie
  for (int i = 0; i < 26; i++)
  {
    string expectedString(3, char(i + int('a')));
    string defaultString(2, char(i + int('a')));
    sampleTrie.addAWord(expectedString);
    assignmentTest.addAWord(defaultString);
  }
  assignmentTest = sampleTrie;
  // Ensures the assigned Trie has the same strings
  for (int i = 0; i < 26; i++)
  {
    string expectedString(3, char(i + int('a')));
    EXPECT_TRUE(sampleTrie.isAWord(expectedString));
    EXPECT_TRUE(assignmentTest.isAWord(expectedString));
  }
}

/**
 * Showcases that values do transfer with an assignment test,
 * even when the Trie is empty.
 */
TEST(TrieTests, EmptyAssignmentTest)
{
  Trie sampleTrie;
  sampleTrie.addAWord("dogs");
  Trie assignmentTest;
  assignmentTest = sampleTrie;
  EXPECT_TRUE(assignmentTest.isAWord("dogs"));
  EXPECT_TRUE(sampleTrie.isAWord("dogs"));
}

// Copy Tests

/**
 * Showcases the rule-of-three by
 * copying the values in one Trie into another.
 */
TEST(TrieTests, SimpleCopyTest)
{
  Trie sampleTrie;
  sampleTrie.addAWord("dogs");
  Trie copyTest;
  copyTest = sampleTrie;
  EXPECT_TRUE(copyTest.isAWord("dogs"));
  EXPECT_TRUE(sampleTrie.isAWord("dogs"));
}

/**
 * Showcases that a copied Trie has the
 * exact same values as the original
 */
TEST(TrieTests, ComplexCopyTest)
{
  Trie sampleTrie;
  Trie copyTest;
  // Adds 26 strings to sampleTrie
  for (int i = 0; i < 26; i++)
  {
    string givenString(3, char(i + int('a')));
    sampleTrie.addAWord(givenString);
  }
  copyTest = sampleTrie;
  // Ensures the copied Trie has the same strings
  for (int i = 0; i < 26; i++)
  {
    string givenString(3, char(i + int('a')));
    EXPECT_TRUE(sampleTrie.isAWord(givenString));
    EXPECT_TRUE(copyTest.isAWord(givenString));
  }
}