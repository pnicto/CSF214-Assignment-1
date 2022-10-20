#pragma once

#include <iostream>
#include <string>

class ParseTree {
 private:
  char value{};
  ParseTree *leftNode{};
  ParseTree *rightNode{};

 public:
  ParseTree(char character);

  char getValue();

  void setLeftNode(ParseTree *node);
  void setRightNode(ParseTree *node);
};

ParseTree prefixToParseTree(std::string prefixFormula);
ParseTree *createTree(std::string::iterator valuePtr);