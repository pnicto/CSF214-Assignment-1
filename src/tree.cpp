#include "tree.h"

ParseTree::ParseTree(char character) {
  value = character;
  leftNode = nullptr;
  rightNode = nullptr;
}

char ParseTree::getValue() { return value; }

void ParseTree::setLeftNode(ParseTree *node) { leftNode = node; }
void ParseTree::setRightNode(ParseTree *node) { rightNode = node; }

ParseTree *createTree(std::string::iterator valuePtr) {
  ParseTree node{*valuePtr};
  switch (*valuePtr) {
    case '+':
    case '*':
    case '>':
      node.setLeftNode(createTree(++valuePtr));
    case '~':
      node.setRightNode(createTree(++valuePtr));
    default:
      break;
  }
  return &node;
}

ParseTree prefixToParseTree(std::string prefixFormula) {
  std::string::iterator characterPtr = prefixFormula.begin();
  ParseTree tree = *createTree(characterPtr);
}
