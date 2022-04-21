/**
 * @Author - Ian Gerrits
 * @Version - 2/12/2022
 */
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node {
    public:
    Node* connectedNodes[26];
    bool isWord;
    std::string word;
    Node();
    Node(const Node& copyNode);
    Node& operator=(Node copyNode);
    ~Node();
    Node getNextNode(Node currNode, int nodeIndex);
    void addNode(Node currNode, int nodeIndex);
    void printTrie(std::string spacess, Node* currNode);
    void searchArray(Node* currNode, std::vector<std::string> &returnStrings);
};

#endif