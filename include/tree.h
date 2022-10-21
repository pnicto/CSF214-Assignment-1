/*!
 * @file tree.h
 * @brief Header file for tree
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
 * @details Implments a rooted binary parse tree for a given propositional logic formula.
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

 public:
  ParseTree(char character);
  ~ParseTree();

  // Getters
  char getValue();
  ParseTree *getLeftNode(ParseTree *node);
  ParseTree *getRightNode(ParseTree *node);

  // Setters
  void setLeftNode(ParseTree *node);
  void setRightNode(ParseTree *node);
};

// Functions related to tasks

// Task 2
ParseTree *createParseTree(std::string::iterator *formulaStartPtr,
                           std::string::iterator formulaEndPtr);
ParseTree *prefixToParseTree(std::string prefixFormula);
void printBinaryParseTree(const std::string &prefix, ParseTree *node,
                          bool isLeft);

// Task 3
void inOrderTraversal(ParseTree *nodePtr);
std::string parseTreeToInfix(ParseTree *nodePtr);

// Task 4
int getNodeHeight(ParseTree *node);
int getBinaryTreeHeight(ParseTree *binaryTree);

// Task 5
bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr);
bool evaluateTreeTruthValue(ParseTree *nodePtr);