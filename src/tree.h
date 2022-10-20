#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class ParseTree {
 private:
  char value{};
  ParseTree *leftNode{};
  ParseTree *rightNode{};

 public:
  ParseTree(char character);
  ~ParseTree();

  char getValue();
  ParseTree *getLeftNode(ParseTree *node);
  ParseTree *getRightNode(ParseTree *node);
  int getHeight(ParseTree *node);

  void setLeftNode(ParseTree *node);
  void setRightNode(ParseTree *node);
};

ParseTree *prefixToParseTree(std::string prefixFormula);
ParseTree *createTree(std::string::iterator *valuePtr,
                      std::string::iterator endPtr);
void printBT(const std::string &prefix, ParseTree *node, bool isLeft);
int treeHeight(ParseTree binaryTree);

std::string parseTreeToInfix(ParseTree *nodePtr);
void inOrderTraversal(ParseTree *nodePtr);

bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr);
bool evaluateTreeTruthValue(ParseTree *nodePtr);