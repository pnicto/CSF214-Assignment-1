/*!
 * @file parsetree.cpp
 * @brief Source file for parse tree
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/parsetree.h"

/*!
 * @brief Construct a new Parse Tree object which takes ParseTree::value
 *@details Creates a new tree with ParseTree::leftNode and ParseTree::rightNode
 *as nullptr
 * @param character
 */
ParseTree::ParseTree(char character) {
  value = character;
  leftNode = nullptr;
  rightNode = nullptr;
}

/*!
 * @brief Destroy the Parse Tree object
 *
 */
ParseTree::~ParseTree() {
  if (leftNode != nullptr) {
    delete leftNode;
  }
  if (rightNode != nullptr) {
    delete rightNode;
  }
}

// Getters

/*!
 * @brief Get the value of the node
 *
 * @return char
 */
char ParseTree::getValue() { return value; }

/*!
 * @brief Get the left node when a node is given
 * @param node
 * @details Returns the pointer to left node when a node is given
 * @return ParseTree*
 */
ParseTree *ParseTree::getLeftNode(ParseTree *node) { return node->leftNode; }

/*!
 * @brief Get the right node when a node is given
 * @param node
 * @details Returns the pointer to right node when a node is given
 * @return ParseTree*
 */
ParseTree *ParseTree::getRightNode(ParseTree *node) { return node->rightNode; }

// Setters

/*!
 * @brief Set the left node of a given node
 *
 * @param node
 */
void ParseTree::setLeftNode(ParseTree *node) { leftNode = node; }

/*!
 * @brief Set the right node of a given node
 *
 * @param node
 */
void ParseTree::setRightNode(ParseTree *node) { rightNode = node; }

/*!
 * @brief Prints the binary tree
 *
 * @param prefix
 * @param node
 * @param isLeft boolean value to identify left or right nodes
 */
void ParseTree::printParseTree(const std::string &prefix, ParseTree *node,
                               bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;
    // Prints the '├' character if the node being printed is the left node, and
    // the '└' character if it's the right node
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << node->getValue() << std::endl;
    // Recursively adds the characters to be printed in every line before the
    // current node's value, inside the 'prefix' variable
    printParseTree(prefix + (isLeft ? "│   " : "    "), node->getLeftNode(node),
                   true);
    printParseTree(prefix + (isLeft ? "│   " : "    "),
                   node->getRightNode(node), false);
  }
}

/*!
 * @brief Traverses the parse tree and return the infix formula
 * @details Uses #inOrderTraversal to traverse
 * @param nodePtr
 * @return std::string infixFormula
 */
std::string ParseTree::getInfixExpression(ParseTree *nodePtr) {
  std::string infixFormula = "";
  this->inOrderTraversal(nodePtr, &infixFormula);
  return infixFormula;
}

// Task 4

/*!
 * @brief Calculate the height of the binary tree recursively
 * @param binaryTree
 * @return int
 */
int ParseTree::getHeight(ParseTree *binaryTree) {
  if (binaryTree == nullptr) return 0;
  // Recursively calls the function on each node of the tree, returning 1 + the
  // larger of the height values returned by its left and right nodes
  return 1 + std::max<int>(getHeight(binaryTree->getLeftNode(binaryTree)),
                           getHeight(binaryTree->getRightNode(binaryTree)));
}
