/*!
 * @file tree.h
 * @brief Header file for tree
 * @version 0.1
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
 *
 */
class ParseTree {
 private:
  /*!
   * @brief  Value stored by node
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
  /*!
   * @brief Construct a new Parse Tree object which takes the value as parameter
   *
   * @param character
   */
  ParseTree(char character);

  /*!
   * @brief Destroy the Parse Tree object
   *
   */
  ~ParseTree();

  /*!
   * @brief Get the value of the node
   *
   * @return char
   */
  char getValue();

  /*!
   * @brief Get the Left node when a node is given
   *
   * @param node
   * @return ParseTree*
   */
  ParseTree *getLeftNode(ParseTree *node);

  /*!
   * @brief Get the Right node when a node is given
   *
   * @param node
   * @return ParseTree*
   */
  ParseTree *getRightNode(ParseTree *node);

  /*!
   * @brief Get the max height of the node
   *
   * @param node
   * @return int
   */
  int getHeight(ParseTree *node);

  /*!
   * @brief Set the left node when a node is given
   *
   * @param node
   */
  void setLeftNode(ParseTree *node);

  /*!
   * @brief Set the right node when a node is given
   *
   * @param node
   */
  void setRightNode(ParseTree *node);
};

/*!
 * @brief Method which takes in a prefix formula and converts it into a rooted
 * binary parse tree
 *
 * @param prefixFormula
 * @return ParseTree*
 */
ParseTree *prefixToParseTree(std::string prefixFormula);

/*!
 * @brief Method which takes in start and end pointers and generates a binary
 * tree recursively
 *
 * @param valuePtr
 * @param endPtr
 * @return ParseTree*
 */
ParseTree *createTree(std::string::iterator *valuePtr,
                      std::string::iterator endPtr);

/*!
 * @brief Method which prints the binary tree
 *
 * @param prefix
 * @param node
 * @param isLeft
 */
void printBT(const std::string &prefix, ParseTree *node, bool isLeft);

/*!
 * @brief Method which calculates the height of the binary tree recursively
 *
 * @param binaryTree
 * @return int
 */
int treeHeight(ParseTree *binaryTree);

/*!
 * @brief Method which gives infix formula for a given parse tree
 *
 * @param nodePtr
 * @return std::string infixFormula
 */
std::string parseTreeToInfix(ParseTree *nodePtr);

/*!
 * @brief Method which traverses the tree in in-order manner
 *
 * @param nodePtr
 */
void inOrderTraversal(ParseTree *nodePtr);

/*!
 * @brief Get the truth value of a given node
 *
 * @param nodePtr
 * @param hashPtr
 * @return true
 * @return false
 */
bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr);

/*!
 * @brief Evaluates the truth value of a given parse tree
 *
 * @param nodePtr
 * @return true
 * @return false
 */
bool evaluateTreeTruthValue(ParseTree *nodePtr);