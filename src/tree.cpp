/*!
 * @file tree.cpp
 * @brief Source file for tree
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/tree.h"

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

// For use in prefixToParseTree()

/*!
 * @brief Takes in start and end pointers and generates a binary
 * tree recursively
 * @details For binary operators generates tree normally but for unary operator
 * like "~" right node is created
 * @param formulaStartPtr
 * @param formulaEndPtr
 * @return ParseTree*
 */
ParseTree *createParseTree(std::string::iterator *formulaStartPtr,
                           std::string::iterator formulaEndPtr) {
  if (*formulaStartPtr == formulaEndPtr) return nullptr;

  ParseTree *node = new ParseTree{**formulaStartPtr};

  switch (*((*formulaStartPtr)++)) {
    case '+':
    case '*':
    case '>':
      node->setLeftNode(createParseTree(formulaStartPtr, formulaEndPtr));
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
    case '~':
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
    default:
      break;
  }
  return node;
}

// Task 2

/*!
 * @brief Takes in a prefix formula and converts it into a rooted
 * binary parse tree
 *
 * @param prefixFormula
 * @return ParseTree*
 */
ParseTree *prefixToParseTree(std::string prefixFormula) {
  std::string::iterator characterPtr = prefixFormula.begin();
  std::string::iterator endPtr = prefixFormula.end();
  ParseTree *parseTree = createParseTree(&characterPtr, endPtr);
  return parseTree;
}

/*!
 * @brief Prints the binary tree
 *
 * @param prefix
 * @param node
 * @param isLeft boolean value to identify left or right nodes
 */
void printBinaryParseTree(const std::string &prefix, ParseTree *node,
                          bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << node->getValue() << std::endl;
    printBinaryParseTree(prefix + (isLeft ? "│   " : "    "),
                         node->getLeftNode(node), true);
    printBinaryParseTree(prefix + (isLeft ? "│   " : "    "),
                         node->getRightNode(node), false);
  }
}

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

/*!
 * @brief Traverses the parse tree and return the infix formula
 * @details Uses #inOrderTraversal to traverse
 * @param nodePtr
 * @return std::string infixFormula
 */
std::string parseTreeToInfix(ParseTree *nodePtr) {
  std::string infixFormula = "";
  inOrderTraversal(nodePtr, &infixFormula);
  return infixFormula;
}

// Task 4

/*!
 * @brief Get the max height of the node
 * @details Recursively calls itself to get the maximum height among the left
 * tree and right node trees
 * @param node
 * @return int
 */
long long int getNodeHeight(ParseTree *node) {
  if (node == nullptr) return 0;
  return 1 + std::max<long long int>(getNodeHeight(node->getLeftNode(node)),
                                     getNodeHeight(node->getRightNode(node)));
}

/*!
 * @brief Calculate the height of the binary tree recursively
 * @details Uses #getNodeHeight with entire tree as parameter
 * @param binaryTree
 * @return int
 */
long long int getBinaryTreeHeight(ParseTree *binaryTree) {
  return getNodeHeight(binaryTree);
}

// Task 5

/*!
 * @brief Gets the truth value of a given node
 *
 * @param nodePtr
 * @param hashPtr
 * @return true
 * @return false
 */
bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr) {
  switch (nodePtr->getValue()) {
    case '+':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '*':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) &&
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '>':
      return (!getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '~':
      return (!getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    default:
      if ((*hashPtr).find(nodePtr->getValue()) != (*hashPtr).end())
        return (*hashPtr)[nodePtr->getValue()];
      else {
        char truthVal{};
        srand((unsigned int)time(0));
        truthVal = rand() < 2147483647 / 2 ? 'T' : 'F';
        // std::cout
        //     << "Please enter the truth value (T/F) for propositional atom '"
        //     << nodePtr->getValue() << "': ";
        // std::cin >> truthVal;
        if (truthVal == 'T' || truthVal == 't') {
          (*hashPtr)[nodePtr->getValue()] = true;
          return true;
        } else if (truthVal == 'F' || truthVal == 'f') {
          (*hashPtr)[nodePtr->getValue()] = false;
          return false;
        } else {
          std::cout << "\nUnknown value entered, assumed to be False\n";
          return false;
        }
      }
      break;
  }
}

/*!
 * @brief Evaluates the truth value of a given parse tree
 * @details Uses #getNodeTruthValue to evaluate the truth value of a given parse
 * tree
 * @param nodePtr
 * @return true
 * @return false
 */
bool evaluateTreeTruthValue(ParseTree *nodePtr) {
  std::unordered_map<char, bool> atomTruthVals;
  return getNodeTruthValue(nodePtr, &atomTruthVals);
}
