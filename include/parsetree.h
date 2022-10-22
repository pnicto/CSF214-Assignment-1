/*!
 * @file parsetree.h
 * @brief Header file for parse tree
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

/*!
 * @brief Class for parse tree
 * @details Implements a rooted binary parse tree for a given propositional
 * logic formula.
 *
 */
class ParseTree {
 private:
  /*!
   * @brief  Value stored by the node
   *
   */
  char value{};

  /*!
   * @brief Left node
   *
   */
  ParseTree *leftNode{};

  /*!
   * @brief Right node
   *
   */
  ParseTree *rightNode{};

  // Task 3
  /*!
   * @brief Utility method which traverses the tree in in-order manner
   *
   * @param nodePtr
   * @param infixFormulaPtr
   */
  void inOrderTraversal(ParseTree *nodePtr, std::string *infixFormulaPtr) {
    if (nodePtr->getLeftNode(nodePtr) != nullptr)
      inOrderTraversal(nodePtr->getLeftNode(nodePtr), infixFormulaPtr);
    infixFormulaPtr->push_back(nodePtr->getValue());
    if (nodePtr->getRightNode(nodePtr) != nullptr)
      inOrderTraversal(nodePtr->getRightNode(nodePtr), infixFormulaPtr);
  }


 public:
  ParseTree(char character);
  ~ParseTree();

  // Getters
  char getValue();
  ParseTree *getLeftNode(ParseTree *node);
  ParseTree *getRightNode(ParseTree *node);
  int getHeight(ParseTree *binaryTree);
  std::string getInfixExpression(ParseTree *nodePtr);

  // Setters
  void setLeftNode(ParseTree *node);
  void setRightNode(ParseTree *node);

  // Misc
  void printParseTree(const std::string &prefix, ParseTree *node, bool isLeft);
};

